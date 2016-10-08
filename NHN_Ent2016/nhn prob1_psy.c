#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

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
  	int min_distance_index;

  	sort(numbers.begin(), numbers.end());
  
  	min_distance_index = 0;
  	for(int i=1 ; i<numbers.size()-1 ; i++){
    	if(numbers[min_distance_index+1] - numbers[min_distance_index] > numbers[i+1] - numbers[i]){
        min_distance_index = i;
      }
    }
  
  	cout << numbers[min_distance_index] << " " << numbers[min_distance_index+1] << endl;
    // 다음과 같은 방식으로 numbers 벡터와 number 변수를 사용할 수 있음
    /*
    for_each(numbers.begin(), numbers.end(), [] (int number) {
            cout << "number=" << number << endl;
        });
    cout << numbers[0] << endl;
    for (vector<int>::const_iterator iter = numbers.begin(); iter != numbers.end(); ++iter) {
        cout << "number=" << *iter << endl;
    }
    */
   
    return 0;
}