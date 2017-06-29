#include <iostream>
#include <string>

using namespace::std;

int main() {
    int T = 100;
    for (int i = 0; i < T; i++) {
        string N;
        cin>>N;
        int j = 1;
        while (j < N.length()) {
            int previous = N[j-1];
            int current = N[j];
            if (current < previous) {
                cout<<"ERRROR!!!\n";
            }
            j++;
        }
    }
    return 0;
}
