/*
	 Yang Ho
	 My attempt at the 3n + 1 problem (id 100)
*/

#include <iostream>
#include <algorithm>

using namespace::std;

int main() {
	int i, j;
	int vals[1000001];
	while ( cin>>i>>j ) {
		cout<<i<<" "<<j<<" ";
		int max = 0;
		if ( i > j ) {
			swap(i,j);
		}
		while ( i <= j ) {
			int n = i;

			int cycle = 1;
			if ( vals[n] == 0 ) {
				while ( n > 1 ) {
					int on = n;
					if ( n % 2 == 0 )
						n = n / 2;
					else if ( n != 1 ) 
						n = 3 * n + 1;
					cycle++;
				}
			} else
				cycle = vals[n];

			if ( cycle > max ) 
				max = cycle;

			i++;
		}
		cout<<max<<"\n";
	}
	return 0;
}
