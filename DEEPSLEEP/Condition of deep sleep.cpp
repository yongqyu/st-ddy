#include <iostream>
using namespace std;

#define FLIP(A) A=='1' ? '0' : '1'

int main(){
	int N, K;
	char lights[100000];
	scanf("%d %d", &N, &K);

	scanf("\n%c", &lights[0]);
	for (int i = 1; i < N; i++){
		scanf(" %c", &lights[i]);
	}

	int count = 0;
	for (int i = 0; i < N-K+1; i++)
	{
		if (lights[i] == '0')
			continue;
		else{
			for (int j = 0; j < K; j++)
				lights[i + j] = FLIP(lights[i + j]);
			count++;
		}
	}
	for (int i = N - K; i < N; i++){
		if (lights[i] == '1'){
			cout << "Insomnia" << endl;
			return 0;
		}
	}
	cout << count << endl;
	return 0;
}