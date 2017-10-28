#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */
#define LIMIT 8
int mgetline(char line[], int maxline);
/* print the longest input line */
main()
{
    int len; /* current line length */
    char line[MAXLINE]; /* current input line */
    while ((len = mgetline(line, MAXLINE)) > 0)
    if (len > LIMIT) /* there was a line */
        printf("%s", line);
    return 0;
}
/* mgetline: read a line into s, return length */
int mgetline(char s[],int lim)
{
    int c, i;
    for (i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}
