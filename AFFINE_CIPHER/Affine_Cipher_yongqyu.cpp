//
//  main.cpp
//  Affine_Cipher
//
//  Created by yongqyu on 2016. 7. 9..
//  Copyright © 2016년 yongqyu. All rights reserved.
//

#include <iostream>
#include <string.h>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int C = 0;
    cin >> C;
    
    for(int Case = 0; Case < C; Case++)
    {
        long a, b = 0;
        string input;
        
        cin >> a >> b;
        
        cin >> input;
        
        long end = input.size();
        for(long i = 0; i <end; i++)
        {
            input[i] = (a * (input[i] - 'A') + b)%26 + 'A';
        }
        cout << input << endl;;
    }
    return 0;
}
