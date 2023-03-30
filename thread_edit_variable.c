#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *thread_1(void *arg) {
    int *i = (int *) arg;
    (*i)++;
    // arret propre du thread 
    pthread_exit(NULL);
}

int main(void) {
    // creation de la variable qui va contenir le thread
    int i = 1;
    pthread_t thread1;
    printf("Avant la creation du thread, i = %i.\n", i);
    // creation du thread
    pthread_create(&thread1, NULL, thread_1, &i);
    pthread_join(thread1, NULL);
    printf("Apres la creation du thread, i = %i.\n", i);
    return EXIT_SUCCESS;
}