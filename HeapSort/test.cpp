// 堆排序
#include <fstream>
#include <iostream>

#include <stdio.h>
#include "SmallHeap.cpp"
using namespace std;

int main() {
    ifstream fin("in");
    int n;
    // scanf("%d", &n);
    fin >> n;

    int s = 0;
    int targetI;
    SmallHeap<int> heap = SmallHeap<int>();
    for (int i = 1; i <= n; i++) {
        // scanf("%d", &targetI);
        fin >> targetI;
        heap.pushNode(targetI);
        s++;
    }

    int sum = 0;
    int x1, x2;
    while (heap.getLength() >= 2) {
        x1 = heap.getData();
        heap.popNode();
        x2 = heap.getData();
        heap.popNode();

        heap.pushNode(x1 + x2);
        sum += x1 + x2;
    }
    printf("%d\n%d\n", sum, s);

    return 0;
}