#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;

int main(){
	int N, weight;
	char input;
	long long output=0;
	stack<int> number_stack;

	scanf("%d\n", &N);
	for (int i = 0; i < N; i++){
		scanf("%c", &input);
		if (input >= '0' && input <= '9'){
			number_stack.push(input - '0');
		}
		else{
			if (number_stack.empty())
				continue;
			else{
				weight = 1;
				while (!number_stack.empty()){
					output += number_stack.top() * weight;
					weight *= 10;
					number_stack.pop();
				}
			}
		}
	}
	if(!number_stack.empty()){
		weight = 1;
		while (!number_stack.empty()){
			output += number_stack.top() * weight;
			weight *= 10;
			number_stack.pop();
		}
	}

	cout << output << endl;
}