//  P4779 【模板】单源最短路径（标准版）
#include <stdio.h>

#include "SmallHeap.cpp"
#include "Vector.cpp"

struct node {
    /* data */
    int u, v, w;
};

int main() {
    int n, m, s;

    scanf("%d %d %d", &n, &m, &s);
    Vector<node> g;
    g.init();
    node tTarget;
    for (int i = 1; i <= m; i++) {
        scanf("%d %d %d", &tTarget.u, &tTarget.v, &tTarget.w);
        g.pushData(tTarget);
    }

    int d[n + 1];
    bool is[n + 1];
    for (int i = 0; i < n + 1; i++) {
        d[i] = 0;
        is[i] = false;
    }
    SmallHeap<int> dQueue;
    dQueue.init();

    is[s] = 0;
    d[s] = 0;
    dQueue.pushNode(s, 0);
    int sum = 0;
    int xNode, wNode;
    int tm;
    while (sum != n) {
        dQueue.print();
        do {
            xNode = dQueue.getData();
            wNode = dQueue.getU();
            dQueue.popNode();
        } while (is[xNode]);
        is[xNode] = true;
        d[xNode] = wNode;

        if (++sum == n) {
            break;
        }
        tm = g.getLength();
        for (int i = 1; i <= tm; i++) {
            tTarget = g.getData(i);
            if (xNode == tTarget.u) {
                dQueue.pushNode(tTarget.v, tTarget.w + wNode);
                g.popData(i);
                i--;
                tm--;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        printf("%d ", d[i]);
    }

    return 0;
}