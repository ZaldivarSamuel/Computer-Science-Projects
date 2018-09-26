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
    
    Person(){} //default constructor
    
    Person(string firstName, string lastName, int age, string occupation, string city){
        
        this->firstName = firstName;
        this->lastName = lastName;
        this->age = age;
        this->occupation = occupation;
        this->city = city;
    }
    
    ~Person(){
        cout << this->firstName << " has died" << endl;
    }
    
    void addAge(int amount){
        this->age += amount;
        cout << this->firstName << " is now " << this->age << endl;
    }
};

void fastFoward(Person**, int);

int NUM_OF_PEOPLE = 3;

int main(){
    
    //People
    Person mike("Mike", "Doe", 47, "Banker", "NYC");
    Person mary("Mary", "Doe", 45, "Secretary", "NYC");
    Person john("John", "Doe", 20, "Student", "NYC");
    
    //Pointers
    Person *mikeP = &mike;
    Person *maryP = &mary;
    Person *johnP = &john;
    
    johnP->farther= mikeP;
    johnP->mother = maryP;
    
    cout << johnP->firstName << " is a " << johnP->age << " year old " << johnP->occupation << " in " << johnP->city << endl;
    cout << johnP->firstName << "'s farther is " << johnP->farther->firstName << " and his mother is " << johnP->mother->firstName << endl << endl;
    
    Person *people[NUM_OF_PEOPLE];
    *(people + 0) = mikeP;
    *(people + 1) = maryP;
    *(people + 2) = johnP;
    
    fastFoward(people, 5);
    
    johnP->occupation = "Computer programmer";
    cout << johnP->firstName << " is now a " << johnP->occupation << endl;
    
    cout << endl;
}

void fastFoward(Person **people, int years){
    
    cout << years << " years later..." << endl;
    
    for(int i = 0; i < NUM_OF_PEOPLE; i++){
        (*(*(people + i))).addAge(years);
    }
    cout << endl;
}
