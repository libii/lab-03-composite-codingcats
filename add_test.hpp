#ifndef __ADD_TEST_HPP__
#define __ADD_TEST_HPP__

#include "gtest/gtest.h"

#include "op.hpp"
#include "add.hpp"

TEST(AddTest, AddEvaluateNonZero) {
    Op* value1 = new Op(8.0);
    Op* value2 = new Op(10.0);
    Add* test = new Add(value1, value2);
    EXPECT_EQ(test->evaluate(), 18.0);
}

TEST(AddTest, AddEvaluateZero) {
    Op* value1 = new Op(0.0);
    Op* value2 = new Op(0.0);
    Add* test = new Add(value1, value2);
    EXPECT_EQ(test->evaluate(), 0.0);
}

#endif //__ADD_TEST_HPP__