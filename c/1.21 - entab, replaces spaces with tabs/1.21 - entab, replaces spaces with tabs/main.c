/* Write a Program entab that replaces strings of blanks by the minimum
 number of tabs and blanks to acheive the same spacing.
 Use the same tab stops as for detab.
 */
#include<stdio.h>
#define TABINC 8

int main(void)
{
    int nb,nt,pos,c;
    
    nb = 0;//number of spaces
    nt = 0;//number of tabs
    
    //Get the current character by calling getchar() and storing it in
    //variable c and keep track of the position
    for(pos=1;(c=getchar())!=EOF;++pos)

//        This step collects the minimum number of tabs and blanks.
        if( c == ' ')
        {
            //See if blank is >8.
            if((pos % TABINC) != 0)
                // >=8 increase the number of spaces
                ++nb;
            else
            {
                nb = 0;
                // <8 increase the number of tabs
                ++nt;
            }
        }
        else
//            we first print the all remaining tabs, then remaining spaces, then print the character.
//            And We reset the position accordingly
        {
            for( ; nt > 0 ; --nt)
                putchar('\t');
            if( c == '\t')//?????
                nb = 0;
            else
                for( ; nb > 0; --nb)
                    putchar(' ');
            
            putchar(c);
            
//            If it is a newline, we reset the pos, if it is a tab character, we reset it to previous tab character - 1. 
            if(c == '\n')
                pos = 0;
            else if ( c == '\t') //tab = 8 pos = 2 -> 8
                pos = pos + ( TABINC - (pos -1) % TABINC) - 1;
        }
    
    return 0;
}

