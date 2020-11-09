#include <stdio.h>

struct Conv_t
{
 char from;
 char to;
};

int nextVowel(int ch)
{
	struct Conv_t conv[] = {
		{'a','e'},
		{'e', 'i'},
		{'i','o'},
		{'o','u'},
		{'u','a'},
		{'A', 'E'},
		{'E','I'},
		{'I','O'},
		{'O','U'},
		{'U','A'}

	};

	unsigned int i;
	for(i = 0; i < sizeof(conv)/sizeof(conv[0]); i++)
	{
		if(ch == conv[i].from)
		{
			ch = conv[i].to;
			break;
		}
	}
	
	return ch;
}

int main()
{
	int ch;
	
	while(EOF != (ch = getchar()))
	{
		putchar(nextVowel(ch));
	}
	return 0;
}
