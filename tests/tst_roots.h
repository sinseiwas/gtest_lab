#ifndef TST_ROOTS_H
#define TST_ROOTS_H

#include <gtest/gtest.h>

#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

extern "C" {
#include "roots.h"
}

double arr[2];

TEST(roots, right_answer) {
    ASSERT_EQ(roots(arr, 1, -5, 6), 1);
    ASSERT_EQ(arr[0], 3);
    ASSERT_EQ(arr[1], 2);
}

TEST(roots, float_input_float_out) {
    ASSERT_EQ(roots(arr, 1, -4, 3.75), 1);
    ASSERT_EQ(arr[0], 2.5);
    ASSERT_EQ(arr[1], 1.5);
}

TEST(roots, one_root) {
    ASSERT_EQ(roots(arr, 1, -6, 9), 1);
    ASSERT_EQ(arr[0], 3);
    ASSERT_EQ(arr[1], 3);
}

TEST(roots, invalid_input) {
    ASSERT_EQ(roots(arr, 0, 0, 0), 0);
}


TEST(roots, no_root) {
    ASSERT_EQ(roots(arr, 1, 2, 3), 0);
}

#endif // TST_ROOTS_H