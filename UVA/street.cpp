/*
	 Yang Ho
	 Street Address problem (id 138)
*/
#include <iostream>
#include <iomanip>

using namespace::std;

int main() {
	int count = 0;

	unsigned long long int lowSum = 1;
	long long int last = 3;
	long long int i = 2;
	unsigned long long int highSum = 0;

	while ( count != 10 ) {
		if ( lowSum == highSum ) {
			cout<<right<<setw(10)<<i;
			cout<<right<<setw(10)<<last<<"\n";
			count++;
			i *= 5.828427;
			lowSum = i * ( i - 1) / 2;
		}

		lowSum += i;
		i++;
		last = i + 1;
		highSum = last;

		while ( highSum < lowSum ) {
			last++;
			highSum += last;
		}
	}
	return 0;
}
