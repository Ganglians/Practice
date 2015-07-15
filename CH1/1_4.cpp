#include <iostream>
#include <cstring>
using namespace std;

class mClass {
    public:
        void rep(char *c, int l) {
            char r[l];
            int j = 0;
            for(int i = 0; i < l - 1; i++ ) {
                if(c[i] == ' ') {
                    r[j] = '%';
                    j++;
                    r[j] = '2';
                    j++;
                    r[j] = '0';
                    j++;
                }
                else {
                    r[j] = c[i];
                    j++;
                }
            }
                for(int i = 0; i < strlen(r); i++) {
                    c[i] = r[i];
                }
                c[l-1] = '\0';
        }
};

int main(int argc, char *argv[]) {
    char c0[4] = " ";
    char c1[50] = "Hello world";
    char c2[50] = "Mr John Smith";
    mClass mc;
    mc.rep(c0, 4);
    mc.rep(c1, 50);
    mc.rep(c2, 50);
    cout << c0 << endl;
    cout << c1 << endl;
    cout << c2 << endl;
    return 0;
}
