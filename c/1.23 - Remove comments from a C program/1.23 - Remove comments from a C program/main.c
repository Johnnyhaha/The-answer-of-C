/* Program to remove comments from a C Program.
 Program should echo quotes and character constants properly
 C Comments do not nest */

#include <stdio.h>

void rcomment(int c);
void incomment(void);
void echo_quote(int c);

int main(void)
{
    int c,d;
    
    printf("To Check /* Quoted String */ \n");
    
    while ((c=getchar())!=EOF)
    {
        rcomment(c);
    }
    return 0;
}

void rcomment(int c)
{
    int d;
    if (c=='/')
    {
        
//        真正实现程序功能的部分，去除/*123*/
//---------------------input /*123*/ and then you will get nothing in the console
        
        d = getchar();//+
        if (d=='*')//in-comment
        {
            incomment();
        }
//         print the first character and start treating the second / as the possible start of comment.
        else if (d=='/')
        {
            putchar(c);
            rcomment(d);
        }
//--------------------
        
        
        
        
        else
        {
            putchar(c);
            putchar(d);
        }
    }
//    if we encouter a single quote or a double quote character, then we understand we are inside a quoted string,
//    putchar everything
    else if (c=='\''||c=='"')
        echo_quote(c);
//    "/*123s"
//    "/*123s"
//    '1234'
//    '1234'
    else
        echo_quote(c);


}

void incomment()
{
    int c,d;
    
    c = getchar();
    d = getchar();
    
    while (c != '*' || d != '/')
    {
        c = d;
        d = getchar();
    }
}

void echo_quote(int c)
{
    int d ;
    putchar(c);
    
    while ((d = getchar())!=c)
    {
        putchar(d);
        
        if (d == '\\') //+
        {
            putchar(getchar());
        }
    }
    putchar(d);
}




