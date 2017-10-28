//
//  main.c
//  hello C
//
//  Created by Johnny_L on 2017/9/8.
//  Copyright © 2017年 Johnny_L. All rights reserved.
// 一行一个单词

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    
    
    int c ,is_in_word;
    while ((c = getchar()) != EOF)
    {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        {
            putchar(c);
            is_in_word = 1;
        }
        else if(is_in_word)
        {
            putchar('\n');
            is_in_word = 0;
            
        }
    }
    
    
    
    
    
   
}
