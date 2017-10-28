/* Verital Histogram of words in a Sentence */

#include <stdio.h>
#define MAXWL 20 /* Maximum Length of a word */
#define MAXNW 25 /* Maximum number of words in a sentence */

int main(void)
{
    int c,i,j,nc,wl; //nc:number of character. wl:length of word
    int word[MAXNW]; //all of the word
    
    for (i=0; i< MAXNW ; i++)
    {
        word[i] = 0;
    }
    
    nc = wl = 0;
    
    while ((c=getchar()) != EOF)
    {
        ++nc;
        if(c == ' ' || c == '\n' || c == '\t')
        {
            word[wl] = nc - 1; //Get the length of every word
            ++wl;
            nc = 0; //Reset the nc for the next word
        }
    }
//    光标从左上角开始，一行行显示
    for (i = MAXWL; i >= 1; --i) //从上到下
    {
        for (j = 0; j <= wl; ++j) //length of word  从左到右
        {
            if (i <= word[j])
            {
                putchar('*');
            }
            else
                putchar(' ');
        }
        putchar('\n');
    }
    return 0;

    
}
 
