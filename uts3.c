#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int waktu;
} Pengunjung;

typedef struct {
    Pengunjung items[MAX_SIZE];
    int front, rear;
    int count;
    int kapasitas;
} Queue;

void initQueue(Queue *q, int kapasitas) {
    q->front = 0;
    q->rear = -1;
    q->count = 0;
    q->kapasitas = kapasitas;
}

void enqueue(Queue *q, Pengunjung pengunjung) {
        q->rear = (q->rear + 1) % MAX_SIZE;
        q->items[q->rear] = pengunjung;
        q->count++;
    }


Pengunjung dequeue(Queue *q) {

        Pengunjung pengunjung = q->items[q->front];
        q->front = (q->front + 1) % MAX_SIZE;
        q->count--;
        return pengunjung;
    }


int isEmpty(Queue *q) {
    return q->count == 0;
}

int main() {
    Queue queue;
    int kapasitas, jumlahPengunjung;
    printf("Masukkan kapasitas pengunjung rumah makan: ");
    scanf("%d", &kapasitas);

    initQueue(&queue, kapasitas);

    printf("Masukkan jumlah pengunjung: ");
    scanf("%d", &jumlahPengunjung);

    for (int i = 0; i < jumlahPengunjung; i++) {
        int waktu;
        printf("Masukkan waktu tinggal pengunjung %d (menit): ", i + 1);
        scanf("%d", &waktu);
        Pengunjung pengunjung = {waktu};
        enqueue(&queue, pengunjung);
    }

    printf("Jumlah pengunjung di restoran: %d\n", queue.count);

    while (!isEmpty(&queue)) {
        Pengunjung pengunjungKeluar = dequeue(&queue);
        printf("Pengunjung keluar setelah %d menit\n", pengunjungKeluar.waktu);
        printf("Jumlah pengunjung di restoran setelah pengunjung keluar: %d\n", queue.count);
    }

    printf("Semua pengunjung telah keluar\n");

    return 0;
}