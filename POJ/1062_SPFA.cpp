//
//  1062_SPFA.cpp
//  POJ
//
//  Created by apple on 2019/12/26.
//  Copyright © 2019 apple. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>
#include <string.h>

// SPFA (Shortest Path Faster Algorithm)，Bellman-Ford的优化版，FIFO版
// 的最短路算法

using namespace std;

const int maxn = 110;
int m, n, w[maxn][maxn], d[maxn], p[maxn], l[maxn];
vector<int> e[maxn];

void SPFA() {
    
    queue<int> q; q.push(1);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int i = 1; i <= n; i++) {
            if (i == u || abs(l[i] - l[u]) > m || w[i][u] == -1) continue;
            
        }
    }
}

void solve() {

    cin >> m >> n; memset(w, -1, sizeof(w));
    for (int i = 1; i <= n; i++) {
        int x; scanf("%d%d%d", d+i, l+i, &x);
        for (int j = 1; j <= x; j++) {
            int u, p; scanf("%d%d", &u, &p); w[u][i] = p;
        }
    }
    
    printf("%d\n", d[1]);
}

int main() {

#ifdef OJ
    freopen("/Users/apple/Develop/POJ/POJ/Inputs/input","r",stdin);
#endif

    solve();

    return 0;
}
