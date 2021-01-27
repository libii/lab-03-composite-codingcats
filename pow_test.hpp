#ifndef __POW_TEST_HPP__
#define __POW_TEST_HPP__

#include "base.hpp"

#include "pow.hpp"

TEST(PowTest, NullArgL){
    Base *a = nullptr, *b = new Op(1.0);
    EXPECT_THROW(Pow(a, b), std::invalid_argument);
    delete b;
}

TEST(PowTest, NullArgR){
	Base *a = new Op(1), *b = nullptr;
	EXPECT_THROW(Pow(a, b), std::invalid_argument);
	delete b;
}

TEST(PowTest, NullArgB){
	Base *a = nullptr, *b = nullptr;
	EXPECT_THROW(Pow(a, b), std::invalid_argument);
}

TEST(PowTest, Eval_ONE){
	Base *a = new Op(1), *b = new Op(1), *c = new Pow(a, b);
	EXPECT_EQ(1.0, c->evaluate());
	delete a, b, c;
}

TEST(PowTest, Eval_TWO){
	Base *a = new Op(4), *b = new Op(2), *c = new Pow(a, b);
	EXPECT_EQ(16.0, c->evaluate());
	delete a, b, c;
}

TEST(PowTest, Eval_THREE){
	Base *a = new Op(-1), *b = new Op(4), *c = new Pow(a, b);
	EXPECT_EQ(1.0, c->evaluate());
	delete a, b, c;
}

TEST(PowTest, Eval_FOUR){
	Base *a = new Op(-4), *b = new Op(-2), *c = new Pow(a, b);
	double check = pow(-4, -2);
	EXPECT_EQ(check, c->evaluate());
	delete a, b, c;
}

TEST(PowTest, OperatorEval_ONE){
	Base *a = new Op(5), *b = new Op(4), *c = new Op(2);
	Base *left = new Div(a, b), *test = new Pow(left, c);
	double check = (5/4.0)*(5/4.0);
	EXPECT_EQ(check, test->evaluate());
	delete a, b, c, left, test;
}

TEST(PowTest, OperatorEval_TWO){
	Base *a = new Op(100), *b = new Op(3), *c = new Op(1), *d = new Op(-1);
	Base *left = new Div(a, b), *right = new Mult(c, d), *test = new Pow(left, right);
	double check = (3.0/100);
	EXPECT_EQ(check, test->evaluate());
	delete a, b, c, d, left, right, test;
}

TEST(PowTest, OperatorEval_THREE){
	Base *a = new Op(5), *b = new Op(1), *c = new Op(2);
	Base *right = new Div(b, c), *test = new Pow(a, right);
	double check = pow(5, .5);
	EXPECT_EQ(check, test->evaluate());
	delete a, b, c, right, test;
}

TEST(PowTest, Throw_ONE){
	Base *a = new Op(-1), *b = new Op(.5);
	EXPECT_THROW(Pow(a, b), std::invalid_argument);
	delete a, b;
}

TEST(PowTest, Throw_TWO){
	Base *a = new Op(-5), *b = new Op(-3), *c = new Op(2), *right = new Div(b, c);
	EXPECT_THROW(Pow(a, right), std::invalid_argument);
	delete a, b, right;
}

TEST(PowTest, Throw_THREE){
	Base *a = new Op(-10), *b = new Op(-7.4);
	EXPECT_THROW(Pow(a, b), std::invalid_argument);
	delete a, b;
}

TEST(PowTest, stringify_ONE){
	Base *a = new Op(1), *b = new Pow(a, a);
	EXPECT_EQ("(1.000000**1.000000)", b->stringify());
	delete a, b;
}

TEST(PowTest, stringify_TWO){
	Base *a = new Op(78), *b = new Op(54), *c = new Pow(a, b);
	EXPECT_EQ("(78.000000**54.000000)", c->stringify());
	delete a, b, c;
}

TEST(PowTest, stringify_THREE){
	Base *a = new Op(1), *b = new Mult(a, a), *c = new Pow(b, a);
	EXPECT_EQ("((1.000000*1.000000)**1.000000)", c->stringify());
	delete a, b, c;
}

#endif
