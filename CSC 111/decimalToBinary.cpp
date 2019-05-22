#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main(){
 
    int num;
    string binaryNum = "";
    
    cout << "Input a decimal number: ";
    cin >> num;
    
    if(num == 0){
        binaryNum = "0";
    }
    else{
        bool foundLargestPower = false;
        int power = 0;
        int largestNum = 0;
        
        do{
            int testPower = pow(2, power);
            
            if(testPower == num){
                largestNum = testPower;
                foundLargestPower = true;
            }
            else if(testPower > num){
                power--;
                largestNum = pow(2, power);
                foundLargestPower = true;
            }
            else{
                power++;
            }
            
        }while(!foundLargestPower);
        
        binaryNum = "1";
        num -= largestNum;
        power--;
        
        for(int i = power; i >= 0; i--){
            
            int testPower = pow(2, i);
            
            if(testPower > num){
                binaryNum += "0";
            }
            else{
                binaryNum += "1";
                num -= testPower;
            }
        }
    }
    
    cout << "The binary number is: " << binaryNum << endl << endl;
}
