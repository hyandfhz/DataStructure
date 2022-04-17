// P1090 [NOIP2004 提高组] 合并果子
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

    int sum = 0;
    while (heap.getLength()) {
        sum += heap.getData();
        heap.popNode();
    }
    printf("%d\n", sum);

    return 0;
}