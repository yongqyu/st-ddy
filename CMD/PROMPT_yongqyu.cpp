//
//  main.cpp
//  PROMPT
//
//  Created by yongqyu on 2016. 9. 10..
//  Copyright © 2016년 yongqyu. All rights reserved.
//

#include <iostream>
using namespace std;

int N;
int length;
char input[50][51];

int main() {
    ios::sync_with_stdio(false);
    
    int i = 0;
    
    cin >> N;
    
    for(i =0; i<N; i++)
        cin >> input[i];
    
    
    for(i =0; ;i++)
    {
        if(!input[0][i])
            break;
    }
    
    length = i;
    
    for(i=0; i<length; i++)
    {
        for(int j=1; j<N; j++)
        {
            if(input[0][i]!=input[j][i])
            {
                input[0][i]='?';
                break;
            }
        }
    }
    
    cout << input[0] << endl;
    
    
    return 0;
}
