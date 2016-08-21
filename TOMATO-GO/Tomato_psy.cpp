#include<iostream>
#include<queue>
using namespace std;

class Welldone{
public:
	int x;
	int y;
	int level;
	Welldone(){}
	Welldone(int y, int x, int level){ this->y = y; this->x = x; this->level = level; }
};

int main(){
	int width, height;
	cin >> width >> height;
	int **arr;
	arr = new int*[height];
	for (int i = 0; i < height; i++){
		arr[i] = new int[width];
		for (int j = 0; j < width; j++){
			cin >> arr[i][j];
		}
	}
	bool allWelldone = true;
	queue<Welldone> que;
	for (int i = 0; i < height; i++){
		for (int j = 0; j < width; j++){
			if (arr[i][j] == 1){
				Welldone temp;
				temp.y = i;
				temp.x = j;
				temp.level = 0;
				que.push(temp);
			}
			else allWelldone = false;
		}
	}
	if (allWelldone){
		cout << 0 << endl;
		return 0;
	}
	int result = 0;
	while (!que.empty()){
		Welldone temp = que.front();
		que.pop();
		bool check = false;
		if (temp.x + 1 < width&&arr[temp.y][temp.x + 1] == 0){//오른쪽
			que.push(Welldone(temp.y, temp.x + 1,temp.level+1));
			arr[temp.y][temp.x + 1] = 1;
			check = true;
		}
		if (temp.x - 1 >= 0&&arr[temp.y][temp.x - 1] == 0){//왼쪽
			que.push(Welldone(temp.y, temp.x - 1,temp.level+1));
			arr[temp.y][temp.x - 1] = 1;
			check = true;
		}
		if (temp.y - 1 >= 0&&arr[temp.y-1][temp.x] == 0){//위
			que.push(Welldone(temp.y-1, temp.x,temp.level+1));
			arr[temp.y-1][temp.x] = 1;
			check = true;
		}
		if (temp.y + 1 < height&&arr[temp.y+1][temp.x] == 0){//아래
			que.push(Welldone(temp.y+1, temp.x,temp.level+1));
			arr[temp.y+1][temp.x] = 1;
			check = true;
		}
		result = temp.level;
	}

	bool checkAll = false;
	for (int i = 0; i < height; i++){
		for (int j = 0; j < width; j++){
			if (arr[i][j] == 0||checkAll){
				checkAll = true;
				break;
			}
		}
	}
	if (checkAll)cout << -1 << endl;
	else cout << result << endl;
}