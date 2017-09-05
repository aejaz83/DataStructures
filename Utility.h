#pragma once
#include<string>

std::string BoolToStr(bool b)
{
    if(b == true)
    {
        return "true";
    }
    else
    {
        return "false";
    }
}

// Function to get weight of an operator. An operator with higher weight will have higher precedence.
int GetOperatorWeight(char op)
{
    int weight = -1;

    switch(op)
    {
        case '+':
        case '-':
            weight = 1;
            break;

        case '*':
        case '/':
            weight = 2;
            break;

        case '$':
            weight = 3;
            break;
    }

    return weight;
}

// Function to perform an operation and return output.
int HasHigherPrecedence(char op1, char op2)
{
    int op1Weight = GetOperatorWeight(op1);
    int op2Weight = GetOperatorWeight(op2);

    // If operators have equal precedence, return true if they are left associative.
    // return false, if right associative.
    // if operator is left-associative, left one should be given priority.
    if(op1Weight == op2Weight)
    {
        return true;
    }

    return op1Weight > op2Weight ? true : false;
}


/*
Evaluation Of postfix Expression in C++
Input Postfix expression must be in a desired format.
Operands must be integers and there should be space in between two operands.
Only '+'  ,  '-'  , '*' and '/'  operators are expected.
*/
// Function to perform an operation and return output.
int PerformOperation(char operation, int operand1, int operand2)
{
    if(operation == '+')
    {
        return operand1 + operand2;
    }
    else if(operation == '-')
    {
        return operand1 - operand2;
    }
    else if(operation == '*')
    {
        return operand1 * operand2;
    }
    else if(operation == '/')
    {
        return operand1 / operand2;
    }

    else
    {
        std::cout << "Unexpected Error \n";
    }

    return -1;
}