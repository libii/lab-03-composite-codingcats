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
  Op a(7854.0), b(2.0);
  Mult c(&a, &b);
  EXPECT_EQ(15708.0, c.evaluate());
}

#endif