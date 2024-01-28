#include <stdio.h>
#include "NumClass.h"

int main()
{
    int f;
    int s;
    int res = scanf("%d %d", &f, &s);
    if (res != 1)
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
            f = s;
        }
        printf("The Armstrong numbers are:");
        for(int i=f;i<=s;i++){
            if(isArmstrong(i))
            printf(" %d",i);
        }
        printf("\nThe Palindromes are:");
        for(int i=f;i<=s;i++){
            if(isPalindrome(i))
            printf(" %d",i);
        }
        printf("\nThe Prime numbers are:");
        for(int i=f;i<=s;i++){
            if(isPrime(i))
            printf(" %d",i);
        }
        printf("\nThe Strong numbers are:");
        for(int i=f;i<=s;i++){
            if(IsStrong(i))
            printf(" %d",i);
        }
    }

    return 0;
}