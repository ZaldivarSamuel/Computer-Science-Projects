//
//  matrix.cpp
//  Multiply two matrices together
//
//  Created by Samuel Zaldivar on 8/27/18.

#include <iostream>
using namespace std;

int main(){
    
    const int SIZE1 = 2;
    const int SIZE2 = 3;

    int m1[SIZE1][SIZE2] = {{1,2,3},
                            {4,5,6}};
    
    int m2[SIZE2][SIZE1] = {{7,8},
                            {9,10},
                            {11, 12}};
    
    int m3[SIZE1][SIZE1];
    
    cout << "Multiplying matrix 1 and matrix 2..." << endl << endl;
    
    //Loop over every row in m1
    for(int m1Row = 0; m1Row < SIZE1; m1Row++){
        
        int sum = 0; //variable to store in the new matrix
        
        //Loop over ever col in m2
        for(int m2Col = 0; m2Col < SIZE1; m2Col++){
            
            //Loop over every col in m1
            for(int m1Col = 0; m1Col < SIZE2; m1Col++){
                
                /*
                 The col in m2 stays the same in this iteration so we can multiply every element in m1row by every
                 element in m2col
                 */
                sum += m1[m1Row][m1Col] * m2[m1Col][m2Col];
            }
            //Assign sum to m3 and reset sum to 0
            m3[m1Row][m2Col] = sum;
            sum = 0;
        }
    }
    
    //Output m3
    cout << "New matrix: " << endl;
    for(int m3Row = 0; m3Row < SIZE1; m3Row++){
        for(int m3Col = 0; m3Col < SIZE1; m3Col++){
            cout << m3[m3Row][m3Col] << "  ";
        }
        cout << endl;
    }
    cout << endl;
}
