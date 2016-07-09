#include <iostream>
#include <string>

using namespace std;

int main(){
	int a, b, T, X;
	int input_len;
	string input;
	string output;
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		scanf("%d %d", &a, &b);
		cin>> input;

		output.clear();
		input_len = input.size();
		for (int j = 0; j < input_len; j++)
		{
			output += ((a*(input[j] - 'A')) + b) % 26 + 'A';
		}
		cout << output << endl;
	}
}

