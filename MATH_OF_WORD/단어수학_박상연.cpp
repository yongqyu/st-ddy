#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int input_count[8][26];
int alphabet_weight[26];

int main(){
	int N, count_index;
	char input[9];
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%s", input);
		for (int j = 0 ; j < strlen(input); j++){
			count_index = strlen(input) - j - 1;
			input_count[j][input[count_index] - 'A']++;
		}// ¾ËÆÄºªÀÇ ÀÚ¸´¼ö count
	}

	int cur_weight;
	for (int i = 0; i < 26; i++){
		cur_weight = 1;
		for (int j = 0; j < 8; j++){
			alphabet_weight[i] += input_count[j][i] * cur_weight;
			cur_weight *= 10;
		}
	}

	unsigned int output = 0;
	int max_index, max_val;

	cur_weight = 9;
	for (int i = 0; i < 9; i++){
		max_val = 0;
		for (int i = 0; i < 26; i++){
			if (max_val < alphabet_weight[i])
			{
				max_val = alphabet_weight[i];
				max_index = i;
			}
		}
		if (max_val == 0)
			break;
		else{
			output += cur_weight * alphabet_weight[max_index];
			alphabet_weight[max_index] = 0;
			cur_weight--;
		}
	}
	cout << output << endl;
}