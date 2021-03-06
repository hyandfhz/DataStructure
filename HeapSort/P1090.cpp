// P1090 [NOIP2004 提高组] 合并果子
#include <stdio.h>

#define MAX_N 10010

template<typename item>
class SmallHeap {
   private:
    item data[10010];
    int length;

    void swapData(item x, item y) {
        item t = data[x];
        data[x] = data[y];
        data[y] = t;
    }

    void shiftUp(item x) {
        while (x / 2 >= 1) {
            if (data[x] < data[x / 2]) {
                swapData(x, x / 2);
                x /= 2;
            } else {
                break;
            }
        }
    }

    void shiftDown(item x) {
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

    int getData(int x = 1) { return data[x]; }

    void pushNode(item node) {
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
    SmallHeap<int> heap = SmallHeap<int>();
    for (int i = 1; i <= n; i++) {
        scanf("%d", &targetI);
        heap.pushNode(targetI);
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
    printf("%d\n", sum);

    return 0;
}