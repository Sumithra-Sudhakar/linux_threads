
//including the required header files
#include <stdio.h> 

#include <unistd.h> 

#include <pthread.h> 

 

void * factorial(void *input) { 
int fact,*num;
fact=1;
num= (int *)input;
for(int i=2;i<=*num;i++)
fact=fact*i;
 printf("factorial of %d  is %d\n",*num ,fact);
    pthread_exit(NULL); 

} 

 

int main(void) { 
int *num;
printf("enter the number\n ");
scanf("%d",num);
    pthread_t tid; //instantiating the thread

    pthread_create(&tid, NULL, factorial, num); //passing a string as the last argument in the create function indicating that it is the parameter of the function jello

    pthread_join(tid, NULL); //joining the thread

    return 0; 

}
