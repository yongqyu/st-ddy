//
//  main.cpp
//  QUADTREE
//
//  Created by yongqyu on 2016. 6. 28..
//  Copyright © 2016년 yongqyu. All rights reserved.
//

#include <iostream>
#include <string.h>

using namespace std;

class QT{
public:
    char value;
    QT *sub[2][2];
    
    void initialize();
    void print_value();
};

void QT::initialize()
{
    QT **temp = new QT*[2];
    for(int i = 0; i<2; ++i)
    {
        temp[i] = new QT[2];
        memset(temp[i], 0, sizeof(QT)*2);
    }
    
    for(int i = 0; i<2; i++)
        for(int j = 0; j<2; j++)
            sub[i][j] = &temp[i][j];
    
    
    for(int i = 0; i<2; i++)
        for(int j = 0; j<2; j++)
            sub[i][j]->value = 0;
}
void QT::print_value()
{
    cout << value;
    
    if (value != 'x')
        return;
    else
    {
        if(sub[0][0]->value != 0)
        {
            
            
            sub[1][0]->print_value();
            sub[1][1]->print_value();
            sub[0][0]->print_value();
            sub[0][1]->print_value();
        }
    }
}

string input_data(QT* root, string input);

string input_data(QT* root, string input)
{
    root->value = input[0];
    
    if (root->value != 'x')
    {
        //printf("%c",root->value);
        return input.erase(0,1);
    }
    else
    {
        string ret;
        
        root->initialize();
        
        input = input_data(root->sub[0][0], input.erase(0,1));
        input = input_data(root->sub[0][1], input);
        input = input_data(root->sub[1][0], input);
        ret = input_data(root->sub[1][1], input);
        
        return ret;
    }
}

int main(int argc, const char * argv[]) {
    
    int C = 0;
    string input;
    
    std::cin >> C;
    
    for(int i = 0; i<C; i++)
    {
        QT root;
        std::cin >> input;
        input_data(&root, input);
        
        root.print_value();
        cout << endl;
    }
}
