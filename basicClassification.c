#include "NumClass.h"
#include <stdio.h>

int atzeret(int x);

int isPrime(int num){
    if(num < 0)
    return 0;
    if(num <= 3)
    return 1;

    int i = 2;
    do
    {
        if(num%i == 0)
        return 0;
        else{
            i += 1;
        }
    } while (i < num);

    return 1;
    
}

int IsStrong(int num){
    if(num < 0)
    return 0;
    int value = num;
    int sum = 0;
    while (value > 0)
    {
        int digit = value%10;
        int a = atzeret(digit);
        sum += a;
        value = value/10;
    }
    return num == sum?1:0;
    
}
// will return 0 if param is negetive
int atzeret(int x){
    if(x <0)
    return 0;
    if(x <= 2)
    return x;

    int sum =2;
    for(int i=3;i<=x;i++){
        sum *=i;
    }
    return sum;
}