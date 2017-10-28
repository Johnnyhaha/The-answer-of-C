
/* Program to print maximum,minimum limits of char,int,long using calculation */

/* The logic used is
 * ~0 will give bits in 1s.
 * (unsigned <type>) will cast it unsigned.
 * >> 1 right shifts 1 bit to remove the sign bit.
 * (<type>) casting it the required type again
 */
/* unsigned char variables have values between 0 and 255, while signed chars have values between -128 and 127 */
#include<stdio.h>

int main(void)
{
//    (unsigned char) 0 = 0000 0000
//    (unsigned char) ~0 = 1111 1111 = 255
//    (char) ((unsigned char) ~0 >> 1) = 0111 1111 = 127 右移一位>>

//    printf("Minimum Signed Char %d\n",-(char)((unsigned char) ~0 >> 1) - 1);
//    //    multiplying it by -1 and going one number further to the left in the number line:
//    printf("Maximum Signed Char %d\n",(char) ((unsigned char) ~0 >> 1));
    printf("Minimum Signed Char %d\n",-((unsigned char) ~0 >> 1) - 1);
    //    multiplying it by -1 and going one number further to the left in the number line:
    printf("Maximum Signed Char %d\n", ((unsigned char) ~0 >> 1));
    
    printf("Minimum Signed Short %d\n",-(short)((unsigned short)~0 >>1) -1);
    printf("Maximum Signed Short %d\n",(short)((unsigned short)~0 >> 1));
    
    printf("Minimum Signed Int %d\n",-(int)((unsigned int)~0 >> 1) -1);
    printf("Maximum Signed Int %d\n",(int)((unsigned int)~0 >> 1));
    
    printf("Minimum Signed Long %ld\n",-(long)((unsigned long)~0 >>1) -1);
    printf("Maximum signed Long %ld\n",(long)((unsigned long)~0 >> 1));
    
    /* Unsigned Maximum Values */
    
    printf("Maximum Unsigned Char %d\n",(unsigned char)~0);
    printf("Maximum Unsigned Short %d\n",(unsigned short)~0);
    printf("Maximum Unsigned Int %u\n",(unsigned int)~0);
    printf("Maximum Unsigned Long %lu\n",(unsigned long)~0);
    
    return 0;
}
