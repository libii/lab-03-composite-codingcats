#ifndef __MULT_TEST_HPP__
#define __MULT_TEST_HPP__

#include "gtest/gtest.h"

#include "mult.hpp"

TEST(MultTest, Evaluate1){
  Base* a = new Op(1.0);
  Base* b = new Op(1.0);
  Base* c = new Mult(a, b);
  EXPECT_EQ(1.0, c->evaluate());
}

TEST(MultTest, Evaluate0){
  Base* a = new Op(1.0);
  Base* b = new Op(0.0);
  Base* c = new Mult(a, b);
  EXPECT_EQ(0.0, c->evaluate());
}

TEST(MultTest, EvaluateLARGE){
  Base *a = new Op(7854.0);
  Base *b = new Op(2.0);
  Base *c = new Mult(a, b);
  EXPECT_EQ(15708.0, c->evaluate());
}

TEST(MultTest, Stringify1){
  Base *a = new Op(1.0);
  Base *b = new Op(1.0);
  Base *c = new Mult(a, b);
  EXPECT_EQ("(1.000000*1.000000)", c->stringify());
}

#endif
