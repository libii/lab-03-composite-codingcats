#ifndef __RAND_HPP__
#define __RAND_HPP__

#include "base.hpp"
#include <stdlib.h>


class Rand : public Base {
    private:
        double myValue=0;
        Base* leftChild=NULL;
        Base* rightChild=NULL;

    public:
        Rand() : Base() { 
            double myValue = rand() % 100;
        }

        virtual double evaluate() { return myValue; }
        virtual std::string stringify() { return std::to_string(myValue); }
        
        double getValue(){
            return myValue;
        }

};

#endif //__RAND_HPP__