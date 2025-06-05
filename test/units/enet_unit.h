#ifndef ENET_UNIT_H
#define ENET_UNIT_H

#include <stdio.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

typedef struct _ENetTestEntry ENetTestEntry;

typedef void (*ENetUnitTestFunc)(ENetTestEntry *entry);

typedef struct _ENetTestEntry {
    const char *name;
    ENetUnitTestFunc func;
    int failed;
} ENetTestEntry;

#define MAX_TESTS 8096

static ENetTestEntry enet_test_entries[MAX_TESTS];
static int enet_test_count = 0;

#ifdef _WIN32
#define ASSERT_SLEEP(ms) Sleep(ms)
#else
#define ASSERT_SLEEP(ms) usleep(ms * 1000);
#endif

#define ENET_EXPAND(x) x
#define GET_MACRO(_1, _2, _3, NAME, ...) NAME
#define ASSERT_THAT(...) ENET_EXPAND( GET_MACRO(__VA_ARGS__, ASSERT_THAT_IMPL3, ASSERT_THAT_IMPL2)(__VA_ARGS__) )

#define ENET_TEST_REGISTER(f) \
    do { \
        if (enet_test_count < MAX_TESTS) { \
            enet_test_entries[enet_test_count].name = #f; \
            enet_test_entries[enet_test_count].func = f; \
            enet_test_count++; \
        } else { \
            fprintf(stderr, "Too many unit tests!\n"); \
        } \
    } while (0)

#ifdef __GNUC__
#define ENET_TEST_REGISTER_FUNC(func) static void __attribute__((constructor)) func(void)
#elif defined(_MSC_VER)
#pragma section(".CRT$XCU", read)
#define ENET_TEST_REGISTER_FUNC(func) \
static void __cdecl func(void); \
__declspec(allocate(".CRT$XCU")) static void (__cdecl * const func##_ptr)(void) = func; \
static void __cdecl func(void)
#else
#pragma message("WARNING: Please ENET_TEST_REGISTER_FUNC for this compiler")
#define ENET_TEST_REGISTER_FUNC
#endif

#define TEST(func) \
    static void enet_test_##func(ENetTestEntry * entry); \
    ENET_TEST_REGISTER_FUNC(enet_test_register_##func) { \
        ENET_TEST_REGISTER(enet_test_##func); \
    } \
    static void enet_test_##func(ENetTestEntry * entry)

#define ASSERT_THAT_IMPL3(a, b, m) do { \
    if ((a) != (b)) { \
        entry->failed += 1; \
        fprintf(stderr, "%s\n", m); \
        fprintf(stderr, "ASSERT_THAT(%s, %s)\n", #a, #b); \
        fprintf(stderr, "  Expected: %s\n", #b); \
        fprintf(stderr, "  But was: %s\n", #a); \
        fprintf(stderr, "at %s:%d\n", __FILE__, __LINE__); \
        return; \
    } \
} while (0)

#define ASSERT_THAT_IMPL2(a, b) do { \
    if ((a) != (b)) { \
        entry->failed += 1; \
        fprintf(stderr, "ASSERT_THAT(%s, %s)\n", #a, #b); \
        fprintf(stderr, "  Expected: %s\n", #b); \
        fprintf(stderr, "  But was: %s\n", #a); \
        fprintf(stderr, "at %s:%d\n", __FILE__, __LINE__); \
        return; \
    } \
} while (0)

static int run_all_tests(void) {
    int failed = 0;
    for (int i = 0; i < enet_test_count; ++i) {
        const char* prefix = "enet_test_";
        ENetTestEntry *entry = &enet_test_entries[i];

        const char *funcName = entry->name + strlen(prefix);

        fprintf(stdout, "[ RUNNING ] TEST(%s)\n", funcName);
        fflush(stdout);

        entry->func(entry);
        fflush(stderr);

        if (0 < entry->failed) {
            fprintf(stderr, "[ FAILED  ] TEST(%s)\n", funcName);
            fflush(stderr);
        } else {
            fprintf(stdout, "[ PASSED  ] TEST(%s)\n", funcName);
            fflush(stdout);
        }

        failed += entry->failed;
    }

    return failed;
}

#endif
