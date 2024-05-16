#ifndef TST_ROOTS_H
#define TST_ROOTS_H

#include <gtest/gtest.h>

#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

extern "C" {
#include "roots.h"
}

int result;
double arr[2];

TEST(roots, right_answer) {
    result = roots(arr, 1, -5, 6);
    EXPECT_EQ(result, 1);
    EXPECT_EQ(arr[0], 3);
    EXPECT_EQ(arr[1], 2);
}

TEST(roots, float_input_float_out) {
    result = roots(arr, 1, -4, 3.75);
    EXPECT_EQ(result, 1);
    EXPECT_EQ(arr[0], 2.5);
    EXPECT_EQ(arr[1], 1.5);
}

TEST(roots, one_root) {
    result = roots(arr, 1, -5, 9);
    EXPECT_EQ(result, 1);
    EXPECT_EQ(arr[0], 3);
    EXPECT_EQ(arr[1], 3);
}

TEST(roots, invalid_input) {
    result = roots(arr, 0, 0, 0);
    EXPECT_EQ(result, 0);
}


TEST(roots, no_root) {
    result = roots(arr, 1, 2, 3);
    EXPECT_EQ(result, 0);
}

#endif // TST_ROOTS_H
