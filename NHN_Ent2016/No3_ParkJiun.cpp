#include <iostream>
#include <string>
#include <exception>

using namespace std;

int ReversPlus(int num) {
	int ret;
	if (num < 10) {
		ret = num + num;
		return num;
	}
	else if (num < 100) {
		int tmp = (num % 10) * 10 + (num / 10);
		ret = tmp + num;
		return ret;
	}
	else {
		int tmp = (num % 10) * 100 + (num / 100) + (((num - ((num / 100) * 100)) / 10) * 10);
		ret = tmp + num;
		return ret;
	}
}

bool check(int num) {
	if (num < 10) {
		return true;
	}
	else if (num < 100) {
		int tmp = (num % 10) * 10 + (num / 10);
		if (tmp == num) return true;
	}
	else if (num < 1000) {
		int tmp = (num % 10) * 100 + (num / 100) + (((num - ((num / 100) * 100)) / 10) * 10);
		if (tmp == num) return true;
	}
	else {
		int tmp = (num % 10) * 1000 + (num / 1000) + ((num - (num / 100) * 100) / 10) * 100 + (num - (num / 1000) * 1000) * 10;
		if (tmp == num) return true;
	}
	return false;
}


int main(void)
{
	// 표준 입력으로부터 자연수를 읽어들임
	int number;
	cin >> number;
	for (int i = 0; i < 3; i++) {
		number = ReversPlus(number);
		if (check(number)) {
			cout << number << "\n";
			return 0;
		}
	}
	cout << "-1\n";
	return 0;
}
