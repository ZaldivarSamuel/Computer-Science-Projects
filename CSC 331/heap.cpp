/*
 COURSE ID:             CSC 331
 FULL NAME:             Samuel Zaldivar
 SECTION:               0900
 FILE NAME:             csc331-0900_zaldivar_prog4.cpp
 ASSIGNMENT NUMBER:     4
 DUE DATE:              04/17/2019
 PROGRAM PURPOSE:       Create a work order schedule using a heap
 */

#include <iostream>
#include <string>
using namespace std;

class WorkOrder{
public:
    static int numberOfOrders;
    
    int priorityNum;
    int orderNum;
    string customerName;
    string order;
    
    WorkOrder(){}
    
    WorkOrder(string name, char warrenty, string year){
        /*
         A warranty repair order (i.e., warranty code = ‘y’) is assigned priority 1 (highest).
         A non-warranty repair for a computer model less than 6 years old is assigned priority 2.
         A non-warranty repair order for a computer model older than 5 years is assigned a priority 3 (lowest)
         */
        
        this->customerName = name;
        numberOfOrders++;
        orderNum = numberOfOrders;
        priorityNum = calcPriorityNum(warrenty, year);
        generateOrderString();
    }
    
    int calcPriorityNum(char w, string y){
        if(w == 'y')
            return 1;
        
        const int CURRENT_YEAR = 2019;
        
        int year = stoi(y);
        if(CURRENT_YEAR - year < 6)
            return 2;
        return 3;
    }
    
    void generateOrderString(){
        order += to_string(priorityNum) += "-";
    
        if(orderNum < 9){
            order += "00"; order += to_string(orderNum);
        }
        else if(orderNum < 99){
            order += "0"; order += to_string(orderNum);
        }
        else{
            order += to_string(orderNum);
        }
        
        order += "-"; order += customerName;
    }
};

int WorkOrder::numberOfOrders = 0;



class Heap{
private:
    int count = 0;
    int EOL = 0;               //End of Line index
    WorkOrder *heap[10];       //Array of 10 elements
public:
    void push(WorkOrder*);
    void pop();
    int getCount();
};

void Heap::push(WorkOrder *order){
    
    if(count == 10){
        cout << "Error: Queue is full" << endl;
        return;
    }
    
    heap[EOL] = order;
    int newNodeIndex = EOL;
    EOL++;
    count++;
    
    while(newNodeIndex){
        int parentNodeIndex = (newNodeIndex - 1) / 2;
        if(heap[parentNodeIndex]->priorityNum > order->priorityNum){
            WorkOrder *temp = heap[parentNodeIndex];
            heap[parentNodeIndex] = order;
            heap[newNodeIndex] = temp;
        }
        else
            return;
        newNodeIndex = parentNodeIndex;
    }
}

