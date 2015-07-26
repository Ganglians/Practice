/* Coder: Juan Chavez
 * Date:  7.21.2015
 * Objective: Figure out how to pass 2D pointer values to a function and 
 * edit them by reference.
 */
 
#include <stdlib.h>
#include <iostream>
using namespace std;

void swap(int **a, int **b) {
    int **tmp = a;
    **a = **b;
    **b = **tmp;
}

int main(int argc, char *argv[]) {
    int **a; //Pointer-of-pointers 2D array
    a = new int*[10];
    for(int i = 0; i < 10; i++) {
        a[i] = new int[10];
    }
    //Init values
    int val = 0;
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            a[i][j] = val;
            val++;
        }
    }
    //Call function in question
    swap(a[0][0], a[0][1]);
    //Print
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
