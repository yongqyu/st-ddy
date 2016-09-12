// http://jungol.co.kr/bbs/board.php?bo_table=pbank&wr_id=386&sca=3040
// BFS

#include<iostream>
#include<queue>
#pragma warning(disable: 4996)
using namespace std;

struct position {
	int row;
	int col;
	int count;
};

int row=0, col = 0, a_r = 0, a_c = 0, b_r = 0, b_c = 0, result = 0;
queue< position > Q;
bool visited[101][101] = { false, };
int janggi(int r, int c);

// 8방향 설정
int direction_row[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int direction_col[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };

int direction[8][2] = { {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2} };

int main() {
	std::ios::sync_with_stdio(false);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin >> row >> col;
	cin >> a_r >> a_c >> b_r >> b_c;
	
	printf("%d\n", janggi(a_r, a_c) );

	return 0;
}

int janggi(int r, int c) {

	int front_r, front_c, count;

	position P;
	P.row = r, P.col = c, P.count = 1;

	Q.push(P);

	while (1) { // 도착할때까지

				// Q front save
		front_r = Q.front().row;
		front_c = Q.front().col;
		count = Q.front().count;

		// Q pop
		Q.pop();

		for (int i = 0; i < 8; i++) { //8방향

									  // 방향 재설정
			int norm_r = front_r + direction[i][0];
			int norm_c = front_c + direction[i][1];

			//체스판 안쪽
			if (norm_r >= 1 && norm_r <= row && norm_c >= 1 && norm_c <= col) {

				// 방문 안했다면
				if (!visited[norm_r][norm_c]) {

					//일치여부
					if (norm_r == b_r && norm_c == b_c) return count;

					visited[norm_r][norm_c] = true;

					position PP;
					PP.row = norm_r, PP.col = norm_c, PP.count = count + 1;
					Q.push(PP);
				}
			}
		}

	}

}