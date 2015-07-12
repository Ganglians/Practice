#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;

class hTable {
    int s;
    int *arrPtr;

    void erase() {
        delete [] arrPtr;
        arrPtr = new int[s];
    }

    public:
    hTable(int S = 100) {
        s = S;
        arrPtr = new int[S];
    }

    bool unique(string S) {
        int L = S.size();
        for(int i = 0; i < L; i++) {
            if(arrPtr[i] == 0)
                arrPtr[i]++;
            else
                return false;
        }
        return true;
    }
};

    int main(int argc, char *argv[]) {
        string s0 = "Hell", s1 = "Pi";
        hTable h;
        cout << h.unique(s0) << endl;
        cout << h.unique(s1) << endl;
        return 0;
    }


