#include <stdio.h> 
#include <stdlib.h> 
#include <pthread.h> //Header file for all the thread related functions
#include <unistd.h> //Header file for sleep(). man 3 sleep for details.
//function  for thread 1
void *SampleThread1(void *vargp) 
{ int i = 0; 
printf("SampleThread(1) is running ... \n"); //indicating start of thread 1
//timer inside the thread 1 is running for 3 times
for(i = 0; i < 3; i++) { 
sleep(1); 
printf("timer running inside SampleThread(1) = %d\n", i); 
} 
printf("SampleThread(1) is exiting ... \n"); //indicating end of thread 1
return NULL; 
}; 
//function for thread 2
void *SampleThread2(void *vargp) 
{ 
int i = 0; 
printf("SampleThread(2) is running ... \n"); //indicating start of thread 2
//timer inside the thread 2 is running for 5 times
for(i = 0; i < 5; i++) { 
sleep(1); 
printf("timer running inside SampleThread(2) = %d\n", i); 
} 
printf("SampleThread(2) is exiting ... \n"); //indicating end of thread 2
return NULL; 
}; 
int main() 
{int i = 0; 
pthread_t tid1, tid2; // two threads are created
pthread_create(&tid1, NULL, SampleThread1, NULL);//thread 1 corresponded to function SampleThread1
pthread_create(&tid2, NULL, SampleThread2, NULL);//thread 2 corresponded to function SampleThread2
printf("timer outside Thread is ended ..\n"); 
pthread_join(tid1, NULL); //joining thread 1
pthread_join(tid2, NULL); //joining thread 2
exit(0); 
}