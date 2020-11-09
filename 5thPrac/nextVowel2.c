#include <stdio.h>

int nextVowel(int ch)
{
	char from[] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
	char to[] = {'e', 'i', 'o', 'u', 'a', 'E', 'I', 'O', 'U', 'A'};

	unsigned int i;
	for(i = 0; i < sizeof(from)/sizeof(char); i++)
	{
		if(ch == from[i])
		{
			ch = to[i];
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
