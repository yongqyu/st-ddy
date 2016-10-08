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


int main(void)
{
    // ǥ�� �Է����κ��� �ִ� 10���� ���ڿ� ��ū�� ���� ���·� ��ȯ����
    vector<string> words = getInput(10);
  	int vow_count, con_count;
  	int vow_flag, con_flag;
  	int vow_output, con_output;
  	char c;  
  // vowel ���� consonant ����
  
  	vow_output = con_output =0;
 		for(int i=0 ; i<words.size() ; i++){
      vow_flag = con_flag = 0;
      vow_count = con_count = 0;
      for(int j=0 ; j<words[i].length() ; j++){
      	 c = words[i][j];
        if(c=='a' || c =='e' || c == 'i' || c == 'o' || c=='u'){
          con_count = 0;
          vow_count ++;
        }
        else{
          vow_count = 0;
          con_count ++;
        }
        if(vow_count >=2)
          vow_flag = 1;
        if(con_count >=3)
          con_flag = 1;
        if(vow_flag && con_flag)
          break;
      }
      if(vow_flag)
        vow_output++;
      if(con_flag)
        con_output++;
    }

  	cout << vow_output <<endl;
  	cout << con_output << endl;
    // ������ ���� �������  words�� word ���ڿ� ������ ����� �� ����
    /*
    for_each(words.begin(), words.end(), [] (string word) {
            cout << "word=" << word << endl;
        });
    cout << words[0] << endl;
    for (vector<string>::const_iterator iter = words.begin(); iter != words.end(); ++iter) {
        cout << "word=" << *iter << endl;
    }
    */

    return 0;
}