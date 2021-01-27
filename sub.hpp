#ifndef __SUB_HPP__
#define __SUB_HPP__

#include "base.hpp"

class Sub : public Base {
    private:
        //double value;
        Base* leftChild;
        Base* rightChild;
        

    public:
        Sub(Base* left, Base* right) : Base() {
            leftChild=left;
            rightChild=right;
        }
        double evaluate() { //return 0.0;
                return leftChild->evaluate() - rightChild->evaluate();
        }
        std::string stringify() { //return "*";
                return "("+leftChild->stringify() + "-" + rightChild->stringify()+")";
        }


};

#endif //__SUB_HPP__