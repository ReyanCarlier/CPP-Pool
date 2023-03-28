#include <stack>
#include <iostream>
#include <string>
#include <cstdlib>

bool isOperator(const std::string &token)
{
    return token == "+" || token == "-" || token == "*" || token == "/";
}

bool isDigit(const std::string &token)
{
    return token[0] >= '0' && token[0] <= '9';
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Usage: " << argv[0] << " <expression>" << std::endl;
        return 1;
    }
    std::string expression = argv[1];
    std::stack<std::string> stack_operator;
    std::stack<int> stack_operand;
    std::string token;

    size_t pos = 0;
    for (size_t i = 1; i <= expression.size(); i++)
    {
        token = expression.substr(pos, i - pos);
        if (token[0] == 0)
            break;
        if (isspace(token[0]))
        {
            pos++;
            continue;
        }
        if (isDigit(token))
        {
            stack_operand.push(std::atoi(token.c_str()));
        }
        else if (isOperator(token))
        {
            stack_operator.push(token);
        }
        else
        {
            std::cerr << "Invalid token: " << token << std::endl;
            return 1;
        }
        pos++;
    }

    if (stack_operator.size() != stack_operand.size() - 1)
    {
        std::cerr << "Invalid amount of operators." << std::endl;
        return 1;
    }
    while (!stack_operator.empty())
    {
        int operand1 = stack_operand.top();
        stack_operand.pop();
        int operand2 = stack_operand.top();
        stack_operand.pop();
        std::string op = stack_operator.top();
        stack_operator.pop();
        if (op == "+")
        {
            stack_operand.push(operand2 + operand1);
        }
        else if (op == "-")
        {
            stack_operand.push(operand2 - operand1);
        }
        else if (op == "*")
        {
            stack_operand.push(operand2 * operand1);
        }
        else if (op == "/")
        {
            if (operand1 == 0)
            {
                std::cerr << "Division by zero." << std::endl;
                return 1;
            }
            stack_operand.push(operand2 / operand1);
        }
    }
    std::cout << "Result: " << stack_operand.top() << std::endl;
    return 0;
}