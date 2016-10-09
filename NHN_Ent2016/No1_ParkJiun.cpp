#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
const int INF = 0x79999999;

using namespace std;

vector<int> getInput(ssize_t sizeLimit)
{
    vector<int> tokenVector;
    string line;
    getline(cin, line);
    istringstream iss(line);
    string token;
    while (getline(iss, token, ' ')) {
        try {
            tokenVector.push_back(stoi(token));
        } catch (exception& e) {
            continue;
        }
        if (tokenVector.size() >= sizeLimit) {
            break;
        }
    }
    return tokenVector;
}


int main(void)
{
    // 표준 입력으로부터 최대 10개의 자연수를 벡터 형태로 읽어들임
    vector<int> numbers = getInput(10);
    int from, to, sum = 0, dif = 0;

		sort(numbers.begin(), numbers.end());
		int min_dif = INF;
  	int nofnum = numbers.size();
  
  	for(int i = 0; i<nofnum-1; ++i){
      int tmp = numbers[i+1] - numbers[i];
      if(tmp < min_dif){
        sum = numbers[i]+numbers[i+1];
        from = numbers[i]; to = numbers[i+1];
        min_dif = tmp;
      }
    }
  
		cout << from << " " << to<< "\n";
    
    return 0;
}