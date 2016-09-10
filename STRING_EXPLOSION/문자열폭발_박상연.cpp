#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int next_valid_index[1000001];
int pre_valid_index[1000001];
char input[1000001];
char cmp_str[37];
int input_str_len;
int cmp_str_len;

int get_next_valid_index(int);

int compare_str(int index){
	if (index + cmp_str_len > input_str_len)
		return 0;

	for (int i = 0; i < cmp_str_len; i++)
	{
		if(index < input_str_len && input[index] == -1)
			index = get_next_valid_index(index);
		if (index == -1)
			return 0;

		if (input[index] != cmp_str[i])
			return 0;
		index++;
	}
	return 1;
}


int get_next_valid_index(const int index){
	if (index + 1 >= input_str_len)
		return -1;
	if (input[index+1] != -1)
		return index + 1;
	else{
		int temp_index = index;
		while (input[temp_index] == -1)
			temp_index = (next_valid_index[temp_index] == -1 ? temp_index + 1 : next_valid_index[temp_index]);
		next_valid_index[index] = temp_index;
		return temp_index;
	}
}
int get_pre_valid_index(const int index){
	if (index - 1 < 0)
		return -1;
	if (pre_valid_index[index - 1] == -1)
		return index -1;
	else{
		int temp_index = index -1;
		while (pre_valid_index[temp_index] != -1)
			temp_index = pre_valid_index[temp_index];

		pre_valid_index[index] = temp_index;
		return temp_index;
	}
}

int main(){
	scanf("%s", input);
	scanf("%s", cmp_str);
	input_str_len = strlen(input);
	cmp_str_len = strlen(cmp_str);
	
	for (int i = 0; i <= input_str_len; i++)
		pre_valid_index[i] = next_valid_index[i] = -1;

	for (int i = 0; i < input_str_len; i++){
		if (input[i] == -1){
			i =  get_next_valid_index(i)-1;
			if (i >= input_str_len || i < 0)
				break;
			continue;
		}
		if (compare_str(i)){
			int count = 0;
			int temp_index = i;

			while (count < cmp_str_len){
				if (input[temp_index] == -1)
					temp_index = get_next_valid_index(temp_index);
				input[temp_index] = -1;
				count++;
			}
			pre_valid_index[temp_index] = get_pre_valid_index(i);
			next_valid_index[i] = get_next_valid_index(temp_index);

			count = 0;
			while (count < cmp_str_len - 1){
				i = get_pre_valid_index(i);
				count++;
				if (i == 0)
					break;
			}
			i--;
		}

	}



	int flag = 0;
	for (int i = 0; i < input_str_len; i++)
		if (input[i] != -1){
			cout << input[i];
			if (!flag)
				flag = 1;
		}
	if (!flag)
		cout << "FRULA";
	cout << endl;

}