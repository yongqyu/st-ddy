#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

int stair[1000001];

int main(){
	queue<int> next_visit;
	int F, S, G, U, D;
	scanf("%d %d %d %d %d", &F, &S, &G, &U, &D);

	for (int i = 1; i <= F; i++)
		stair[i] = -1;

	stair[S] = 0;
	next_visit.push(S);

	int cur_stair;
	while (!next_visit.empty()){
		cur_stair = next_visit.front();
		next_visit.pop();

		if (cur_stair + U <= F && stair[cur_stair + U] == -1){
			stair[cur_stair + U] = stair[cur_stair] + 1;
			next_visit.push(cur_stair + U);
		}
		if (cur_stair - D > 0 && stair[cur_stair - D] == -1){
			stair[cur_stair - D] = stair[cur_stair] + 1;
			next_visit.push(cur_stair - D);
		}
		
		if (cur_stair + U == G || cur_stair - D == G)
			break;
	}
	if (stair[G] == -1)
		cout << "use the stairs" << endl;
	else
		cout << stair[G] << endl;

}