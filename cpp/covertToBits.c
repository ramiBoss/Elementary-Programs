#include<stdio.h>
#include<stdlib.h>
void showbits(int);


void showbits(int n)
{
int i,k,mask;
for(i=15;i>=0;i--)
{
mask=1<<i;
k=n&mask;
k==0?printf("0"):printf("1");
}
printf("\n");
}

int main()
{
int n,k,sh,ch;
printf("Enter any number\n");
scanf("%d",&n);
printf("****Binary Representation****\n");
showbits(n);
while(1){
printf("1:1's complement\n2:Left Shift\n3:Right Shift\n0:exit");
scanf("%d",&ch);
switch(ch){
case 1: k=~n;
        printf("****1's complement****\n");
        showbits(k);
        break;
case 2: printf("Left Shift by=");
        scanf("%d",&sh);
        k=n<<sh;
        showbits(k);
        break;
case 3: printf("Right Shift by=");
        scanf("%d",&sh);
        k=n>>sh;
        showbits(k);
        break;
case 0: exit(1);
        break;
default:printf("Choose any option\n");
}
}
return 0;
}
