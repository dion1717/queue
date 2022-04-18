#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX 3

typedef struct Queue {
  int data[MAX], head, tail;
} queue_t;

queue_t antri;

void awal() { antri.head = antri.tail = -1; }

short isFull() {
  if (antri.tail == MAX - 1) {
    return 1;
  }
  return 0;
}

short isEmpty() {
  if (antri.tail == -1) {
    return 1;
  }
  return 0;
}

void enqueue(int data) {
  if (isEmpty()) {
    antri.head = antri.tail = 0;
  } else if (isFull()) {
    printf("Data sudah Full!");
    return;
  } else {
    antri.tail++;
  }
  antri.data[antri.tail] = data;
  printf("%d berhasil ditambahkan!", antri.data[antri.tail]);
}

void cetak() {
  if (isEmpty()) {
    printf("Data masih kosong!");
    return;
  }
  for (int i = 0; i <= antri.tail; i++) {
    printf("%d\n", antri.data[i]);
  }
}

void dequeue() {
  if (isEmpty()) {
    printf("Data sudah kosong!");
    return;
  }
  int temp = antri.data[0];
  for (int i = 0; i < antri.tail; i++) {
    antri.data[i] = antri.data[i + 1];
  }
  antri.tail--;
  printf("Data %d berhasil keluar!", temp);
}

void clear() {
  antri.head = antri.tail = -1;
  printf("Data sudah kosong!");
}

int main() {
  short pilihan;
  int data;
  awal();
  while (1) {
    system("cls");
    puts("Menu");
    puts("1. Masukkan satu antrian");
    puts("2. Keluarkan satu antrian");
    puts("3. Lihat isi antrian");
    puts("4. Hapus isi antrian");
    puts("5. Keluar");
    printf("Pilihan: ");
    scanf("%d", &pilihan);

    if (pilihan == 1) {
      printf("Data: ");
      scanf("%d", &data);
      enqueue(data);
    } else if (pilihan == 2) {
      dequeue();
    } else if (pilihan == 3) {
      cetak();
    } else if (pilihan == 4) {
      clear();
    } else if (pilihan == 5) {
      return 0;
    } else {
      printf("Pilihan salah!");
    }

    getch();
  }
}
