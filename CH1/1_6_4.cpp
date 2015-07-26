/* Coder: Juan Chavez
 * Date:  7.23.2015
 * Objective: Rotate a matrix 90 degrees
 */

#include <stdlib.h>
#include <iostream>
using namespace std;

//2D array print function
template <typename T>
print(T **M, int N) {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cout << M[i][j] << " ";
        }
        cout << endl;
    }
}

class rClass {
    template<typename T>
        void propagate(T &pos, T&prev);
    public:
    template<typename T>
        void rotate(T **M, int N);
};

int main(int argc, char *argv[]) {
    char **M;
    int N = 5;
    M = new char *[N];
    for(int i = 0; i < N; i++) {
        M[i] = new char [N];
    }
    char letter = 'a';
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            M[i][j] = letter;
            letter = static_cast<char>(letter + 1);
        }
    }
    rClass r;
    r.rotate(M, N);
    print(M, N);
    return 0;
}

template <typename T>
void rClass::propagate(T &pos, T&prev) {
    T tmp = pos;
    pos = prev;
    prev = tmp;
}

template <typename T>
void rClass::rotate(T **M, int N) {
    int row, col;
    int rS, rN = N - 1, rings = N/2;
    int spins;
    T prev;
    bool first;
    for(int i = 0; i < rings; i++) {
        rS = i;
        spins = rN - rS;
        row = col = rS;
        int j = 0;
        first = true;
        while(j <= spins) {
            //Top-left corner
            if(row == rS && col == rS) {
                if (first) {
                    prev = M[row][col];
                    first = false;
                }
                else {
                    M[row][col] = prev;
                }
                j++;
                col++;
                continue;
            }
            //Top edge
            if(row == rS && col > rS && col < rN) {
                propagate(M[row][col], prev);
                col++;
            }
            //Top-right corner and right edge
            if(row >= rS && row < rN && col == rN) {
                propagate(M[row][col], prev);
                row++;
            }
            //Lower-right corner and lower edge
            if(row == rN && col <= rN && col > rS) {
                propagate(M[row][col], prev);
                col--;
            }
            //Lower-left corner and left edge
            if(row <= rN && row > rS && col == rS) {
                propagate(M[row][col], prev);
                row--;
            }
        }
        rN--;
    }
}
