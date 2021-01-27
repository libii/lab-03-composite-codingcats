#ifndef __MULT_TEST_HPP__
#define __MULT_TEST_HPP__

#include "gtest/gtest.h"

#include "mult.hpp"

TEST(MultTest, NullArgL){
  Base *a = nullptr, *b = new Op(1.0);
  EXPECT_THROW(Mult(a, b), std::invalid_argument);
  delete b;
}

TEST(MultTest, NullArgR){
  Base *a = new Op(1), *b = nullptr;
  EXPECT_THROW(Mult(a, b), std::invalid_argument);
  delete a;
}

TEST(MultTest, NullArgB){
  Base *a = nullptr, *b = nullptr;
  EXPECT_THROW(Mult(a, b), std::invalid_argument);
}

TEST(MultTest, Evaluate_ONE){
  Base* a = new Op(1.0);
  Base* b = new Op(1.0);
  Base* c = new Mult(a, b);
  EXPECT_EQ(1.0, c->evaluate());
  delete a, b, c;
}

TEST(MultTest, Evaluate_TWO){
  Base* a = new Op(1.0);
  Base* b = new Op(0.0);
  Base* c = new Mult(a, b);
  EXPECT_EQ(0.0, c->evaluate());
  delete a, b, c;
}

TEST(MultTest, Evaluate_THREE){
  Base *a = new Op(7854.0);
  Base *b = new Op(2.0);
  Base *c = new Mult(a, b);
  EXPECT_EQ(15708.0, c->evaluate());
  delete a, b, c;
}

TEST(MultTest, Evaluate_FOUR){
  Base *a = new Op(1.5), *b = new Op(7.83), *c = new Mult(a, b);
  double check = 1.5*7.83;
  EXPECT_EQ(check, c->evaluate());
  delete a, b, c;
}

TEST(MultTest, Stringify_ONE){
  Base *a = new Op(1.0);
  Base *b = new Op(1.0);
  Base *c = new Mult(a, b);
  EXPECT_EQ("(1.000000*1.000000)", c->stringify());
  delete a, b, c;
}

TEST(MultTest, Stringify_TWO){
  Base *a = new Op(78), *b = new Op(54), *c = new Mult(a, b);
  EXPECT_EQ("(78.000000*54.000000)", c->stringify());
  delete a, b, c;
}

TEST(MultTest, Stringify_THREE){
  Base *a = new Op(1.5), *b = new Op(7.854), *c = new Mult(a, b);
  EXPECT_EQ("(1.500000*7.854000)", c->stringify());
  delete a, b, c;
}

#endif
