#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main(){
	int N;
	int cluster_size;
	long long temp;
	vector<long long> input;
	long long count;

	scanf("%d", &N);
	for (int i = 1; i <= N; i++){
		scanf("%lld", &temp);
		input.push_back(temp);
	}

	scanf("%d", &cluster_size);
	count = 0;
	for (int i = 0; i < N; i++){
		count += input[i] / cluster_size;
		if (input[i]%cluster_size != 0)
			count++;
	}

	cout << count * cluster_size << endl;
}