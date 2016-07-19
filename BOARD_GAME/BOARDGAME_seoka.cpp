#include<iostream>
#include<stdlib.h>
#include<cstring>
#include<vector>

using namespace std;

struct road {
	int v1;
	int v2;
	char r_color;
};

struct PossibleRoad {
	vector< pair<int, char> > pr;
};

int dp[500][500];
PossibleRoad * village;
struct road R[10000];
char color[1000];
int n;
int v, r;			// number of (village, road)
int mmax = 0;
int impossible=0;	// can't start

// find each village's possible path
void find() {
	for (int i = 1; i <= n; i++) { // i = village
		// Å½»ö
		for (int j = 0; j < r; j++) { // j = road
			int v = -1;
			if (R[j].v1 == i) v = R[j].v2;
			else if (R[j].v2 == i) v = R[j].v1;

			if (v != -1) { // if found
				if (i == 1) impossible++;
				village[i].pr.push_back(pair<int, char>(v, R[j].r_color));
			}
		}
	}
}

void board() {
	for (int i = 1; i <= n; i++) {		// i = number of road
		if (i == 1) {
			vector<pair<int, char> >::iterator iter;
			for (iter = village[1].pr.begin(); iter != village[1].pr.end(); iter++) {
				int kk = iter->first;
				char kkk = iter->second;
				dp[iter->first][1] = (color[1] == iter->second) ? 10 : 0;
			}
		}
		else {
			for (int j = 1; j <= v; j++) {	// j = number of village


				vector<pair<int, char> >::iterator iter;
				for (iter = village[j].pr.begin(); iter != village[j].pr.end(); iter++) {
					//int s = score;
					if (color[i] == iter->second) {
						dp[j][i] = (dp[j][i] >= dp[iter->first][i - 1] + 10) ? dp[j][i] : dp[iter->first][i - 1] + 10;
					}
					dp[j][i] = (dp[j][i] >= dp[iter->first][i - 1]) ? dp[j][i] : dp[iter->first][i - 1];
				}

			}

		}
	}

	return;
}

int main() {

	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> color[i];

	cin >> v >> r;

	village = new PossibleRoad[v+1];

	for (int i = 0; i < r; i++) {
		cin >> R[i].v1 >> R[i].v2 >> R[i].r_color;
	}
	
	find();

	if(impossible!=0) board();

	for (int i = 1; i <= v; i++)
		mmax = (dp[i][n] >= mmax) ? dp[i][n] : mmax;

	cout << mmax << endl;

	return 0;
}