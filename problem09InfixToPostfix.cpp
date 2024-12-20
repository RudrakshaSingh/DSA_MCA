#include <bits/stdc++.h>

using namespace std;

const int MAX_SIZE = 100;
char Stack[MAX_SIZE];
int top = -1;

void push(char val) {
    if (top >= MAX_SIZE - 1) {
        cout << "Stack overflow\n";
    } else {
        top++;
        Stack[top] = val;
    }
}

void pop() {
    if (top <= -1) {
        cout << "Stack underflow\n";
    } else {
        top--;
    }
}

char peek() {
    if (top <= -1) {
        return '\0';
    } else {
        return Stack[top];
    }
}

int prec(char c) {
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

bool isValidInfix(string s) {
    int cnt = 0;

    for (int i = 0; i < s.length(); i++) {
        if (!((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') ||
                (s[i] >= '0' && s[i] <= '9') || s[i] == '+' || s[i] == '-' ||
                s[i] == '*' || s[i] == '/' || s[i] == '^' || s[i] == '(' || s[i] == ')')) {
            cout << "Invalid operator or operand: " << s[i] << endl;
            return false;
        } else if (s[i] == '(') {
            cnt++;
        } else if (s[i] == ')') {
            cnt--;
            if (cnt < 0) {
                cout << "Mismatched parentheses" << endl;
                return false;
            }
        }
    }
    if (cnt != 0) {
        cout << "Mismatched parentheses" << endl;
        return false;
    }

    return true;
}

string infixToPostfix(string s) {
    string result;
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];

        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
            result += c;
        } else if (c == '(') {
            push(c);
        } else if (c == ')') {
            while (peek() != '\0' && peek() != '(') {
                result += peek();
                pop();
            }
            pop(); // Remove '(' from the stack
        } else {
            while (top >= 0 && prec(c) <= prec(peek())) {
                result += peek();
                pop();
            }
            push(c);
        }
    }

    while (top >= 0) {
        result += peek();
        pop();
    }
    return result;
}

int evaluatePostfix(const string postfix) {
    for (char c: postfix) {
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
            cout << "cannot evaluate postfix having characters" << endl;
            return INT_MIN;
        }
        if (c == ' ')
            continue;

        if (c >= '0' && c <= '9') {
            push(c - '0'); // Convert char to int and push
        } else {
            int operand2 = peek();
            pop();
            int operand1 = peek();
            pop();
            int result;

            switch (c) {
            case '+':
                result = operand1 + operand2;
                break;
            case '-':
                result = operand1 - operand2;
                break;
            case '*':
                result = operand1 * operand2;
                break;
            case '/':
                result = operand1 / operand2;
                break;
            case '^':
                result = pow(operand1, operand2);
                break;
            }

            push(result); // Push the result back onto the evaluation stack
        }
    }

    return peek(); // The final result is the top of the evaluation stack
}

int main() {
    string expression;

    cout << "Enter infix expression: ";
    cin >> expression;

    if (!isValidInfix(expression)) {
        return 0;
    }

    string postfixResult = infixToPostfix(expression);
    cout << "Postfix expression: " << postfixResult << endl;

    char evaluate;
    cout << "Want to evaluate the postfix expression? (y/n): ";
    cin >> evaluate;

    if (evaluate == 'y' || evaluate == 'Y') {
        top = -1;
        int result = evaluatePostfix(postfixResult);
        if (result != INT_MIN) {
            cout << "Evaluation result: " << result << endl;
        }
    }

    return 0;
}