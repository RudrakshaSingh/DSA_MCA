#include <iostream>
#include <cctype>
#include <math.h>
using namespace std;

char stack[100];  // char stack for infix-to-postfix conversion
int top = -1;

void push(char data) {
    if (top < 99) {
        top++;
        stack[top] = data;
    } else {
        cout << "Stack Overflow" << endl;
    }
}

char pop() {
    if (top >= 0) {
        char popped = stack[top];
        top--;
        return popped;
    } else {
        cout << "Stack Underflow" << endl;
        return '\0'; // Error case
    }
}

char peek() {
    if (top >= 0) {
        return stack[top];
    } else {
        return '\0'; // Error case
    }
}

// Check precedence
int precedence(char c) {
    if (c == '^') {
        return 3;
    } else if (c == '/' || c == '*') {
        return 2;
    } else if (c == '+' || c == '-') {
        return 1;
    } else {
        return -1;
    }
}

string infixToPostFix(string s) {
    string result;
    for (int i = 0; i < s.length(); i++) {
        // If it's not an alphanumeric character and not a valid operator or parentheses
        if (!((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9') || s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '^' || s[i] == '(' || s[i] == ')')) {
            cout << "Operator and Operand is not valid" << endl;
            return "";
        }
        // If it's an operand (letter or digit)
        if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')) {
            result += s[i];
        }
        // If it's a left parenthesis
        else if (s[i] == '(') {
            push(s[i]);
        }
        // If it's a right parenthesis, pop until the left parenthesis is found
        else if (s[i] == ')') {
            while (top != -1 && peek() != '(') {
                result += pop();
            }
            if (top != -1) {
                pop();  // Pop '('
            }
        }
        // If it's an operator
        else {
            while (top != -1 && precedence(peek()) >= precedence(s[i])) {
                result += pop();
            }
            push(s[i]);
        }
    }
    // Pop all the remaining operators from the stack
    while (top != -1) {
        result += pop();
    }
    return result;
}

int evaluatePostfixExpression(string s) {
    int evalStack[100]; // Integer stack for evaluation
    int evalTop = -1;
    
    for (int i = 0; i < s.length(); i++) {
        // If it's a character, we can't evaluate it
        if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z')) {
            cout << "Evaluation cannot be done on characters." << endl;
            return -1;
        }
        
        // If it's a number, push it onto the evaluation stack
        if (s[i] >= '0' && s[i] <= '9') {
            evalTop++;
            evalStack[evalTop] = s[i] - '0';  // Convert char to int
        }
        // If it's an operator, pop two values and perform the operation
        else {
            int op2 = evalStack[evalTop--];  // Second operand
            int op1 = evalStack[evalTop--];  // First operand
            int result;
            switch (s[i]) {
                case '+': result = op1 + op2; break;
                case '-': result = op1 - op2; break;
                case '*': result = op1 * op2; break;
                case '/': result = op1 / op2; break;
                case '^': result = pow(op1, op2); break;
                default: cout << "Invalid operator." << endl; return -1;
            }
            evalTop++;
            evalStack[evalTop] = result;  // Push result to eval stack
        }
    }
    return evalStack[evalTop];  // Final result
}

int main() {
    string infixExpression;
    // Infix expression input
    cout << "Enter an infix expression: ";
    cin >> infixExpression;
    // Conversion to postfix
    string postfixExpression = infixToPostFix(infixExpression);
    if (!postfixExpression.empty()) {
        cout << "Postfix expression: " << postfixExpression << endl;
        // Evaluate the postfix expression
        int result = evaluatePostfixExpression(postfixExpression);
        if (result != -1) {
            cout << "Evaluation result: " << result << endl;
        }
    }
    return 0;
}