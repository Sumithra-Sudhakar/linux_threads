
#include <stdio.h> 

#include <stdlib.h> 

#include <unistd.h>  //Header file for sleep(). man 3 sleep for details. 

#include <pthread.h> //Header file for all the thread related functions

 

// A normal C function that is executed as a thread 

// when its name is specified in pthread_create() 

void *myThreadFun(void *j) //function the thread is implementing

{ 

    sleep(1); 

    printf("Printing string from Thread \n"); 

    return NULL; 

} 

 

int main() 

{ 

    pthread_t thread_id; //creating variable of type pthread_t

    printf("Before Thread\n"); 

    pthread_create(&thread_id, NULL, myThreadFun, NULL); //creating the threat

    pthread_join(thread_id, NULL); // pthread_join

    printf("After Thread\n"); 

    exit(0); 

}