void Heap::pop(){
    if(count == 0)
        cout << "Heap is empty" << endl;
    else if(count == 1){
        cout << heap[0]->customerName << endl;
        count = 0; EOL = 0;
        heap[0] = 0;
    }
    else if(count == 2){
        cout << heap[0]->customerName << endl;
        count--; EOL--;
        heap[0] = heap[1]; heap[1] = 0;
    }
    else{
        cout << heap[0]->customerName << endl;
        count--; EOL--;
        heap[0] = heap[EOL]; heap[EOL] = 0;
        
        int nodeIndex = 0;
        int leftChildIndex = (2 * nodeIndex) + 1, rightChildIndex = (2 * nodeIndex) + 2;
        
        do{
            
            if(heap[rightChildIndex] != NULL){
                //Check both
                
                if( (heap[nodeIndex]->priorityNum > heap[leftChildIndex]->priorityNum) ||
                    (heap[nodeIndex]->priorityNum > heap[rightChildIndex]->priorityNum)){
                
                    if(heap[leftChildIndex]->priorityNum < heap[rightChildIndex]->priorityNum){
                        WorkOrder *temp = heap[nodeIndex];
                        heap[nodeIndex] = heap[leftChildIndex];
                        heap[leftChildIndex] = temp;
                        nodeIndex = leftChildIndex;
                    }
                    else if(heap[leftChildIndex]->priorityNum == heap[rightChildIndex]->priorityNum){
                        if(heap[leftChildIndex]->orderNum < heap[rightChildIndex]->orderNum){
                            WorkOrder *temp = heap[nodeIndex];
                            heap[nodeIndex] = heap[leftChildIndex];
                            heap[leftChildIndex] = temp;
                            nodeIndex = leftChildIndex;
                        }
                        else{
                            WorkOrder *temp = heap[nodeIndex];
                            heap[nodeIndex] = heap[rightChildIndex];
                            heap[rightChildIndex] = temp;
                            nodeIndex = rightChildIndex;
                        }
                    }
                    else{
                        WorkOrder *temp = heap[nodeIndex];
                        heap[nodeIndex] = heap[rightChildIndex];
                        heap[rightChildIndex] = temp;
                        nodeIndex = rightChildIndex;
                    }
                
                    leftChildIndex = (2 * nodeIndex) + 1; rightChildIndex = (2 * nodeIndex) + 2;
                }
            }
            else{
                //Check Left
                if(heap[nodeIndex]->priorityNum > heap[leftChildIndex]->priorityNum){
                    WorkOrder *temp = heap[nodeIndex];
                    heap[nodeIndex] = heap[leftChildIndex];
                    heap[leftChildIndex] = temp;
                    nodeIndex = leftChildIndex;
                }
                leftChildIndex = (2 * nodeIndex) + 1; rightChildIndex = (2 * nodeIndex) + 2;
            }
            

        }while(rightChildIndex < EOL);
    }
}

int Heap::getCount(){
    return count;
}



//FUNCTION PROTOTYPES
void displayWelcomeMssg();
bool processInput(string, char&, string&, string&);
bool checkWarrenty(char);
void showErrorMessage();
bool checkYear(string&);


int main(){
    displayWelcomeMssg();
    string input;
    
    Heap workHeap;
    
    do{
        cout << "Input: "; getline(cin, input);
        if(input != "end-of-file"){
            if(input == "service"){
                workHeap.pop();
            }
            else{
                char warrenty;
                string year;
                string name;
                
                if(processInput(input, warrenty, year, name)){
                    WorkOrder *w = new WorkOrder(name, warrenty, year);
                    //Add to heap
                    workHeap.push(w);
                }
            }
        }
        else{
            cout << "There are " << workHeap.getCount() << " repair orders in the queue." << endl;
        }
    }while(input != "end-of-file");
}

bool processInput(string s, char &warrenty, string &year, string &name){
    
    warrenty = *(s.end() - 1); //Last charater is warrentys
    
    if(!checkWarrenty(warrenty)){ //Check warrenty
        showErrorMessage();
        return false;
    }
    
    year = string(s.end() - 7, s.end() - 1); //get year from input
    if(!checkYear(year)){
        showErrorMessage();
        return false;
    }
    
    name = string(s.begin(), s.end() - 7); //The rest of the charaters is the name
    return true;
}

//Wil return true if warrenty is in correct format
bool checkWarrenty(char w){
    return w == 'y' || w == 'n';
}

//Will retrun true if the year is in correct format
bool checkYear(string &y){
    if(y.length() != 6)
        return false;
    else if( *(y.begin()) != '-' || *(y.end() - 1) != '-' )
        return false;
    else{
        string yearNum(y.begin() + 1, y.end() - 1);
    
        for(int i = 0; i < yearNum.length(); i++){
            char num = yearNum[i];
            if(num < 48 || num > 57){
                return false;
            }
        }
        y = yearNum;
    }
    return true;
}

void displayWelcomeMssg(){
    cout << "*********************************************************************************************" << endl;
    cout << "* Computer Repair Schedule                                                                  *" << endl;
    cout << "* Enter a new repair order in the following format: [CUSTOMER NAME]-[MODEL YEAR]-[Warranty] *" << endl;
    cout << "* To service a repair order enter: service                                                  *" << endl;
    cout << "* To end the work day enter: end-of-file                                                    *" << endl;
    cout << "*********************************************************************************************" << endl;
}

void showErrorMessage(){
    cout << "Invalid input" << endl;
}
