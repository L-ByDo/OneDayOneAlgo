#include<conio.h>
#include<stdio.h>
int recursion(int n,int d){
    if(n==0){
        return 0;
    }
    else{
        return n+recursion(n-d,d);  /*returning to the function*/
    }
}
void main(){
    int n,d,res;
    scanf("%d%d",&n,&d);
    res=recursion(n,d);  /*calling function/*
    printf("%d",res);
}

