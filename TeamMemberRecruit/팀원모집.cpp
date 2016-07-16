#include <iostream>
using namespace std;
int M, N;
int flag = 0;

/*
	canSolveProb - 각 사람마다 풀 수 있는 문제의bit가 setting 돼있는 int형 배열
	rightResult - 모두 풀 수 있게 됐을때, 알맞는 답 Ex) N이 4면 1111 즉, 15가 됨
	result - 현재 풀 수 있는 문제들이 setting된 int형 변수
	count - 문제를 풀 수 있는 인원
	curIndex - 함수가 불릴 때 문제를 풀 인원의 index
*/
void solveProblem(int * canSolveProb, const int rightResult, int result, int count, int curIndex){
	count--;
	result |= canSolveProb[curIndex];
	if (count == 0){
		if (result == rightResult)
			flag = 1;
		return;
	}

	for (int i = curIndex + 1; (i <= M - count) && !flag; i++)
	{
		solveProblem(canSolveProb, rightResult, result, count, i);
	}
}


int main(){
	int canSolveProb[10];	// 문제를 풀 수 있는 bit들이 setting된 int들의 배열, M명이면 0~M-1 index만 사용됨
	int canSolveProb_num;	// 입력을 받을 때, 몇 문제를 풀 수 있는지 입력 받기 위한 변수
	int input;				// 문제 번호를 입력 받기 위한 변수
	int solveProbSum;		// 모든 인원이 문제를 풀었을때 모든 문제를 풀 수 있는지 확인 하기 위한 변수

	for (int i = 0; i<10; i++)
		canSolveProb[i] = 0;
	scanf("%d %d", &N, &M);

	const int rightResult = (1 << N) - 1;		// 모든 문제를 풀 수 있을때의 bit값 setting  Ex) N=5일때 11111 <=> 2^5-1

	for (int i = 0; i < M; i++)
	{
		scanf("%d", &canSolveProb_num);
		for (int j = 0; j < canSolveProb_num; j++){		//문제의 수만큼 반복하면서 문제 번호에 해당하는 bit setting
			scanf(" %d", &input);
			canSolveProb[i] |= 1 << (input - 1);
		}
	}

	solveProbSum = 0;
	for (int j = 0; j < M; j++)
		solveProbSum |= canSolveProb[j];
	if (solveProbSum != rightResult)			// 모든 사람이 다 풀어도 모든 문제를 풀 수 없을 때
	{
		cout << "-1" << endl;
		return 0;
	}

	for (int i = 1; i <= 10; i++)
	{
		for (int j = 0; j <= M - i; j++)
			solveProblem(canSolveProb, rightResult, 0, i, j);
		if (flag)
		{
			cout << i << endl;
			return 0;
		}
	}
}
