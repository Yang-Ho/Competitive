/*
ID: yho1
PROG: sort3
LANG: C++
*/
#include <iostream>
#include <fstream>

using namespace::std;

int main() {
    ofstream fout("sort3.out");
    ifstream fin("sort3.in");

    int N;
    fin>>N;
    int values[N];
    int ones = 0;
    int twos = 0; 
    for (int i = 0; i < N; i++) {
        values[i] = 0;
        int value;
        fin>>value;
        values[i] = value;
        if (value == 1)
            ones += 1;
        else if (value == 2)
            twos += 1;
    }
    int next_one = 0;
    int next_two = ones;

    int exchanges = 0;
    while (next_one < ones) {
        if (values[next_one] == 1) {
            next_one += 1;
        } else {
            if (values[next_one] == 2) {
                for (int index = ones; index < N; index++) {
                    if (values[index] == 1) {
                        exchanges += 1;
                        int temp = values[index];
                        values[index] = values[next_one];
                        values[next_one] = temp;
                        break;
                    }
                }
            } else {
                for (int index = N - 1; index >= ones; index--) {
                    if (values[index] == 1) {
                        exchanges += 1;
                        int temp = values[index];
                        values[index] = values[next_one];
                        values[next_one] = temp;
                        break;
                    }
                }
            }
        }
    }
    
    for (int i = ones; i < N; i++) {
        if (values[i] == 2) 
            if (i >= twos + ones) {
                exchanges += 1;
                while (values[next_two] == 2)
                    next_two += 1;
                int temp = values[next_two];
                values[next_two] = values[i];
                values[i] = temp;
                next_two += 1;
            }
    }

    fout<<exchanges<<'\n';

    return 0;
}
