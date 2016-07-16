//
//  main.cpp
//  PLUMTREE
//
//  Created by yongqyu on 2016. 7. 16..
//  Copyright © 2016년 yongqyu. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int T, W, i;
int input[1001];
int dp[1001][2][31];

int move(int t, int now, int w)
{
    int a, b;
    
    input[t]==now ? dp[t][now][w] = 1 : dp[t][now][w] = 0;
    
    if(t==1)
        return dp[t][now][w];
    
    dp[t-1][now][w] ? a= dp[t-1][now][w] : a = move(t-1, now, w);
    
    w>0 ? ( dp[t-1][now^1][w-1] ? b = dp[t-1][now^1][w-1] : b = move(t-1, now^1, w-1) ) : b=a;
    
    a > b ? dp[t][now][w]+=a : dp[t][now][w]+=b;
    
    return dp[t][now][w];
}

int main() {
    
    int a, b;
    
    cin >> T >> W;
    
    for(i = T; i>0; i--)
    {
        cin >> input[i];
        input[i]-=1;
    }
    
    a = move(T, 0, W);
    b = move(T, 1, W);
    
    a > b ? cout << a << endl : cout << b << endl;
    
    return 0;
}
