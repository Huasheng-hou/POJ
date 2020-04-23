//
//  1062_Dijkstra.cpp
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

// 经典Dijkstra，用O(V²)实现

using namespace std;

const int maxn = 110;
int m, n, w[maxn][maxn], d[maxn], l[maxn];

void Dijkstra() {
    
    
}

void solve() {

    cin >> m >> n;
    for (int i = 1; i <= n; i++) {
        int x; scanf("%d%d%d", d+i, l+i, &x);
        for (int j = 1; j <= x; j++) {
            int u, p; scanf("%d%d", &u, &p); w[u][i] = p;
        }
    }
    
    Dijkstra();
    printf("%d\n", d[1]);
}

int main() {

#ifdef OJ
    freopen("/Users/apple/Develop/POJ/POJ/Inputs/input","r",stdin);
#endif

    solve();

    return 0;
}
