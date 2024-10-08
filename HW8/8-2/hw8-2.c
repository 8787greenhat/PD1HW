#include <stdio.h>
#include <stdlib.h>
#include "hw8-2.h"

static int check =0;

void modify(int *pos,int val)
{
    
    *pos = val;

}

int query(int (*mp)[131][131][131], char a[4], char b[4])
{
    if(check == 0)
    {
        int i,j,k;

        for(i = 0; i< 130;i++)
        {
            for(j = 0;j< 130;j++)
            {

                for(k = 0;k <130;k++)
                {
                    (*mp)[i][j][k] = 1;
                }
            }
        }
        check++;
    }

    int a_num = (*mp)[(int)a[0]][(int)a[1]][(int)a[2]];
    int b_num = (*mp)[(int)b[0]][(int)b[1]][(int)b[2]];

    if (a_num == 0)
        a_num = 2;
    if (b_num == 0)
        b_num = 2;

    if ((a_num + b_num) % 2 != 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


