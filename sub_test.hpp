#ifndef __SUB_TEST_HPP__
#define __SUB_TEST_HPP__

#include "gtest/gtest.h"

#include "op.hpp"
#include "sub.hpp"

TEST(SubTest, SubEvaluateNonZero) {
    Op* value1 = new Op(18.0);
    Op* value2 = new Op(10.0);
    Sub* test = new Sub(value1, value2);
    EXPECT_EQ(test->evaluate(), 8.0);
}

TEST(SubTest, SubEvaluateNegative) {
    Op* value1 = new Op(18.0);
    Op* value2 = new Op(10.0);
    Sub* test = new Sub(value1, value2);
    EXPECT_EQ(test->evaluate(), 8.0);
}

TEST(SubTest, SubEvaluateZero) {
    Op* value1 = new Op(10.0);
    Op* value2 = new Op(10.0);
    Sub* test = new Sub(value1, value2);
    EXPECT_EQ(test->evaluate(), 0.0);
}

#endif //__SUB_TEST_HPP__