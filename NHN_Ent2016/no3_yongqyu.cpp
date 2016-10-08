#include <iostream>
#include <exception>

using namespace std;

int getInput()
{
    string line;
    int number = 0;
    getline(cin, line);
    try {
        number = stoi(line);
    } catch (exception& e) {
        number = -1;
    }
    return number;
}


int main(void)
{
    // 표준 입력으로부터 자연수를 읽어들임
    int number = getInput();
    int i=0;
    int t,h,d,n,tmp = 0;
    int cmp;
    
    for(i=0; i<3; i++)
    {
        t = number/1000;    tmp=(number-1000*t);
        h = tmp/100;        tmp=(tmp-100*h);
        d = tmp/10;         n=(tmp-10*d);
        
        if(t==0 && h == 0 && d == 0)
        {
            cmp = n;
            number = cmp + number;
            
            if(d==0)
            {
                cout << number << endl;
                return 0;
            }
            else if(d==n)
            {
                cout << number << endl;
                return 0;
            }
        }
        else if(t==0 && h==0)
        {
            cmp = n*10 + d;
            number = cmp + number;
            
            h = tmp/100;        tmp=(tmp-100*h);
            d = tmp/10;         n=(tmp-10*d);
            
            if(h==0)
            {
                if(d==n)
                {
                    cout << number << endl;
                    return 0;
                }
            }
            else if(h==n)
            {
                cout << number << endl;
                return 0;
            }
        }
        else if(t==0)
        {
            cmp = n*100 + d*10 + h;
            number = cmp + number;
            
            t = number/1000;    tmp=(number-1000*t);
            h = tmp/100;        tmp=(tmp-100*h);
            d = tmp/10;         n=(tmp-10*d);
            
            if(t==0)
            {
                if(h==n)
                {
                    cout << number << endl;
                    return 0;
                }
            }
            else if(t==n)
            {
                if(h==d)
                {
                    cout << number << endl;
                    return 0;
                }
            }
            
        }
        else
        {
            cmp = n*1000 + d*100 + h*10 + t;
            number = cmp + number;
            
            t = number/1000;    tmp=(number-1000*t);
            h = tmp/100;        tmp=(tmp-100*h);
            d = tmp/10;         n=(tmp-10*d);
            
            if(t==n)
                if(h==d)
                {
                    cout << number << endl;
                    return 0;
                }
        }
        
        if(i==2)
            cout << "-1" << endl;
        
    }
    
    return 0;
}
