#include <stdio.h>

int main(void) {
  int ch; /* instead of char cuz ther might be problems when dealing with binary files */
  //ch = getchar();
  int cnt = 0;
  int cnt_nl = 0;
  int cnt_wd = 0;
  int prev = ' ';

  while (EOF != (ch = getchar())) // ctl + d to stop
  {
    //putchar(ch);
    if(ch == '\n') cnt_nl++;
    else cnt++;
    // ch = getchar(); /* printf("%c", ch) */
    if((' ' == prev || '\n' == prev) &&
        (' ' != ch && '\n' != ch))
        cnt_wd++;
    prev = ch;
  }
  printf("%d, %d, %d\n", cnt_nl, cnt_wd, cnt);
  return 0;
}