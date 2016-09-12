#include <iostream>
#include <queue>

using namespace std;

int N, M, R, C, S, K;
int visit[101][101];
int dir[8][2] = { { 1, -2 }, { 2, -1 }, { 2, 1 }, { 1, 2 }, { -1, 2 }, { -2, 1 }, { -2, -1 }, { -1, -2 } };

class Point {
public :
	int x, y, move;

	Point(int a, int b, int c) {
		x = a;
		y = b;
		move = c;
	}
};

queue<Point> bfsQ;

void bfs();

int main() {
	cin >> N >> M >> R >> C >> S >> K;
	
	Point point(R, C, 0);
	bfsQ.push(point);

	bfs();

	system("pause");
	return 0;
}

void bfs() {
	int r = bfsQ.front().x;
	int c = bfsQ.front().y;
	int move = bfsQ.front().move;
	
	visit[r][c] = 1;

	if (r == S && c == K) {
		cout << move << endl;
		return;
	}
	
	for (int i = 0; i < 8; i++) {
		int tempR = r + dir[i][0];
		int tempC = c + dir[i][1];
		if (0 < tempR && tempR <= N && 0 < tempC && tempC <= M) {
			if (visit[tempR][tempC] == 0) {
				Point temp(tempR, tempC, move+1);
				bfsQ.push(temp);
			}
		}
	}

	bfsQ.pop();

	bfs();
}
