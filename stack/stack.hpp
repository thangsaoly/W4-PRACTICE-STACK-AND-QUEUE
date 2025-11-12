// Brief: Simple templated Stack implementation.
// - Template parameter T: element type stored in the stack.
// - Internally uses a dynamic array; top index tracks the current top element.
// - Provides push, pop, peek (inspect top), and empty.
// Notes:
//  - pop() and peek() print an error and return default T on underflow; callers must check empty() first.
//  - Fixed initial buffer (10); no automatic growth and no destructor/copy-safety in this example.
//  - Suitable for small teaching examples; replace with a robust implementation for production.
#include <iostream>
using namespace std;

template <typename T>

class Stack
{
private:
    T *arr = new T[10]; // fixed-size buffer (example). Stores stack elements.
    int top = -1;       // index of the top element (-1 means empty)

public:
    void push(T value)
    {
        // overflow guard: simple check for fixed buffer size
        if (top == 9)
        {
            cout << "Stack Overflow" << endl;
            return;
        }
        arr[++top] = value; // increment top then store value
    }

    T pop()
    {
        T temp;
        // underflow guard: no elements to pop
        if (top == -1)
        {
            cout << "Stack Underflow" << endl;
            return temp; // return default-constructed T
        }
        return arr[top--]; // return top element then decrement top
        return temp;       // unreachable but harmless (keeps previous structure)
    }

    T peek()
    {
        T temp;
        if (top == -1)
        {
            cout << "Stack Underflow" << endl;
            return temp; // return default-constructed T if empty
        }
        T val = arr[top]; // read top value
        return arr[top];  // return top element (do not modify top)
        return temp;      // unreachable (left from original code)
    }

    bool empty()
    {
        return top == -1; // true when no elements are present
    }
};