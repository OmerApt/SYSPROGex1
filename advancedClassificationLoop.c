#include "NumClass.h"
#include <stdio.h>

int numOfDigits(int x);
int power(int x,int of);
int isPalindromeRec(char* num,int start,int end);
void toChar(char* res,int n);

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
    int length = numOfDigits(num);
    char t[20]={};
    toChar(t,num);
    int ans = isPalindromeRec(t,0,length-1);
    return ans;
}

int isPalindromeRec(char* num,int start,int end){
    if(start == end)
    return 1;
    if(num[start]!=num[end])
    return 0;
    return isPalindromeRec(num,start+1,end-1);
}

void toChar(char* res,int n){
    int length = numOfDigits(n);
    for (int i =0;i<length;i++){
        int digit = n%10;
        res[i]=digit + '0';
        n /=10;
    }
    return ;
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