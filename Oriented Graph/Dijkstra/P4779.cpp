//  P4779 【模板】单源最短路径（标准版）
#include <stdio.h>
#include "SmallHeap.cpp"
struct node {
    /* data */
    int u, v, w;
};

int main() {
    int n, m, s;

    scanf("%d %d %d", &n, &m, &s);
    node g[m + 1];
    node tTarget;
    for (int i = 1; i <= m; i++) {
        scanf("%d %d %d", &tTarget.u, &tTarget.v, &tTarget.w);
        g[i] = tTarget;
    }

    int d[m + 1];
    bool is[m + 1];
    SmallHeap<int> dQueue;
    dQueue.init();

    is[s] = 0;
    dQueue.pushNode(d[s] = 0, s);
    int sum = 0;
    int xNode, wNode;
    while (sum != 6) {
        do {
            xNode = dQueue.getData();
            wNode = dQueue.getU();
            d[xNode] = wNode;
            dQueue.popNode();
        } while (is[xNode]);
        d[xNode] = wNode;
        sum++;
        if (sum == 6)
            continue;
        for (int i = 0; i < m; i++) {
            if (g[i].u == m) {
                dQueue.pushNode(g[i].v, g[i].w + wNode);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", d[i]);
    }

    return 0;
}