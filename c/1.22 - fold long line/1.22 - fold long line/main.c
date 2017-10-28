/* fold, to fold long lines after a specified Column */
//
//1234567 8912345678

//1234567
//891234578
//
#include <stdio.h>

#define MAXCOL 15
#define TABVAL 8

char line[MAXCOL];
int expendtab(int pos);
void printline(int pos);
int getblank(int pos);
int newposition(int pos);

int main(void)
{
    int pos, c;
    pos = 0;
    
    while ((c=getchar())!=EOF)
    {
        line[pos] = c;//    Every character of the file is filled into a line[MAXCOL]
        
        if (c == '\t')//line[' ', ' ', ' ',' ',' ',' ',' ',' '] and pos = 8
            pos = expendtab(pos);
        if (c == '\n')//If character is \n then we print the entire line contents reset the pos back to 0
        {
            printline(pos);
            pos = 0;
        }
        else if (++pos > MAXCOL)
        {
            pos = getblank(pos);
            printline(pos);
            pos = newposition(pos);
        }
    }
    return 0;
}

int expendtab(int pos)
{
    line[pos] = ' ';
    
    for (++pos; (pos<MAXCOL)&&((pos%TABVAL)!=0); ++pos)
    line[pos] = ' ';
    
    if (pos>=MAXCOL)
    {
        printline(pos);
        return 0;
    }
    else
        return pos;
}

void printline(int pos)
{
    int i;
    for(i=0;i<pos;++i)
        putchar(line[i]);//1~' ' pos = 8
    if (pos>0)
        putchar('\n');
}

int getblank(int pos)// get the position of that blank.
{
    if (pos>0)
        while (line[pos]!=' ')
        {
            --pos;
        }
        if (pos==0)//pos=7
            return MAXCOL;
        else
            return pos+1;//return the pos which is not greater than MAXCOL
}


//We determine the new position based the return value of getblank
int newposition(int pos)
{
    int i,j;
//    If the return value of getblank was greater than MAXCOL, then our new position is 0, which is a newline.
    if ((pos<=0)||(pos>=MAXCOL))
        return 0;
    else
    {
        i=0;
        //空格之后的字符串作为新的一行的开始
        for (j=pos; j<MAXCOL; ++j,++i)//place the folded contents
            line[i]=line[j];//We will replace the contents of line starting from 0, mark this as i。
    }
    return i;
}

















