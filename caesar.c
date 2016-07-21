#include <stdio.h>
#include <string.h>
//Prints all shifts of a Caesar cipher for one word at a time
//gcc caesar -o caesar.c

int main(int argc, char **argv)
{
	char word[2048];
	while(1)
	{
		printf("Enter text:\n");
        scanf("%s", word);
        int i, j;
        int size = strlen(word);
        for (i = 0; i < 26; i++)
        {
        	printf("N = %d:  %s\n\n", i, word);
        	for (j = 0; j < size; j++)
        	{
        		word[j]++;
        		if (word[j] == 123) word[j] = 97;
        		if (word[j] == 91) word[j] = 65;
        	}
        }
    }
}