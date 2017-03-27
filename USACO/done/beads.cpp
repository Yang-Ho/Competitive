/*
ID: yho1
PROG: beads
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>

using namespace::std;

int main() {
    ofstream fout("beads.out");
    ifstream fin("beads.in");

    int N;
    string beads;

    fin>>N;
    fin>>beads; 

    int optimal = 0;
    for (int i = 0; i < N; i++) {
        int r_color;
        int l_color;

        int r_index = i;
        int l_index = i - 1;
        if (l_index < 0) {
            l_index = N - 1;
        }
        int r_count = 0;
        int l_count = 0;

        r_color = beads[r_index];
        while (r_color == 'w') {
            r_count += 1;
            r_index += 1;
            if (r_index < N) {
                r_color = beads[r_index];
            } else {
                break;
            }
        }
        while (beads[r_index] == r_color || beads[r_index] == 'w') {
            r_count += 1;
            r_index += 1;
            if (r_index == N) {
                break;
            }
        }

        l_color = beads[l_index];
        while (l_color == 'w' || l_color == r_color) {
            r_count += 1;
            l_index -= 1;
            if (l_index >= 0) {
                l_color = beads[l_index];
            } else {
                break;
            }
        }
        while (beads[l_index] == l_color || beads[l_index] == 'w') {
            l_count += 1;
            l_index -= 1;
            if (l_index < 0) {
                break;
            }
        }

        int sum = l_count + r_count;
        if (sum > N) {
            sum = N;
        }
        if (sum > optimal) {
            optimal = sum;
        }
    }

    fout<<optimal<<endl;

    return 0;
}
