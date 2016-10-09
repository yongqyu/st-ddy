#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

vector<string> getInput(ssize_t sizeLimit)
{
    vector<string> tokenVector;
    string line;
    getline(cin, line);
    istringstream iss(line);
    string token;
    while (getline(iss, token, ' ')) {
        tokenVector.push_back(token);
        if (tokenVector.size() >= sizeLimit) {
            break;
        }
    }
    return tokenVector;
}

bool checkAEIOU(char c) {
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
	return false;
}

int main(void)
{
    // 표준 입력으로부터 최대 10개의 문자열 토큰을 벡터 형태로 반환받음
    vector<string> words = getInput(10);

  	int nofstr = words.size();
    int cntM = 0, cntJ = 0;

    for (int i = 0; i < nofstr; ++i) {
      int M = 0, J = 0;
      int len = words[i].length();
      for (int j = 0; j < len; ++j) {
        if (checkAEIOU(words[i][j])) {
          if (J == 3) cntJ++;
          J = 0;
          M++;

        }
        else {
          if (M == 2) cntM++;
          M = 0;
          J++;
        }
      }
      if (M == 2) cntM++;
			if (J == 3) cntJ++;
    }

    cout << cntM << "\n" << cntJ << "\n";
    return 0;
}