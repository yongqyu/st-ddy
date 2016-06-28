//
//  main.cpp
//  TRIANGLEPATH
//
//  Created by yongqyu on 2016. 6. 28..
//  Copyright © 2016년 yongqyu. All rights reserved.
//

#include <iostream>
#include <string.h>

using namespace std;

int **triangle;
int **sum;
int *ans;

int main(int argc, const char * argv[]) {
    int C = 0;
    cin >> C;
    
    ans = new int[C];
    
    for(int Case = 0; Case < C; Case++)
    {
        int size = 0;
        cin >> size;
        triangle = new int*[size];
        sum = new int*[size];
        for(int i = 0; i < size; i++)
        {
            triangle[i] = new int[size];
            memset(triangle[i], 0, sizeof(int)*size);
            sum[i] = new int[size];
            memset(sum[i], 0, sizeof(int)*size);
        }
        
        for(int i = 0; i < size; i++)
            for(int j = 0; j < i+1; j++)
                cin >> triangle[i][j];
        
        for(int i = 0; i < size; i++)
            sum[size-1][i] = triangle[size-1][i];
        
        for(int i = size-2; i>=0; i--)
            for(int j = 0; j<i+1; j++)
            {
                if(sum[i+1][j] > sum[i+1][j+1])
                    sum[i][j] = triangle[i][j] + sum[i+1][j];
                else
                    sum[i][j] = triangle[i][j] + sum[i+1][j+1];
            }
        cout << sum[0][0] << endl;
    }
    return 0;
}
