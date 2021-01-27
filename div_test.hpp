#ifndef __DIV_TEST_HPP__
#define __DIV_TEST_HPP__

#include "gtest/gtest.h"

#include "div.hpp"
#include "pow.hpp"

TEST(DivTest, Throw_DivideByZero1){
	Base *a = new Op(1.0), *b = new Op(0.0);
	EXPECT_THROW(Div(a, b), std::invalid_argument);
	delete a, b;
}

TEST(DivTest, Throw_DivideByZero2){
	Base *a = new Op(15.75), *b = new Op(0.0);
	EXPECT_THROW(Div(a, b), std::invalid_argument);
	delete a, b;
}

TEST(DivTest, Throw_DivideByZero3){
	Base *a = new Op(1.0), *b = new Op(0.000);
	EXPECT_THROW(Div(a,b), std::invalid_argument);
	delete a, b;
}

TEST(DivTest, Throw_NullArgL){
	Base *a = nullptr, *b = new Op(1.0);
	EXPECT_THROW(Div(a,b), std::invalid_argument);
	delete b;
}

TEST(DivTest, Throw_NullArgR){
	Base *a = new Op(1.0), *b = nullptr;
	EXPECT_THROW(Div(a,b), std::invalid_argument);
	delete a;
}

TEST(DivTest, Throw_NullArgB){
	Base *a = nullptr, *b = nullptr;
	EXPECT_THROW(Div(a,b), std::invalid_argument);
}

TEST(DivTest, OneEvaluate){
  Base *a = new Op(1);
  Base *b = new Op(1);
  Base *c = new Div(a, b);
  EXPECT_EQ(1.0, c->evaluate());
  delete a, b, c;
}

TEST(DivTest, TenEvaluate){
	Base *a = new Op(10), *b = new Op(1), *c = new Div(a, b);
	EXPECT_EQ(10.0, c->evaluate());
	delete a, b, c;
}

TEST(DivTest, FiftyAndThreeEval){
	Base *a = new Op(50), *b = new Op(3), *c = new Div(a, b);
	double check = 50/3.0;
	EXPECT_EQ(check, c->evaluate());
	delete a, b, c;
}

TEST(DivTest, OneHalfEval){
	Base *a = new Op(1), *b = new Op(2), *c = new Div(a, b);
	double check = 1/2.0;
	EXPECT_EQ(check, c->evaluate());
	delete a, b, c;
}

TEST(DivTest, NegativeEval){
	Base *a = new Op(1), *b = new Op(-1), *c = new Div(a, b);
	double check = 1/-1.0;
	EXPECT_EQ(check, c->evaluate());
	delete a, b, c;
}

TEST(DivTest, OperatorEval_ONE){
	Base *a = new Op(25), *b = new Op(5), *c = new Op(1), *d = new Mult(b, c), *e = new Div(a, d);
	double check = 25/5.0;
	EXPECT_EQ(check, e->evaluate());
	delete a, b, c, d, e;
}

TEST(DivTest, OperatorEval_TWO){
	Base *a = new Op(390), *b = new Op(5), *c = new Op(18), *d = new Op(3);
	Base *left = new Div(a, b), *right = new Mult(c, d), *test = new Div(left, right);
	double check = (390/5.0)/(18*3.0);
	EXPECT_EQ(check, test->evaluate());
	delete a, b, c, d, left, right, test;
}

TEST(DivTest, OperatorEval_THREE){
	Base *a = new Op(4), *b = new Op(2), *c = new Op(5);
	Base *left = new Pow(a, b), *test = new Div(left, c);
	double check = (4*4)/5.0;
	EXPECT_EQ(check, test->evaluate());
	delete a, b, c, left, test;
}

TEST(DivTest, stringify_ONE){
	Base *a = new Op(1), *b = new Op(1), *c = new Div(a, b);
	EXPECT_EQ("(1.000000/1.000000)", c->stringify());
	delete a, b, c;
}

TEST(DivTest, stringify_TWO){
	Base *a = new Op(78), *b = new Op(54), *c = new Div(a, b);
	EXPECT_EQ("(78.000000/54.000000)", c->stringify());
	delete a, b, c;
}

TEST(DivTest, stringify_THREE){
	Base *a = new Op(78), *b = new Op(54), *c = new Op(1);
	Base *left = new Mult(a, b), *test = new Div(left, c);
	EXPECT_EQ("((78.000000*54.000000)/1.000000)", test->stringify());
	delete a, b, c, left, test;
}

#endif
