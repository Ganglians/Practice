#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class cClass {
    public:
        void compress(string &s) {
            int length = s.size();
            int count = 1;
            bool compressed = false;
            string c;
            for(int i = 0; i < length - 1; i++) {
                if(s[i] == s[i+1]) {
                    count++;
                    compressed = true;
                }
                if(s[i] != s[i+1] || i == length - 2) {
                    c += s[i];
                    ostringstream ss;
                    ss << count;
                    c += ss.str();
                    count = 1;
                }
            }
            if(compressed) {
                s = c;
            }
        }
};

int main(int argc, char *argv[]) {
    string s0 = "aabcccccaaabb", s1 = "asdf";
    cClass cc;
    cc.compress(s0);
    cc.compress(s1);
    cout << s0 << endl << s1 << endl;
    return 0;
}
