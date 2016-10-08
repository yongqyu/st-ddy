#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

int dist[9];

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

int main()
{
    int i =0;
    int temp, index=0;
    unsigned long size;
    vector<int> numbers = getInput(10);
    
    ios::sync_with_stdio(false);
    
    size = numbers.size();
    
    sort(numbers.begin(), numbers.end());
    
    for(i=0; i<size-1; i++)
        dist[i]=numbers.at(i+1)-numbers.at(i);
    
    temp=dist[0];
    index = 0;
    for(i=1; i<size-1; i++)
        if(dist[i]<temp)
        {
            index = i;
            temp=dist[i];
        }
    
    cout << numbers.at(index) << " " << numbers.at(index+1) << endl;
    return 0;
}