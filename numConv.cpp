#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int arr[]={'A','B','C','D','E','F'};

int dectbin(int a){
	if(a<=1)
	return 1;
	printf("%d",dectbin(a/2));
	return (a%2);
}

int decthex(int a)
{
	int n;
	if(a<=9)
	return a;

	n=decthex(a/16);

	if(n>9)
	{
		printf("%c",arr[n%10]);
	}
	else
	printf("%d",n);

	return (a%16);
}

int main(){
	int num,bin,n,ch;
	while(1){
        printf("1: Decimal to Binary\n2:Decimal to Hexadecimal\n0:exit");
        scanf("%d",&ch);
        switch(ch){
            case 1: printf("Enter number");
                    scanf("%d",&num);
                    printf("%d",dectbin(num));
                    break;

            case 2:	printf("Enter number");
                        scanf("%d",&num);
                        n=decthex(num);
                        if(n>9)
                        {
                            printf("%c",arr[n%10]);
                        }
                        else
                            printf("%d",n);
            break;

            case 0: exit(0);
            default:printf("\nChoose correct option");
        }
	}
return 0;
}
