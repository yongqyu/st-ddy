#include<iostream>
#include<stdlib.h>
#include<cstring>
#pragma warning(disable:4996)
using namespace std;

int T[512][512];

void tile(int size, int startx, int starty, int holex, int holey) {
	// find hole position
	int position = 1;
	int newx = startx, newy = starty;
	if (holex >= startx + size / 2) { position += 1; newx = startx + size / 2; }
	if (holey >= starty + size / 2) { position += 2; newy = starty + size / 2; }

	// fill position number
	if (position != 1) T[starty + size / 2 - 1][startx + size / 2 - 1] = position;
	if (position != 2) T[starty + size / 2 - 1][startx + size / 2] = position;
	if (position != 3) T[starty + size / 2][startx + size / 2 - 1] = position;
	if (position != 4) T[starty + size / 2][startx + size / 2] = position;

	// half-size recursive
	if (size != 2) {
		if (position != 1) tile(size / 2, startx, starty, startx + size / 2 - 1, starty + size / 2 - 1);
		if (position != 2) tile(size / 2, startx + size / 2, starty, startx + size / 2, starty + size / 2 - 1);
		if (position != 3) tile(size / 2, startx, starty + size / 2, startx + size / 2 - 1, starty + size / 2);
		if (position != 4) tile(size / 2, startx + size / 2, starty + size / 2, startx + size / 2, starty + size / 2);

		tile(size / 2, newx, newy, holex, holey);
	}

	return;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, x, y;
	cin >> n;

	cin >> y;
	cin >> x;

	tile(n, 0, 0, x, y);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << T[i][j] << " ";
		cout << endl;
	}

	return 0;
}
