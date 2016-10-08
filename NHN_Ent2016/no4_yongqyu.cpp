#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

int one[10][10];
int each[10];
int ret[10];

int big[20];
int small[20];
int sum[21];

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
    unsigned long size=0;
    int i=0, j=0, index=0, index_for_0=0;
    int jusq=0;
    
    // 표준 입력으로부터 최대 10개의 자연수를 벡터 형태로 읽어들임
    vector<int> numbers = getInput(10);
    
    //십 곱하고 더하고
    sort(numbers.begin(), numbers.end());
    
    size=numbers.size();
    
    for(i=0; i<10; i++)
    {
        index=0;
        
        for(; j<size; j++)
            if(numbers[j]>=((i+1)*10))
                break;
            else
                one[i][index++]=numbers[j];
        
        each[i]=index;
    }
    
    index=0;
    jusq=one[0][index_for_0]*11;
    
    for(i=1; i<10; i++)
    {
        for(j=0; j<each[i]; j++)
        {
            if(jusq>one[i][j])
            {
                ret[index++]=one[i][j];
            }
            else if(jusq<=one[i][j])
            {
                ret[index++]=one[0][index_for_0++];
                ret[index++]=one[i][j];
                
                if(index_for_0<each[0])
                    jusq=one[0][index_for_0]*11;
                else
                    jusq=100;
            }
        }
        
        if(index==size)
            break;
    }
    
    if(index_for_0<each[0])
        for(i=index_for_0; i<each[0]; i++)
            ret[index++]=one[0][i];
    
    
    index=0;
    for(i=0; i<size; i++)
    {
        if(ret[i]>=10)
        {
            big[index++]=ret[i]/10;
            big[index++]=ret[i]%10;
        }
        else
            big[index++]=ret[i];
    }
    
    index=0;
    for(i=size-1; i>=0; i--)
    {
        if(ret[i]>=10)
        {
            small[index++]=ret[i]/10;
            small[index++]=ret[i]%10;
        }
        else
            small[index++]=ret[i];
    }
    
    for(i=0; i<10; i++)
    {
        sum[i]+=small[i]+big[i];
        if(sum[i]>=10)
        {
            
            sum[i+1]=sum[i]/10;
            sum[i]=sum[i]%10;
        }
    }
    
    for(i=0; i<10; i++)//10212249 92422110
        cout << sum[i];
    
    cout << endl;
    
    
    
    return 0;
}