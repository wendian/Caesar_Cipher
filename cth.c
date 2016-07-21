#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>

char final[25][1024];

typedef struct one_word
{
	int loc;
	char the_word[32];
} one_word_t;

void * decoder(void * arg)
{
	one_word_t * part = (one_word_t *) arg;
    int i, j, location, sz;
    char word[32];

    location = part->loc;
    strcpy(word, part->the_word);
    sz = strlen(part->the_word);
    for (i = 0; i < 25; i++)
    {
    	for (j = 0; j < sz; j++)
    	{
    		if ((word[j] > 96 && word[j] < 132) || (word[j] > 64 && word[j] < 91))
    		{
    			word[j]++;
	    		if (word[j] == 123) word[j] = 97;
	    		if (word[j] == 91) word[j] = 65;
    		}
    		final[i][location + j] = word[j];
    	}
    	final[i][location + sz] = ' ';
    }
	return NULL;
}

int main(int argc, char **argv)
{
    if(argc == 1)
    {
        printf("usage: %s <N offset> <1+ words separated by spaces>\n", argv[0]);
        return -1;
    }
    int N = atoi(argv[1]);
    if (N > 25 || N < 0)
    {
    	printf("N should be an integer between [0,25]\n0 prints all rotations");
        return -1;
    }
    int words = argc - 2;
    int i;
    int size = 0;
    int place = 0;

    for (i = 2; i < argc; i++)
    {
    	size += strlen(argv[i]) + 1;
    }
    one_word_t phrase[words];
    pthread_t ths[words];
    for (i = 0; i < words; i++)
    {
    	phrase[i].loc = place;
    	strcpy(phrase[i].the_word, argv[i + 2]);
    	place += strlen(phrase[i].the_word) + 1;
    	if(pthread_create(&ths[i], NULL, decoder, (void *) &phrase[i]) != 0)
	    {
	      printf("Error creating thread\n");
	      exit(1);
	    }
    }
    for (i = 0; i < words; i++)
	{
		if (pthread_join(ths[i], NULL) != 0)
		{
			printf("failed to join thread\n");
			exit(1);
		}
	}
	printf("Original:\n");
	for (i = 2; i < argc; i++) printf("%s ", argv[i]);
	printf("\n");

	if (N == 0)
	{
		for (i = 0; i < 25; i++)
		{
			final[i][size - 1] = '\0';
			printf("N = %d:\n%s\n", i + 1, final[i]);
    }
	}
	else
	{
		final[N-1][size - 1] = '\0';
		printf("N = %d:\n%s\n", N, final[N-1]);
	}
    return 0;
}