#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *thread_1(void *arg) {
    printf("Nous sommes dans le thread. \n");
    // arret propre du thread
    pthread_exit(EXIT_SUCCESS);
}

int main(void) {
    // variable qui va contenir le thread
    pthread_t thread1;
    printf("Avant la creation du thread. \n");
    // creation du thread
    pthread_create(&thread1, NULL, thread_1, NULL);
    pthread_join(thread1, NULL);
    printf("Apres la creation du thread. \n");
    return EXIT_SUCCESS;
}