/*
	 Yang Ho
	 Postal Worker Rings Only Once (id 117)
*/

#include<iostream>
#include<string>
#include<map>
#include<climits>
#include<vector>

using namespace::std;

typedef map< char, int > mci;
typedef map< char, mci > mcmci;

typedef vector< char > vc;

typedef mcmci::iterator miter;
typedef mci::iterator mjter;

int main() {
	string input;
	while ( getline( cin, input ) ) {
		mcmci graph;
		mci weights;
		mci visited;
		int cost = 0;
		while ( input.compare( "deadend" ) != 0 ) {
			int length = input.length();
			char first = input[0];
			char last = input[length - 1];
			cost += length;
			
			graph[first][last] = length;
			graph[last][first] = length;

			weights[first] = INT_MAX;
			weights[last] = INT_MAX;

			visited[first] = 0;
			visited[last] = 0;

			getline( cin, input );
		}

		int odd = 0;
		char oddNodes[2] = ""; 
		for ( miter iter = graph.begin(); iter != graph.end(); iter++ ) {
			if ( iter->second.size() % 2 == 1 ) {
				oddNodes[odd] = iter->first;
				odd++;
			}
		}
		if ( odd == 2 ) {

			weights[oddNodes[0]] = 0;
			vc queue;
			queue.push_back( oddNodes[0] );
			while ( queue.size() > 0 ) {
				char curr = queue[0];
				queue.erase( queue.begin() );
				if ( visited[curr] == 0 ) {
					for ( mjter iter = graph[curr].begin(); iter != graph[curr].end(); iter++ ) {
						int newDist = weights[curr] + iter->second;
						if ( newDist < weights[iter->first] )
							weights[iter->first] = newDist;
						queue.push_back( iter->first );
					}
					visited[curr] = 1;
				}
			}
			cost += weights[oddNodes[1]];

		}
		cout<<cost<<"\n";
	}
	return 0;
}
