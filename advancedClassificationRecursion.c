#include "NumClass.h"
#include <stdio.h>

int power(int num,int of);
int recArmstrong(int num,int sum,int length);
int numOfDigits(int x);

int isArmstrong(int num){
    if(num < 0)
    return 0;
    int length = numOfDigits(num);
    int arm_num = recArmstrong(num,0,length);
    int ans = num==arm_num;
    return ans;
}

int recArmstrong(int num,int sum,int length){
    if(num <= 0)
    return sum;
    int digit = num%10;
    int value = power(digit,length);
    return recArmstrong(num/10,sum+value,length);
}

int isPalindrome(int num){
    if(num < 0)
    return 0;
    
    int length = numOfDigits(num);
    if(length == 1)
    return 1;
    int right = num%10;
    int left = num/power(10,length-1);

    if(left != right){
        return 0;
    }
     num = num%power(10,length-1);
     num = num/10;
     return isPalindrome(num)*1;
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