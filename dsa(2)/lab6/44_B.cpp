#include <iostream>
#include <vector>
#include <climits>

void heapify(std::vector<int>& heap, int heapSize, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < heapSize && heap[left] < heap[smallest]) {
        smallest = left;
    }

    if (right < heapSize && heap[right] < heap[smallest]) {
        smallest = right;
    }

    if (smallest != i) {
        std::swap(heap[i], heap[smallest]);
        heapify(heap, heapSize, smallest);
    }
}

void buildMinHeap(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; --i) {
        heapify(arr, n, i);
    }
}

int popMin(std::vector<int>& heap, int& heapSize) {
    int minElement = heap[0];
    heap[0] = heap[heapSize - 1];
    heapSize--;
    heapify(heap, heapSize, 0);
    return minElement;
}

void pushHeap(std::vector<int>& heap, int& heapSize, int element) {
    heap[heapSize] = element;
    heapSize++;
    int i = heapSize - 1;

    while (i > 0) {
        int parent = (i - 1) / 2;
        if (heap[i] < heap[parent]) {
            std::swap(heap[i], heap[parent]);
            i = parent;
        } else {
            break;
        }
    }
}

int cookies(int k, std::vector<int>& arr) {
    int heapSize = arr.size();

    buildMinHeap(arr);

    int operations = 0;
    while (heapSize > 1 && arr[0] < k) {
        int leastSweet = popMin(arr, heapSize);
        int secondLeastSweet = popMin(arr, heapSize);

        int newCookie = leastSweet + 2 * secondLeastSweet;
        pushHeap(arr, heapSize, newCookie);

        operations++;
    }

    if (heapSize == 0 || arr[0] < k) {
        return -1;
    }

    return operations;
}

int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> arr(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    int result = cookies(k, arr);

    std::cout << result << std::endl;

    return 0;
}
