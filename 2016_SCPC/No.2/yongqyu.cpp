#include <cstdio>
#include <iostream>
#include <string.h>

using namespace std;

int main(int argc, char** argv) {
    /* 아래 freopen 함수는 input.txt 를 read only 형식으로 연 후,
     앞으로 표준 입력(키보드) 대신 input.txt 파일로 부터 읽어오겠다는 의미의 코드입니다.
     만약 본인의 PC 에서 테스트 할 때는, 입력값을 input.txt에 저장한 후 freopen 함수를 사용하면,
     그 아래에서 scanf 함수 또는 cin을 사용하여 표준입력 대신 input.txt 파일로 부터 입력값을 읽어 올 수 있습니다.
     또한, 본인 PC에서 freopen 함수를 사용하지 않고 표준입력을 사용하여 테스트하셔도 무방합니다.
     단, Codeground 시스템에서 "제출하기" 할 때에는 반드시 freopen 함수를 지우거나 주석(//) 처리 하셔야 합니다. */
    //freopen("input.txt", "r", stdin);
    
    /* setbuf 함수를 사용하지 않으면, 본인의 프로그램이 제한 시간 초과로 강제 종료 되었을 때,
     C++에서 printf를 사용할 경우, printf로 출력한 내용이 채점되지 않고 '0점'이 될 수도 있습니다.
     따라서 printf를 사용할 경우 setbuf(stdout, NULL) 함수를 반드시 사용하시기 바랍니다. */
    setbuf(stdout, NULL);
    
    int T;
    int test_case;
    
    scanf("%d", &T);	// Codeground 시스템에서는 C++에서도 scanf 함수 사용을 권장하며, cin을 사용하셔도 됩니다.
    for(test_case = 1; test_case <= T; test_case++) {
        // 이 부분에서 알고리즘 프로그램을 작성하십시오. 기본 제공된 코드를 수정 또는 삭제하고 본인이 코드를 사용하셔도 됩니다.
        
        int stone, jump, mine_num, ret = 0;
        int mi = -1;
        int *mine = NULL;
        
        cin >> stone >> jump >> mine_num;
        
        if(mine_num)
        {
            mine = new int[mine_num];
            
            for(int i = 0; i<mine_num; i++)
                cin >> mine[i];
            
            mi = mine_num -1;
        }
        
        int **value = new int*[jump];
        for(int i = 0; i<jump; i++)
        {
            value[i] = new int[stone];
            memset(value[i], 0, sizeof(int)*(stone+1));
        }
        
        for(int i = 0; i<jump; i++)
        {
            value[i][stone-1-i] = 1;
        }
        
        for(int i = stone-1; i>=0; i--)
        {
            if(mi>=0)
                if(i == mine[mi])
                {
                    for(int j = 0; j<jump; j++)
                        value[j][i] = 0;
                    mi--;
                    continue;
                }
            for(int j = 0; j<jump; j++)
                for(int k = 1; k<jump; k++)
                    if(i+j<=stone)
                        value[j][i] += value[(j+k)%jump][i+j+1];
        }
        
        // 이 부분에서 정답을 출력하십시오. Codeground 시스템에서는 C++에서도 printf 사용을 권장하며, cout을 사용하셔도 됩니다.
        printf("Case #%d\n", test_case);
        
        for(int i = 0; i<jump; i++)
            ret += value[i][0];
        ret = ret%1000000009;
        printf("%d\n", ret);
        
    }
    
    return 0;	// 정상종료 시 반드시 0을 리턴해야 합니다.
}