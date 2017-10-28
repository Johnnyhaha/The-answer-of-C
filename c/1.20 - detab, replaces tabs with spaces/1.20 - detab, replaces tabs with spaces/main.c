/* Write a program detab,which replaces tabs in the input with a proper
 number of blanks to spaces */

#include <stdio.h>
#define TABINC 8

int main(void)
{
    int nb,c,pos;
    
    nb = 0;
    pos = 1;
    
    while ((c=getchar()) != EOF)
    {
        if (c == '\t')
        {
//            输入Tab越早，显示#越多
//            pos增加，nb减小，#减小
            nb = TABINC - ((pos - 1)%TABINC);
            
            while (nb > 0)
            {
                putchar('#');
                ++pos;
                --nb;
            }
        }
        else if (c == '\n')
        {
            putchar(c);
//            重置pos，为下次输入
            pos = 1;
        }
        else
        {
            putchar(c);
            ++pos;
        }
    }
    return 0;
}
