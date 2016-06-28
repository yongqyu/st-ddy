#include<iostream>
using namespace std;
void backTrack(int **arr, int arrSize, int current, int current_x, int current_y);
bool flag = false;
int main(){
	int count;
	cin >> count;
	for (int i = 0; i < count; i++){
		int arrSize;
		cin >> arrSize;

		int **arr = new int*[arrSize];
		for (int i = 0; i < arrSize; i++){
			arr[i] = new int[arrSize];
			for (int j = 0; j < arrSize; j++){
				cin >> arr[i][j];
			}
		}
		flag = false;
		backTrack(arr, arrSize, arr[0][0], 0, 0);
		if (flag == true){
			cout << "YES" << endl;
		}
		else
			cout << "NO" << endl;
	}
}

void backTrack(int **arr,int arrSize,int current,int current_x,int current_y){
	if ((current_x + current) < arrSize){
		if (current_x +current== arrSize - 1 && current_y == arrSize - 1){
			flag = true;
		}
		else backTrack(arr, arrSize, arr[current_x + current][current_y], current_x + current, current_y);
	}
	if ((current_y + current) < arrSize){
		if (current_x == arrSize - 1 && current_y + current == arrSize - 1){
			flag = true;
		}
		else backTrack(arr, arrSize, arr[current_x][current_y + current], current_x, current_y + current);
	}
}