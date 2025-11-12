// Brief: checkBalanced -- verifies bracket pairing in a string.
// - Uses a custom Stack<pair<char,int>> to track opening brackets and their positions.
// - Skips contents of single-quoted character literals (handles escaped characters).
// - Returns "OK" for balanced input or "ERROR pos=<1-based> reason=<...>" for the first problem.
//
// Key ideas:
//  - Store both the opening bracket and its index so we can report the position of unclosed brackets.
//  - When encountering a single-quoted literal, advance past the entire literal so any brackets inside
//    the literal don't affect balancing logic.
//  - Positions in error messages are 1-based to match typical user-facing indexing.
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
    string s = "()[]{}";
    // string s = "([{}])";
    // string s = "([)]";
    // string s = "(((";
    // string s = "()))";
    // string s = "if(a[0] == '{')";

    cout << checkBalanced(s) << endl;

    return 0;
}

// Notes:
//  - Escaped chars inside single quotes are handled: a backslash skips the next char.
//  - If a single-quote literal is unterminated, the loop will reach end and remaining opens may be reported.
//  - Current code does NOT skip double-quoted strings or block comments; add handling if needed.
//  - Error messages are 1-based positions for user-friendly reporting.