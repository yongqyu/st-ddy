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

bool test(char s)
{
    if(s=='i' || s=='o' || s=='a' || s=='e' || s=='u')
        return false;
    else
        return true;
}

int main(void)
{
    int i, j = 0;
    int jaem=0, moem=0;
    unsigned long length=0;
    bool flag=false; //false == moem, true == jaem
    bool pre_flag=false;
    bool flag_j = false, flag_m = false;
    int ret_j=0, ret_m=0;
    
    // 표준 입력으로부터 최대 10개의 문자열 토큰을 벡터 형태로 반환받음
    vector<string> words= getInput(10);

    unsigned long size = words.size();
    
    for(i=0; i<size; i++)
    {
        jaem=moem=0;
        flag_j=flag_m=false;
        
        length=words[i].length();
        
        pre_flag=test(words[i][0]);
        
        if(pre_flag)
        {
            jaem=1;
        }
        else
            moem=1;
        
        for(j=1; j<length; j++)
        {
            flag=test(words[i][j]);
            if(pre_flag==flag)
            {
                if(flag)
                    jaem++;
                else
                    moem++;
                
                if(jaem==3)
                    flag_j=true;
                if(moem==2)
                    flag_m=true;
            }
            else
            {
                pre_flag=flag;
                
                if(flag)
                {
                    jaem=1;
                    moem=0;
                }
                else
                {
                    jaem=0;
                    moem=1;
                }
            }
        }
        
        if(flag_j)
            ret_j++;
        if(flag_m)
            ret_m++;
    }
    
    cout << ret_m << endl << ret_j << endl;
    
    return 0;
}