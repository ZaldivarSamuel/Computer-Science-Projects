//
//  ArrayShift
//
//  Created by Samuel Zaldivar on 9/5/18.

#include <iostream>
using namespace std;

//Function prototypes
void getArrayLength();
void fillArray(int*);
void rotate(int, int*);
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

    rotate(rotation, arr);

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


void rotate(int rotationNum, int * arr){
    
    //Loop for number of rotations
    for(int r = 0; r < abs(rotationNum); r++){
        
        //save the first element
        int temp = *(arr + 0);
        
        //if right rotations
        if(rotationNum > 0){
            
            //from the last element down to the second element
            for(int i = arrayLength - 1; i >= 1; i--){
                
                int index = (i + 1) % arrayLength;
                
                //swap
                *(arr + index) = *(arr + i);
            }
            //set the secound element to temp
            *(arr + 1) = temp;
        }
        //left rotation
        else{
            //from the secound element to the last element
            for(int i = 1; i < arrayLength; i++){
                
                int index = (i - 1) % arrayLength;
                
                //swap
                *(arr + index) = *(arr + i);
            }
            
            //set the last element to temp
            *(arr + arrayLength - 1) = temp;
        }
    }
}

void displayArray(int *arr){
    
    for(int i = 0; i < arrayLength; i++){
        cout << *(arr + i) << " ";
    }
    cout << endl;
}
