#include <stdio.h>

int nextVowel(int ch)
{
	switch(ch)
	{	
		default: ch = '_'; break;
		case 'a': ch = 'e'; break;
		case 'e': ch = 'i'; break;
		case 'i': ch = 'o'; break;
		case 'o': ch = 'u'; break;
		case 'u': ch = 'a'; break;
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
