//
//  ArrayShift
//
//  Created by Samuel Zaldivar on 9/5/18.

#include <iostream>
using namespace std;

//Function prototypes
void getArrayLength();
void fillArray(int*);
void rotateRight(int, int*);
void rotateLeft(int, int*);
void displayArray(int*);

//Global variables
int arrayLength = 0;

int main(){
    
    //getting array info
    getArrayLength();
    int arr[arrayLength];
    fillArray(arr);
    
    //How much rotation does the user want to rotate
    int rotation;
    cout << "Enter rotation number: ";
    cin >> rotation;
    
    cout << endl << "Old array: " << endl;
    displayArray(arr);
    cout << endl;
    
    //positive rotate right, negative rotate left
    if(rotation > 0){
        rotateRight(rotation, arr);
    }
    else{
        rotateLeft(rotation, arr);
    }
    
    //Output new array
    cout << "New array: " << endl;
    displayArray(arr);
    cout << endl << endl;
}

void getArrayLength(){
    
    cout << "Enter the total number of elements in the array: ";
    cin >> arrayLength;
    
    //INPUT VALIDATION: make sure arrayLength is greater than 0
    while(arrayLength <= 0){
        cout << "Array length must be greater than 0. Please enter again: ";
        cin >> arrayLength;
    }
}

void fillArray(int *arr){
    
    for(int i = 0; i < arrayLength; i++){
        
        int inputNum;
        cout << "Enter an integer for element " << i << ": ";
        cin >> inputNum;
        
        *(arr + i) = inputNum;
    }
}

void rotateRight(int rotationNum, int *arr){
    
    for(int r = 0; r < rotationNum; r++){
        
        int lastElement = *(arr + arrayLength - 1);
        
        //place holder for the next element to change. We have this so we dont loose the value of the element
        int temp = *(arr + 0);
        
        for(int i = 0; i < arrayLength - 1; i++){
            
            int numToChange = temp;
            temp = *(arr + i + 1);  //save temp as the next element
            
            *(arr + i + 1) = numToChange;
        }
        
        //Save the first element as the saved last element
        *(arr + 0) = lastElement;
    }
}

void rotateLeft(int rotationNum, int *arr){
    
    for(int r = rotationNum; r < 0; r++){
        
        //save the first element of the array
        int firstElement = *(arr + 0);
        
        for(int i = 1; i < arrayLength; i ++){
            *(arr + i - 1) = *(arr + i);
        }
        
        //Save the last element of the array as the saved first element
        *(arr + arrayLength - 1) = firstElement;
    }
}

void displayArray(int *arr){
    
    for(int i = 0; i < arrayLength; i++){
        cout << *(arr + i) << " ";
    }
    cout << endl;
}
