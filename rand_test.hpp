#ifndef __RAN_TEST_HPP__
#define __RAN_TEST_HPP__

#include "gtest/gtest.h"

#include "rand.hpp"

TEST(RandTest, RandValueEqualsString) {
    Rand* test = new Rand();
    EXPECT_EQ(std::to_string(test->evaluate()), test->stringify());
}

#endif //__RAN_TEST_HPP__
