//
//  main.cpp
//  LIS
//
//  Created by yongqyu on 2016. 9. 17..
//  Copyright © 2016년 yongqyu. All rights reserved.
//

#include <iostream>
using namespace std;

int C, N;
int input[500];
int output[500];

void search(int index)
{
    int ret=0;
    
    for(int i = index+1; i<N; i++)
    {
        if(input[i]>input[index])
        {
            if(output[i]<0)
                search(i);
            
            if(output[i] > ret)
                ret=output[i];
        }
    }
    
    output[index]=ret+1;
    
}

int main() {
    ios::sync_with_stdio(false);
    
    cin >> C;
    
    for(int c=0; c<C; c++)
    {
        cin >> N;
        for(int n=0; n<N; n++)
        {
            cin >> input[n];
            output[n]=-1;
        }
        
        for(int i=0; i<N; i++)
            search(i);
        
        int ret=0;
        for(int i=0; i<N; i++)
            if(output[i]>ret)
                ret=output[i];
        
        cout << ret << endl;
        
    }
    return 0;
}
