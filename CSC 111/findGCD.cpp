//
//  Question15.cpp
//  PracticeProblems
//
//  Created by Samuel Zaldivar on 8/14/18.

#include <iostream>
using namespace std;

void userInput(int&, int&);
int getGCD(int, int);

int main(){

    int num1, num2;
    userInput(num1, num2);
    
    cout << "The Greatest Common Divisor is: " << getGCD(num1, num2) << endl << endl;
}

void userInput(int &num1, int &num2){
    
    cout << "Input the first number: ";
    cin >> num1;
    
    cout << "Input the secound number: ";
    cin >> num2;
}

int getGCD(int num1, int num2){
    
    int lowerNumber;
    int gcd = 1;
    
    if(num1 < num2){
        lowerNumber = num1;
    }
    else{
        lowerNumber = num2;
    }
    
    for(int i = 1; i <= lowerNumber; i++){
        
        if(num1 % i == 0 && num2 % i == 0){
            gcd = i;
        }
    }
    return gcd;
}
