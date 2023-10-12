#include <bits/stdc++.h>
using namespace std;

int n, m, a, b;
vector <int> adj[501];
int vis[501];
int ans = 0;

void dfs() {
    stack<int> s;
    s.push(1);                          //상근이를 스택에 집어넣고
    while (!s.empty()) {                //스택이 비어있지 않은 동안
        int cur = s.top();              //현재 탐색할 값 = cur
        s.pop();
        vis[cur] = true;                //탐색한 사람은 vis값을 true로 바꿈
        for (int nxt : adj[cur]) {      //연결되어있는 사람 nxt
            if (vis[nxt]) continue;     //이미 방문했던 사람이라면 반복
            vis[nxt] = true;            //방문표시
            ans++;
            if (cur == 1) s.push(nxt);  //상근이의 이웃인 경우에만 스택에 추가
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs();
    cout << ans;
}
