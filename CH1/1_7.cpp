#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void print(int **Mx, int M, int N) {
    for(int i = 0; i < M; i ++) {
        for(int j = 0; j < N; j++) {
            cout << Mx[i][j] << "   ";
        }
        cout << endl;
    }
    cout << endl;
}

//Initialize a matrix
void mInit(int **Mx, int M, int N) {
    Mx = new int*[M];
    for(int i = 0; i < M; i++) {
        Mx[i] = new int[N];
    }
}

void zeros(int **Mx, int M, int N) {
    vector<int> rows;
    vector<int> columns;
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            if(Mx[i][j] == 0) {
                if(!binary_search(rows.begin(), rows.end(), i)) {
                    rows.push_back(i);
                }
                if(!binary_search(columns.begin(), columns.end(), j)) {
                        columns.push_back(j);
                }
            }
        }
    }
    while(!rows.empty()) {
        int r = rows.back();
        rows.pop_back();
        for(int i = 0; i < N; i++) {
            Mx[r][i] = 0;
        }
    }
    while(!columns.empty()) {
        int c = columns.back();
        columns.pop_back();
        for(int i = 0; i < M; i++) {
            Mx[i][c] = 0;
        }
    }
}

int main(int argc, char *argv[]) {
    int **Mx, M = 5, N = 4;
     Mx = new int*[M];
     for(int i = 0; i < M; i++) {
        Mx[i] = new int[N];
     }

    int tmp = 10;
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            Mx[i][j] = tmp;
            tmp++;
        }
    }
    Mx[0][1] = 0;
    Mx[4][3] = 0;
    Mx[2][2] = 0;
    print(Mx, M, N);
    zeros(Mx, M, N);
    print(Mx, M, N);
    return 0;
}
