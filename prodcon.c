#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

sem_t empty, full;
int buffer = 0;

void *producer(void *arg) {
    sem_wait(&empty);
    buffer++;
    printf("Produced: %d\n", buffer);
    sem_post(&full);
}

void *consumer(void *arg) {
    sem_wait(&full);
    printf("Consumed: %d\n", buffer);
    buffer--;
    sem_post(&empty);
}

int main() {
    pthread_t p, c;

    sem_init(&empty, 0, 1);
    sem_init(&full, 0, 0);

    pthread_create(&p, NULL, producer, NULL);
    pthread_create(&c, NULL, consumer, NULL);

    pthread_join(p, NULL);
    pthread_join(c, NULL);

    return 0;
}