/*
 COURSE ID:             CSC 331
 FULL NAME:             Samuel Zaldivar
 SECTION:               0900
 FILE NAME:             csc331-0900_zaldivar_prog3.cpp
 ASSIGNMENT NUMBER:     2
 DUE DATE:              03/25/2019
 PROGRAM PURPOSE:       Evaluate post-fix experessions using a stack
 */

#include <iostream>
#include <stack>
#include <string>
using namespace std;

double getResult(string);

int main(){
    string userInput;
    
    while(userInput != "end-of-file"){
        
        cout << "Enter a post-fix expression: ";
        getline(cin, userInput);
        
        if(userInput != "end-of-file"s){
            try{
                double result = getResult(userInput);
                cout << "Result = " << result << endl;
            }catch(int error){
                cout << "Division by zero. Unable to evaluate experssion." << endl;
            }
        }
    }
}

double getResult(string expression){
    
    stack<double> stack;
    
    //For every character in experession
    for(char& c : expression){
        int asciiValue = static_cast<int>(c); //Get ASCII value of character
        
        //If the ASCII value of character is between 48 and 57 then the character is a number
        if((asciiValue >= 48) && (asciiValue <= 57)){
            int numValue = asciiValue - 48; //Subtract ASCII value by 48 gives the actual value of the number
            stack.push(numValue); // Push number value to stack
        }
        else{
            
            //Get operands from stack
            int operand2 = stack.top();
            stack.pop();
            int operand1 = stack.top();
            stack.pop();
            
            //Check which operator is character
            switch(c){
                case '*':{
                    double product = operand1 * operand2;
                    stack.push(product);
                    break;
                }
                case '/':{
                    //Check for divide by zero error
                    if(operand2 == 0){
                        throw 0;
                    }
                    else{
                        double quotient = operand1 / operand2;
                        stack.push(quotient);
                    }
                    break;
                }
                case '+':{
                    double sum = operand1 + operand2;
                    stack.push(sum);
                    break;
                }
                case '-':{
                    double difference = operand1 - operand2;
                    stack.push(difference);
                    break;
                }
            }
            
        }
    }
    return stack.top();
}


