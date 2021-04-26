#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
struct students{
char name[25];
char rollno[20];
}s1;

int marks[5];
void *fn1(void)
{
printf("enter student's name\n");
scanf("%s",s1.name);
printf("\nenter student's roll number\n");
scanf("%s",s1.rollno);
pthread_exit(NULL);
}

void *fn2(void)
{
printf("\nplease enter the marks for 5 subjects \n");
for(int i = 0;i < 5;i++){
scanf("%d",&marks[i]);
}
pthread_exit(NULL);
}

int main()
{
pthread_t t1,t2;
pthread_create(&t1,NULL,fn1,NULL);
pthread_join(t1, NULL); 
pthread_create(&t2,NULL,fn2,NULL);
pthread_join(t2, NULL); 

printf("Name:  %s \n",s1.name);
printf("RollNo: %s \n",s1.rollno);
int sum,points;
sum = 0;
for (int i = 0;i < 5;i++){
points = 0;
if(marks[i] > 90){
sum = sum + 10;
points = points + 10;
}
else if(marks[i] > 80){
sum = sum + 9;
points = points + 9;
}
else if(marks[i] > 70){
sum = sum + 8;
points = points + 8;
}
else if(marks[i] > 60){
sum = sum + 7;
points = points + 7;
}
else if(marks[i] > 50){
sum = sum + 6;
points = points + 6;
}
else if(marks[i] > 40){
sum = sum + 5;
points = points + 5;
}
else if(marks[i] > 30){
sum = sum + 4;
points = points + 4;
}
else{
sum = sum + 3;
points = points + 3;
}
printf("subject %d : %d points \n ",i+1,points);
}
float point = sum/5;
printf("The grade points : %f \n" ,point);
return 0;
}