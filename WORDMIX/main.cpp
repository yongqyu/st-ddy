//
//  main.cpp
//  WORDMIX
//
//  Created by yongqyu on 2016. 9. 4..
//  Copyright © 2016년 yongqyu. All rights reserved.
//

#include <iostream>
using namespace std;

int c;
char input1[201];
char input2[201];
char output[401];
int branch[200][200];

bool compare(int, int, int);

int main() {
    ios::sync_with_stdio(false);
    
    cin >> c;
    
    for(int i = 0; i < c; i++)
    {
        for(int j = 0; j<201; j++)
        {
            input1[j]=0;
            input2[j]=0;
        }
        for(int j = 0; j<401; j++)
            output[j]=0;
        for(int j = 0; j<200; j++)
            for(int k = 0; k<200; k++)
                branch[j][k]=0;

        cin >> input1 >> input2 >> output;
        
        bool ret = compare(0,0,0);
        
        if(ret)
            cout << "Data set " << i+1 << ": yes\n";
        else
            cout << "Data set " << i+1 << ": no\n";
    }
    return 0;
}

bool compare(int a, int b, int c)
{
    while(output[c])
    {
        if(input1[a]==output[c] && input2[b]==output[c])
        {
            if(branch[a][b]==1)
                return true;
            else if(branch[a][b]==2)
                return false;
            else
            {
                if((compare(a, b+1, c+1) || compare(a+1, b, c+1))==true)
                {
                    branch[a][b]=1;
                    return true;
                }
                else
                {
                    branch[a][b]=2;
                    return false;
                }
            }
        }
        else if(input1[a]==output[c] && input2[b]!=output[c])
        {
            a++;
            c++;
        }
        else if(input1[a]!=output[c] && input2[b]==output[c])
        {
            b++;
            c++;
        }
        else
        {
            return false;
        }
    }
    
    return true;
}