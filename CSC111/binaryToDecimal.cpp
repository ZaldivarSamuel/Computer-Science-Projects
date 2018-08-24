//
//  Question33.cpp
//  PracticeProblems
//
//  Created by Samuel Zaldivar on 8/14/18.

#include <iostream>
#include <cmath>
#include <string>
using namespace std;

void getBinaryNum(string&, int&);
int getStringSize(string);
int convertBinaryToDecimal(string, int);

int main(){
    string binaryNum;
    int stringSize = 0;
    getBinaryNum(binaryNum, stringSize);
    
    int decimal = convertBinaryToDecimal(binaryNum, stringSize);
    cout << "The decimal number: " << decimal << endl;
}

void getBinaryNum(string &binary, int &size){
    
    bool goodString = false;
    
    cout << "Enter a binary num: ";
    cin >> binary;
    size = getStringSize(binary);
    
    while(!goodString){
        bool foundError = false;
        for(int i = 0; i <= size; i++){
            
            char number = binary[i];
            
            if(number != '1' && number != '0'){
                foundError = true;
                break;
            }
        }
        
        if(!foundError){
            goodString = true;
        }
        else{
            cout << "Binary number must only have 1's and 0's. Please enter again: ";
            cin >> binary;
            size = getStringSize(binary);
        }
    }
}

int getStringSize(string str){
    int size = 0;
    
    while(str[size] != '\0'){
        size++;
    }
    size--;
    
    return size;
}

int convertBinaryToDecimal(string binaryNum, int size){
    int decimal = 0;
    int power = 0;
    
    for(int i = size; i >= 0; i--){
        
        char digit = binaryNum[i];
        
        if(digit == '1'){
            decimal += pow(2, power);
        }
        power++;
    }
    
    return decimal;
}
