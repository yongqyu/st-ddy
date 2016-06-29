#include <cstdio>
#include <iostream>
#include <vector>
#include <numeric>

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
        
        int stone, jump, mine_num, ret, i, j = 0;
        int mi = -1;
        typedef unsigned long long ull;
        ull zero = 0;
        vector<ull> mine;
        
        cin >> stone >> jump >> mine_num;   //돌 갯수 >> 점프 칸 수 >> 지뢰 갯수
        
        if(mine_num)    //지뢰가 있다면
        {
            mine.resize(mine_num);
            
            for(i = 0; i<mine_num; i++)
                cin >> mine[i];         //mine에 넣어주기
            
            mi = mine_num -1;           //mi 는 mine index라서 -1
        }
        
        vector < vector<ull> > value;
        for(i = 0; i<stone+1; i++)      //value는 dp저장소. 동적할당으로 생성
        {
            vector<ull> element;
            element.resize(jump);
            value.push_back(element);
        }

        for(i = 0; i<jump; i++)         //적군 맨 앞에서부터 한칸 떨어진곳은 한칸가는곳이 1
        {                               //두칸 떨어진곳은 두칸 가는곳이 1.... 처리
            value[stone-1-i][i] = 1;
        }
        
        for(i = stone; i>=0; i--)
        {
            if(mi>=0)                   //지뢰가 아직 남아있다면
                if(i == mine[mi])       //지금 지뢰 칸이라면
                {
                    value[i].assign(jump, 0);   //그 돌에서 갈 수 있는 방법은 0개로
                    
                    mi--;               //갯수하나 줄이기
                    continue;
                }
            for(j = 0; j<jump; j++)     //1칸점프 부터
                if(stone-1-j == i)      //아까 한칸앞은 한칸점프 1, 두칸앞은 두칸점프 1... 처리 한곳이면 넘어가
                    continue;
                else if(i+j+1<=stone)   //아니면 배열범위 안넘어가는 선에서
                {
                    value[i][j] = accumulate(value[i+j+1].begin(), value[i+j+1].end(), zero) - value[i+j+1][j];
                    zero = 0;
                }   //한칸 점프는 한칸앞에서 한칸 점프 빼고 다 더한 값, 두칸 점프는 두칸 앞에서 두칸 점프 빼고 다 더한 값...
        }
        for(i = 0; i<stone+1; i++)      //이건 제출할때 지워야하는데 그냥 배열 출력해보는 테스트기
        {    for(j =0; j<jump; j++)
            cout << value[i][j] << " ";
            cout <<endl;
        }
        
        ret = accumulate(value[0].begin(), value[0].end(), zero) % 1000000009;  //결과값은 0번 땅의 모든 점프값의 합
        
        // 이 부분에서 정답을 출력하십시오. Codeground 시스템에서는 C++에서도 printf 사용을 권장하며, cout을 사용하셔도 됩니다.
        printf("Case #%d\n", test_case);

        printf("%d\n", ret);
        
    }
    
    return 0;	// 정상종료 시 반드시 0을 리턴해야 합니다.
}