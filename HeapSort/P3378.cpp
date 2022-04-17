// P3378 【模板】堆
#include <stdio.h>
#include "SmallHeap.cpp"

int main() {
    int n;
    scanf("%d", &n);

    int targetI;
    SmallHeap<int> heap = SmallHeap<int>();
    for (int i = 1; i <= n; i++) {
        scanf("%d", &targetI);
        switch (targetI) {
            case 1:
                scanf("%d", &targetI);
                heap.pushNode(targetI);
                break;
            case 2:
                printf("%d\n", heap.getData());
                break;
            case 3:
                heap.popNode();
                break;
        }
    }

    return 0;
}