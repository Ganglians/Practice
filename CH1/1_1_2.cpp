#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

class hashT {
    int l;
    int *arrPtr;
    
    void erase() {
        delete [] arrPtr;
        arrPtr = new int[l];
    }
    
    bool hash(char c, int pos) {
        int h = pos % l ;
        if(arrPtr[h] == 0) {
            arrPtr[h]++;
            return true;
        }
        else
            return false;
    }
    public:
   
    hashT(int i = 1000) {
        l = i;
        arrPtr = new int[i];
    }

    bool unique(string s) {
        erase();
        int size = s.size();
        for(int i = 0; i < size; i++) {
            if(hash(s[i], i) == false)
                return false;
        }
        return true;
    }
};

int main(int argc, char *argv[]) {
    string s0 = "he//";
    string s1 = "pi";
    hashT H;
    cout << H.unique(s0) << endl;
    cout << H.unique(s1) << endl;
    return 0;
}
