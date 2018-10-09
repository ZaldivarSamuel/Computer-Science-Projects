//
//  StringCompare
//
//  Created by Samuel Zaldivar on 10/3/18.
//  Copyright © 2018 Samuel Zaldivar. All rights reserved.
//

#include <iostream>
#include<cstring>
using namespace std;

int stringCompare(char*,char*);
int getLength(char*);

int main(){
    char word1[] = "C++";
    char word2[] = "Swift";
    
    cout << strcmp(word1, word2) << endl;
    cout << stringCompare(word1, word2) << endl;
}

int stringCompare(char *word1, char *word2){
    
    const int word1Length = getLength(word1);
    const int word2Length = getLength(word2);
    int maxWordLength = 0;
    
    if(word1Length >= word2Length){
        maxWordLength = word1Length;
    }
    else{
        maxWordLength = word2Length;
    }
    
    for(int i = 0; i <= maxWordLength; i++){
        
        int word1CharDigit = static_cast<int>(*(word1 + i));
        int word2CharDigit = static_cast<int>(*(word2 + i));
        
        if(word1CharDigit - word2CharDigit != 0){
            return word1CharDigit - word2CharDigit;
        }
    }
    
    return 0;
}

int getLength(char* word){

    int i = 0;
    
    while(*(word + i) != '\0'){
        i++;
    }
    
    return i;
}
