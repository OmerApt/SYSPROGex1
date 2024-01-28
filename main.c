#include <stdio.h>
#include "NumClass.h"

int main()
{
    int f;
    int s;
    int res = scanf("%d", &f);
    int res2 = scanf("%d",&s);
    if (res < 0 || res2 < 0)
    {
        printf("error in input type");
        return 0;
    }
    else if (f < 0 || s < 0)
    {
        printf("error in input, both need to be a \
         positive number");
         return 0;
    }else{
        if(s<f){
            int temp = s;
            s = f;
            f = temp;
        }
        printf("The Armstrong numbers are:");
        for(int i=f;i<=s;i++){
            if(isArmstrong(i)){
                printf(" ");
                printf("%d",i);
            }
            
        }
        printf("\n");
        printf("The Palindromes are:");
        for(int i=f;i<=s;i++){
            if(isPalindrome(i)){
                printf(" ");
                printf("%d",i);
            }
        }
        printf("\n");
        printf("The Prime numbers are:");
        for(int i=f;i<=s;i++){
            if(isPrime(i)){
                printf(" ");
                printf("%d",i);
            }
        }
        printf("\n");
        printf("The Strong numbers are:");
        for(int i=f;i<=s;i++){
            if(IsStrong(i)){
                printf(" ");
                printf("%d",i);
            }
        }
    }

    return 0;
}