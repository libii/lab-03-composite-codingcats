#ifndef __DIV_TEST_HPP__
#define __DIV_TEST_HPP__

#include "gtest/gtest.h"

#include "div.hpp"

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

TEST(DivTest, TenEvaulate){
	Base *a = new Op(10), *b = new Op(1), *c = new Div(a, b);
	EXPECT_EQ(10.0, c->evaluate());
	delete a, b, c;
}

TEST(DivTest, FiftyAndThreeEvaul){
	Base *a = new Op(50), *b = new Op(3), *c = new Div(a, b);
	EXPECT_EQ(16.6667, c->evaluate());
	delete a, b, c;
}

#endif
