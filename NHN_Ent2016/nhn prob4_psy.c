#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <stack>

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
  
  	int first_number1, first_number2, temp;
  
  	for(int i=0 ; i < numbers.size() ; i++)
    {
     	for(int j=0 ; j< numbers.size() - i -1 ; j++){
       	first_number1 = (numbers[j] >= 10 ? numbers[j]/10 : numbers[j]);
        first_number2 = (numbers[j+1] >= 10 ? numbers[j+1]/10 : numbers[j+1]);
        
        if(first_number1 > first_number2){
          temp = numbers[j];
          numbers[j] = numbers[j+1];
          numbers[j+1] = temp;
        }
        else if((first_number1 == first_number2) && (numbers[j]%10 > numbers[j+1]%10)){
          temp = numbers[j];
          numbers[j] = numbers[j+1];
          numbers[j+1] = temp;
        }
      }
    }
		
  	string max_val,min_val;
  	max_val.clear();min_val.clear();

  	for(int i=0 ; i<numbers.size() ; i++){
      if(numbers[i] >= 10){
       	min_val.append(to_string(numbers[i]/10));
        min_val.append(to_string(numbers[i]%10));
      }
      else
        min_val.append(to_string(numbers[i]));
    }
  
    for(int i=numbers.size()-1 ; i>=0; i--){
      if(numbers[i] >= 10){
       	max_val.append(to_string(numbers[i]/10));
        max_val.append(to_string(numbers[i]%10));
      }
      else
        max_val.append(to_string(numbers[i]));
    }
  	stack<int> result;
  	int carry, num1, num2;
  	
  	cout << min_val <<endl;
  	cout << max_val << endl;
  	carry=0;
  	for(int i=min_val.length() -1 ; i>=0 ; i--)
    {
      num1 = min_val[i] - '0';
      num2 = max_val[i] - '0';
      result.push((num1+num2+carry)%10);
      carry = ((num1 + num2 + carry>= 10) ? 1 : 0);
    }
  	if(carry)
      result.push(1);
  	
  while(!result.empty())
  {
    cout << result.top();
    result.pop();
  }
  cout << endl;
    return 0;
}