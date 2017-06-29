/*
ID: yho1
PROG: milk2
LANG: C++
*/
#include <iostream>
#include <fstream>

using namespace::std;

void sort(int s[], int e[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (s[i] > s[j]) {
                int temp = s[i];
                s[i] = s[j];
                s[j] = temp;

                temp = e[i];
                e[i] = e[j];
                e[j] = temp;
            }
        }
    }
}

int main() {
    ofstream fout("milk2.out");
    ifstream fin("milk2.in");

    int N;
    fin>>N;

    int starts[N];
    int ends[N];
    int index = 0;
    for (int i = 0; i < N; i++) {
        fin>>starts[i]>>ends[i];
    }

    sort(starts, ends, N);

    int idle_time = 0;
    int milking_time = 0;

    int start_time = starts[0];
    int end_time = ends[0];
    for (int i = 1; i < N; i++) {
        if (starts[i] <= end_time) {
            if (ends[i] > end_time) {
                end_time = ends[i];
            }
        } else {
            int milk = end_time - start_time;
            if (milk > milking_time) {
                milking_time = milk;
            }
            int idle = starts[i] - end_time;
            if (idle > idle_time) {
                idle_time = idle;
            }
            start_time = starts[i];
            end_time = ends[i];
        }
    }
    int milk = end_time - start_time;
    if (milk > milking_time) {
        milking_time = milk;
    }

    fout<<milking_time<<" "<<idle_time<<endl;

    return 0;
}
