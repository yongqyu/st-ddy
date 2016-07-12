#include<iostream>
using namespace std;

int main(){
	int testcase;
	cin >> testcase;
	for (int i = 0; i < testcase; i++){
		int M, result;
		unsigned long long minD = -1;
		cin >> M;
		unsigned long long before, current;
		for (int j = 0; j < M; j++){
			cin >> current;
			if (j != 0){
				if (current - before < minD || minD == -1){
					minD = current - before;
				}
				else if (minD == 0 && current - before != 0){
					result = 0;
				}
				else if (minD == 0 && j == M - 1)result = 1;
			}
			before = current;
		}

		if (minD != 0){
			result = 1;
			for (int i = 2; minD != 1; i++){
				int temp = 0;
				while (minD%i == 0){
					temp++;
					minD /= i;
				}
				result *= temp + 1;
			}
		}

		cout << "Case #" << i + 1 << endl;
		cout << result << endl;
	}
}