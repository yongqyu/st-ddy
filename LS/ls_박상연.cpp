#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

vector<string> divided_pattern;

void divide_string(string pattern){
	int pattern_size = pattern.size();
	string str;

	str.clear();
	for (int i = 0; i < pattern_size; i++)
	{
		if (pattern[i] == '*')
		{
			if (str != ""){
				divided_pattern.push_back(str);
			}
			divided_pattern.push_back("*");
			str.clear();
		}
		else
			str += pattern[i];
	}
	if (pattern[pattern.size() - 1] != '*')
		divided_pattern.push_back(str);
}

int Pattern_In_string(string pattern, string str, int start){
	if (pattern.size() <= str.size()-start){
		int i;
		for (i = 0; i < pattern.size(); i++){
			if (pattern[i] != str[start + i])
				break;
		}
		if (i == pattern.size())
			return start;
	}
	return -1;
}

int judge_for_ls(string str){
	int dp[101][101];
	const int pattern_count = divided_pattern.size();
	const int str_size = str.size();

	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 100; j++)
			dp[i][j] = 0;

	if (divided_pattern[0] == "*"){
		for (int i = 0; i <= str_size; i++)
			dp[0][i] = 1;
	}
	else{
		if (Pattern_In_string(divided_pattern[0], str, 0) == -1)
			return 0;
		else
			dp[0][divided_pattern[0].size()] = 1;
	}

	for (int i = 1; i < pattern_count; i++){
		for (int j = 0; j <= str_size; j++){
			if (dp[i-1][j] == 0)
				continue;

			if (divided_pattern[i] == "*"){
				for (int k = j; k <= str_size; k++)
					dp[i][k] = 1;
				break;
			}
			else{
				if (Pattern_In_string(divided_pattern[i], str, j) == -1)
					continue;
				else{
					dp[i][j + divided_pattern[i].size()] = 1;
				}
			}
		}
	}

	if (dp[pattern_count-1][str_size] == 1)
		return 1;
	else
		return 0;
}

int main(){
	string pattern;
	string temp;
	vector<string> input;
	int N;

	cin >> pattern;
	scanf("%d", &N);

	divide_string(pattern);

	for (int i = 1; i <= N; i++)
	{
		cin >> temp;
		input.push_back(temp);
	}

	for (int i = 0; i < N; i++){
		if (judge_for_ls(input[i]))
			cout << input[i] << endl;
	}
}