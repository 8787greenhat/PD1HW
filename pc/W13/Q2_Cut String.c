#include<stdio.h>
#define N 100

int read_line(char str[], int n)
{
    int ch, i = 0;

    while ((ch = getchar()) != '\n')
        if (i < n)
        str[i++] = ch;
    str[i] = '\0';   /* terminates string */
    return i;        /* number of characters stored */
}


int CutString(char** substr, char* str, char* cut)
{
	
    int index = 0;
    int cut_long = 0;
    int i = 0;
    substr[1] = str;

    while(cut[cut_long] != '\0') cut_long++;

    while (str[i] != '\0')
    {
        int n_record = 0;
        while (n_record < cut_long)
        {
            if(str[i+n_record] != cut[n_record])
            {
                break;
            }

            n_record ++;
        }

        if(n_record == cut_long)
        {
            substr[index] = &str[i + cut_long];

            for(int j = 0;j<cut_long;j++)
            {
                str[i+j] = '\0';

            }

            index++;
            i += cut_long - 1;
        }
        i++;
    }

    return index;
}

int main(){
	
	char str[N];
	char cut[N];
	char* substr[N];
	
	read_line(str, N);
	read_line(cut, N);
	
	int n = CutString(substr, str, cut);
	
	for(int i = 0 ; i < n ; i++)
		printf("%s\n", substr[i]);
		
	
	return 0;
}