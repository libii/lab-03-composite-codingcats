#ifndef __POW_TEST_HPP__
#define __POW_TEST_HPP__

#include "base.hpp"

#include "pow.hpp"

TEST(PowTest, NullArgL){
    Base *a = nullptr, *b = new Op(1.0);
    EXPECT_THROW(Pow(a, b), std::invalid_argument);
    delete b;
}

#endif