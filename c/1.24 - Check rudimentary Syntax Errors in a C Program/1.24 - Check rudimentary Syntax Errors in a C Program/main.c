/* Program to check rudimentary syntax errors like unmatch braces,brakets or parenthesis */

#include <stdio.h>
//brace {,brack (,paren [
int brace,brack,paren;

void incomment();
void inquote(int c);
void search(int c);

int main(void)
{
    int c;
    
    extern int brace,brack,paren;
    
    while ((c=getchar())!=EOF && c != '\n')//+
    {
//        The text of the program when it is in- comment, in-quote and rest of the program text
        if (c == '/')
            if ((c=getchar()) == '*')
                incomment();
            else
                search(c);
        
        else if (c == '\'' || c == '"')
            inquote(c);
        
//         It is only the rest that we care about
        else
            search(c);
    }
    if (brace < 0)
    {
        printf("Umatched Braces\n");
        brace = 0;
    }
    if (brack < 0)
    {
        printf("Umatched Brackets\n");
        brack = 0;
    }
    if (paren < 0)
    {
        printf("Umatched Parenthesis\n");
        paren = 0;
    }
    
    if (brace > 0)
        printf("Umatched Braces\n");
    if (brack > 0)
        printf("Umatched Brackets\n");
    if (paren > 0)
        printf("Umatched Parenthesis\n");
    
    return 0;

}

//When a two sequence characters starts with /* we enter in-comment block and continue till we end up with */
void incomment()
{
    int c,d;
    
    c = getchar();
    d = getchar();
    
    while (c != '*' || d != '/') {
        c = d;
        d = getchar();
    }
}

//When a single quote ' or a double quote " character is found, we do the same and continue till we find it’s match.
//'123'{
//    ''Umatched Braces
void inquote(int c)
{
    int d;
    
    putchar(c);
    
    while ((d=getchar())!=c)
    {
        if (d == '\\')
        {
            putchar(getchar());//+
        }
    }
    putchar(d);
}

void search(int c)
{
    extern int brace,brack,paren;
    
    if(c == '{')
        --brace;
    else if (c == '}')
        ++brace;
    else if (c == '(')
        --brack;
    else if (c == ')')
        ++brack;
    else if (c == '[')
        --paren;
    else if (c == ']')
        ++paren;
}
//
//  main.c
//  1.24 - Check rudimentary Syntax Errors in a C Program
//
//  Created by Johnny_L on 2017/9/11.
//  Copyright © 2017年 Johnny_L. All rights reserved.
//

//#include <stdio.h>
//
//int main(int argc, const char * argv[]) {
//    // insert code here...
//    printf("Hello, World!\n");
//    return 0;
//}
