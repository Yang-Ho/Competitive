/*
ID: yho1
PROG: gift1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace::std;

int main() {
    ofstream fout("gift1.out");
    ifstream fin("gift1.in");
    
    int NP;
    fin>>NP;
    string names[NP];
    int moneys[NP];

    for (int i = 0; i < NP; i++) {
        fin>>names[i];
        moneys[i] = 0;
    }

    string name;
    int index;
    for (int i = 0; i < NP; i++) {
        fin>>name;
        for (int j = 0; j < NP; j++) {
            if (names[j] == name) {
                index = j;
                break;
            }
        }

        int amount, gifts;
        fin>>amount>>gifts;

        moneys[index] -= amount;
        if (gifts > 0) {
            moneys[index] += amount % gifts;
            amount = amount / gifts;
        }

        string gname;
        int gindex;
        for (int j = 0; j < gifts; j++) {
            fin>>gname;
            for (int k = 0; k < NP; k++) {
                if (names[k] == gname) {
                    gindex = k;
                    break;
                }
            }

            moneys[gindex] += amount;
        }
    }

    for (int i = 0; i < NP; i++) {
        fout<<names[i]<<" "<<moneys[i]<<endl;
    }

    return 0;
}
