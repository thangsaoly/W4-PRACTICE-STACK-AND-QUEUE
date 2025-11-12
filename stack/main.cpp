#include <iostream>
#include <string>
#include <utility>
#include "stack.hpp"

using namespace std;

string checkBalanced(const string &s)
{
    Stack<pair<char, int>> st; // stack of (opening-bracket, index)

    for (int i = 0; i < (int)s.length(); ++i)
    {
        char ch = s[i];

        // If we hit a single-quoted literal, skip everything until the closing quote.
        // This prevents characters like '{' inside literals from being interpreted as code.
        if (ch == '\'')
        {
            ++i; // move past opening quote
            while (i < (int)s.length())
            {
                if (s[i] == '\\')
                { // escaped char inside literal: skip it and the next char
                    ++i;
                    if (i < (int)s.length())
                        ++i;
                    continue; // continue scanning inside the literal
                }
                if (s[i] == '\'')
                    break; // found closing quote of the literal
                ++i;
            }
            continue; // continue main loop after the literal is skipped
        }

        // If an opening bracket, push it with its index.
        if (ch == '(' || ch == '{' || ch == '[')
        {
            st.push({ch, i});
        }
        // If a closing bracket, check matching with top of stack.
        else if (ch == ')' || ch == '}' || ch == ']')
        {
            if (st.empty())
            {
                // No opening bracket for this closing one.
                return "ERROR pos=" + to_string(i + 1) + " reason=extra-closing";
            }
            auto top = st.peek();  // get the top pair<char,int> without removing
            char open = top.first; // the opening bracket char
            int pos = top.second;  // its index (0-based)
            st.pop();              // remove the matched opening
            // If types don't match, it's a mismatch error at this closing bracket.
            if ((ch == ')' && open != '(') ||
                (ch == '}' && open != '{') ||
                (ch == ']' && open != '['))
            {
                return "ERROR pos=" + to_string(i + 1) + " reason=mismatch";
            }
        }
    }

    // After scanning: any remaining opening bracket is unclosed.
    if (!st.empty())
    {
        auto top = st.peek();
        // Report position as 1-based index of the unmatched opening bracket.
        return "ERROR pos=" + to_string(top.second + 1) + " reason=unclosed";
    }
    return "OK";
}

int main()
{
    // string s = "()[]{}";
    // string s = "([{}])";
    // string s = "([)]";
    // string s = "(((";
    // string s = "()))";
    string s = "if(a[0] == '{')";

    cout << checkBalanced(s) << endl;

    return 0;
}