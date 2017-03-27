/*
ID: yho1
PROG: namenum
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>

using namespace::std;

map<string, vector<string> > dict;

char letters[8][3] = {
    {'A', 'B', 'C'},
    {'D', 'E', 'F'},
    {'G', 'H', 'I'},
    {'J', 'K', 'L'},
    {'M', 'N', 'O'},
    {'P', 'R', 'S'},
    {'T', 'U', 'V'},
    {'W', 'X', 'Y'}};

char GetNumber(char c) {
    for (int i = 0; i < 8; i++) {
        if (c >= letters[i][0] && c <= letters[i][2]) {
            return '0' + i + 2;
        }
    }
}

string Convert(string n) {
    string num_form;
    for (int i = 0; i < n.length(); i++) {
        num_form += GetNumber(n[i]);
    }
    return num_form;
}

int main() {
    ifstream nin("dict.txt");
    string name;
    string number;
    while(nin>>name) {
        number = Convert(name);
        dict[number].push_back(name);
    }

    ofstream fout("namenum.out");
    ifstream fin("namenum.in");

    fin>>number;


    if (dict[number].size() > 0) {
        for (int i = 0; i < dict[number].size(); i++) {
            fout<<dict[number][i]<<endl;
        }
    } else {
        fout<<"NONE\n";
    }

    return 0;
}
