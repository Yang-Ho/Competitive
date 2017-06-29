/*
ID: yho1
PROG: transform
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace::std;

void Print(vector<string> a) {
    cout<<"~~~\n";
    for (int i = 0; i < a.size(); i++) {
        cout<<a[i]<<endl;
    }
}

vector<string> Rotate(vector<string> a) {
    vector<string> rotated(a.size());
    for (int i = 0; i < a.size(); i++) {
        for (int j = a.size() - 1; j >= 0; j--) {
            rotated[i] += a[j][i];
        }
    }
    return rotated;
}

vector<string> Flip(vector<string> a) {
    for (int i = 0; i < a.size(); i++) {
        reverse(a[i].begin(), a[i].end());
    }
    return a;
}

bool IsMatch(vector<string> a, vector<string> b) {
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    ofstream fout("transform.out");
    ifstream fin("transform.in");

    int N;
    fin>>N;
    vector<string> before(N);
    vector<string> after(N);
    for (int i = 0; i < N; i++) {
        fin>>before[i];
    }
    for (int i = 0; i < N; i++) {
        fin>>after[i];
    }

    int transform = 7;
    for (int i = 0; i < 3; i++) {
        before = Rotate(before);
        if (IsMatch(before, after)) {
            transform = i + 1;
            break;
        }
    }
    if (transform == 7) {
        before = Rotate(before);
        if (IsMatch(before, after)) {
            transform = 6;
        } else {
            before = Flip(before);
            if (IsMatch(before, after)) {
                transform = 4;
            } else {
                for (int i = 0; i < 3; i++) {
                    before = Rotate(before);
                    if (IsMatch(before, after)) {
                        transform = 5;
                        break;
                    }
                }
            }
        }
    }
    fout<<transform<<endl;

return 0;
}
