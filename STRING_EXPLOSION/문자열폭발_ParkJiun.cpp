#include<iostream>
#include<stack>
#include<string.h>
using namespace std;

char str[1000002];
char out[1000002];
char bomb[38];
int len1, len2;

int main() {
	scanf("%s %s", str, bomb);
	len1 = strlen(str);
	len2 = strlen(bomb);

	stack<char> result;
	int j = len2 - 1;

	for (int i = 0; i < len1; i++) {
		result.push(str[i]);
		if (result.top() == bomb[j]) {
			result.pop();
			if (result.empty()) continue;
			for (j = j - 1; result.empty() == false && result.top() == bomb[j] && j >= 0; --j) {
				result.pop();
			}

			if (j != -1) {
				for (j += 1; j < len2; j++) {
					result.push(bomb[j]);
				}
			}
			j = len2 - 1;
		}
	}

	if (result.empty()) printf("FRULA\n");
	else {
		int size = result.size();
		int i = size - 1;
		for (; i >= 0; i--) {
			out[i] = result.top();
			result.pop();
		}
		out[size] = '\0';
		printf("%s\n", out);
	}
}
