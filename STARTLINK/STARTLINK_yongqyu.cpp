
#include <iostream>
#include <queue>
using namespace std;

int F, S, G, U, D;
int floor[1000001];

queue<int> Q;
queue<int> C;

int main() {
    ios::sync_with_stdio(false);
    int temp, flag=0;
    int ret=0;
    
    cin >> F >> S >> G >> U >> D;
    
    floor[S]=1;
    Q.push(S);
    C.push(0);
    while(!Q.empty())
    {
        temp = Q.front();
        
        if(temp>F || temp<1)
        {
            Q.pop();
            C.pop();
        }
        else if(temp==G)
        {
            ret=C.front();
            flag=1;
            break;
        }
        else
        {
            ret = C.front();
            floor[temp]=1;
            ret++;
            
            Q.pop();
            C.pop();
            
            if(temp+U<=F && floor[temp+U]!=1)
            {
                floor[temp+U]=1;
                Q.push(temp+U);
                C.push(ret);
            }
            if(temp-D>=1 && floor[temp-D]!=1)
            {
                floor[temp-D]=1;
                Q.push(temp-D);
                C.push(ret);
            }
        }
    }
    
    switch(flag)
    {
        case 0:
            cout << "use the stairs" << endl;
            break;
        case 1:
            cout << ret << endl;
            break;
    }
    return 0;
}
