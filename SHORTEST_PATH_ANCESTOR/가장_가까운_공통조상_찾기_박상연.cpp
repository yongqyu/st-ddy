#include <stdio.h>
#include <iostream>

using namespace std;

char path[10001];
int ancestor_list[10001];

int main(){
	int N;
	int child, parent;
	int child1, child2;

	scanf("%d", &N);
	for (int i = 0; i < N-1; i++)
	{
		scanf("%d %d", &parent, &child);
		ancestor_list[child] = parent;
	}

	scanf("%d %d", &child1, &child2);
	path[child1] = 1;
	parent = ancestor_list[child1];
	while (parent != 0){
		path[parent] = 1;
		parent = ancestor_list[parent];
	}

	parent = ancestor_list[child2];
	while (path[parent] == 0)
		parent = ancestor_list[parent];

	cout << parent << endl;
}