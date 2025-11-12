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