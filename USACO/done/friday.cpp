/*
ID: yho1
PROG: friday
LANG: C++
*/
#include <iostream>
#include <fstream>

using namespace::std;

int START_YEAR = 1900;

int main() {
    ofstream fout("friday.out");
    ifstream fin("friday.in");

    int N;
    fin>>N;

    int counts[7] = {0,0,0,0,0,0,0};
    int day = 0;
    int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for (int year = START_YEAR; year < START_YEAR + N; year++) {
        bool leap_year = false;
        if (year % 4 == 0) {
            if (year % 100 == 0) { 
                if (year % 400 == 0) {
                    leap_year = true;
                }
            } else {
                leap_year = true;
            }
        }
        for (int m = 0; m < 12; m++) {
            counts[(day + 12) % 7] += 1;
            day += months[m];
            if (m == 1) {
                if (leap_year) {
                    day += 1;
                }
            }
        } 
    }

    fout<<counts[5]<<" ";
    fout<<counts[6]<<" ";
    fout<<counts[0]<<" ";
    fout<<counts[1]<<" ";
    fout<<counts[2]<<" ";
    fout<<counts[3]<<" ";
    fout<<counts[4]<<endl;
    return 0;
}
