#include "PostfixCalculator.hpp"
#include "PrecondViolatedExcep.hpp"
#include<iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
/*Name: Gabriella Alexis
Date: November 18, 2019
Class: CS235 
Implementation of PostfixCalculator*/
PostfixCalculator::PostfixCalculator(){}

/*Determines the precedence of the operators */
int PostfixCalculator::precedence(char ch)
{
    switch(ch)
    {
        case '+':
        case '-':
            return 1;
        
        case '*':
        case '/':
            return 2;

        default:
            return 0;  
    }

}

std::string PostfixCalculator::convertToPostfix(std::string infix_expression)
{
    char ch;
    std::stack<char> aStack;
    std::string Postfixexp ="";

    for(int i = 0; i < infix_expression.length(); i++)
    {
        ch = infix_expression[i]; //copying every char in infix to ch 
        switch(ch)
        {
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':         
                Postfixexp += ch; //if ch = a number, append to string
                break;
            case '(':
                aStack.push(ch);
                break;
            case '+':
            case '-':
            case '*':
            case '/':
                while(!aStack.empty() && aStack.top() != '(' 
                && precedence(ch) <= precedence(aStack.top()))
                {
                    Postfixexp += " "; //adds space
                    Postfixexp += aStack.top();
                    aStack.pop();
                }
                Postfixexp += " "; //adds space
                aStack.push(ch);
                break;
            case ')':
                while(!aStack.empty() && aStack.top() != '(' ) 
                {
                    Postfixexp += " "; //adds space
                    Postfixexp += aStack.top();
                    aStack.pop();

                }

                if(aStack.empty()) 
                {
                    throw(PrecondViolatedExcep("Unbalanced parenthesis")); 
                }
                else{
                    aStack.pop();
                }
                
                break;
            case ' ':
                break;
            default: 
                throw (PrecondViolatedExcep("Unknown operator"));
            break;
        }
    }
    while(!aStack.empty() && aStack.top()!= '(')
    {
        Postfixexp += " "; //adds space 
        Postfixexp += aStack.top();
        aStack.pop();
    }
    if(!aStack.empty() && aStack.top() == '(')
    {
        throw(PrecondViolatedExcep("Unbalanced parenthesis"));
    }
    //if stack is not empty, yet the top is open parenthis, throw exception
    Postfixexp += " "; //adds space 
    return Postfixexp;
}

double PostfixCalculator::calculatePostfix(std::string infix_expression)
{
    double op2, op1;
    double result;
    double numbers;
    std::stack<double> operands;
    std::string postFix = infix_expression;
    std::stringstream ss(postFix);

    while(getline(ss,postFix,' '))
    {
        if(isdigit(postFix[0]))
        {
            numbers = std::stod(postFix); //makes doubles
            operands.push(numbers); //push to stack
        }
        else if(postFix[0] == '+') //if string has '+'
        {
            op2 = operands.top();           
            operands.pop();

            op1 = operands.top();           
            operands.pop();

            operands.push(op1+op2); //add stack top and next stack top
        }
        else if(postFix[0] == '-') //if string has '-'
        {
            op2 = operands.top();
            operands.pop();

            op1 = operands.top();
            operands.pop();

            operands.push(op1-op2); //subtract stack top and next stack top
        }
        else if(postFix[0] == '*') //if string has '*'
        {
            op2 = operands.top();
            operands.pop();

            op1 = operands.top();
            operands.pop();

            operands.push(op2*op1); //multiply stack top and next stack top
        }
        else if(postFix[0] == '/') //if string has '/'
        {
            op2 = operands.top();
            operands.pop();

            op1 = operands.top();
            operands.pop();

            operands.push(op1/op2); //divide stack top and next stack top
        }
    }
    
    return operands.top();
}

void PostfixCalculator::testCalculator(std::string input_file_name)
{
    bool t_exception = false;
    std::string line;
    std::ifstream infile(input_file_name);
    std::string post;
    std::ofstream post_fix_file("postfix.txt");
    std::ofstream result_file("results.txt");
    double result;
    if(infile.fail()){
        std::cerr << "Error" << std::endl;
        exit(1);
    }
    while(getline(infile,line))
    {
        if(line.length() == 0)
        {
            post_fix_file << "" << std::endl;
            result_file << "" << std::endl;
        }
        else{
        /*TRY CATCH*/
            try
            {
                post = convertToPostfix(line); //converts every infix line to postfix
            }
            catch(PrecondViolatedExcep& e)
            {
                post = e.what(); //postfix string is overwritten with error message
                result_file << post << std::endl; //error message is written to result file
                t_exception = true;
            }
            post_fix_file << post << std::endl;
            if(!t_exception) //if no error 
            {
                result = calculatePostfix(post); //result computed from postfix
                result_file << result << std::endl; //result written into result file
            }
            t_exception = false;
        }
    }
    post_fix_file.close();
    result_file.close();
    infile.close(); 
}
    


