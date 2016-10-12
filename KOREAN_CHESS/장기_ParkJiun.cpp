#include<iostream>
#include<queue>
using namespace std;

struct Point {
	int r, c;
	int cnt = 0;
};

int r_dir[] = { -2, -2, -1, 1, 2, 2, 1, -1 };
int c_dir[] = { -1, 1, 2, 2, 1, -1, -2, -2 };
int visited[101][101];

int main() {
	int n, m;
	Point mal, jol;
	scanf("%d %d", &n, &m);
	scanf("%d %d %d %d", &mal.r, &mal.c, &jol.r, &jol.c);
		
	queue<Point> q;
	q.push(mal);
	visited[mal.r][mal.c] = 1;

	int c = 0;
	Point f;

	while (!q.empty()) {
		f = q.front();
		q.pop();
		if ((f.r == jol.r) && (f.c == jol.c)) {
			c = f.cnt;
			break;
		}
		for (int i = 0; i < 8; i++) {
			Point temp; temp.r = r_dir[i] + f.r; temp.c = c_dir[i] + f.c;
			if (0 < temp.r && temp.r <= n && 0 < temp.c && temp.c <= m && !visited[temp.r][temp.c]) {
				temp.cnt = f.cnt + 1;
				visited[temp.r][temp.c] = 1;
				q.push(temp);
			}
		}
	}

	printf("%d\n", c);
	
}