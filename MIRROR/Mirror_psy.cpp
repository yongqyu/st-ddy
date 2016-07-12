#include<iostream>
#include<string>//제출할땐 string.h
using namespace std;

int room[1000][1000] = { 0, };
int check[1000][1000] = { 0, };

int main(){
	int testcase;
	cin >> testcase;
	for (int i = 0; i < testcase; i++){
		int N;
		cin >> N;

		memset(check, 0, sizeof(int) * 1000 * 1000);

		for (int j = 0; j < N; j++){
			string input;
			cin >> input;
			for (int k = 0; k < N; k++){
				room[j][k] = input[k] - '0';
			}
		}
		
		int width = 0, height = 0, direction = 0;//우:0, 하:1, 좌:2, 상:3
		while (width != -1 && height != -1 && width != N && height != N){
			if ((room[height][width] == 0 && direction == 1) || (room[height][width] == 1 && direction == 2) || (room[height][width] == 2 && direction == 0)){	//아래로 가는경우
				room[height][width] != 0 ? check[height][width] = 1 : check[height][width] = 0;
				height++; direction = 1;
			}
			else if ((room[height][width] == 0 && direction == 0) || (room[height][width] == 1 && direction == 3) || (room[height][width] == 2 && direction == 1)){//오른쪽으로 가는경우
				room[height][width] != 0 ? check[height][width] = 1 : check[height][width] = 0;
				width++; direction = 0;
			}
			else if ((room[height][width] == 0 && direction == 3) || (room[height][width] == 1 && direction == 0) || (room[height][width] == 2 && direction == 2)){//위로 가는경우
				room[height][width] != 0 ? check[height][width] = 1 : check[height][width] = 0;
				height--; direction = 3;
			}
			else{//왼쪽으로 가는경우
				room[height][width] != 0 ? check[height][width] = 1 : check[height][width] = 0;
				width--; direction = 2;
			}
		}

		int result = 0;
		for (int j = 0; j < N; j++){
			for (int k = 0; k < N; k++){
				result += check[j][k];
			}
		}
		cout << "Case #" << testcase + 1 << endl;
		cout << result << endl;
	}
}