//2016.07.06 보드게임 http://www.jungol.co.kr/bbs/board.php?bo_table=pbank&wr_id=1142&sca=30a0
#include<iostream>
#include<vector>
using namespace std;
typedef vector<pair<char, int> > adjEdge; 
//GNU gcc/g++ 컴파일러에서 , int>> 처럼 >> 붙여쓰면 컴파일 에러 뜸. char, int> > adjEdge로 띄어쓰기 넣어줘야 함

int main() {
	int n, m, k, i, j;
	cin >> n;
	char *color = new char[n + 1];
	int **score = new int*[n + 1];
	for (i = 1; i <= n; i++) cin >> color[i];

	cin >> m >> k;
	adjEdge *edge = new adjEdge[m + 1];

	for (i = 1; i <= n; i++)
		score[i] = new int[m + 1];
	
	int e1, e2; char c;
	for (i = 0; i < k; i++) {
		cin >> e1 >> e2 >> c;
		edge[e1].push_back(pair<char, int>(c, e2));
		edge[e2].push_back(pair<char, int>(c, e1));
	}
	
	if (edge[1].size() == 0) {
		cout << "0" << endl; 
		for (i = 1; i <= n; i++) delete[] score[i];
		delete[] color;
		delete[] score;
		delete[] edge; 
		return 0;
	}
	else {//dynamin programming
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= m; j++) {
				if (i == 1) {
					if (j == 1) continue;
					for (int num = 0; num < edge[1].size(); num++) {
						if (edge[1][num].first == color[1])
							score[1][edge[1][num].second] = 10;
					}
				}
				else {
					int max = score[i - 1][j];
					for (int num = 0; num < edge[j].size(); num++) {
						if (edge[j][num].first == color[i]) {
							int temp = score[i - 1][edge[j][num].second] + 10;
							max = max < temp ? temp : max;
						}
						else {
							int temp = score[i - 1][edge[j][num].second];
							max = max < temp ? temp : max;
						}
						score[i][j] = max;
					}
				}
			}
		}
	}

	int max = score[n][1];
	for (i = 2; i <= m; i++) 
		max = max < score[n][i] ? score[n][i] : max;

	cout << max << endl;

	for (i = 1; i <= n; i++) delete[] score[i];
	delete[] color;
	delete[] score;
	delete[] edge;

	return 0;
}
