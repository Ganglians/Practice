#include <iostream>
#include <string>
using namespace std;
class sClass {
    public:
        bool permutation(string s1, string s2) {
            int l = 500;
            int hTable[l] = {0};
            int pos;
            if(s1.size() != s2.size()) {
                return false;
            }
            int size = s1.size();
            for(int i = 0; i < size; i++) {
                pos = s1[i] % l;
                hTable[pos]++;
                pos = s2[i] % l;
                hTable[pos]++;
            }
            for(int i = 0; i < l; i++) {
                if((hTable[i] % 2) != 0) {
                    return false;
                }
            }
            return true;
        }
};

int main(int argc, char *argv[]) {
    string s1 = "cat", s2 = "tac", s3 = "pi";
    sClass sc;
    cout << sc.permutation(s1, s2) << endl;
    cout << sc.permutation(s1, s3) << endl;
    return 0;
}
