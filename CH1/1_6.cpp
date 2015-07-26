#include <stdlib.h>
#include <string>
#include <iostream>
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
            void propagate(T **M, int r, int c, T tmp1, T tmp2) {
                tmp2 = M[r][c];
                M[r][c] = tmp1;
                tmp1 = tmp2;
            }

    public:
        template<typename T>
            void rotate(T **M, int N) {
                int ringSt;
                int row, col;
                int ringBound, rN, numTimes;
                rN = N;
                for(int i = 0; i < N/2; i++) {
                    ringSt = i;
                    row = col = ringSt;
                    numTimes = rN - 1;
                    int j = 0;
                    T tmp1, tmp2;
                    tmp1 = M[ringSt][ringSt];
                    while(j < rN) {
                        //Top-Left Corner
                        if(row == ringSt && col == ringSt) {
                            tmp1 = M[row][col];
                            j++;
                            col++;
                        }
                        //Top Edge
                        if(row == ringSt && col > ringSt && col < rN-1) {
                            propagate(M, row, col, tmp1, tmp2);
                            col++;
                        }
                        //Top-Right Corner
                        if(row == ringSt && col == rN-1) {
                            propagate(M, row, col, tmp1, tmp2);
                            row++;
                        }
                        //Right Edge
                        if(row > ringSt && row < rN-1 && col == rN-1) {
                            propagate(M, row, col, tmp1, tmp2);
                            row++;
                        }
                        //Bottom-Right Corner
                        if(row == rN-1 && col == rN-1) {
                            propagate(M, row, col, tmp1, tmp2);
                            col--;
                        }
                        //Bottom Edge
                        if(row == rN-1 && col > ringSt && col < rN-1) {
                            propagate(M, row, col, tmp1, tmp2);
                            col--;
                        }
                        //Bottom-Left Corner
                        if(row == rN-1 && col == ringSt) {
                            propagate(M, row, col, tmp1, tmp2);
                            row--;
                        }
                        //Left Edge
                        if(row > ringSt && row < rN-1 && col == ringSt) {
                            propagate(M, row, col, tmp1, tmp2);
                            row--;
                        }
                        //printM(M, N);
                        //cout << endl;
                    }
                    rN-=2;
                }
            }
};

int main(int argc, char *argv[]) {
    int n = 4;
    char **array;
    array = new char *[n];
    //Initialize array
    for(int i = 0; i < n; i++) {
        array[i] = new char [n];
    }
    char letter = 'a';
    //Initialize parameters
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

