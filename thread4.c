
//including the required header files
#include <stdio.h> 

#include <unistd.h> 

#include <pthread.h> 

 

void * hello(void *input) { 

    printf("%s\n", (char *)input); //type casting to char since we know the input is string

    pthread_exit(NULL); //exiting the thread

} 

 

int main(void) { 

    pthread_t tid; //instantiating the thread

    pthread_create(&tid, NULL, hello, "hello world"); //passing a string as the last argument in the create function indicating that it is the parameter of the function jello

    pthread_join(tid, NULL); //joining the thread that was created

    return 0; 

}