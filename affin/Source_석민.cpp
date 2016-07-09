#include <iostream>

using namespace std;

int main() {
	int T;

	cin >> T;

	for (int i = 0; i < T; i++) {
		int a, b;
		char str[1000000];

		cin >> a >> b;
		cin >> str;

		//E(X) = (aX + b) mod 26
		for (int j = 0; str[j] != '\0'; j++) {
			str[j] = 65 + (a * (str[j]-65) + b) % 26;
		}

		cout << str << endl;
	}

	return 0;
}
