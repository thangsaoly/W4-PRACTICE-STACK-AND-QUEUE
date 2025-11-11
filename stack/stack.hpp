#include <iostream>
using namespace std;

template <typename T>

class Stack {
    private:
        T  *arr = new T[10];
        int top = -1;

    public:

        void push(T value){
            //overflow guard
            if(top == 9){
                cout<<"Stack Overflow"<<endl;
                return;
            }
            arr[++top] = value;
        }

        T pop(){
            T temp;
            //underflow guard
            if(top == -1){
                cout<<"Stack Underflow"<<endl;
                return temp;
            }
            return arr[top--];
            return temp;
        }

        T peek(){
            T temp;
            if(top == -1){
                cout<<"Stack Underflow"<<endl;
                return temp;
            }
            T val = arr[top];
            return arr[top];
            return temp;
        }

        bool empty(){
            return top == -1;
        }
};