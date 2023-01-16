#ifndef CALCLIST_HPP
#define CALCLIST_HPP

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <sstream>
#include "CalcListInterface.hpp"


class DNode { // Doubly linked list node
    private:
        DNode* prev = nullptr;
        DNode* next = nullptr;
        friend class CalcList;

        FUNCTIONS n_operator;
        double n_operand = 0.0;
        double total = 0.0;
 };

class CalcList : public CalcListInterface {
    public:
        CalcList(); // empty list constructor
        ~CalcList(); // destructor
        int num_operations = 0;

        // GIVEN FUNCTIONS
        double total() const;
        void newOperation(const FUNCTIONS func, const double operand); 
        void removeLastOperation();
        std::string toString(unsigned short precision) const;

    protected:
        // LIST FUNCTIONS
        bool empty() const; // is list empty?
        void add(DNode* curr); 
        void remove(DNode* curr);

    private:
        DNode* head;
	    DNode* tail;
};


#endif
