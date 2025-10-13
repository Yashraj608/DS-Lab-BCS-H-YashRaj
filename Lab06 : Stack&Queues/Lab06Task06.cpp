#include <iostream>
#include <stack>
#include <algorithm>
#include <cctype>
#include <cmath>
using namespace std;

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return -1;
}

string infixToPostfix(string infix) {
    stack<char> s;
    string result;
    for (int i = 0; i < infix.size(); i++) {
        char c = infix[i];
        if (isalnum(c)) result += c;
        else if (c == '(') s.push(c);
        else if (c == ')') {
            while (!s.empty() && s.top() != '(') {
                result += s.top();
                s.pop();
            }
            s.pop(); 
        }
        else { 
            while (!s.empty() && precedence(s.top()) >= precedence(c)) {
                if (c == '^' && s.top() == '^') break; 
                result += s.top();
                s.pop();
            }
            s.push(c);
        }
    }
    while (!s.empty()) {
        result += s.top();
        s.pop();
    }
    return result;
}

string infixToPrefix(string infix) {
    reverse(infix.begin(), infix.end());
    for (int i = 0; i < infix.size(); i++) {
        if (infix[i] == '(') infix[i] = ')';
        else if (infix[i] == ')') infix[i] = '(';
    }
    string postfix = infixToPostfix(infix);
    reverse(postfix.begin(), postfix.end());
    return postfix;
}

int evaluatePrefix(string expr) {
    stack<int> s;
    for (int i = expr.size() - 1; i >= 0; i--) {
        char c = expr[i];
        if (isdigit(c)) s.push(c - '0');
        else {
            int a = s.top(); s.pop();
            int b = s.top(); s.pop();
            switch (c) {
                case '+': s.push(a + b); break;
                case '-': s.push(a - b); break;
                case '*': s.push(a * b); break;
                case '/': s.push(a / b); break;
                case '^': s.push(pow(a, b)); break;
            }
        }
    }
    return s.top();
}

int main() {
    string infix;
    cout << "Enter infix expression: ";
    cin >> infix;

    string prefix = infixToPrefix(infix);
    cout << "Prefix expression: " << prefix << endl;
    cout << "Evaluation result: " << evaluatePrefix(prefix) << endl;

    return 0;
}
