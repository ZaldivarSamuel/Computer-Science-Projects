//
//  Question12.cpp
//  PracticeProblems
//
//  Created by Samuel Zaldivar on 8/13/18.
#include <iostream>
#include <cmath>
using namespace std;

int main(){
    
    int number;
    bool isPrime = true;
    
    cout << "Input a number to check prime or not: ";
    cin >> number;
    
    //Input validation: Only accept values greater than 0
    while(number <= 0){
        cout << "Number must be greater than zero. Enter again:";
        cin >> number;
    }
    
    //If the number is even, then it is not prime. But 2 can be prime.
   if((number % 2) == 0 && number != 2){
        isPrime = false;
    }
    //The number 1 is not prime
   else if(number == 1){
       isPrime = false;
   }
    else{
        //This is the square root of the user's number. Any numbers above this number can not be factors for the user's number
        int bound = static_cast<int>(sqrt(number));
        
        /*
         Check all the odd numbers from 3 to the bound.
         If there is a factor, then the number is not prime.
         */
        for(int i = 3; i <= bound; i += 2){
            if(number % i == 0){
                isPrime = false;
                break;
            }
        }
    }
    
    //Display the result
    if(isPrime){
        cout << "The entered number is a prime number" << endl << endl;
    }
    else{
        cout << "The entered number is not a prime number" << endl << endl;
    }
    
    
    
    return 0;
}
