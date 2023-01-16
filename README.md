# Linked-List-Calculator
This is a doubly linked list calculator that is able to do commands such as:
- Addition
- Subtraction
- Multiplication
- Division

The calculator also keeps a running total of the operations completed, the number of operations completed,
and what those operations were. The calculator also has an "undo" function for removing the last operation.
The calculator outputs a string of the operations completed so far with fixed precision.

CalcList calc;                        // Total == 0
calc.newOperation(ADDITION, 10);      // Total == 10
calc.newOperation(MULTIPLICATION, 5); // Total == 50
calc.newOperation(SUBTRACTION, 15); // Total == 35
calc.newOperation(DIVISION, 7); // Total == 5
calc.removeLastOperation(); // Total == 10
calc.newOperation(SUBTRACTION, 30); // Total == 5
calc.newOperation(ADDITION, 5); // Total == 10
calc.removeLastOperation(); // Total == 5

std::cout << calc.toString(2);
// Returns:
// 4: 35.00-30.00=5.00
// 3: 50.00-15.00=35.00
// 2: 10.00*5.00=50.00
// 1: 0.00+10.00=10.00

calc.removeLastOperation(); // Total == 35
std::cout << calc.toString(0);

// Returns:
// 3: 50-15=35
// 2: 10*5=50
// 1: 0+10=10
