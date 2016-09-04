#include <iostream>
#include <cstdio>

using namespace std;

int input[1000];

int main(){
	int N, temp;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &input[i]);
	for (int i = 0; i < N; i++){
		scanf("%d", &temp);
		input[i] = temp - input[i];
	}
	int count = 0;
	int index;
	for (int i = 0; i < N; i++){
		if (input[i] == 0)
			continue;
		index = i;
		count++;
		if (input[i]>0){
			while (index < N){
				if (input[index] <= 0)
					break;
				else
					input[index++] -= 1;
			}

		}
		else{
			while (index < N){
				if (input[index] >= 0)
					break;
				else
					input[index++] += 1;
			}
		}
		i--;
	}

	cout << count << endl;
}