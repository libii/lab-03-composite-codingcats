#ifndef __MULT_HPP__
#define __MULT_HPP__

#include "base.hpp"

class Mult : public Base {
    public:
        Mult(Base* left, Base* right) : Base() {
            if(left == nullptr || right == nullptr){throw std::invalid_argument("Null argument passed into Mult class.");}
            lChild = left; rChild = right;
        }
        double evaluate() {
           return lChild->evaluate() * rChild->evaluate();
        }
        std::string stringify() {
            return '(' + lChild->stringify() + "*" + rChild->stringify() + ')';
        }
        
    private:
        Base *lChild, *rChild;
};

#endif