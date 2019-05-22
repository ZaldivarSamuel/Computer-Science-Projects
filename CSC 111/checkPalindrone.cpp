//
//  Question46.cpp
//  PracticeProblems
//
//  Created by Samuel Zaldivar on 8/14/18.

#include <iostream>
#include <cmath>
using namespace std;

void getNumber(int&);
int getNumberOfDigits(int);
int digit(int, int);
void checkIfPalindrone(int, int);

int main(){
    
    int num;
    //ask user to enter a number
    getNumber(num);
    
    int numberOfDigits = getNumberOfDigits(num);
    checkIfPalindrone(num, numberOfDigits);
}

void getNumber(int &num){
    cout << "Enter a number: ";
    cin >> num;
}

/*
 This function will return the number of digits
 in the user number
 */
int getNumberOfDigits(int num){
    
    bool gotNumDigits = false;
    int power = 0;
    
    while(!gotNumDigits){
        
        if(num >= pow(10, power)){
            power++;
        }
        else if(num < pow(10, power)){
            
            gotNumDigits = true;
        }
    }
    return power;
}

/*
 This function will return the digit at a
 certain place
 */
int digit(int number, int power){
    
    int num = 0;
    int p = pow(10, power);
    
    if(power == 1){
        num = (number % p);
    }
    else{
        num = (number % p) / pow(10,power - 1);
    }
    
    return num;
}

void checkIfPalindrone(int num, int maxPower){
    
    int halfPower = maxPower / 2; //half of the digits of the number
    bool isPalindrone = true;
    
    for(int i = 1; i <= halfPower; i++){
        
        int firstNum = digit(num, i);
        int lastNum = digit(num, maxPower);
        
        //If these numbers are not the same, then it is not a palindrone
        if(firstNum != lastNum){
            isPalindrone = false;
        }
        maxPower--;
    }
    
    //Output result
    if(isPalindrone){
        cout << num << " is a palindrone" << endl << endl;
    }
    else{
        cout << num << " is not a palindrone" << endl << endl;
    }
}
