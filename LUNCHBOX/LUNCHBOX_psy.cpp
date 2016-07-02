#include <iostream>
#include <algorithm>
#include <vector>
#include<functional>
#include <list>
using namespace std;

struct LUNCH{
	int M;
	int E;
};

template <typename T> struct COMPARE_E{
	bool operator()(const T l, const T r) const{
		return l.E > r.E;
	}
};

int main(){
	int count;
	cin >> count;

	for (int k = 0; k < count; k++){
		int N;
		cin >> N;
		int*M = new int[N];
		int*E = new int[N];
		for (int i = 0; i < N; i++){
			cin >> M[i];
		}
		for (int i = 0; i < N; i++){
			cin >> E[i];
		}

		list < LUNCH > l;
		list<LUNCH>::iterator iter;
		for (int i = 0; i < N; i++){
			LUNCH temp;
			temp.M = M[i];
			temp.E = E[i];
			l.push_back(temp);
		}

		l.sort(COMPARE_E< LUNCH >());
		sort(E, E+N, greater<int>());
		int time = 0;
		int eat_time = 0;
		int i;

		for (iter = l.begin(), i = 0; iter != l.end(); iter++, i++){
			time = time + iter->M;
			for (int j = i - 1; j >= 0; j--){
				E[j] -= iter->M;
			}
		}

		int max=0;
		for (int i = 0; i < N; i++){
			if (E[i]>max)max = E[i];
		}
		time += max;

		cout << time << endl;
	}
}

/*vector<pair<int, int>> v;
vector<pair<int, int>>::iterator iter;
for (int i = 0; i < N; i++){
v.push_back(pair<int,int>(M[i],E[i]));
}

sort(v.begin(), v.end());

for (iter=v.begin(); iter!=v.end(); iter++){
cout << iter->first << " " << iter->second << endl;
}*/