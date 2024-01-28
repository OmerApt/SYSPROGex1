#include "NumClass.h"
#include <stdio.h>

int numOfDigits(int x);
int power(int x,int of);

int isArmstrong(int num){
    if(num < 0)
    return 0;
    int value = num;
    int sum = 0;
    int count = numOfDigits(num);
    while (value > 0)
    {
        int digit = value%10;
        sum += power(digit,count);
        value = value/10;
    }
    return num == sum?1:0;
}

int isPalindrome(int num){
    if(num < 0)
    return 0;
    if (num/10 == 0)
    return 1;
    
    int value = num;
    int i=1;
    

    while (value > 0)
    {
        int j = numOfDigits(value)-1;
        int i_num = value%power(10,i);
        int j_num = value/power(10,j);
        if(i_num != j_num)
        return 0;
        value %= power(10,j);
        value /= 10;
    }
    return 1;
    
}

int numOfDigits(int x){
    int i = 1;
    x/=10;
    while (x > 0)
    {
        i++;
        x/=10;
    }
    return i;
}

int power(int x,int of){
    int result = 1;
    for (int i = 0; i < of; i++)
    {
        result*=x;
    }
    
    return result;
}