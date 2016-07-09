//
//  main.cpp
//  Base_Conversion
//
//  Created by yongqyu on 2016. 7. 9..
//  Copyright © 2016년 yongqyu. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    
    int A, B, m, i = 0;
    cin >> A >> B;
    
    cin >> m;
    vector<int> output;
    
    int ret = 0;
    
    for(i = m-1; i >= 0; i--)
    {
        int input;
        
        cin >> input;
        
        ret += input * pow(A, i);
    }
    
    for(i = 0; ret!=0; i++)
    {
        output.push_back(ret%B);
        ret = ret/B;
    }
    
    cout << output.at(output.size()-1);
    for(i = output.size()-2; i>= 0; i--)
        cout << " " << output[i];
    cout << endl;
    
    return 0;
}
