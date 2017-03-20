#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<graphics.h>

int main()
{
struct emp{
char name[20];
int age;
long int salary;
};
struct emp e;
long int recsize;
char empname[20];
FILE *fp,*ft;
int count;
char another,choice;
int gdriver=DETECT,gmode;
initgraph(&gdriver, &gmode, "C:\\TC\\bgi");

fp=fopen("emp.DAT","rb+");
if(fp == NULL)
{
fp=fopen("emp.DAT","wb+");
if(fp == NULL)
{
puts("Cannot open file");
exit(1);
}
}
recsize=sizeof(e);
while(1){
clearviewport();//clrscr();
outtextxy(300,200,"1:Add Records");
outtextxy(300,210,"2:List Records");
outtextxy(300,220,"3:Modify record");
outtextxy(300,230,"4:Delete Record");
outtextxy(300,240,"0:Exit");
fflush(stdin);
choice=getche();

switch(choice)
{
case '1':clearviewport();//clrscr();
another='y';
fseek(fp,0,SEEK_END);
while(another=='y')
{
clearviewport();//clrscr();
outtextxy(300,200,"Enter the name age and salary");
scanf("%s%d%ld",&e.name,&e.age,&e.salary);
printf("\n%s\t%d\t%ld\n",e.name,e.age,e.salary);
printf("Add Confirm y/n\n");
if(getche() == 'y')
{
if((fwrite(&e,recsize,1,fp)) == 1)
puts("Record Added Successfully");
puts("Add another record");
fflush(stdin);
}
else
{
fflush(stdin);
}
another=getche();
}
break;


//List Records
case '2':
clrscr();
count=0;
rewind(fp);
printf("Name	Age		Salary\n");
while((fread(&e,recsize,1,fp)) == 1)
{
//puts(e.name);
printf("%s\t%d\t%ld",e.name,e.age,e.salary);
printf("\n");
count++;
}
if(count == 0)
puts("No records");
else{
printf("%d records outputted",count);
}
getch();
break;


//Modify Records
case '3': another='y';
while(another == 'y')
{
puts("Enter the employee name");
scanf("%s",&empname);
rewind(fp);
while(fread(&e,recsize,1,fp) == 1)
{
if(strcmp(e.name,empname) == 0)
{
puts("Enter the name age and salary");
scanf("%s%d%ld",&e.name,&e.age,&e.salary);
fseek(fp,-recsize,SEEK_CUR);
fwrite(&e,recsize,1,fp);
}
}
puts("Modify another record");
fflush(stdin);
another=getche();
}
break;


//Delete Records
case '4': another='y';
while(another == 'y')
{
clrscr();
puts("Enter the name of the employee to delete");
scanf("%s",&empname);
ft=fopen("temp.DAT","wb");
rewind(fp);
while(fread(&e,recsize,1,fp) == 1)
{
if(strcmp(e.name,empname) != 0)
fwrite(&e,recsize,1,fp);
}
fclose(fp);
fclose(ft);
remove("emp.DAT");
rename("temp.DAT","emp.DAT");
fp=fopen("emp.DAT","rb+");
puts("Delete another record");
fflush(stdin);
another=getche();
}
break;


case '0': exit(1);
break;


default: puts("Choose correct option");
}
}
//return 0;
}
