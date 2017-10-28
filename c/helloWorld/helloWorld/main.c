#include <stdio.h>

#define IN 1  /* inside a word */
#define OUT 0 /* outside a word */
main()
{
    int c, state;
    state = OUT;
    while ((c = getchar()) != EOF) {
//        if ((c == ' ' && state == IN) || c == '\n')
        if (c == ' ' && state == IN)
//            printf("\n");
            putchar('\n');
            state = OUT;
        if (c == ' ' && state == OUT)
            ;
                
        else {
            state = IN;
//            printf("%d",c );
            putchar(c);
        }
    }
    }
//}#include <stdio.h>
//
///* Here, a word is any   sequence of letter(s). */
//
//main ()
//
//{
//	int	is_in_word, c;
//
//	is_in_word = 0;
//	while ((c = getchar()) != EOF)
//
//		if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z') {
//
//			is_in_word = 1;
//			putchar(c);
//
//		} else {
//
//			if (is_in_word)
//
//				putchar('\n');
//
//			is_in_word = 0;
//
//		}
//}
//#include <stdio.h>
///* a word is any sequence of letters. */
//main()
//{
//    int is_in_word, c;
//    is_in_word = 0;
//    while ((c = getchar()) != EOF) {
//        if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z') {
//            is_in_word = 1;
//            putchar(c);
//        } else {
//            if (is_in_word)
//                putchar('\n');
//            is_in_word = 0;
//        }
//    }
