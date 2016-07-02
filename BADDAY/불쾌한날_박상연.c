#include <stdio.h>

int main(void)
{
	int N;
	int count;

	unsigned long sum;

	int input, temp;
	int * heights;
	int min;

	scanf("%d", &N);

	sum = 0;
	count = 0;
	min = 0;
	heights = (int *)malloc(sizeof(int)*N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &input);
		if (min <= input)
			for (int j = 0; j < count;j++)
			{
				if (heights[j] <= input)
					count = j;
			}

		sum += count;
		heights[count] = input;
		min = input;
		count++;
	}
	printf("%u\n", sum);
	free(heights);
}