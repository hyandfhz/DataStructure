// P1177 【模板】快速排序
#include <stdio.h>

class SmallHeap {
   private:
    int data[0x7fffffff];
    int length;

    void swapData(int x, int y) {
        int t = data[x];
        data[x] = data[y];
        data[y] = t;
    }

    void shiftUp(int x) {
        while (x / 2 >= 1) {
            if (data[x] < data[x / 2]) {
                swapData(x, x / 2);
                x /= 2;
            } else {
                break;
            }
        }
    }

    void shiftDown(int x) {
        while (x * 2 <= length) {
            int t = x * 2;
            // 选出两个最大的子节点
            if (t + 1 <= length /* 判断越界 */ && data[t + 1] < data[t]) {
                t++;
            }
            if (data[x] > data[t]) {
                swapData(x, t);
                x = t;
            } else {
                break;
            }
        }
    }

   public:
    int getLength() { return length; }

    int getData(int x = 1) { return data[1]; }

    void pushNode(int node) {
        data[++length] = node;
        shiftUp(length);
    }

    void popNode(int x = 1) {
        swapData(x, length--);
        shiftDown(x);
    }

    SmallHeap() { length = 0; }
};

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