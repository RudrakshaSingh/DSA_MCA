#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <cctype>
#include <vector>

using namespace std;

// Function to check if a character is an operator
bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

// Function to get the precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3; // Higher precedence for exponentiation
    return 0;
}

// Function to check if the operator is left associative
bool isLeftAssociative(char op) {
    return op != '^'; // ^ is right associative
}

// Function to convert infix to postfix
string infixToPostfix(const string &infix) {
    stack<char> operators;
    string postfix;
    istringstream iss(infix);
    string token;

    while (iss >> token) {
        if (isdigit(token[0])) { // Operand (number)
            postfix += token + " ";
        } else if (token[0] == '(') {
            operators.push('(');
        } else if (token[0] == ')') {
            while (!operators.empty() && operators.top() != '(') {
                postfix += operators.top();
                postfix += " ";
                operators.pop();
            }
            operators.pop(); // Pop the '('
        } else if (isOperator(token[0])) {
            while (!operators.empty() && 
                   (precedence(operators.top()) > precedence(token[0]) || 
                   (precedence(operators.top()) == precedence(token[0]) && isLeftAssociative(token[0])))) {
                postfix += operators.top();
                postfix += " ";
                operators.pop();
            }
            operators.push(token[0]);
        }
    }

    // Pop all the operators left in the stack
    while (!operators.empty()) {
        postfix += operators.top();
        postfix += " ";
        operators.pop();
    }

    return postfix;
}

// Function to evaluate a postfix expression
int evaluatePostfix(const string &postfix) {
    stack<int> values;
    istringstream iss(postfix);
    string token;

    while (iss >> token) {
        if (isdigit(token[0])) {
            values.push(stoi(token)); // Convert string to int
        } else if (isOperator(token[0])) {
            int b = values.top(); values.pop();
            int a = values.top(); values.pop();
            switch (token[0]) {
                case '+': values.push(a + b); break;
                case '-': values.push(a - b); break;
                case '*': values.push(a * b); break;
                case '/': values.push(a / b); break;
                case '^': {
                    int result = 1;
                    for (int i = 0; i < b; ++i) result *= a;
                    values.push(result);
                    break;
                }
            }
        }
    }

    return values.top(); // The result
}

int main() {
    string infix;
    cout << "Enter an infix expression (e.g., 3 + 5 * ( 2 - 8 ) ^ 2): ";
    getline(cin, infix);

    string postfix = infixToPostfix(infix);
    cout << "Postfix expression: " << postfix << endl;

    int result = evaluatePostfix(postfix);
    cout << "Evaluation result: " << result << endl;

    return 0;
}
