#ifndef __POW_HPP__
#define __POW_HPP__

#include "base.hpp"

class Pow : public Base {
    public:
        Pow(Base* left, Base* right) : Base() {
            //configure below to throw an error when right is negative
            //if(right->evaluate() < 0){throw;}
            lChild = left;
            rChild = right;
        }
        double evaluate() {
            return 0.0;
        }
        std::string stringify() {
            return '(' + lChild->stringify() + "**" + rChild->stringify() + ')';
        }
    private:
        Base *lChild, *rChild;
};

#endif