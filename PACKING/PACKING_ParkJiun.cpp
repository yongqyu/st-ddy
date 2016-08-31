#include<iostream>
#include<vector>
#include<string>
#include<string.h>
using namespace std;
#define max(a,b) (a)>(b) ? (a) : (b)

struct ITEM {
	string name;
	int volume;
	int need;
};

ITEM item[100];
int cache[100][1001];
int pack(int, int);
int nofitem, w;

int main() {
	std::ios::sync_with_stdio(false);
	int test;
	cin >> test;
	while (test--) {
		cin >> nofitem >> w;
		for (int i = 0; i < nofitem; i++) {
			cin >> item[i].name >> item[i].volume >> item[i].need;
		}
		memset(cache, -1, sizeof(cache));

		int result = pack(0, w);

		vector<string> picked(0);
		int num = 0;
		int capa = w;

		for (int i = 0; i < nofitem; i++) {
			if (pack(i, capa) == pack(i + 1, capa)) continue;
			else {
				picked.push_back(item[i].name);
				capa -= item[i].volume;
				num++;
			}
		}

		cout << result << " " << num << endl;
		for (int i = 0; i < num; i++)
			cout << picked[i] << endl;

	}
}

int pack(int item_index, int capacity) {
	if (item_index == nofitem) return 0;

	if (cache[item_index][capacity] != -1) return cache[item_index][capacity];

	int no_include = pack(item_index + 1, capacity);
	int include = 0;
	if (capacity >= item[item_index].volume)
		include = pack(item_index + 1, capacity - item[item_index].volume) + item[item_index].need;

	cache[item_index][capacity] = max(no_include, include);
	return cache[item_index][capacity];
}