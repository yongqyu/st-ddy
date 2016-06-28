//
//  main.cpp
//  JUMPGAME
//
//  Created by yongqyu on 2016. 6. 28..
//  Copyright © 2016년 yongqyu. All rights reserved.
//

#include <iostream>
#include <string.h>

using namespace std;

int **area;

bool check(int x, int y)
{
    
    for(int i = x-1; i >= 0; i--)
        if(area[i][y] == x-i)
        {
            if(i == 0 && y == 0)
                return true;
            else
                if(check(i, y))
                    return true;
        }
    
    for(int j = y-1; j >= 0; j--)
        if(area[x][j] == y-j)
        {
            if(x == 0 && j == 0)
                return true;
            else
                if(check(x, j))
                    return true;
        }
    return false;
}

int main(int argc, const char * argv[]) {
    
    int C = 0;
    cin >> C;
    
    for(int Case = 0; Case < C; Case++)
    {
        int size = 0;
        cin >> size;
        area = new int*[size];
        for(int i = 0; i < size; i++)
        {
            area[i] = new int[size];
            memset(area[i], 0, sizeof(int)*size);
        }
        
        for(int i = 0; i < size; i++)
            for(int j = 0; j < size; j++)
                cin >> area[i][j];
        
        if(check(size-1, size-1))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
        
        for(int i = 0; i < size; i++)
            delete []area[i];
        delete []area;
    }
    return 0;
}
