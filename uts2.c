#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_QUEUE_SIZE 100

typedef struct antrian{
    char nama[50];
    char pesanan[50];
} Antrian;

typedef struct queue{
    Antrian data[MAX_QUEUE_SIZE];
    int front, rear;
} Queue;

void initiateQueue(Queue *queue) {
    queue->front = -1;
    queue->rear = -1;
}

int isFull(Queue *queue) {
    return (queue->rear == MAX_QUEUE_SIZE - 1);
}

int isEmpty(Queue *queue) {
    return (queue->front == -1 || queue->front > queue->rear);
}

void enqueue(Queue *queue, Antrian pengunjung) {
    if (isFull(queue)) {
        printf("Antrian penuh");
        return;
    }
    if (isEmpty(queue)) {
        queue->front = 0;
    }
    queue->rear++;
    queue->data[queue->rear] = pengunjung;
}

Antrian dequeue(Queue *queue) {
    Antrian temp;
    if (isEmpty(queue)) {
        printf("Antrian kosong");
        strcpy(temp.nama, "");
        strcpy(temp.pesanan, "");
        return temp;
    }
    temp = queue->data[queue->front];
    queue->front++;
    if (queue->front > queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    }
    return temp;
}

void displayQueue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Antrian kosong.\n");
        return;
    }
    printf("Antrian Pengunjung dan Pesanan:\n");
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("Nama :%s\n", queue->data[i].nama);
        printf("Pesanan : %s\n", queue->data[i].pesanan);
    }
}

int main() {
    Queue antrian;
    initiateQueue(&antrian);

    while (1) {
        printf("\nMenu:\n");
        printf("1. Tambah pengunjung dan pesanan\n");
        printf("2. Selesai melayani pengunjung\n");
        printf("3. Tampilkan antrian\n");
        printf("4. Keluar\n");

        int pilihan;
        printf("Pilihan: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                if (!isFull(&antrian)) {
                    Antrian pengunjung;
                    printf("Masukkan nama: ");
                    scanf("%s", pengunjung.nama);
                    printf("Masukkan pesanan: ");
                    scanf("%s", pengunjung.pesanan);
                    enqueue(&antrian, pengunjung);
                    printf("Antrian bertambah\n");
                } else {
                    printf("Antrian penuh\n");
                }
                break;
            case 2:
                if (!isEmpty(&antrian)) {
                        printf("Pesanan yang diselesaikan : %s",dequeue(&antrian));

                }break;
            case 3:
                if(!isEmpty(&antrian)){
                    displayQueue(&antrian);
                }
                break;
            case 4:
                exit(0);
            default:
                printf("Pilihan tidak valid");
        }
    }
return 0;
}