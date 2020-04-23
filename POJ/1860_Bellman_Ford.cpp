//
//  1860_Bellman_Ford.cpp
//  POJ
//
//  Created by apple on 2019/12/25.
//  Copyright © 2019 apple. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string.h>

// mark 这是用 Bellman_Ford 判环路的做法，时间复杂度 O(V*E)

using namespace std;

// 此处将权值初始化为 -inf时会发生WA，原因待查
// const double inf = 1e30;
const int maxn = 110;
const int maxm = 110;
int n, m, s, flag; double v;

int e1[maxm], e2[maxm];
double r1[maxm], c1[maxm], r2[maxm], c2[maxm], d[maxn];

void solve() {
    
    scanf("%d%d%d%lf", &n, &m, &s, &v);
    for (int i = 1; i <= m; i++) {
        scanf("%d%d%lf%lf%lf%lf", e1+i, e2+i, r1+i, c1+i, r2+i, c2+i);
    }
    
    // 如果d数组的初值设为负值，在松弛时会错将负环判定为正环
    d[s] = v;
    for (int k = 1; k < n; k++) {
        for (int i = 1; i <= m; i++) {
            int x = e1[i], y = e2[i];
            d[y] = max((d[x]-c1[i])*r1[i], d[y]);
            d[x] = max((d[y]-c2[i])*r2[i], d[x]);
        }
    }
    
    for (int i = 1; i <= m; i++) {
        int x = e1[i], y = e2[i];
        if (d[x] < (d[y]-c2[i])*r2[i]) {
            flag = 1; break;
        }
        if (d[y] < (d[x]-c1[i])*r1[i]) {
            flag = 1; break;
        }
    }
    
    puts(flag ? "YES" : "NO");
}

int main() {
    
#ifdef OJ
    freopen("/Users/apple/Develop/POJ/POJ/Inputs/input","r",stdin);
#endif
    
    solve();
    
    return 0;
}
