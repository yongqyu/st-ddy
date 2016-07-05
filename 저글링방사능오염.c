#include<stdio.h>

void zerglingPollution(int * map,int * map_count, int mapX, int mapY, int curX, int curY, int count){
        int sideX[4] = {-1,0,1,0};
        int sideY[4] = {0,-1,0,1};
        int i, max_count,temp_count;

        map[mapX* curY + curX] = 2;
        map_count[mapX* curY + curX] = count;
        for(i=0 ; i<4 ; i++)
        {
                if(curX+sideX[i]>=mapX || curX+sideX[i]<0 || curY+sideY[i]>=mapY || curY+sideY[i]<0)
                        continue;
                if(map[mapX* (curY+sideY[i]) + (curX + sideX[i])] != 0 &&
                map_count[mapX* (curY+sideY[i]) + (curX + sideX[i])] > count+1 )
                        zerglingPollution(map,map_count, mapX, mapY, curX+sideX[i], curY+sideY[i], count +1);
        }

}

int main(){
        int X, Y;
        int * map,* map_count;
        int pollutionX, pollutionY;
        char line[100];
        int i,j;
        int count;
        int zero_count;

        scanf("%d %d", &X, &Y);
        map = (int *)malloc(sizeof(int)*X*Y);
        map_count = (int *)malloc(sizeof(int)*X*Y);
        for(i=0 ; i<Y ; i++){
                scanf("%s",line);
                for(j=0 ; j<X ; j++){
                        map[i*X + j] =line[j] - '0';
                }
        }
        for(i=0 ; i<Y ; i++){
                for(j=0 ; j<X ; j++)
                        map_count[i*X + j] =200;
        }

        scanf("%d %d", &pollutionX, &pollutionY);
        pollutionX--; pollutionY--;
        count=0;
        if(map[X*pollutionY + pollutionX]==1)
                zerglingPollution(map,map_count, X, Y, pollutionX, pollutionY, 0);

        for(i=0 ; i<Y ; i++){
                for(j=0 ; j<X ; j++){
//                        printf("%d ", map_count[i*X + j]);
                        if(count<map_count[i*X + j] && map_count[i*X + j]<200)
                                count = map_count[i*X + j];
                }
//              printf("\n");
        }


        zero_count=0;
        for(i=0 ; i<Y ; i++)
                for(j=0 ; j<X ; j++)
                        if(map[i*X + j]==1)
                                zero_count++;

        printf("%d\n", count+3);
        printf("%d\n", zero_count);


        return 0;
}
b111077@park:~$ #include<stdio.h>
b111077@park:~$
b111077@park:~$ void zerglingPollution(int * map,int * map_count, int mapX, int mapY, int curX, int curY, int count){
bash: syntax error near unexpected token `('
b111077@park:~$         int sideX[4] = {-1,0,1,0};
        int X, Y;
        int * map,* map_count;
        int pollutionX, pollutionY;
        char line[100];
        int i,j;
        int count;
        int zero_count;

        scanf("%d %d", &X, &Y);
        map = (int *)malloc(sizeof(int)*X*Y);
        map_count = (int *)malloc(sizeof(int)*X*Y);
        for(i=0 ; i<Y ; i++){
                scanf("%s",line);
                for(j=0 ; j<X ; j++){
                        map[i*X + j] =line[j] - '0';
                }
        }
        for(i=0 ; i<Y ; i++){
                for(j=0 ; j<X ; j++)
                        map_count[i*X + j] =200;
        }

        scanf("%d %d", &pollutionX, &pollutionY);
        pollutionX--; pollutionY--;
        count=0;
        if(map[X*pollutionY + pollutionX]==1)
                zerglingPollution(map,map_count, X, Y, pollutionX, pollutionY, 0);

        for(i=0 ; i<Y ; i++){
                for(j=0 ; j<X ; j++){
//                        printf("%d ", map_count[i*X + j]);
                        if(count<map_count[i*X + j] && map_count[i*X + j]<200)
                                count = map_count[i*X + j];
                }
//              printf("\n");
        }


        zero_count=0;
        for(i=0 ; i<Y ; i++)
                for(j=0 ; j<X ; j++)
                        if(map[i*X + j]==1)
                                zero_count++;

        printf("%d\n", count+3);
        printf("%d\n", zero_count);


        return 0;
}
