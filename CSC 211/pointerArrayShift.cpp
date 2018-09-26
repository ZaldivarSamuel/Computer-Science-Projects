#include <iostream>
using namespace std;

struct Computers{
    string name;
    double price;
    
    //default constructor
    Computers(){};
    
    //Constructor
    Computers(string n, double p){
        this->name = n;
        this->price = p;
        
        cout << "Created " << this->name << " with price: $" << this->price << endl;
    }
    
    Computers(string name){
        this->name = name;
        cout << "Created " << this->name << " with price: $" << this->price << endl;
    }
};

void displayArray(Computers**);
void rotate(Computers**, int);

const int NUM_OF_PRODUCTS = 3;

int main(){

    Computers macbook("Macbook", 999);
    Computers macbookAir("Macbook air", 899);
    Computers macbookPro("Macbook Pro", 1899);
    
    //Array to hold pointers
    Computers *products[NUM_OF_PRODUCTS];
    *(products + 0) = &macbook;
    *(products + 1) = &macbookAir;
    *(products + 2) = &macbookPro;
    
    //Number to rotate
    int rotationNum;
    cout << "Enter rotation number: ";
    cin >> rotationNum;
    
    cout << endl;
    displayArray(products);
    rotate(products, rotationNum);
    cout << endl << "New array: " << endl;
    displayArray(products);
}

void displayArray(Computers **products){
    
    for(int i = 0; i < NUM_OF_PRODUCTS; i++){
        cout << (*(products + i))->name << endl;
    }
}

void rotate(Computers **products, int rotationNum){
    
    for(int r = 0; r < abs(rotationNum); r++){
        //Rotate right
        if(rotationNum > 0){
            Computers temp = *(*(products + NUM_OF_PRODUCTS - 1));
            for(int i = NUM_OF_PRODUCTS - 2; i >= 0; i--){
                *(*(products + i + 1)) = *(*(products + i));
            }
            *(*(products + 0)) = temp;
        }
        //Rotate left
        else{
            Computers temp = *(*(products + 0));
            for(int i = 0; i < NUM_OF_PRODUCTS - 1; i++){
                *(*(products + i)) = *(*(products + i + 1));
            }
            *(*(products + NUM_OF_PRODUCTS - 1)) = temp;
        }
    }
}

