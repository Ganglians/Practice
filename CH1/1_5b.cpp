#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class cClass {
    public:
        void compress(string &s) {
            int count = 1, length = s.size(), previous;
            string cs;
            bool compressed = false;
            for(int i = 1; i <= length; i++) {
                previous = i-1;
                if(s[previous] == s[i]) {
                    compressed = true;
                    count++;
                }
                else {
                    ostringstream oss;
                    oss << count;
                    cs += s[previous];
                    cs += oss.str();
                    count = 1;
                }
            }
            if(compressed) {
                s = cs;
            }
        }
};

int main(int arc, char *argv[]) {
    string s0 = "aabcccccaaa", s1 = "aabcccccaaab", s2 = "asdf";
    cClass cc;
    cc.compress(s0);
    cc.compress(s1);
    cc.compress(s2);
    cout << s0 << endl << s1 << endl << s2 << endl;
    return 0;
}
