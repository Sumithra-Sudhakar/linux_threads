
//header files required 
#include <pthread.h> 

#include <stdio.h> 

#include <unistd.h> 

#include <stdlib.h> 

#define NUM_THREADS     8 //declaring the number of threads

char *messages[NUM_THREADS]; //creating a charecter array
//thread function
void *PrintHello(void *threadid) 

{ 

   int *id_ptr, taskid; 

 

   sleep(1); 

   id_ptr = (int *) threadid; //type casting as int

   taskid = *id_ptr; 

   printf("Thread %d: %s\n", taskid, messages[taskid]); 

   pthread_exit(NULL); //exiting the thread

} 

int main(int argc, char *argv[]) 

{ 

    pthread_t threads[NUM_THREADS]; //creating array if threads

    int *taskids[NUM_THREADS]; //creating array of int pointers

    int rc, t; 
//assigning the values to the charecter array
    messages[0] = "English: Hello World!"; 

    messages[1] = "French: Bonjour, le monde!"; 

    messages[2] = "Spanish: Hola al mundo"; 

    messages[3] = "Klingon: Nuq neH!"; 

    messages[4] = "German: Guten Tag, Welt!"; 

    messages[5] = "Russian: Zdravstvytye, mir!"; 

    messages[6] = "Japan: Sekai e konnichiwa!"; 

    messages[7] = "Latin: Orbis, te saluto!"; 

  for(t=0;t<NUM_THREADS;t++) 

 {    taskids[t] = (int *) malloc(sizeof(int)); //instantiating task id

      *taskids[t] = t; //value at taskid

     printf("Creating thread %d\n", t); 

   rc = pthread_create(&threads[t], NULL, PrintHello, (void *) taskids[t] ); //creating threads

     if (rc) { 

        printf("ERROR; return code from pthread_create() is %d\n", rc); 

        exit(-1); 

      } 

  } 

  pthread_exit(NULL);  //exit threads

}