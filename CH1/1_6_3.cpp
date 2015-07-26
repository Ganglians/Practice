/* Coder: Juan Chavez
 * Date:  7.22.2015
 * Objective: Rotate a matrix 90 degrees.
 */

#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

template <typename T>
    void printM(T **M, int N) {
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                cout << M[i][j] << " ";
            }
            cout << endl;
        }
    }

class rClass {
    template <typename T>
        void propagate(T &pos, T &prev);
    public:
    template <typename T>
        void rotate(T **M, int N);
};

int main(int argc, char *argv[]) {
    int N = 2;
    char **M;
    M = new char*[N];
    for(int i = 0; i < N; i++) {
        M[i] = new char[N];
    }
    char letter = 'a';
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            M[i][j] = letter;
            letter = static_cast<char>(letter + 1);
        }
    }
    printM(M, N);
    cout << endl;
    rClass r;
    r.rotate(M, N);
    printM(M, N);
    return 0;
}

//Move letters one space forward (keeping them in line).
template <typename T>
void rClass::propagate(T &pos, T &prev) {
    T temp = prev;
    prev = pos;
    pos = temp;
}

template <typename T>
void rClass::rotate(T **M, int N) {
    bool first;
    int row, col;
    int rS; //Ring start (@ Upper left corner).
    int rN = N - 1;
    int numR = N/2; //Number of rings.
    int shiftNum; //How much shift/ring.
    T p;
    for(int i = 0; i < numR; i++) {
        first = true;
        rS = i;
        shiftNum = rN - rS;
        row = col = rS;
        int j = 0;
        while(j <= shiftNum) {
            //Upper-left corner
            if(row == rS && col == rS) {
				j++;
                if(first) {
                    p = M[row][col];
                    M[row][col] = M[row + 1][col];
                    col++;
                    continue;
                }
                propagate(M[row][col], p);
                col++;
            }
            //Upper edge
            if(row == rS && col > rS && col < rN) {
                propagate(M[row][col], p);
                col++;
            }
            //Upper-right corner & right edge
            if(row >= rS && row < rN && col == rN) {
                propagate(M[row][col], p);
                row++;
            }
            //Lower-right corner & lower edge
            if(row == rN && col <= rN && col > rS) {
                propagate(M[row][col], p);
                col--;
            }
            //Lower-left corner & left edge
            if(row <= rN && row > rS && col == rS) {
                if(first && row == rS + 1) {
					M[row][col] = p;
                    first = false;
                    row--;
                    continue;
                }
                propagate(M[row][col], p);
                row--;
            }
            printM(M, N);
            cout << endl;
		}
		rN--;
	}
}
