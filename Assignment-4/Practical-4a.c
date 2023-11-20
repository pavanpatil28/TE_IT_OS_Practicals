#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <semaphore.h>
#include <unistd.h>

#define buffer_size 10

sem_t full, empty;
int buffer[buffer_size];
pthread_mutex_t mutex;
void *producer(void *p);
void *consumer(void *p);
void insert_item(int);
int remove_item();
int counter;

int items_produced = 0;
int items_consumed = 0;

void initialize() {
    pthread_mutex_init(&mutex, NULL);
    sem_init(&full, 1, 0);
    sem_init(&empty, 1, buffer_size);
    counter = 0;
}

void *producer(void *p) {
    int item, waittime;
    waittime = rand() % 2;  // Reduced waiting time
    sleep(waittime);

    item = rand() % 10;

    sem_wait(&empty);
    pthread_mutex_lock(&mutex);

    // Produce an item and insert it into the buffer
    insert_item(item);
    items_produced++;

    printf("\nProducer produced %d item. Buffer: [", item);
    for (int i = 0; i < counter; i++) {
        printf("%d", buffer[i]);
        if (i < counter - 1) {
            printf(", ");
        }
    }
    printf("]");

    pthread_mutex_unlock(&mutex);
    sem_post(&full);
    return 0;
}

void *consumer(void *p) {
    int item, waittime;
    waittime = rand() % 2;  // Reduced waiting time
    sleep(waittime);

    sem_wait(&full);
    pthread_mutex_lock(&mutex);

    // Consume an item from the buffer
    item = remove_item();
    items_consumed++;

    printf("\nConsumer consumed %d item. Buffer: [", item);
    for (int i = 0; i < counter; i++) {
        printf("%d", buffer[i]);
        if (i < counter - 1) {
            printf(", ");
        }
    }
    printf("]");

    pthread_mutex_unlock(&mutex);
    sem_post(&empty);
    return 0;
}

void insert_item(int item) {
    buffer[counter++] = item;
}

int remove_item() {
    return (buffer[--counter]);
}

int main() {
    int n1, n2, i;
    printf("\nEnter no. of producers you want to create:");
    scanf("%d", &n1);
    printf("\nEnter no. of consumers you want to create:");
    scanf("%d", &n2);
    initialize();
    pthread_t tid[n1], tid1[n2];
    
    for (i = 0; i < n1; i++)
        pthread_create(&tid[i], NULL, producer, NULL);
    
    for (i = 0; i < n2; i++)
        pthread_create(&tid1[i], NULL, consumer, NULL);
    
    // Reduced sleep time for quicker execution (you can adjust this value)
    sleep(5);

    printf("\nTotal items produced: %d", items_produced);
    printf("\nTotal items consumed: %d\n", items_consumed);
    
    exit(0);
}






