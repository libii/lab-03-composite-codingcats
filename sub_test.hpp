#ifndef __SUB_TEST_HPP__
#define __SUB_TEST_HPP__

#include "gtest/gtest.h"

#include "op.hpp"
#include "sub.hpp"
#include "add.hpp"
#include "mult.hpp"
#include "div.hpp"

TEST(SubTest, SubEvaluateNonZero) {
    Op* value1 = new Op(18.0);
    Op* value2 = new Op(10.0);
    Sub* test = new Sub(value1, value2);
    EXPECT_EQ(8.0, test->evaluate());
}

TEST(SubTest, SubStringNonZero) {
    Op* value1 = new Op(18.0);
    Op* value2 = new Op(10.0);
    Sub* test = new Sub(value1, value2);
    EXPECT_EQ("(18.000000-10.000000)", test->stringify());
}

TEST(SubTest, SubStringNegative) {
    Op* value1 = new Op(-10.0);
    Op* value2 = new Op(-18.0);
    Sub* test = new Sub(value1, value2);
    EXPECT_EQ("(-10.000000--18.000000)", test->stringify());
}

TEST(SubTest, SubEvaluateZero) {
    Op* value1 = new Op(10.0);
    Op* value2 = new Op(10.0);
    Sub* test = new Sub(value1, value2);
    EXPECT_EQ(test->evaluate(), 0.0);
}

TEST(SubTest, SubEvaluateComplex) {
    Op* ten = new Op(10.0);
    Op* two = new Op(2.0);
    Op* eight = new Op(8.0);
    Op* negFour = new Op(-4);
    Add* value1 = new Add(two, ten);
    Mult* value2 = new Mult(value1, two);
    Div* value3 = new Div(value2, negFour);
    Sub* test = new Sub(value2, value3);
    EXPECT_EQ(test->evaluate(), 30);
}

TEST(SubTest, SubStringComplex) {
    Op* ten = new Op(10.0);
    Op* two = new Op(2.0);
    Op* eight = new Op(8.0);
    Op* negFour = new Op(-4);
    Add* value1 = new Add(two, ten);
    Mult* value2 = new Mult(value1, two);
    Div* value3 = new Div(value2, negFour);
    Sub* test = new Sub(value2, value3);
    EXPECT_EQ(test->stringify(), "(((2.000000+10.000000)*2.000000)-(((2.000000+10.000000)*2.000000)/-4.000000))");
}

#endif //__SUB_TEST_HPP__