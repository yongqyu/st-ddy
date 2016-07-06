#include <stdio.h>
#include <string.h>

void fillTheTile(int * map, int initN, int N, int sewerX, int sewerY){
        if(N==1)
                return;
        int side = 0;
        side = (N/2 <= sewerX) ? 3 : 1;
        side = (N/2 <= sewerY) ? side+1 : side;
        // 하수구가 몇사분면에 있는지 구함

        int * centerOfMap = map + (initN * (N/2) + N/2);
        int * nextMap;
        int fillX[5] = {0,-1, -1 ,0, 0};
        int fillY[5] = {0, -1, 0, -1, 0};
        int i;

        for(i=1 ; i <= 4 ; i++)
        {
                nextMap = centerOfMap + (fillX[i] * initN * (N/2) + fillY[i] * (N/2));
                if(i!=side){
                        *(centerOfMap + fillX[i]*initN + fillY[i]) = side;
                        fillTheTile(nextMap,initN, N/2,
                                        (-fillX[i])*N/2+fillX[i],(-fillY[i])* N/2+fillY[i]);
                }
                else
                        fillTheTile(nextMap, initN, N/2,
                                sewerX >= N/2 ? sewerX - N/2 : sewerX,
                                sewerY >= N/2 ? sewerY - N/2 : sewerY);
        }
}

int main(void)
{
        int N;
        int X, Y;
        int * map;
        int i,j;

        scanf("%d",&N);
        map = (int *)malloc(sizeof(int)*N*N);
        memset(map, 0, N*N);

        scanf("%d %d", &X, &Y);
        fillTheTile(map, N, N, X, Y);
        for(i=0 ; i<N ; i++)
                for(j=0 ; j<N ; j++){
                        printf("%d", map[i*N + j]);
                        if(j!=N-1)
                                printf(" ");
                        else
                                printf("\n");
                }
        return 0;
}
