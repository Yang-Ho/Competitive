/*
ID: yho1
PROG: ride
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace::std;

int main() {
    ofstream fout("ride.out");
    ifstream fin("ride.in");
    
    string line1;
    string line2;
    fin>>line1;
    fin>>line2;
   
    int group = 1;
    int comet = 1;

    for (int i = 0; i < line1.length(); i++) {
        group *= (line1[i] - 'A' + 1);
    }
    for (int i = 0; i < line2.length(); i++) {
        comet *= (line2[i] - 'A' + 1);
    }

    if (group % 47 == comet % 47)
        fout<<"GO\n";
    else
        fout<<"STAY\n";

    return 0;
}
