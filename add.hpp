#ifndef __ADD_HPP__
#define __ADD_HPP__

#include "base.hpp"

class Add : public Base {
    private:
        //double value;
        Base* leftChild;
        Base* rightChild;
        
    public:
        Add(Base* left, Base* right) : Base() {
            leftChild=left;
            rightChild=right;
        }
        double evaluate() { 
            return leftChild->evaluate() + rightChild->evaluate();
        }
        std::string stringify() { //return "*";
            return "(" + leftChild->stringify() + "+" + rightChild->stringify() + ")";
        }

};

#endif //__ADD_HPP__