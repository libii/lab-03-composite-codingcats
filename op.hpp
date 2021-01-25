#ifndef __OP_HPP__
#define __OP_HPP__

#include "base.hpp"
#include <string>

class Op : public Base {
    private:
        double myValue=0;
        Base* leftChild=NULL;
        Base* rightChild=NULL;

    public:
        Op(double value) : Base() { 
            myValue = value;
        }
        virtual double evaluate() { return myValue; }
        virtual std::string stringify() { 
            return std::to_string(myValue); }
        
        double getValue(){
            return myValue;
        }

        void setValue(double v){
            myValue=v;
        }


};

#endif //__OP_HPP__
