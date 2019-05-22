/*
 COURSE ID:             CSC 331
 FULL NAME:             Samuel Zaldivar
 SECTION:               0900
 FILE NAME:             csc331-0900_zaldivar_prog2.cpp
 ASSIGNMENT NUMBER:     2
 DUE DATE:              03/05/2019
 PROGRAM PURPOSE:       Create an adress book using the link list data structure
 */


#include <iostream>
#include <string>
using namespace std;

struct ContactNode{
    ContactNode *headLink;
    string name;
    ContactNode *tailLink;
};

//Function Prototypes
void displayMenu();
string getUserInput();
void proccessCommand(ContactNode*&, ContactNode*&, char, string);
void addNewContact(ContactNode*&, ContactNode*&, string);
void deleteContact(ContactNode*&, ContactNode*&, string);
void listContacts(ContactNode* head);
void reverseListContacts(ContactNode* tail);

int main(){
    //Head and tail pointers for the start and end of the LinkList
    ContactNode *head = NULL;
    ContactNode *tail = NULL;
    

    char userCommand = NULL;
    
    cout << "CONTACTS LINK LIST" << endl << endl;
    do{
        displayMenu();
        string userInput = getUserInput();
        
        //Check userInput's length in order to prevent outofbounds error
        if(userInput.length() > 0){
    
            //User command is the first character of the userInput
            userCommand = toupper(userInput.at(0));
            string contactName;
            
            //Check to see if user enter a name
            if(userInput.length() > 2){
                
                if((userCommand == 'A' || userCommand == 'D') && userInput.at(1) == ' '){ //If user entered a [SPACE] between the A and D commands and contact name
                    contactName = userInput.substr(2, userInput.length() - 1);
                }
                else{
                    cout << "Please enter a [SPACE] between the command and contact name" << endl << endl;
                    continue;
                }
            }
            
            proccessCommand(head, tail, userCommand, contactName);
        }
        //User entered empty command
        else{
            cout << endl << "Please enter a command from the menu" << endl << endl;
        }
    }while(userCommand != 'Q');
}

void proccessCommand(ContactNode*& head, ContactNode*& tail, char userCommand, string contactName){
    
    switch(userCommand){
        case 'A':
            addNewContact(head, tail, contactName);
            break;
        case 'D':
            deleteContact(head, tail, contactName);
            break;
        case 'L':
            listContacts(head);
            break;
        case 'R':
            reverseListContacts(tail);
            break;
        case 'Q':
            cout << "Good Bye!" << endl << endl;
            break;
        default:
            cout << "Invalid command. Please enter a command from the menu" << endl << endl;
    }
}




void addNewContact(ContactNode*& head, ContactNode*& tail, string name){
    
    //Head is empty, so new contact becomes the head
    if(head == NULL){
        ContactNode *newContact = new ContactNode;
        newContact->name = name;
        newContact->headLink = NULL;
        newContact->tailLink = NULL;
        
        head = newContact;
        tail = newContact;
    }
    else{
        ContactNode *newContact = new ContactNode;
        newContact->name = name;
        
        ContactNode *indexNode = head; //IndexNode to where the newContact node will go in the list
        bool foundIndex = false;
        
        do{
            int compareStringValue = name.compare(indexNode->name);
            
            //If names are equal, do not add to list
            if(compareStringValue == 0){
                cout << endl << "Name not added" << endl << endl;
                return;
            }
            else if(compareStringValue < 0){ //newContact node goes before indexNode in the list
                
                if(head == indexNode){ //newContact becomes new head
                    newContact->headLink = indexNode;
                    newContact->tailLink = NULL;
                    indexNode->tailLink = newContact;
                    
                    head = newContact;
                }
                else{ //insert newContact before indexNode
                    
                    /*
                     before:
                     <- otherNode -> <- indexNode -> ......
                     
                     after:
                     <- otherNode -> <- newContact -> <- indexNode -> ......
                     */
                    
                    newContact->headLink = indexNode;
                    newContact->tailLink = indexNode->tailLink;
                    indexNode->tailLink->headLink = newContact;
                    indexNode->tailLink = newContact;
                }
                foundIndex = true;
            }
            else if(tail == indexNode){ //checked every node. newContact becomes the tail
                /*
                 before:
                 ... <- indexNode ->
                     tail -^
                 
                 after:
                 ... <- indexNode -> < newContact ->
                                        tail -^
                 */
                newContact->tailLink = indexNode;
                newContact->headLink = NULL;
                indexNode->headLink = newContact;
                tail = newContact;
                foundIndex = true;
            }
            else{ //Check next node on list
                indexNode = indexNode->headLink;
            }
        }while(!foundIndex);
    }
    cout << endl << "Name added" << endl << endl;
}




