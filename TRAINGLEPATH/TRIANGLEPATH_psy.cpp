#include <iostream>
#include <memory>
using namespace std;

int main(){
	int count;
	cin >> count;

	for (int index = 0; index < count; index++){
		int **arr;
		int sizeIndex = 1;
		int triangleSize;
		int **result;
		cin >> triangleSize;

		arr = new int*[triangleSize];
		result = new int*[triangleSize];
		for (int i = 0; i < triangleSize; i++){
			result[i] = new int[triangleSize];
		}
		for (int i = 0; i < triangleSize; i++){
			arr[i] = new int[sizeIndex];
			int j;
			for (j = 0; j < sizeIndex; j++){
				cin >> arr[i][j];
			}		
			sizeIndex++;
		}
		sizeIndex = 1;
		for (int i = 0; i < triangleSize; i++){
			for (int j = 0; j < sizeIndex; j++){
				if (i == 0){
					result[i][j] = arr[i][j];
				}
				else if (i != 0&&j==0){
					result[i][j] = result[i - 1][j] + arr[i][j];
				}
				else if (i != 0 && j ==sizeIndex-1){
					result[i][j] = result[i - 1][j - 1] + arr[i][j];
				}
				else{
					result[i][j]=result[i - 1][j - 1] > result[i - 1][j] ? result[i - 1][j - 1] + arr[i][j] : result[i - 1][j] + arr[i][j];
				}
			}
			sizeIndex++;
		}

		int max = 0;
		for (int i = 0; i < triangleSize; i++){
			if (result[triangleSize - 1][i]>max)
				max = result[triangleSize-1][i];
		}
		cout << max << endl;
	}
}