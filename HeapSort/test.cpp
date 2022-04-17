// 堆排序
#include <stdio.h>
#include "SmallHeap.cpp"

int main() {
    int n;
    scanf("%d", &n);

    int targetI;
    SmallHeap heap = SmallHeap();
    for (int i = 1; i <= n; i++) {
        scanf("%d", &targetI);
        heap.pushNode(targetI);
    }

    while (heap.getLength()) {
        printf("%d ", heap.getData());
        heap.popNode();
    }
    printf("\n");

    return 0;
}