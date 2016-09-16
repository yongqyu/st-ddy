#include <iostream>
#include <cstdio>

using namespace std;

long long numbers[1000001];

int main(){
	long long min, max;
	int count = 0;
	scanf("%lld %lld", &min, &max);

	int i = 0;
	int N = max - min + 1;
	long long temp = min;
	for (int i = 0; temp <= max; i++)
	{
		numbers[i] = temp++;
	}

	long long sqr_num, root_number = 2;

	while ((sqr_num = root_number * root_number) <= max){
		long long i;

		i = min / sqr_num;
		i *= sqr_num;
		if (i < min)
			i += sqr_num;
		if(i>=min)
			i -= min;


		while (i < N){
			if (numbers[i] != -1)
				numbers[i] = -1;
			i += sqr_num;
		}
		root_number++;
	}

	for (i = 0; i < N; i++)
	{
		if (numbers[i] != -1)
			count++;
	}

	cout << count << endl;
}