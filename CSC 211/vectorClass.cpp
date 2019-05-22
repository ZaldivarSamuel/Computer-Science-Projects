#include <iostream>
using namespace std;

class Vector{
private:
    int cap = 0, size = 0, *v = new int[0];
    void increaseCapacity();
    void replaceVector(int*);
public:
    Vector(){};
    Vector(int);
    ~Vector(){delete[] v;}
    void push_back(int);
    void insert(int, int);
    void erase(int);
    int at(int);
    int vecSize(){return this->size;}
    void printVector();
};

Vector::Vector(int c){
    this->cap = c;
    
    int *nv = new int[this->cap];
    replaceVector(nv);
}

void Vector::increaseCapacity(){
    //Increse capacity of vector
    this->cap *= 2;
    
    //Make a new vector with the new capacity and hold the elements of the previous vector
    int *nv = new int[this->cap];
    for(int i = 0; i < this->size; i++){
        nv[i] = v[i];
    }
    //delete old vector and set it to the new vector
    replaceVector(nv);
}

void Vector::push_back(int n){
    
    //If the vector is filled up to capacity
    if(this->size == this->cap){
        increaseCapacity();
    }
    //Add element to vector
    v[this->size] = n;
    this->size++;
}

void Vector::insert(int n, int pos){
    if(this->size == this->cap){
        increaseCapacity();
    }
    //Increse size, shift all elements from pos to the right
    size++;
    for(int i = size; i >= pos; i--){
        v[i] = v[i - 1];
    }
    v[pos] = n;
}

void Vector::erase(int pos){
    
    int *nv = new int[cap];
    size--;
    
    for(int i = 0; i < size; i++){
        if(i >= pos){
            nv[i] = v[i + 1];
        }
        else{
            nv[i] = v[i];
        }
    }
    replaceVector(nv);
}

int Vector::at(int pos){
    return v[pos];
}

void Vector::replaceVector(int *nv){
    delete[] v;
    v = nv;
}

void Vector::printVector(){
    for(int i = 0; i < this->size; i++){
        cout << v[i] << " ";
    }
    cout << endl << "Size: " << this->size << endl;
    cout << "Cap: " << this->cap << endl;
    cout << endl;
}

int main(){
    
    Vector v(3);
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    
    v.printVector();
    v.insert(4, 3);
    
    v.printVector();
    
    v.erase(2);
    
    v.printVector();
}
