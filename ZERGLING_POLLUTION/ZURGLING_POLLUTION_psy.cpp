#include <iostream>
#include <string>
#include <deque>
using namespace std;

class Pollute{
public:
	int polluteWidth;
	int polluteHeight;
	int level;
	Pollute(int height, int width, int l){ polluteWidth = width; polluteHeight = height; level = l; }
};

int main(){
	int width, height;
	cin >> width >> height;
	int **arr=new int*[height];
	string line;
	int polluteWidth, polluteHeight;
	int time = 3;

	for (int i = 0; i < height; i++){
		arr[i] = new int[width];
		cin >> line;
		for (int j = 0; j < width; j++){
			arr[i][j] = atoi(line.substr(j, 1).c_str());	//입력값이 스트링으로 주어져서 string에서 int로 하나씩 잘라서 저장
		}
	}
	cin >> polluteWidth >> polluteHeight;
	polluteWidth -= 1;
	polluteHeight -= 1;

	deque<Pollute> que;
	Pollute first(polluteHeight,polluteWidth,3);
	arr[polluteHeight][polluteWidth] = 0;
	que.push_back(first);

	while (!que.empty()){
		Pollute temp=que.front();
		que.pop_front();
		int l = temp.level + 1;
		if (temp.polluteHeight - 1 >= 0 && arr[temp.polluteHeight - 1][temp.polluteWidth] == 1){
			que.push_back(Pollute(temp.polluteHeight - 1, temp.polluteWidth,l));
			arr[temp.polluteHeight - 1][temp.polluteWidth] = 0;
		}
		if (temp.polluteWidth - 1 >= 0 && arr[temp.polluteHeight][temp.polluteWidth - 1] == 1){
			que.push_back(Pollute(temp.polluteHeight, temp.polluteWidth - 1,l));
			arr[temp.polluteHeight][temp.polluteWidth - 1] = 0;
		}
		if (temp.polluteHeight + 1 < height && arr[temp.polluteHeight + 1][temp.polluteWidth] == 1){
			que.push_back(Pollute(temp.polluteHeight + 1, temp.polluteWidth,l));
			arr[temp.polluteHeight + 1][temp.polluteWidth] = 0;
		}
		if (temp.polluteWidth + 1 < width && arr[temp.polluteHeight][temp.polluteWidth + 1] == 1){
			que.push_back(Pollute(temp.polluteHeight, temp.polluteWidth + 1,l));
			arr[temp.polluteHeight][temp.polluteWidth + 1] = 0;
		}
		if (temp.level > time)time = temp.level;
	}

	cout << time << endl;

	int alive=0;
	for (int i = 0; i < height; i++){
		for (int j = 0; j < width; j++){
			alive += arr[i][j];
		}
	}

	cout << alive << endl;
}