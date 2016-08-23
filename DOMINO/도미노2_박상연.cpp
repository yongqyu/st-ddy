#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

int main(){
	int N;
	int temp1, temp2;
	vector<int> input;

	scanf("%d", &N);

	for (int i = 0; i < N; i++){
		scanf("%d %d", &temp1, &temp2);
		input.push_back(temp1+temp2);
	}
	sort(input.begin(), input.end());

	int flag = 0;
	int flag2 = 0;

	for (int i = 0; i < N; i++)
	{
		if (input[i]>9){
			input[i] -= 10;
			if (i != N - 1)
				input[i + 1]++;
			else
				flag2 = 1;
		}
	}

	if (flag2)
		cout << 1;

	for (int i = N-1; i >=0; i--)
	{
		if (flag || input[i] != 0 || i == 0){
			cout << input[i];
			if (!flag)
				flag = 1;
		}
	}

	cout << endl;
}