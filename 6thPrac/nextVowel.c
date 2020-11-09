#include <stdio.h>
#include <stdlib.h>

void init(void);
void readFrom(FILE *fin);
int nextVowel(int ch);

char from[257];
char to[257];

int main(int argc, char *argv[])
{
 int i;

 init();

 if (argc > 1)
 {
  for(i = 1; i < argc; ++i)
  {
   FILE *fp = fopen(argv[i], "r");
   if(NULL == fp)
   {
    printf("Error at opening %s\n", argv[i]);
    exit(1);
   }
   else
   {
    /*while(EOF != (ch = fgetc(fp)))
    {
     putchar(nextVowel(ch));
    }
    fclose(fp);*/
    readFrom(fp);
   } 
  }
 }
 else
 {
  /*while(EOF != (ch = fgetc(stdin)))
   {
    putchar(nextVowel(ch));
   }*/
   readFrom(stdin);

 }

 return 0;
}


void init(void)
{
 FILE *input = fopen("from.txt", "r");
 FILE *output = fopen("to.txt", "r");

 if(NULL == input)
 {
  printf("Error at opening from.txt\n");
  exit(1);
 }
 if(NULL == output)
 {
  printf("Error at opening to.txt\n");
  exit(1);
 }
 
 fgets(from, 257, input);
 fgets(to, 257, output);

 fclose(input);
 fclose(output);
}

void readFrom(FILE *fin)
{
 int ch;
 while(EOF != (ch = fgetc(fin)))
  {
   putchar(nextVowel(ch));
  }
 fclose(fin);

}

int nextVowel(int ch)
{
 int i;
 for(i = 0; from[i] != '\0'; ++i)
 {
  if(ch == from[i])
   return to[i];
 }
 return ch;
}
