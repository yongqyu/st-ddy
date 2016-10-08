#include <iostream>
#include <exception>

using namespace std;

int getInput()
{
    string line;
    int number = 0;
    getline(cin, line);
    try {
        number = stoi(line);
    } catch (exception& e) {
        number = -1;
    }
    return number;
}

int flip_number(int input){
  int output=0;
  while(input){
    output *= 10;
    output += input%10;
    input /= 10;
  }
  
  return output;
}

int main(void)
{
    // 표준 입력으로부터 자연수를 읽어들임
    int number = getInput();

  	for(int i=0 ; i<3 ; i++){
      if(number == flip_number(number)){
        break;
      }
      else{
       number = number + flip_number(number); 
      }
    }
  
  	if(number == flip_number(number))
      cout << number << endl;
  	else
      cout << -1 << endl;
    return 0;
}
