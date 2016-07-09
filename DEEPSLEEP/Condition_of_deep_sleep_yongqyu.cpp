//
//  main.cpp
//  Condition_of_deep_sleep
//
//  Created by yongqyu on 2016. 7. 9..
//  Copyright © 2016년 yongqyu. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int main() {
    
    char light[100000];
    int N, K, count, i, j = 0;
    cin >> N >> K;
    
    for(i = 0; i < N; i++)
        cin >> light[i];
    
    for(i = 0; i <= N-K; i++)
        if(light[i]=='1')
        {
            light[i]='0';
            for(j = 1; j < K; j++)
                light[i+j]=='0' ? light[i+j]='1' : light[i+j]='0';
            count++;
        }
    
    for(i = N-K+1; i < N; i++)
        if(light[i]=='1')
        {
            cout << "Insomnia" << endl;
            return 0;
        }
    
    cout << count << endl;
    
    return 0;
}
