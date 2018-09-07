//
//  Question36.cpp
//  PracticeProblems
//
//  Created by Samuel Zaldivar on 8/16/18.

#include <iostream>
#include <string>
using namespace std;


void getStringAndLength(string*, int*);
int getStringLength(string);
void findElements(string, int, int*, int*, int*, int*);
void displayResult(int, int, int, int, int);

int main(){
    
    string str;
    int length;
    
    int numOfAlpha = 0;
    int numOfDigits = 0;
    int numOfSpaces = 0;
    int numOther = 0;
    
    getStringAndLength(&str, &length);
    findElements(str, length, &numOfAlpha, &numOfDigits, &numOfSpaces, &numOther);
    displayResult(length, numOfAlpha, numOfDigits, numOfSpaces, numOther);
}


void getStringAndLength(string *str, int *length){
    
    cout << "Enter a string: ";
    getline(cin, *str);
    *length = getStringLength(*str);
    
}

int getStringLength(string str){
    
   int length = 0;
    
    while(str[length] != '\0'){
        length++;
    }
    
    return length;
}

void findElements(string str, int length, int *numOfAlpha, int *numOfDigits, int *numOfSpaces, int *numOther){
    
    for(int i = 0; i < length; i++){
        
        int elementNum = static_cast<int>(str[i]);
        
        if((elementNum >= 65 && elementNum <= 90) ||
           (elementNum >= 97 && elementNum <= 122)){
            
            *numOfAlpha += 1;
        }
        else if(elementNum >= 48 && elementNum <= 57){
            *numOfDigits += 1;
        }
        else if(elementNum == 32){
            *numOfSpaces += 1;
        }
        else{
            *numOther += 1;
        }
    }
}

void displayResult(int length, int numOfAlpha, int numOfDigits, int numOfSpaces, int numOther){
    
    cout << "The number of characters in this string: " << length << endl;
    cout << "The number of alphabets are: " << numOfAlpha << endl;
    cout << "The number of digits are: " << numOfDigits << endl;
    cout << "The number of spaces are: " << numOfSpaces << endl;
    cout << "The number of other characters are: " << numOther << endl << endl;
}
