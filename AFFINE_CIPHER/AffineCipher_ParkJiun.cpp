#include<iostream>
#include<string>
using namespace std;

int main() {
	int T, a, b;
	int test_case;
	string plain;
	char cipher[1000000];

	scanf("%d", &T);
	for (test_case = 1; test_case <= T; test_case++) {
		cin >> a >> b;
		cin >> plain;
		for (int i = 0; i<plain.length(); i++) 
			cipher[i] = ((a*plain[i] - 65) + b) % 26 + 65;
		
		for (int i = 0; i < plain.length(); i++) cout << cipher[i];
		cout << endl;
	}
}