void deleteContact(ContactNode*& head, ContactNode*& tail, string name){
    
    if(head == NULL){
        cout << endl << "Empty List" << endl << endl;
        return;
    }
    
    ContactNode *currentNode = head; //Current node to check if equals name
    
    do{
        if(name.compare(currentNode->name) == 0){ //If name equals currentNode's name
            
            if(head == currentNode){
                if(currentNode->headLink == NULL){ //Only node in the list. Head becomes NULL
                    /*
                     before:
                     <- currentNode ->
                     head -^ tail -^
                     
                     after:
                     head-^ tail-^
                     */
                    delete currentNode;
                    head = NULL;
                    tail = NULL;
                }
                else{ //Node after current node becomes head
                    /*
                     before:
                     <- currentNode -> <- nextNode -> ....
                     head -^
                     
                     after:
                     <- nextNode -> ....
                     head-^
                     */
                    head = currentNode->headLink;
                    currentNode->headLink->tailLink = NULL;
                    delete currentNode;
                }
            }
            else if(tail == currentNode){ //Tail becomes previos node
                /*
                 before:
                 ... <- prevNode -> <- currentNode ->
                                    tail -^
                 
                 after:
                 ... <- prevNode ->
                        tail -^
                 */
                
                currentNode->tailLink->headLink = NULL;
                tail = currentNode->tailLink;
                delete currentNode;
            }
            else{ //delete currentNode
                
                /*
                 before:
                 .... <- currentNode -> <- nextNode -> ....
                 
                 after:
                 .... <- nextNode -> ....
                 */
                
                currentNode->tailLink->headLink = currentNode->headLink;
                currentNode->headLink->tailLink = currentNode->tailLink;
                delete currentNode;
            }
            cout << endl << "Name Deleted" << endl << endl;
            return;
        }
        else if(tail == currentNode){ //At the last node. No node equals name.
            cout << "Name not found" << endl << endl;
            return;
        }
        else{ //Check next node
            currentNode = currentNode->headLink;
        }
        
    }while(currentNode != NULL);
}





void listContacts(ContactNode* head){
    cout << endl << "Contact List" << endl;
    cout << "************" << endl;
    
    if(head == NULL){ //List is empty
        cout << "Empty" << endl << endl;
        return;
    }
    
    ContactNode *currentNode; //Current node to display
    currentNode = head;
    
    do{
        cout << currentNode->name << endl;
        currentNode = currentNode->headLink;
    }while(currentNode != NULL);
    cout << "************" << endl << endl;
}





void reverseListContacts(ContactNode* tail){
    cout << endl << "Reverse Contact List" << endl;
    cout << "********************" << endl;
    
    ContactNode *currentNode; //Current node to display
    currentNode = tail;
    
    do{
        cout << currentNode->name << endl;
        currentNode = currentNode->tailLink;
    }while(currentNode != NULL);
    cout << "********************" << endl << endl;
}




string getUserInput(){
    string userInput;
    getline(cin, userInput);
    return userInput;
}

void displayMenu(){
    cout << endl
    << "****************************************************" << endl
    << "Add Contact:            Enter A [Space] Contact Name" << endl
    << "Delete Contact:         Enter D [Space] Contact Name" << endl
    << "List Contacts:          Enter L" << endl
    << "Reverse List Contacts:  Enter R" << endl
    << "Quit:                   Enter Q" << endl
    << "****************************************************" << endl << endl;
    cout << "Enter: ";
}
