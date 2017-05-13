/*
小甲鱼学习视频
*/
#include<stdio.h>
#define max 8
int mark[8]={0};//标记已被访问过的节点
int chart[max][max]={ {0,1,0,1,1,0,0,0}, {1,0,1,0,1,0,0,0}, {0,1,0,0,0,1,0,0}, {1,0,0,0,0,0,1,0}, {1,1,0,0,0,0,0,0}, {0,0,1,0,0,0,0,0}, {0,0,0,1,1,0,0,1}, {0,0,0,0,0,0,1,0} };

int DFS(int i)
{
    int j;
    for( j=0; j<max; j++)
    {
        if(chart[i][j]==1 && !mark[j])
        {
            printf("被访问的节点：%d\n",j);
            mark[j] = 1;
            DFS(j);
        }
    }
    return i;
}

int main()
{
    printf("被访问的节点：0\n");
    mark[0] = 1;
    DFS(0);
    return 0;
}
