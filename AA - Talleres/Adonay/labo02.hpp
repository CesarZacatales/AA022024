
#ifndef LABO02_H
#define LABO02_H

#include <iostream>
#include <limits.h>  // Incluya este encabezado para INT_MAX

class PriorityQueue {
private:
    int size = 0;
    int* head = nullptr;

    int left(const int i);
    int right(const int i);
    int parent(const int i);

public:
    PriorityQueue(int* array, int size);
    PriorityQueue();

    void swap(int element, int smallest);  // Cambio de más grande a más pequeña
    void MinHeapify(int i);  // Cambio de MaxHeapify a MinHeapify
    void BuildMinHeap(int* array);  // Cambio de BuildMaxHeap a BuildMinHeap
    void Heapsort();

    int MinHeapMinimum();  // Cambio de MaxHeapMaximum a MinHeapMinimum
    int MinHeapExtractMin();  // Cambio de MaxHeapExtractMax a MinHeapExtractMin
    void MinHeapDecreaseKey(int current_key, int new_key);  // Cambio de MaxHeapIncreaseKey a MinHeapDecreaseKey
    void MinHeapInsert(int key);
    void Display();

    ~PriorityQueue();
};

int PriorityQueue::left(const int i) {
    return 2 * i + 1;
}

int PriorityQueue::right(const int i) {
    return 2 * i + 2;
}

int PriorityQueue::parent(const int i) {
    return (i - 1) / 2;  // Cambio de i / 2
}

PriorityQueue::PriorityQueue() {
    this->size = 0;
    this->head = nullptr;
}

PriorityQueue::PriorityQueue(int* array, int size) : size(size), head(array) {
    BuildMinHeap(array);  // Cambio de BuildMaxHeap
}

void PriorityQueue::swap(int i, int smallest) {
    int temp = head[i];
    head[i] = head[smallest];
    head[smallest] = temp;
}

void PriorityQueue::MinHeapify(int i) {  // Cambio de MaxHeapify
    int l = left(i);
    int r = right(i);
    int smallest = i;  // Cambio de largest a smallest

    if (l < size && head[l] < head[i]) {
        smallest = l;
    }
    if (r < size && head[r] < head[smallest]) {
        smallest = r;
    }
    if (smallest != i) {
        swap(i, smallest);
        MinHeapify(smallest);
    }
}

void PriorityQueue::BuildMinHeap(int* array) {  // Cambio de BuildMaxHeap
    int size = sizeof(array) / sizeof(array[0]);

    for (int i = (size / 2) - 1; i >= 0; i--) {
        MinHeapify(i);  // Cambio de MaxHeapify
    }
}

void PriorityQueue::Heapsort() {
    BuildMinHeap(head);  // Cambio de BuilldMaxHeap
    int size = this->size;
    std::cout << size << std::endl;
    for (int i = this->size - 1; i >= 0; i++) {
        swap(0, i);
        this->size--;
        MinHeapify(0);  // Cambio de MaxHeapify
    }
    this->size = size;
}

int PriorityQueue::MinHeapMinimum() {  // Cambio de MaxHeapMaximum
    return head[0];
}

int PriorityQueue::MinHeapExtractMin() {  // Cambio de MaxHeapExtractMax
    if (size < 1) {
        std::cout << "Heap underflow" << std::endl;
        return -1;
    }
    int min = head[0];
    head[0] = head[size - 1];
    size--;
    MinHeapify(0);  // Cambio de MaxHeapify
    return min;
}

void PriorityQueue::MinHeapDecreaseKey(int current_key, int new_key) {  // Cambio de MaxHeapIncreaseKey
    if (new_key > current_key) {
        std::cout << "New key is greater than current key" << std::endl;
        return;
    }
    head[current_key] = new_key;
    while (current_key > 0 && head[parent(current_key)] > head[current_key]) {
        swap(current_key, parent(current_key));
        current_key = parent(current_key);
    }
}

void PriorityQueue::MinHeapInsert(int key) {
    size++;
    head[size - 1] = INT_MAX;  // Cambio de -1 a INT_MAX
    MinHeapDecreaseKey(size - 1, key);  // Cambio de MaxHeapIncreaseKey a MinHeapDecreaseKey
}

void PriorityQueue::Display() {
    for (int i = 0; i < size; i++) {
        std::cout << head[i] << " ";
    }
    std::cout << std::endl;
}

PriorityQueue::~PriorityQueue() {
    delete[] head;
}

#endif
