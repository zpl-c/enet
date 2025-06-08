#include "enet.h"
#include "enet_unit.h"

TEST(ENET_TIME_LESS) {
    enet_uint32 a = 1000;
    enet_uint32 b = 2000;
    // Normal cases
    ASSERT_EQ(ENET_TIME_LESS(a, b), true, "ENET_TIME_LESS should return true for a < b");
    ASSERT_EQ(ENET_TIME_LESS(a, a), false, "ENET_TIME_LESS should return false for a == b");
    ASSERT_EQ(ENET_TIME_LESS(b, a), false, "ENET_TIME_LESS should return false for a > b");

    // Cases involving ENET_TIME_OVERFLOW constant
    ASSERT_EQ(ENET_TIME_LESS(a, ENET_TIME_OVERFLOW), true,
                "ENET_TIME_LESS with a < ENET_TIME_OVERFLOW and b == ENET_TIME_OVERFLOW should be true");
    ASSERT_EQ(ENET_TIME_LESS(ENET_TIME_OVERFLOW, a), false,
                "ENET_TIME_LESS with a == ENET_TIME_OVERFLOW and b < ENET_TIME_OVERFLOW should be false");
    ASSERT_EQ(ENET_TIME_LESS(ENET_TIME_OVERFLOW, ENET_TIME_OVERFLOW), false,
                "ENET_TIME_LESS with a == ENET_TIME_OVERFLOW and b == ENET_TIME_OVERFLOW should be false");
}

TEST(ENET_TIME_GREATER) {
    enet_uint32 a = 1000;
    enet_uint32 b = 2000;
    // Normal cases
    ASSERT_EQ(ENET_TIME_GREATER(b, a), true, "ENET_TIME_GREATER should return true for a > b");
    ASSERT_EQ(ENET_TIME_GREATER(a, a), false, "ENET_TIME_GREATER should return false for a == b");
    ASSERT_EQ(ENET_TIME_GREATER(a, b), false, "ENET_TIME_GREATER should return false for a < b");

    // Cases involving ENET_TIME_OVERFLOW constant
    ASSERT_EQ(ENET_TIME_GREATER(a, ENET_TIME_OVERFLOW), false,
                "ENET_TIME_GREATER with a < ENET_TIME_OVERFLOW and b == ENET_TIME_OVERFLOW should be false");
    ASSERT_EQ(ENET_TIME_GREATER(ENET_TIME_OVERFLOW, a), true,
                "ENET_TIME_GREATER with a == ENET_TIME_OVERFLOW and b < ENET_TIME_OVERFLOW should be true");
    // ENET_TIME_GREATER is !ENET_TIME_LESS_EQUAL
    ASSERT_EQ(ENET_TIME_GREATER(ENET_TIME_OVERFLOW, ENET_TIME_OVERFLOW), false,
                "ENET_TIME_GREATER with a == ENET_TIME_OVERFLOW and b == ENET_TIME_OVERFLOW should be false");
}

TEST(ENET_TIME_LESS_EQUAL) {
    enet_uint32 a = 1000;
    enet_uint32 b = 2000;
    // Normal cases
    ASSERT_EQ(ENET_TIME_LESS_EQUAL(a, b), true, "ENET_TIME_LESS_EQUAL should return true for a <= b");
    ASSERT_EQ(ENET_TIME_LESS_EQUAL(a, a), true,
                "ENET_TIME_LESS_EQUAL should return true for a <= b (equal)");
    ASSERT_EQ(ENET_TIME_LESS_EQUAL(b, a), false,
                "ENET_TIME_LESS_EQUAL should return false for a <= b (greater)");

    // Cases involving ENET_TIME_OVERFLOW constant
    ASSERT_EQ(ENET_TIME_LESS_EQUAL(a, ENET_TIME_OVERFLOW), true,
                "ENET_TIME_LESS_EQUAL with a < ENET_TIME_OVERFLOW and b == ENET_TIME_OVERFLOW should be true");
    ASSERT_EQ(ENET_TIME_LESS_EQUAL(ENET_TIME_OVERFLOW, a), false,
                "ENET_TIME_LESS_EQUAL with a == ENET_TIME_OVERFLOW and b < ENET_TIME_OVERFLOW should be false");
    ASSERT_EQ(ENET_TIME_LESS_EQUAL(ENET_TIME_OVERFLOW, ENET_TIME_OVERFLOW), true,
                "ENET_TIME_LESS_EQUAL with a == ENET_TIME_OVERFLOW and b == ENET_TIME_OVERFLOW should be true");
}

TEST(ENET_TIME_GREATER_EQUAL) {
    enet_uint32 a = 1000;
    enet_uint32 b = 2000;
    // Normal cases
    ASSERT_EQ(ENET_TIME_GREATER_EQUAL(b, a), true, "ENET_TIME_GREATER_EQUAL should return true for a >= b");
    ASSERT_EQ(ENET_TIME_GREATER_EQUAL(a, a), true, "ENET_TIME_GREATER_EQUAL should return true for a >= b (equal)");
    ASSERT_EQ(ENET_TIME_GREATER_EQUAL(a, b), false, "ENET_TIME_GREATER_EQUAL should return false for a >= b (less)");

    // Cases involving ENET_TIME_OVERFLOW constant (based on ENET_TIME_GREATER logic)
    ASSERT_EQ(ENET_TIME_GREATER_EQUAL(a, ENET_TIME_OVERFLOW), false,
                "ENET_TIME_GREATER_EQUAL with a < ENET_TIME_OVERFLOW and b == ENET_TIME_OVERFLOW should be false");
    ASSERT_EQ(ENET_TIME_GREATER_EQUAL(ENET_TIME_OVERFLOW, a), true,
                "ENET_TIME_GREATER_EQUAL with a == ENET_TIME_OVERFLOW and b < ENET_TIME_OVERFLOW should be true");
    ASSERT_EQ(ENET_TIME_GREATER_EQUAL(ENET_TIME_OVERFLOW, ENET_TIME_OVERFLOW), true,
                "ENET_TIME_GREATER_EQUAL with a == ENET_TIME_OVERFLOW and b == ENET_TIME_OVERFLOW should be true");
}

TEST(ENET_TIME_DIFFERENCE) {
    // Normal cases
    enet_uint32 a = 2000;
    enet_uint32 b = 1000;
    ASSERT_EQ(ENET_TIME_DIFFERENCE(a, b), 1000,
                "ENET_TIME_DIFFERENCE should return the absolute difference for a > b");
    ASSERT_EQ(ENET_TIME_DIFFERENCE(b, a), 1000,
                "ENET_TIME_DIFFERENCE should return the absolute difference for a < b");
    ASSERT_EQ(ENET_TIME_DIFFERENCE(a, a), 0u, "ENET_TIME_DIFFERENCE should return 0 for a == b");

    // Case involving ENET_TIME_OVERFLOW constant as per user's example
    enet_uint32 c = 1000;
    enet_uint32 d = ENET_TIME_OVERFLOW;
    ASSERT_EQ(ENET_TIME_DIFFERENCE(c, d), d - c,
                "ENET_TIME_DIFFERENCE should return the difference involving ENET_TIME_OVERFLOW");
}

TEST(enet_time_get) {
    enet_uint32 firstTime = enet_time_get();
    TEST_SLEEP(100);
    enet_uint32 secondTime = enet_time_get();

    ASSERT_EQ(secondTime >= firstTime, true, "enet_time_get should return increasing time");
    ASSERT_EQ(secondTime - firstTime > 90, true, "Time difference should be at least ~100ms");
}
