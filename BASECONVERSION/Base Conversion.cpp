#include <iostream>
#include <vector>
using namespace std;

int main(){
	int A, B;
	int number;
	int num_len;
	int input;
	vector<int> output;
	
	scanf("%d %d", &A, &B);
	scanf("%d", &num_len);

	scanf("%d", &number);
	for (int i = 0; i < num_len-1; i++){
		number *= A;
		scanf(" %d", &input);
		number += input;
	}

	output.clear();
	int i = 0;
	while (1){
		output.push_back(number%B);
		number -= output.at(i++);
		number /= B;
		if (number == 0)
			break;
	}
	
	cout << output.at(output.size()-1);
	for (i = output.size()-2; i >= 0; i--)
		cout << " " << output.at(i);
}