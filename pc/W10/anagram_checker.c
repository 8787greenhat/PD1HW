#include <stdio.h>
#include <string.h>

int areAnagrams(char str1[], char str2[]) {
   for(int i =0;i<=99;i++)
   {
    int flag = 0;

    for(int j=0;j<=99;j++)
    {
        if(str1[i] == str2[j] )
        {
            flag = 1;
        }
    }

    if((str1[i] == 0 ) && (str2[i] !=0))
    {
        flag =0;
    }

    if(flag ==0)
    {
        printf("No, the strings are not anagrams.");
        return 0;
    }

   }
   printf("Yes, the strings are anagrams.");
}

int main() {
    char str1[100] = {0}, str2[100] = {0};

    scanf("%s", &str1);
    
    scanf("%s", &str2);

    areAnagrams(str1, str2);

    return 0;
}