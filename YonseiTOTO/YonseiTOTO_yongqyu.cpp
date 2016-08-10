//
//  main.cpp
//  YonseiTOTO
//
//  Created by yongqyu on 2016. 8. 6..
//  Copyright © 2016년 yongqyu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

int main() {
    std::ios::sync_with_stdio(false);
    
    int n, m, P[100], L[100];
    std::vector<int> DES;
    std::vector<int> point[100];
    int i, j, tmp=0;
    int count=0;
    
    std::cin >> n >> m;
    
    for(i=0; i<n; i++)
    {
        std::cin >> P[i] >> L[i];
        for(j=0; j<P[i]; j++)
        {
            std::cin >> tmp;
            point[i].push_back(tmp);
        }
        sort(point[i].begin(), point[i].end(), std::greater<int>());
        
        if(P[i] < L[i])
        {
            DES.push_back(1);
        }
        else
        {
            DES.push_back(point[i].at(L[i]-1));
        }
    }
    sort(DES.begin(), DES.end());
    
    for(i=0; m>0 && i<n; i++)
    {
        if(m>=DES.at(i))
        {
            m-=DES.at(i);
            count++;
        }
        else if(m<DES.at(i))
            break;
        else
            continue;
    }
    
    std::cout << count << "\n";
    
    return 0;
}
