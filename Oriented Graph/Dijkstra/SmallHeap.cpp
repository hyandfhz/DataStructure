#define MAX_N 10010

template <typename item>
class SmallHeap {
   private:
    item data[10010];
    item w[10010];
    int length;

    void swapData(item x, item y) {
        item t = data[x];
        data[x] = data[y];
        data[y] = t;
        t = w[x];
        w[x] = w[y];
        w[y] = t;
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
    int getU(int x = 1) { return w[x]; }

    void pushNode(item node, item wNode) {
        data[++length] = node;
        w[length] = wNode;
        shiftUp(length);
    }

    void popNode(int x = 1) {
        swapData(x, length--);
        shiftDown(x);
    }

    void init() { length = 0; }
};