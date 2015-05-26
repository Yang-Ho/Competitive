/*
	 Yang Ho
	 The Psychic Poker Player (id 131) 
*/

#include<iostream>
#include<string>
#include<map>
#include<vector>

using namespace::std;

struct card {
	int value;
	int suit;

	card( int v, int s ) {
		value = v;
		suit = s;
	}
};

typedef vector< card > vc;

card getCard( char val, char suit ) {
	int v, s;
	switch(val) {
		case '1':
			v = 1;
		case '2':
			v = 2;
		case '3':
			v = 3;
		case '4':
			v = 4;
		case '5':
			v = 5;
		case '6':
			v = 6;
		case '7':
			v = 7;
		case '8':
			v = 8;
		case '9':
			v = 9;
		case 'T':
			v = 10;
	}
	switch(suit) {
		case 'C':
			s = 1;
		case 'D':
			s = 2;
		case 'H':
			s = 3;
		case 'S':
			s = 4;
	}
	return card( v, s );
}

int main() {
	char val;
	char suit;	
	while( cin>>val>>suit ) {
		vc hand;
		vc deck;
		for( int i = 0; i < 4; i++ ) {
			hand.push_back( getCard( val, suit ) );	
			cin>>val>>suit;
		}
		for( int i = 0; i < 4; i++ ) {
			deck.push_back( getCard( val, suit ) );	
			cin>>val>>suit;
		}

		cout<<"Hand: ";
		for( int i = 0; i < 5; i++ )
			cout<<hand[i].value<<hand[i].suit<<" ";
		cout<<"Deck: ";
		for( int i = 0; i < 5; i++ )
			cout<<deck[i].value<<deck[i].suit<<" ";
		cout<<"Best Hand: ";

		int best = 1;

		switch(best) {
			case 9:
				cout<<"straight flush\n";
			case 8:
				cout<<"four-of-a-kind\n";
			case 7:
				cout<<"full-house\n";
			case 6:
				cout<<"flush\n";
			case 5:
				cout<<"straight\n";
			case 4:
				cout<<"three-of-a-kind\n";
			case 3:
				cout<<"two-pair\n";
			case 2:
				cout<<"one-pair\n";
			case 1:
				cout<<"highest-card\n";
		}

	}

	return 0;
}
