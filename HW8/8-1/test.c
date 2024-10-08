#include <stdio.h>
#include <stdlib.h>
#include "hw8-1.h"


void init(int*** mp)
{
    int i,j,k;

    for(i = 0; i< 5;i++)
    {
        mp[i] = (int**)malloc(5* sizeof(int*));

        for(j = 0;j< 5;j++)
        {
            mp[i][j] = (int*)malloc(5*sizeof(int));

            for(k = 0;k <5;k++)
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

int query(int ****mp,char a[4],char b[4])
{
    return 1;
}

int main()
{
    int*** mp;
    mp = (int***)malloc( 5 * sizeof(int**) );
    init(mp);

    int q = 1000;
    while(q--)
    {
        int opt;
        scanf("%d",&opt);
        if( opt == 1 )
        {
            char str[4] = {};
            int val;

            scanf("%s %d",str,&val);

            int* pos = &(mp[(int)str[0]][(int)str[1]][(int)str[2]]);
            modify(pos,val);
        }
        else
        {
            char a[4],b[4];
            scanf("%s %s",a,b);
            int check = query(&mp,a,b);

            printf( ( check == 1 ? "YES\n" : "NO\n" )  );
        }
    }

    return 0;
}     