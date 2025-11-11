#include <iostream>
#include <string>
#include "stack.hpp"

using namespace std;

bool isBalanced(const string& s) {
    Stack<char> st;
    for (char ch : s) {
        if (ch == '(' || ch == '{' || ch == '[') {
            st.push(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (st.empty()) return false;
            char top = st.peek();
            st.pop();
            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) {
                return false;
            }
        }
    }
    return st.empty();
}

int main() {
    string s = "()[]{}";

    cout << (isBalanced(s) ? "OK" : "Not Balanced") << endl;  
    
    return 0;
}

