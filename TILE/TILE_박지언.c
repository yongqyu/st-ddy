//2016.07.06 Å¸ÀÏ Ã¤¿ì±â http://www.jungol.co.kr/bbs/board.php?bo_table=pbank&wr_id=1804&sca=3060
#include<stdio.h>

int A[512][512];
int N, X, Y;
void fill(int, int, int, int, int);

int main() {
	scanf("%d %d %d", &N, &X, &Y);

	A[X][Y] = 0;

	fill(N, 0, 0, X, Y);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) printf("%d ", A[i][j]);
		printf("\n");
	}
	return 0;
}

void fill(int n, int srow, int scol, int hrow, int hcol) {
	if (n == 1) return;
	int quad = (hrow < srow + n / 2) ? 1 : 3;
	quad = (hcol < scol + n / 2) ? quad : quad + 1;

	int addhR[5] = { 0,-1,-1,0,0 };
	int addhC[5] = { 0,-1,0,-1,0 };

	for (int i = 1; i < 5; i++) {
		int next_srow = i < 3 ? srow : srow + n / 2;
		int next_scol = i % 2 == 0 ? scol + n / 2 : scol;
		if (i == quad) fill(n / 2, next_srow, next_scol, hrow, hcol);
		else {
			int next_hrow = srow + n / 2 + addhR[i];
			int next_hcol = scol + n / 2 + addhC[i];
			fill(n / 2, next_srow, next_scol, next_hrow, next_hcol);
			A[next_hrow][next_hcol] = quad;
		}
	}
}
