//including the required header files
#include <pthread.h> 

#include <stdio.h> 

#include <unistd.h> 

#include <stdlib.h> 

 
//creatinng structure with 2 fields
struct args { 

    char* name; 

    int age; 

}; 

 
//thread function to execute the thread
void *hello(void *input) { 

    printf("name: %s\n", ((struct args*)input)->name); //printing name

    printf("age: %d\n", ((struct args*)input)->age); //printing age

} 

 

int main() { 

    struct args *Allen = (struct args *)malloc(sizeof(struct args)); //creating a pointer struct variable

    char allen[] = "Sumithra"; 
//assigning the values
    Allen->name = allen; 

    Allen->age = 20; 

 

    pthread_t tid; //instantiating the threads

    pthread_create(&tid, NULL, hello, (void *)Allen); //passing the struct pointer as an argument

    pthread_join(tid, NULL); //joining

return 0; 

}