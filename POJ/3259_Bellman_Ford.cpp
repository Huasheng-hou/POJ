//
//  3259_Bellman_Ford.cpp
//  POJ
//
//  Created by apple on 2019/12/26.
//  Copyright © 2019 apple. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string.h>

// 

using namespace std;

const int inf = 1<<30;
const int maxn = 510;
const int maxm = 6000;

int T, N, M, W, nw;
int d[maxn], e1[maxm], e2[maxm], w[maxm];

int Bellman_Ford() {
    
    for (int i = 1; i < N; i++) {
        for (int j = 1; j <= nw; j++) {
            int x = e1[j], y = e2[j];
            d[x] = min(d[y] + w[j], d[x]);
        }
    }
    for (int j = 1; j <= nw; j++) {
        int x = e1[j], y = e2[j];
        if (d[x] > d[y] + w[j]) return 1;
    }
    return 0;
}

void solve() {

    cin >> T;
    while (T--) {
        cin >> N >> M >> W;
        for (int i = 1; i <= N; i++) d[i] = inf;
        d[1] = 0; nw = 0;
        for (int i = 1; i <= M; i++) {
            int u, v, dist; scanf("%d%d%d", &u, &v, &dist);
            e1[++nw] = u; e2[nw] = v; w[nw] = dist;
            e2[++nw] = u; e1[nw] = v; w[nw] = dist;
        }
        for (int i = 1; i <= W; i++) {
            int u, v, dist; scanf("%d%d%d", &u, &v, &dist);
            e1[++nw] = u; e2[nw] = v; w[nw] = -dist;
        }
        if (Bellman_Ford()) printf("YES\n"); else printf("NO\n");
    }
}

int main() {

#ifdef OJ
    freopen("/Users/apple/Develop/POJ/POJ/Inputs/input","r",stdin);
#endif

    solve();

    return 0;
}
