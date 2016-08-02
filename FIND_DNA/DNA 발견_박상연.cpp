#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

#define FLIP(X) (X == 'A'? 'B' : 'A')
#define AHLPABET(X) (flip==0 ? X : FLIP(X))

int flip;

int main(){
	int N, count;
	char input[1000000];

	scanf("%d", &N);
	scanf("%s", input);

	flip = 0;
	count = 0;

	for (int i = N-1; i >= 0 ; i--)
	{	
		if (AHLPABET(input[i]) == 'A')
			continue;
		else if (i >=1 && (AHLPABET(input[i]) == 'B') && (AHLPABET(input[i - 1]) == 'B')){
			count++;
			flip = (flip ? 0 : 1);
		}
		else
			count++;
	}
	cout << count << endl;
}