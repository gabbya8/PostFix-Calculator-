#ifndef PostfixCalculator_hpp
#define PostfixCalculator_hpp 
#include "PrecondViolatedExcep.hpp"

#include <iostream>
#include <stack>
/*Name: Gabriella Alexis
Date: November 18, 2019
Class: CS235 
Interface of PostfixCalculator*/
class PostfixCalculator
{
    public: 
        //Default constructor
        PostfixCalculator(); 
        
        //Converts string in file to postfix
        std::string convertToPostfix(std::string infix_expression);
        
        //calculates the postfix
        double calculatePostfix(std::string postfix_expression);
        
        //test the calculator
        void testCalculator(std::string input_file_name);

    private:
        int precedence(char ch);
    
};
#endif