//
//  main.cpp
//  MOUNTAIN
//
//  Created by yongqyu on 2016. 9. 17..
//  Copyright © 2016년 yongqyu. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

struct Loc
{
    int x;
    int y;
};

int size;
int mount[100][100];
int dp[100][100];
Loc top;
queue<Loc> Q;

int tired(Loc from, Loc to)
{
    int ret=0;
    int heigh_f=mount[from.x][from.y];
    int heigh_t=mount[to.x][to.y];

    if(heigh_f==heigh_t)
        ret=0;
    else if(heigh_f>heigh_t)
    {
        ret=heigh_f-heigh_t;
    }
    else
    {
        ret = (heigh_t-heigh_f)*(heigh_t-heigh_f);
    }
    
    if(dp[to.x][to.y]>0 && dp[from.x][from.y] + ret>=dp[to.x][to.y])
        return -1;
    else
    {
        dp[to.x][to.y] = dp[from.x][from.y] + ret;
        return dp[to.x][to.y];
    }
}

void move(Loc loc)
{
    int ret = 0;
    Loc to;
    
    if(loc.x-1>=0)
    {
        to.x=loc.x-1; to.y=loc.y;
        ret=tired(loc, to);
        
        if(ret>0)
            Q.push(to);
    }
    
    if(loc.x+1<size)
    {
        to.x=loc.x+1; to.y=loc.y;
        ret=tired(loc, to);
        
        if(ret>0)
            Q.push(to);
    }
    
    if(loc.y-1>=0)
    {
        to.x=loc.x; to.y=loc.y-1;
        ret=tired(loc, to);
        
        if(ret>0)
            Q.push(to);
    }
    
    if(loc.y+1<size)
    {
        to.x=loc.x; to.y=loc.y+1;
        ret=tired(loc, to);
        
        if(ret>0)
            Q.push(to);
    }
}

int main() {
    ios::sync_with_stdio(false);
    
    int i, j=0;
    Loc temp;
    
    cin >> size;
    cin >> top.x >> top.y;
    
    for(i=0; i<size; i++)
        for(j=0; j<size; j++)
        {
            cin >> mount[i][j];
            dp[i][j]=-1;
        }
    
    for(i=0; i<size; i++)
    {
        temp.x=0; temp.y=i;
        Q.push(temp);
        dp[0][i]=mount[0][i]*mount[0][i];
        
        temp.x=size-1;
        Q.push(temp);
        dp[size-1][i]=mount[size-1][i]*mount[size-1][i];
        
        temp.x=i; temp.y=0;
        Q.push(temp);
        dp[i][0]=mount[i][0]*mount[i][0];
        
        temp.y=size-1;
        Q.push(temp);
        dp[i][size-1]=mount[i][size-1]*mount[i][size-1];
    }
    
    while(!Q.empty())
    {
        temp=Q.front();
        move(temp);
        Q.pop();
    }
    
    cout << dp[top.x-1][top.y-1] << endl;
    
    return 0;
}
