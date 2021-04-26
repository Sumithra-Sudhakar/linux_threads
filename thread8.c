
#include <pthread.h> 

#include <stdio.h> 

#include <unistd.h> 

#include <stdlib.h> 

#define NUM_THREADS     8 

void *PrintEvenSum(void *ptr) 

{ 

   
 int sum=0;

  int *array=(int *)ptr;
 printf("printing from threads\n");
 
 for(int i=0;i<NUM_THREADS;i++)
 {
 
 if(array[i]%2==0)
 sum+=array[i];
 } 
printf("sum of even numbers \n");
 printf("%d\n",sum);
   pthread_exit(NULL); 

} 

int main(int argc, char *argv[]) 

{ 
int array[NUM_THREADS]; 
    pthread_t threads; 

     
 printf("Enter the numbers\n");
 for(int i=0;i<NUM_THREADS;i++)
 scanf("%d",&array[i]);
 
 printf("printing from main\n");
 int sum=0;
 for(int i=0;i<NUM_THREADS;i++)
 {if(array[i]%2==1)
 sum+=array[i];
}
 printf("sum of odd numbers \n");
 printf("%d\n",sum);

pthread_create(&threads, NULL, PrintEvenSum, array );
 pthread_join(threads, NULL);
  pthread_exit(NULL);  
return 0;
}
