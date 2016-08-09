#include<iostream>
#pragma warning(disable:4996)
using namespace std;


int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, cluster, total=0;
	
	scanf("%d", &n);
	int *files = new int[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &files[i]);
	}
	scanf("%d", &cluster);
	
	for (int i = 0; i < n; i++) {
		int space = files[i] / cluster;
		if (files[i]%cluster != 0) space++;
		
		total += space;
	}

	printf("%d\n", total * cluster);

	return 0;
}