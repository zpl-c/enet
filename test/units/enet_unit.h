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

#define GET_MACRO(_1, _2, _3, NAME, ...) NAME
#define ASSERT_THAT(...) GET_MACRO(__VA_ARGS__, ASSERT_THAT_IMPL3, ASSERT_THAT_IMPL2)(__VA_ARGS__)

#define REGISTER_TEST(f) \
    do { \
        if (enet_test_count < MAX_TESTS) { \
            enet_test_entries[enet_test_count].name = #f; \
            enet_test_entries[enet_test_count].func = f; \
            enet_test_count++; \
        } else { \
            fprintf(stderr, "Too many unit tests!\n"); \
        } \
    } while (0)

#define TEST(func) \
    static void test_##func(ENetTestEntry * entry); \
    __attribute__((constructor)) static void register_##func(void) { \
        REGISTER_TEST(test_##func); \
    } \
    static void test_##func(ENetTestEntry * entry)

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
        ENetTestEntry *entry = &enet_test_entries[i];

        fprintf(stdout, "[ RUNNING ] %s\n", entry->name);
        fflush(stdout);

        entry->func(entry);
        fflush(stderr);

        if (0 < entry->failed) {
            fprintf(stderr, "[ FAILED  ] %s\n", entry->name);
            fflush(stderr);
        } else {
            fprintf(stdout, "[ PASSED  ] %s\n", entry->name);
            fflush(stdout);
        }

        failed += entry->failed;
    }

    return failed;
}

#endif
