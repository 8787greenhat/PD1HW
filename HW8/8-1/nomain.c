#include <stdio.h>
#include <stdlib.h>

void init(int*** mp)
{
    int i,j,k;

    for(i = 0; i< 130;i++)
    {
        mp[i] = (int**)malloc(130* sizeof(int*));

        for(j = 0;j< 130;j++)
        {
            mp[i][j] = (int*)malloc(130*sizeof(int));

            for(k = 0;k <130;k++)
            {
                mp[i][j][k] = 1;
            }
        }
    }

}

void modify(int *pos,int val)
{
    *pos = val;
}


int query(int**** mp,char a[4],char b[4])
{
    int ***arr = *mp;
    int a_num = arr[(int)a[0]][(int)a[1]][(int)a[2]];
    int b_num = arr[(int)b[0]][(int)b[1]][(int)b[2]];

    if(a_num == 0) a_num =2;
    if(b_num == 0) b_num =2;

    if((a_num+b_num)%2!=0)
    {
        return 1;
    }else{
        return 0;
    }
    
}

