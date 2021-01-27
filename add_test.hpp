#ifndef __ADD_TEST_HPP__
#define __ADD_TEST_HPP__

#include "gtest/gtest.h"

#include "op.hpp"
#include "add.hpp"
#include "sub.hpp"
#include "mult.hpp"
#include "div.hpp"

TEST(AddTest, AddEvaluateNonZeroPostive) {
    Op* value1 = new Op(8.0);
    Op* value2 = new Op(10.0);
    Add* test = new Add(value1, value2);
    EXPECT_EQ(18.0, test->evaluate());
}

TEST(AddTest, AddStringifyNonZeroPostive) {
    Op* value1 = new Op(8.0);
    Op* value2 = new Op(10.0);
    Add* test = new Add(value1, value2);
    EXPECT_EQ("(8.000000+10.000000)", test->stringify());
}

TEST(AddTest, AddEvaluateNonZeroNegative) {
    Op* value1 = new Op(-8.0);
    Op* value2 = new Op(-10.0);
    Add* test = new Add(value1, value2);
    EXPECT_EQ(test->evaluate(), -18.0);
}

TEST(AddTest, AddStringNonZeroNegative) {
    Op* value1 = new Op(-8.0);
    Op* value2 = new Op(-10.0);
    Add* test = new Add(value1, value2);
    EXPECT_EQ("(-8.000000+-10.000000)", test->stringify());
}

TEST(AddTest, AddEvaluateZero) {
    Op* value1 = new Op(0.0);
    Op* value2 = new Op(0.0);
    Add* test = new Add(value1, value2);
    EXPECT_EQ(0.0, test->evaluate());
}

TEST(AddTest, AddEvaluateAddingAdd) {
    Op* value1 = new Op(8.0);
    Op* value2 = new Op(10.0);
    Add* result = new Add(value1, value2);
    Add* test = new Add(result, value2);
    EXPECT_EQ(28.0, test->evaluate());
}

TEST(AddTest, AddStringAddingAdd) {
    Op* value1 = new Op(8.0);
    Op* value2 = new Op(10.0);
    Add* result = new Add(value1, value2);
    Add* test = new Add(result, value2);
    EXPECT_EQ("((8.000000+10.000000)+10.000000)", test->stringify());
}

TEST(AddTest, AddEvaluateAddingSubtract) {
    Op* value1 = new Op(18.0);
    Op* value2 = new Op(10.0);
    Op* two = new Op(2.0);
    Sub* result = new Sub(value1, value2);
    Add* test = new Add(result, two);
    EXPECT_EQ(10, test->evaluate());
}

TEST(AddTest, AddEvaluateStringSubtract) {
    Op* value1 = new Op(18.0);
    Op* value2 = new Op(10.0);
    Op* two = new Op(2.0);
    Sub* result = new Sub(value1, value2);
    Add* test = new Add(result, two);
    EXPECT_EQ("((18.000000-10.000000)+2.000000)", test->stringify());
}

TEST(AddTest, AddEvaluateAddingMultiply) {
    Op* two = new Op(2.0);
    Op* three = new Op(3.0);
    Op* six = new Op(6.0);
    Mult* result = new Mult(two, three);
    Add* test = new Add(result, six);
    EXPECT_EQ(12.0, test->evaluate());
}

TEST(AddTest, AddStringAddingMultiply) {
    Op* two = new Op(2.0);
    Op* three = new Op(3.0);
    Op* six = new Op(6.0);
    Mult* result = new Mult(two, three);
    Add* test = new Add(result, six);
    EXPECT_EQ("((2.000000*3.000000)+6.000000)", test->stringify());
}

TEST(AddTest, AddEvaluateAddingDivide) {
    Op* eight = new Op(8.0);
    Op* two = new Op(2.0);
    Div* division = new Div(eight, two);
    Op* ten = new Op(10.0);
    Add* test = new Add(division, ten);
    EXPECT_EQ(14.0, test->evaluate());
}

TEST(AddTest, AddStringAddingDivide) {
    Op* eight = new Op(8.0);
    Op* two = new Op(2.0);
    Div* division = new Div(eight, two);
    Op* ten = new Op(10.0);
    Add* test = new Add(division, ten);
    EXPECT_EQ("((8.000000/2.000000)+10.000000)", test->stringify());
}

#endif //__ADD_TEST_HPP__