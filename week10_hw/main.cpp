//Romans_Prokopjevs_201RDB381

#include <fstream>
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
    // Check for invalid syntax
    bool was_operator = false;
    // Parse the input string into result queue
    char numBuffer[5200];
    int numI = 0;
    string num;

    for (char token : expression) {
        // Parse digits into numbers
        if (isdigit(token)) {
            was_operator = false;
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
        if (token == '(') {
            operatorStack.push(string(1, token));
        }
        else if (token == '*' || token == '/') {
            if (was_operator){
                throw invalid_argument("Operator error!");
            }
            was_operator = true;
            // Multiplication and division are pushed straight into operand stack
            if (!operatorStack.empty()){
                if (operatorStack.top() == "*" || operatorStack.top() == "/"){
                    // Following PEMDAS, multiplication and division are moved to queue
                    resQueue.push(operatorStack.top());
                    operatorStack.pop();
                }
            }
            operatorStack.push(string(1, token));
        }
        else if (token == '+' || token == '-') {
            if (was_operator){
                throw invalid_argument("Operator error!");
            }
            was_operator = true;
            // Addition and subtraction are pushed into operand stack
            if (!operatorStack.empty()){
                if (operatorStack.top() == "*" || operatorStack.top() == "/") {
                    resQueue.push(operatorStack.top());
                    operatorStack.pop();
                }
            }
            if (!operatorStack.empty()){
                if (operatorStack.top() == "+" || operatorStack.top() == "-") {
                    resQueue.push(operatorStack.top());
                    operatorStack.pop();
                }
            }
            operatorStack.push(string(1, token));
        }
        else if (token == ')') {
            while (true){
                if (operatorStack.empty()){
                    throw invalid_argument("Extra closed parenthesis!");
                }
                else if (operatorStack.top() == "("){
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
    // Convert last numeric buffer
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
        if (operatorStack.top() == "(") {
            throw invalid_argument("Extra open parenthesis!");
        }
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
    /* Arithmetic File Parser. */
    float res;
    // Open the file
    ifstream file("sequence_with_parenthesis.txt");
    if (!file.is_open()) {
        cerr << "Failed to open the file." << std::endl;
        return 1;
    }
    // Read the first line
    string expression;
    getline(file, expression);
    std::cout << "Expression: " << expression << '\n';
    file.close();
    //
    try {
        // Translate given expression from infix to postfix
        queue<string> postfixQueue = shuntingYard(expression);
        if (postfixQueue.empty()){
            cout << "nan\n";
        }
        // Compute the postfix expression
        res = computePostfix(postfixQueue);
        cout << "Answer: " << res << '\n';
    }
    catch (const invalid_argument& e) {
        cerr << "Expression error: " << e.what() << '\n';
    }
    return 0;
}
