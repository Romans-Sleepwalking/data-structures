//Romans_Prokopjevs_201RDB381

#include <iostream>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <string>
#include <queue>


using namespace std;


queue<string> shuntingYard(string expression) {
    /* Convert infix expression to postfix expressions. */
    stack<string> operatorStack;
    queue<string> resQueue;
    // Parse the input string into result queue
    char numBuffer[42];
    int numI = 0;
    string num;
    for (char token : expression) {
        // Parse digits into numbers
        if (isdigit(token)) {
            numBuffer[numI] = token;
            numI++;
            continue;
        } else if (numI > 0) {
            numBuffer[numI] = '\0';
            numI = 0;
            num = string(numBuffer);
            // Catch division by zero
            if (!operatorStack.empty() && num == "0"){
                if (operatorStack.top() == "/"){
                    // Return an empty queue
                    return queue<string>();
                }
            }
            resQueue.push(num);
        }
        // Parse operands
        if (token == '*' || token == '/' || token == '(') {
            // Multiplication and division are pushed straight into operand stack
            operatorStack.push(string(1, token));
        }
        else if (token == '+' || token == '-') {
            // Addition and subtraction are pushed into operand stack
            if (!operatorStack.empty()){
                if (operatorStack.top() == "*" || operatorStack.top() == "/"){
                    // Following PEMDAS, multiplication and division are moved to queue
                    resQueue.push(operatorStack.top());
                    operatorStack.pop();
                }
            }
            operatorStack.push(string(1, token));
        }
        else if (!operatorStack.empty() && token == ')') {
            while (!operatorStack.empty()){
                if (operatorStack.top() == "("){
                    // Parentheses closed
                    operatorStack.pop();
                    break;
                } else {
                    resQueue.push(operatorStack.top());
                    operatorStack.pop();
                }
            }
        } else if (token == ' '){  // Ignore whitespaces
            continue;
        }
        else {
            throw invalid_argument("Bad input: \"" + string(1, token) + "\"!");
        }
    }
    // Convert last buffer
    if (numI > 0) {
        numBuffer[numI] = '\0';
        num = string(numBuffer);
        // Catch division by zero
        if (!operatorStack.empty() && num == "0"){
            if (operatorStack.top() == "/"){
                // Return an empty queue
                return queue<string>();
            }
        }
        resQueue.push(num);
    }
    // Move all operands left from the stack into the queue
    while (!operatorStack.empty()) {
        resQueue.push(operatorStack.top());
        operatorStack.pop();
    }
    return resQueue;
}


float computePostfix(queue<string>& tokens) {
    /* Compute the given postfix expression. */
    stack<float> stack;
    cout << "Postfix: ";
    while (!tokens.empty()) {
        string token = tokens.front();
        cout << token << ' ';
        tokens.pop();
        if (isdigit(token[0]) || (token.length() > 1 && token[0] == '-')) {
            // Token is an operand, push it to the stack
            stack.push(stoi(token));
        } else {
            // Token is an operator, pop two operands and apply the operator
            float operand2 = stack.top();
            stack.pop();
            float operand1 = stack.top();
            stack.pop();
            switch (token[0]) {
                case '+': stack.push(operand1 + operand2); break;
                case '-': stack.push(operand1 - operand2); break;
                case '*': stack.push(operand1 * operand2); break;
                case '/': stack.push(operand1 / operand2); break;
            }
        }
    }
    cout << endl;
    return stack.top();
}


int main() {
    /* Arithmetic Parser. */
    float res;
    while (true) {
        try {
            // Ask the user to prompt their statement to be calculated
            string expression;
            cout << "Please enter an arithmetic expression: ";
            getline(cin, expression);
            // Translate given expression from infix to postfix
            queue<string> postfixQueue = shuntingYard(expression);
            if (postfixQueue.empty()){
                cout << "nan\n"; break;
            }
            // Compute the postfix expression
            res = computePostfix(postfixQueue);
            cout << "Answer: " << res << '\n';
        }
        catch (const invalid_argument& e) {
            cerr << "Expression error: " << e.what() << std::endl;
            continue;
        }
    }
    return 0;
}
