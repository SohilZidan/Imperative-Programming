#include <stdio.h>
#include <stdlib.h>

void reverse(FILE *input, FILE *output);

int main(int argc, char *argv[])
{
    int i;

    if (1 == argc)
    {
	reverse(stdin, stdout);
    }
    if (2 == argc)
    {
	FILE* fp = fopen(argv[1], "w");
	if(NULL == fp)
	{
	    fprintf(stderr, "Can't open file: %s\n", argv[1]);
	}
	else
	{
	    reverse(stdin, fp);
	    fclose(fp);
	}
    }
    if (2 < argc)
    {
	FILE* fp_out = fopen(argv[1], "w");
	if (NULL == fp_out)
	{
	    fprintf(stderr, "Can't open file: %s\n", argv[1]);
	    return 0;
	}
        for (i = 2; i < argc; ++i)
        {
            FILE *fp = fopen(argv[i], "r");
            if (NULL == fp)
            {
	        fprintf(stderr,"Can't open file: %s\n", argv[i]);
	    }
	    else
	    {
	        reverse(fp, fp_out);
	        fclose(fp);
	    }
        }
    }
    return 0;
}


void reverse(FILE *input, FILE *output)
{
    int num;
    int max = 4;
    int cnt = 0;

    int *buffer = malloc( max * sizeof(int) );
    while(1 == fscanf(input, "%d", &num))
    {
	if (cnt == max)
	{
	    max = 2 * max;
	    buffer = realloc(buffer , max * sizeof(int));
	}
	buffer[cnt] = num;
	++cnt;
    }
    for (--cnt; cnt >= 0; --cnt)
    {
	fprintf(output, "%d ", buffer[cnt]);
    }
    fprintf(output, "\n");
}
