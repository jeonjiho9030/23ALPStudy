#include <bits/stdc++.h>
using namespace std;

int v, e, a, b;
vector <int> adj[105];
int vis[105];
int ans = 0;

void dfs(int cur) {
    vis[cur] = true;
    for (auto node : adj[cur]) {             //연결된 노드를 반복문을 통해 방문
        if (vis[node]) continue;          //이미 방문했던 노드인지 확인
        ans++;                              //방문하지 않은 연결된 컴퓨터가 있으면 결과값 증가
        dfs(node);                          //재귀적으로 수행
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> v >> e;
    for (int i = 0; i < e; i++) {
        cin >> a >> b;
        adj[a].push_back(b);                //무방향 그래프이므로
        adj[b].push_back(a);                //양쪽의 벡터에 다 추가해줘야함
    }
    dfs(1);                       //1번컴퓨터부터 연결된 컴퓨터의 개수를 셈
    cout << ans;
}
