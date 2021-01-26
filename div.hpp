#ifndef __DIV_HPP__
#define __DIV_HPP__

#include "base.hpp"
#include <stdexcept>
#include <limits>
#include <cmath>

class Div : public Base {
    public:
        Div(Base* left, Base* right) : Base() {
            if(left == nullptr || right == nullptr) {throw std::invalid_argument("Null argument passed into Div class.");}
            lChild = left; rChild = right;
            if(fabs(rChild->evaluate()) < std::numeric_limits<double>::epsilon()){
		        throw std::invalid_argument("Divide by zero.");
	        }
        }

        double evaluate() {
            return lChild->evaluate() / rChild->evaluate();
        }

        std::string stringify() {
            return '(' + lChild->stringify() + "/" + rChild->stringify() + ')';
        }
    private:
        Base *lChild, *rChild;
};

#endif
