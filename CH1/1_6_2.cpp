/* Coder: Juan Chavez
 * Date:  7.22.2015
 * Objective: Create a method to rotate a matrix by 90 degrees.
 */

#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;

template<typename T>
void printM(T **M, int N) {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cout << M[i][j] << " ";
        }
        cout << endl;
    }
}

class rClass {
    template<typename T>
        void propagate(T **a, T &prev) {
            T tmp = prev;
            prev = **a;
            **a = tmp;
        }
    public:
    template<typename T>
        void rotate(T **M, int N) {
            int ringSt;
            int row, col;
            int rN = N;
            int rB, numTimes;
            T p;
            for(int i = 0; i < N/2; i++) {
                numTimes = rN;
                ringSt = i;
                rB = rN - ringSt;
                row = ringSt;
                col = ringSt;
                int j = 0;
                while(j < numTimes) {
                    //Top-right corner
                    if(row == ringSt && col == ringSt) {
                        j++;
                        p = M[row + 1][col];
                        propagate(M, p);
                        col++;
                    }
                    //Top edge
                    if(row == ringSt && col > ringSt && col < rB - 1) {
                        propagate(M, p);
                        col++;
                    }
                    //Top-right corner and right edge
                    if(row >= ringSt && row < rB - 1 && col == rB - 1) {
                        propagate(M, p);
                        row++;
                    }
                    //Bottom-right corner and bottom edge
                    if(row == rB - 1 && col <= rB - 1 && col > ringSt) {
                        propagate(M, p);
                        col--;
                    }
                    //Bottom-left corner and left edge
                    if(row <= rB - 1 && row > ringSt && col == ringSt) {
                        propagate(M, p);
                        row--;
                    }
                }
                rN -= 2;
            }
        }
};

int main(int argc, char *argv[]) {
    int n = 4;
    char **array;
    array = new char * [n];
    for(int i = 0; i < n; i++) {
        array[i] = new char[n];
    }
    //Initial values
    char letter = 'a';
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            array[i][j] = letter;
            letter = static_cast<char>(letter + 1);
        }
    }
    rClass r;
    r.rotate(array, n);
    printM(array, n);
    return 0;
}
