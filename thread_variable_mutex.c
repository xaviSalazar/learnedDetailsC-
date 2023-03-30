#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// nombre total de thread
#define NB_THREAD 2
// limite de l'increment
#define INCREMENT_LIMIT 10

// Tableau contenant les threads
pthread_t threads[NB_THREAD];

// Structure de donnees contenant le mutex
typedef struct mutex_data {
    int data;
    pthread_mutex_t mutex;
} mutex_data;

// Fonction executee dans le thread 
void *job(void *arg) {
    mutex_data *md = (mutex_data*) arg;
    pthread_t tid = pthread_self();
    while ((*md).data < INCREMENT_LIMIT) {
        // verouillage du mutex
        pthread_mutex_lock(&(*md).mutex);
        (*md).data++;
        // deverouillage du mutex
        pthread_mutex_unlock(&(*md).mutex);
        printf("thread [ %ld ] data [ %i ]\n", tid, (*md).data);
        // pause l'execution du thread pendant 1 seconde
        sleep(1);
    }
    printf("Fin du thread %ld\n", tid);
    pthread_exit(NULL);
}

// Fonction principale 
int main() {
    // creation du mutex
    mutex_data md;
    // Initialization de la donnee
    md.data = 0;
    // initialization du mutex
    if(pthread_mutex_init(&md.mutex, NULL) != 0) {
        printf("\n mutex init failed\n");
        return EXIT_FAILURE;
    }

    // Boucle de creation des threads
    for (int i=0; i < NB_THREAD; i++) {
        // creation du thread et passage de la structure par reference
        int err = pthread_create(&threads[i], NULL, job, &md);
        if( err != 0 ) {
            printf("Echec de la creation du thread: [%s]", strerror(err));
            break;
        }
        printf("creation du thread numero %ld\n", threads[i]);
    }
    // en attente des threads 
    for (int i = 0; i < NB_THREAD; i++) {
        pthread_join(threads[i], NULL);
    }
    // destruction du mutex
    pthread_mutex_destroy(&md.mutex);
    return EXIT_SUCCESS;
}