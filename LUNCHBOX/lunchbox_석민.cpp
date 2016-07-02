//#pragma warning(disable:4996)

#include <iostream>
#include <list>
#include <cstdio>

using namespace std;

class LunchBox {
public:
	int M, E;


	LunchBox(int m, int e) {
		M = m;
		E = e;
	}

	bool operator< (const LunchBox& other) const {
		return E > other.E;
	}
};

int main() {
	int T;

	scanf("%d", &T);

	for (int i = 0; i < T; i++) {
		int count;
		int result = 0;
		int max = 0;

		scanf("%d", &count);

		list<LunchBox> boxList;

		int* arrayM = new int[count];
		int* arrayE = new int[count];

		for (int j = 0; j < count; j++) {
			scanf("%d", &arrayM[j]);
		}

		for (int j = 0; j < count; j++) {
			scanf("%d", &arrayE[j]);

			LunchBox lb = LunchBox(arrayM[j], arrayE[j]);

			boxList.push_back(lb);
		}

		boxList.sort();

		list<LunchBox>::iterator iter;
		for (iter = boxList.begin(); iter != boxList.end(); iter++) {
			result += iter->M;
			if (result + iter->E > max) max = result + iter->E;
		}

		cout << max << "\n";
	}

	return 0;
}