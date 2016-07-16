#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int DP[5001];
int max_result;

int get_ways(int length)
{	
	if (length <= 1)
		return 1;
	if (DP[length] != 0)
		return DP[length];
	for (int i = max_result + 1; i <= length; i++)
		DP[i] = (DP[i - 1] + DP[i - 2]) % 1000000;
	max_result = length;
	return DP[length];
}

int main(){
	int result=1;
	char input[5001];
	int count;

	DP[0] = DP[1] = 1;
	max_result = 1;
	count = 0;

	scanf("%s", input);
	for (int i = 0; input[i] != '\0' ; i++){
		if (input[i] == '1' || input[i] == '2'){
			count++;
			continue;
		}
		else
		{
			if (input[i] == '0')
				result = (result * get_ways(count - 1)) % 1000000;
			else if (i > 0 && input[i - 1] == '2' && input[i] >= '7')
				result = (result * get_ways(count)) % 1000000;
			else
				result = (result * get_ways(count + 1)) % 1000000;
			count = 0;
		}
	}
	result = (result * get_ways(count)) % 1000000;

	cout << result << endl;
}