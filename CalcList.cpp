
// Ali Aslanbayli, Chloe Berry
#include "CalcList.hpp"

// CONSTRUCTOR
CalcList::CalcList() { 
	head = new DNode;
	tail = new DNode;   
    head->next = tail;
    tail->prev = head;
}

// DESTRUCTOR
CalcList::~CalcList() {
	while (!empty()) {
        remove(head->next);
    }
    delete head;
    delete tail;
}

// Check if the list is empty
bool CalcList::empty() const {
    return (head->next == tail);
}

// ADD A NEW NODE
// helper function used by the required functions for assignment
void CalcList::add(DNode* curr){
	++num_operations;
	DNode* new_node = new DNode;
	new_node->total = curr->prev->total; // storing previous total, we will update
	
	// inserting new node before the current node
	new_node->next = curr;
	new_node->prev = curr->prev; 
	curr->prev->next = new_node; 
	curr->prev = new_node;
}

// REMOVE A NODE
// helper function used by the required functions for assignment
// removes a node v
void CalcList::remove(DNode* curr){
    if (empty()) { throw ("The list is empty, can't remove a node."); }
    else {
	    --num_operations;
        DNode* prev_node = curr->prev;
        DNode* next_node = curr->next;
        prev_node->next = next_node;
        next_node->prev = prev_node;
        delete curr;
    }
}

// RETURN CURRENT TOTAL AMOUNT
double CalcList::total() const{
    return tail->prev->total;
}

// CREATE NEW NODE TO STORE NEW OPERATIONS AND INFO
void CalcList::newOperation(const FUNCTIONS n_operator,  const double operand){
	add(tail); // add a new node before tail
    DNode* new_node = tail->prev;

	switch (n_operator) {
  	case ADDITION:
		new_node->n_operator = ADDITION;
		new_node->n_operand = operand;
		new_node->total += operand;
		break;
		
	case SUBTRACTION:
		new_node->n_operator = SUBTRACTION;
		new_node->n_operand = operand;
		new_node->total -= operand;
		break;
		
	case MULTIPLICATION:
		new_node->n_operator = MULTIPLICATION;
		new_node->n_operand = operand;
		new_node->total *= operand;
		break;
		
	case DIVISION: 
		if (operand == 0) { 
            removeLastOperation(); 
            throw("You can't divide by zero."); 
        } 
		else {
			new_node->n_operator = DIVISION;
			new_node->n_operand = operand;
			new_node->total /= operand;
			break; 
		}
	default:
		throw ("Bad arithmetic operation. Use Addition, Substraction, Multiplication, or Divison.");
		break;
	}
}

// REMOVE PREVIOUS NODE
void CalcList::removeLastOperation() {
    remove(tail->prev);
}

// PRINT ALL OF THE OPERATIONS
std::string CalcList::toString(unsigned short precision) const {
    std::stringstream ss; // take the data stream
	std::string data_to_string = ""; // Blank variables that holds the past operations
	DNode* temp_ptr = tail; 
	int temp_steps = num_operations;

	ss.precision(precision); // set the precision
	while (temp_ptr->prev != head) { // Simple load until header != [trailer]
		ss << temp_steps << ": ";

		ss << std::fixed << temp_ptr->prev->prev->total;

		if (temp_ptr->prev->n_operator == ADDITION) {
			ss << "+";
		}
		else if (temp_ptr->prev->n_operator == SUBTRACTION) {
			ss << "-";
		}
		else if (temp_ptr->prev->n_operator == MULTIPLICATION) {
			ss << "*";
		}
		else if (temp_ptr->prev->n_operator == DIVISION) {
			ss << "/";
		}
		ss << temp_ptr->prev->n_operand;
		ss << "=";
		ss << temp_ptr->prev->total;
		ss << std::endl;

		temp_ptr = temp_ptr->prev;
		--temp_steps; 
	}
	data_to_string = ss.str(); // Now whole ss will be converted and set equal to the data member
	return data_to_string;
}
