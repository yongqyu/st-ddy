#include <iostream>
using namespace std;

int main(){
	int testcase;
	cin >> testcase;
	for (int i = 0; i < testcase; i++){
		int N, K, current = 0, jump = 0;
		cin >> N;
		int *arr = new int[N+1];
		arr[0] = 0;
		for (int j = 1; j < N+1; j++){
			cin >> arr[j];
		}
		cin >> K;
		while (current != N){
			for (int j = current+1; j < N+1; j++){
				if (arr[j] - arr[current] > K && j!=current+1){
					current = j - 1;
					jump++;
					break;
				}
				else if (arr[j] - arr[current] > K){
					jump = -1;
					break;
				}
				else if(j==N && arr[j]-arr[current]<=K){
					current = N;
					jump++;
					break;
				}
			}
			if (jump == -1)break;
		}
		cout << "Case #" << i + 1 << endl;
		cout << jump << endl;
	}
	return 0;
}