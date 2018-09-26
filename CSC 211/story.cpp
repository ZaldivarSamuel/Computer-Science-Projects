#include <iostream>
using namespace std;

struct Person{
    
    string firstName;
    string lastName;
    int age;
    string occupation;
    string city;
    
    //Family
    Person *farther;
    Person *mother;
    
    Person(string firstName, string lastName, int age, string occupation, string city){
        
        this->firstName = firstName;
        this->lastName = lastName;
        this->age = age;
        this->occupation = occupation;
        this->city = city;
    }
    
    void addAge(int amount){
        this->age += amount;
        cout << this->firstName << " is now " << this->age << endl;
    }
};

void fastFoward(Person*,int);

int main(){
    
    Person mike("Mike", "Doe", 47, "Banker", "NYC");
    Person john("John", "Doe", 20, "Student", "NYC");
    
    cout << john.firstName << " is a " << john.age << " year old " << john.occupation << " in " << john.city << endl;
    
    john.farther = &mike;
    
    cout << john.firstName << "'s farther is " << john.farther->firstName << " who is a " << john.farther->occupation << endl;
    
    Person family[2] = {mike, john};
    fastFoward(family, 5);
    
    john.occupation = "Computer Programmer";
    
    cout << endl << john.firstName << " is now a " << john.occupation << endl;
    
    cout << endl;
}

void fastFoward(Person *people, int years){
   
    cout << endl << "Fast foward " << years << " years..." << endl;
    
    for(int i = 0; i < 2; i++){
        (*(people + i)).addAge(years);
    }
}
