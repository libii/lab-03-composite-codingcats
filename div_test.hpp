#ifndef __DIV_TEST_HPP__
#define __DIV_TEST_HPP__

#include "gtest/gtest.h"

#include "div.hpp"

TEST(DivTest, Throw_DivideByZero){
	Base *a = new Op(1.0);
	Base *b = new Op(0.0);
	EXPECT_THROW(Div(a, b), std::invalid_argument);
}

TEST(DivTest, Throw_DivieByZero2){
	Base *a = new Op(15.75);
	Base *b = new Op(0.0);
	EXPECT_THROW(Div(a, b), std::invalid_argument);
}

TEST(DivTest, OneEvaluate){
  Base *a = new Op(1);
  Base *b = new Op(1);
  Base *c = new Div(a, b);
  EXPECT_EQ(1.0, c->evaluate());
}

#endif
