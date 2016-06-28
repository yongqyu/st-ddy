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

//class QT
//describe : quadtree node
//attribute value - value what this node has
//          sub - sub is 4 subtree. order is [0][0],[0][1],[1][0],[1][1]
//                after process, print [1][0],[1][1],[0][0],[0][1]
//
//function initialize() - initialize 4 subtree by dynamic allocate and value by 0
//         print_value() - print own value and sub's value
//
class QT{
public:
    char value;
    QT *sub[2][2];
    
    void initialize();
    void print_value();
};

//function void QT::initialize()
//describe : initialize 4 subtree by dynamic allocate and value by 0
void QT::initialize()
{
    QT **temp = new QT*[2];
    for(int i = 0; i<2; ++i)
    {
        temp[i] = new QT[2];
        memset(temp[i], 0, sizeof(QT)*2);
        //memset is memory set by 0 for temp[i]
        //and It need string.h header
    }
    
    for(int i = 0; i<2; i++)
        for(int j = 0; j<2; j++)
            sub[i][j] = &temp[i][j];
    
    for(int i = 0; i<2; i++)
        for(int j = 0; j<2; j++)
            sub[i][j]->value = 0;
}

//function void QT::print_value()
//describe : print own value and sub's value by processed order
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

//declaration due to recursive call
string input_data(QT* root, string input);

//function string input_data(QT* root, string input)
//describe : input first string data at own value
//           if data is not x, return rest string
//           else recursive call by each subtree, rest string
//
//return : rest string except own value
//
//parameter root - root of subtree
//          input - thr rest input string
//
string input_data(QT* root, string input)
{
    root->value = input[0];
    
    if (root->value != 'x')
        return input.erase(0,1);
    else
    {
        string ret;
        
        root->initialize();     //이거 버그인 듯 한데 왜 성공했지?
                                //root->value가 0으로 초기화되지않나?
        input = input_data(root->sub[0][0], input.erase(0,1));
        input = input_data(root->sub[0][1], input);
        input = input_data(root->sub[1][0], input);
        ret = input_data(root->sub[1][1], input);
        
        return ret;
    }
}

//int main(int argc, const char * argv[])
//
//attribute C - test case
int main(int argc, const char * argv[]) {
    
    int C = 0;
    string input;
    
    std::cin >> C;
    
    for(int i = 0; i<C; i++)
    {
        QT root;
        std::cin >> input;
        input_data(&root, input);       //input
        
        root.print_value();             //output
        cout << endl;
    }
}
