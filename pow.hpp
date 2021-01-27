#ifndef __POW_HPP__
#define __POW_HPP__

#include "base.hpp"
#include <stdexcept>
#include <limits>
#include <cmath>

class Pow : public Base {
    public:
        Pow(Base* left, Base* right) : Base() {
            //configure below to throw an error when right is negative
            if(left==nullptr || right == nullptr){throw std::invalid_argument("Null argument passed into Pow class.");}
            //checks is left is negative and is right is a negative fraction. if true, returns error as this is causes an imaginary number.
            if(left->evaluate() < 0 && !( right->evaluate() == floor(right->evaluate()) ) ){throw std::invalid_argument("Undefined. Imaginary number.");}
            lChild = left;
            rChild = right;
        }
        double evaluate() {
            return pow(lChild->evaluate(), rChild->evaluate());
        }
        std::string stringify() {
            return '(' + lChild->stringify() + "**" + rChild->stringify() + ')';
        }
    private:
        Base *lChild, *rChild;
};

#endif
