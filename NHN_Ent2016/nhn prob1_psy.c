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
    // ǥ�� �Է����κ��� �ִ� 10���� �ڿ����� ���� ���·� �о����
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
    // ������ ���� ������� numbers ���Ϳ� number ������ ����� �� ����
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