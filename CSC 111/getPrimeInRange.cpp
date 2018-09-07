//
//  Question13.cpp
//  PracticeProblems
//
//  Created by Samuel Zaldivar on 8/13/18.
#include <iostream>
#include <cmath>
using namespace std;

bool checkPrime(int);

int main(){
    
    int min, max, numOfPrimes = 0;
    
    cout << "Input number for starting range: ";
    cin >> min;
    
    //Input validation: min must be greater than 0
    while(min < 0){
        cout << "Min number can not be negative. Please enter again: ";
        cin >> min;
    }
    
    cout << "Input number for ending range: ";
    cin >> max;
    
    //Input validation: max must be greater than 0 and min
    while(min > max || max < 0){
        cout << "Max must be greater than min and not negative. Please enter again: ";
        cin >> max;
    }
    
    cout << endl;
    
    for(int num = min; num <= max; num++){
        
        if(checkPrime(num)){
            cout << num << " ";
            numOfPrimes++;
        }
    }
    
    cout << endl << "The total number of prime numbers between " << min << " to " << max << " is: " << numOfPrimes << endl << endl;
}

bool checkPrime(int num){
    
    bool isPrime = true;
    
    //If the number is even, then it is not prime. But 2 can be prime.
    if((num % 2) == 0 && num != 2){
        isPrime = false;
    }
    //The number 1 is not prime
    else if(num == 1){
        isPrime = false;
    }
    else{
        //This is the square root of the user's number. Any numbers above this number can not be factors for the user's number
        int bound = static_cast<int>(sqrt(num));
        
        /*
         Check all the odd numbers from 3 to the bound.
         If there is a factor, then the number is not prime.
         */
        for(int i = 3; i <= bound; i += 2){
            if(num % i == 0){
                isPrime = false;
                break;
            }
        }
    }
    
    return isPrime;
}
