#include<bits/stdc++.h>
using namespace std;

const int MAX_SIZE = 100;
char Stack[MAX_SIZE];
int top = -1;

void push(char val)
{
    if (top >= MAX_SIZE - 1)
    {
        cout << "Stack overflow\n";
    }
    else
    {
        top++;
        Stack[top] = val;
    }
}

void pop()
{
    if (top <= -1)
    {
        cout << "Stack underflow\n";
    }
    else
    {
        top--;
    }
}

char peek()
{
    if (top <= -1)
    {
        return '\0'; // Indicate empty stack
    }
    else
    {
        return Stack[top];
    }
}

int prec(char c)
{
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

void infixToPostfix(string s, string &result)
{
    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];

        if (isalnum(c))
        {
            result += c;
        }
        else if (c == '(')
        {
            push(c);
        }
        else if (c == ')')
        {
            while (peek() != '\0' && peek() != '(')
            {
                result += peek();
                pop();
            }
            pop(); // Remove '(' from the stack
        }
        else
        {
            while (top >= 0 && prec(c) <= prec(peek()))
            {
                result += peek();
                pop();
            }
            push(c);
        }
    }

    while (top >= 0)
    {
        result += peek();
        pop();
    }

    cout << "Postfix expression: ";
    for (char c : result)
    {
        cout << c << ' ';
    }
    cout << endl;
}

double evaluatePostfix(const string &postfix)
{
    for (char c : postfix)
    {
        if (isalpha(c)) {
            cout << "cannot evaluate postfix having characters" << endl;
            return INT_MIN;
        }
        if (isspace(c))
            continue;

        if (isdigit(c))
        {
            push(c - '0'); // Convert char to int and push
        }
        else
        {
            double operand2 = peek();
            pop();
            double operand1 = peek();
            pop();
            double result;

            switch (c)
            {
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

int main()
{
    string expression;
    string postfixResult;

    cout << "Enter infix expression: ";
    cin >> expression;

    infixToPostfix(expression, postfixResult);

    char evaluate;
    cout << "Want to evaluate the postfix expression? (y/n): ";
    cin >> evaluate;

    if (evaluate == 'y' || evaluate == 'Y')
    {
        top = -1;
        double result = evaluatePostfix(postfixResult);
        if (result!=INT_MIN)
        {
        cout << "Evaluation result: " << result << endl;
        }
    }

    return 0;
}