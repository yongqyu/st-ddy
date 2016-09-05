#include <iostream>
#include <cstdio>

using namespace std;

#define FIRST_ELEMENT 0
#define SECOND_ELEMENT 1

typedef struct{
	int SL,SW;
}SOUSAGE;

SOUSAGE input[5000];
char foot_print[5000];
int N;

void my_sort(int start_index, int end_index){
	//int pivot = input[start_index].SL;
	//int front, rear;
	SOUSAGE temp;

	//if (end_index - start_index < 1)
	//	return;

	//front = start_index + 1;
	//rear = end_index;

	//while (1){
	//	while (pivot > input[front].SL)
	//		front++;
	//	while (pivot < input[rear].SL)
	//		rear--;
	//	if (front >= rear)
	//		break;

	//	temp = input[rear];
	//	input[rear] = input[front];
	//	input[front] = temp;
	//}
	//temp = input[rear];
	//input[rear] = input[start_index];
	//input[start_index] = temp;


	//my_sort(start_index, rear - 1);
	//my_sort(rear + 1, end_index);


	//왜 퀵정렬로하면 시간초과고, 선택정렬로하면 빠른가 ?
	for (int i = 0; i < end_index; i++){
		for (int j = i+1; j <= end_index; j++){
			if (input[i].SL > input[j].SL){
				temp = input[i];
				input[i] = input[j];
				input[j] = temp;
			}
			else if (input[i].SL == input[j].SL){
				if (input[i].SW > input[j].SW){
					temp = input[i];
					input[i] = input[j];
					input[j] = temp;
				}
			}
		}
	}
}

int main(){
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d %d", &input[i].SL, &input[i].SW);
	
	my_sort(0, N - 1);
	int over_head = 0;
	int count = 0;
	int pre_size;

	while (count < N){
		over_head++;
		pre_size = -1;
		for (int i = 0; i < N; i++){
			if (foot_print[i] != 0 || pre_size > input[i].SW)
				continue;
			pre_size = input[i].SW;
			foot_print[i] = 1;
			count++;
		}
	}

	cout << over_head << endl;

}