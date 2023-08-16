#include<stdio.h>
#include<stdlib.h>

void swap(int *a,int *b){
    int temp;
    temp=*b;
    *b=*a;
    *a=temp;
}

int main(int argc, char *argv[]){
    int c=atoi(argv[1]);
    int d=atoi(argv[2]);

    swap(&c,&d);

    printf("%d %d",c,d);

    return 0;
}