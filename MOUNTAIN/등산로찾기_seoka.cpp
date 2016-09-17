//http://jungol.co.kr/bbs/board.php?bo_table=pbank&wr_id=391&sca=3070
// 등산로찾기
// dfs로 탐색 -> 가중치를 저장 -> 가중치가 초기화될때 큐에 다시 넣는다

#pragma warning(disable:4996)
#include<iostream>
#include<queue>
#include<memory.h>
#include<string>
using namespace std;

struct position {
	int row;
	int col;
};

queue<position> Q;
int mountain_size;
int top_row, top_col;
int height[101][101];
int up_cost[101][101] = {1, };

int direction[4][2] = { {-1, 0},{ 0, -1 },{ 1, 0 },{ 0, 1 } };

bool inner(int row, int col) {
	if (row >= 1 && row <= mountain_size && col >= 1 && col <= mountain_size)
		return true;
	return false;
}

int find_path() {

	int cost=100000;
	
	// Q가 비었다면
	while ( !Q.empty() ) { 

		int p_row = Q.front().row, p_col = Q.front().col;
		Q.pop();

		for (int i = 0; i < 4; i++) {
			int tmp_row = p_row + direction[i][0], tmp_col = p_col + direction[i][1];
			if ( inner(tmp_row, tmp_col) ) { // 범위안
				
				int gap = height[tmp_row][tmp_col] - height[p_row][p_col];
				if (gap >= 0) gap = gap*gap;
				else gap = -gap;

				
				// 더작아서 초기화, Q에 추가
				if (up_cost[tmp_row][tmp_col] > gap + up_cost[p_row][p_col]) { 
					up_cost[tmp_row][tmp_col] = gap + up_cost[p_row][p_col];

					// 정상이라면
					if (tmp_row == top_row && tmp_col == top_col)
						cost = up_cost[tmp_row][tmp_col];
					
					// 정상아니라면 큐에 추가
					else {
						position P2;
						P2.row = tmp_row, P2.col = tmp_col;
						Q.push(P2);
					}
				}	
			}
		}
	}
	
	return cost;
}

int main() {
	std::ios::sync_with_stdio(false);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin >> mountain_size;
	cin >> top_row >> top_col;

	for (int i = 1; i <= mountain_size; i++)
		for (int j = 1; j <= mountain_size; j++)
			up_cost[i][j] = 100000;

	for (int i = 1; i <= mountain_size; i++) {
		for (int j = 1; j <= mountain_size; j++) {
			cout << up_cost[i][j] << " ";
		}
		cout << endl;
	}

	position P1;
	for (int i = 1; i <= mountain_size; i++) {
		for (int j = 1; j <= mountain_size; j++) {
			cin >> height[i][j];
			
			// 테두리 등산로를 큐에 추가
			if (i == 1 || i == mountain_size || j == 1 || j == mountain_size) {
				P1.row = i, P1.col = j;
				up_cost[i][j] = height[i][j] * height[i][j];
				Q.push(P1);
			}			
		}
	}

	printf("%d\n", find_path() );
	
	return 0;
}