#include "PostfixCalculator.hpp"
#include <iostream>
#include <fstream>
#include <stack>
#include <string>
#include <sstream> 
#include <stdlib.h>

std::string getString(char x) 
{ 
    // string class has a constructor 
    // that allows us to specify size of 
    // string as first parameter and character 
    // to be filled in given size as second 
    // parameter. 
    std::string s(1, x); 
  
    return s;    
} 

std::string add_spaces(const std::string& input)
{
  std::string output;

  for (int i = 0; i < input.length(); i++)
  {
    switch(input[i])
    {
      case '+':
      case '-':
      case '*':
      case '/':
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
{
        if (!output.empty() && output.back() != ' ')
        {
          output += ' ';
        }
      }
      break;
    }    
    output += input[i];
  }
  return output;
}
/*-----------------------START HERE------------------------*/
int main()
{ 
    PostfixCalculator test;
    test.testCalculator("input.txt");
    // std::string str = "1 + 2 + 4";
    // std::stringstream ss(str);
    // while(getline(ss,str,' ')){
    //     std::cout << str<< std::endl;
    // }
    // std::cout << "" << std::endl;
    
    
    // std::string postFix = test.convertToPostfix("( 12 + 3 ) * ( 9 - 74 ) + 34 / ( ( 85 - 93 ) + ( 3 + 5 ) * 3 ) - 5 "); 
    // std::cout << postFix << std::endl;
    // double op2, op1;
    // double nums;
    // std::stack<double> operands;
    // std::stringstream ss(postFix);

    // while(getline(ss,postFix,' ')) //stream through postfix by space
    // {
    //     if(isdigit(postFix[0])) //if find digits
    //     {
    //         nums = std::stod(postFix);
    //         //std::cout << nums << std::endl;
    //         operands.push(nums);
    //     }
    //     if(postFix[0] == '+')
    //     {   
    //         op2 = operands.top();
    //         std::cout << "PLUS OP2: " << operands.top() << std::endl; 
    //         operands.pop();

    //         op1 = operands.top();
    //         std::cout << "PLUS OP1: " << operands.top() << std::endl;          
    //         operands.pop();

    //         operands.push(op1+op2);
    //         std::cout << "PLUS RESULT: " << operands.top() << std::endl;           
    //     }
    //     else if(postFix[0] == '-')
    //     {
    //         op2 = operands.top();
    //         std::cout << "MINUS OP2: "<< operands.top() << std::endl;          
    //         operands.pop();

    //         op1 = operands.top();
    //         std::cout << "MINUS OP1: " << operands.top() << std::endl;          
    //         operands.pop();

    //         operands.push(op1-op2);
    //        std::cout << "MINUS RESULT: " << operands.top() << std::endl;          
    //     }
    //     else if(postFix[0] == '*')
    //     {
    //         op2 = operands.top();
    //         std::cout << "MULT OP2: " << operands.top() << std::endl;
    //         operands.pop();

    //         op1 = operands.top();
    //         std::cout << "MULT OP1: " << operands.top() << std::endl;
    //         operands.pop();

    //         operands.push(op2*op1);
    //         std::cout << "MULT RESULT: " << operands.top() << std::endl; 
    //     }
    //     else if(postFix[0] == '/')
    //     {
    //         op2 = operands.top();
    //         std::cout << "DIV OP2: " << operands.top() << std::endl;
    //         operands.pop();

    //         op1 = operands.top();
    //         std::cout << "DIV OP1: " << operands.top() << std::endl;
    //         operands.pop();

    //         operands.push(op1/op2);
    //         std::cout << "DIV RESULT: " << operands.top() << std::endl;
    //     }
    //  }
    //  while(!operands.empty())
    //  {
    //      std::cout << operands.top() << std::endl;
    //      operands.pop();
    //  }
    // std::cout << operands1.top() << " ";
 }
    

