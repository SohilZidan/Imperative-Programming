#include <stdio.h>

int nextVowel(int ch)
{
	char conv[][2] = {
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
		if(ch == conv[i][0])
		{
			ch = conv[i][1];
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
