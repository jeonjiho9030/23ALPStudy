#include <bits/stdc++.h>

#define endl "\n"
#define MAX 20010
#define INF 987654321
using namespace std;

int N, M, Answer;
int Dist[MAX];
vector<int> V[MAX];
vector<int> Answer_V;

int Bigger(int A, int B) { if (A > B) return A; return B; }

void Input()
{
    cin >> N >> M;
    for (int i = 1; i <= N; i++) Dist[i] = INF;
    for (int i = 0; i < M; i++)
    {
        int a, b; cin >> a >> b;
        V[a].push_back(b);
        V[b].push_back(a);
    }
}

void Solution()
{
    priority_queue<pair<int, int>> PQ;
    PQ.push(make_pair(0, 1));
    Dist[1] = 0;

    while (PQ.empty() == 0)
    {
        int Cost = -PQ.top().first;
        int Cur = PQ.top().second;
        PQ.pop();

        for (int i = 0; i < V[Cur].size(); i++)
        {
            int Next = V[Cur][i];
            int nCost = Cost + 1;

            if (Dist[Next] > nCost)
            {
                Dist[Next] = nCost;
                PQ.push(make_pair(-nCost, Next));

                if (Dist[Next] > Answer)
                {
                    Answer = Dist[Next];
                    Answer_V.clear();
                    Answer_V.push_back(Next);
                }
                else if (Dist[Next] == Answer) Answer_V.push_back(Next);
            }
        }
    }

    sort(Answer_V.begin(), Answer_V.end());
    cout << Answer_V[0] << " " << Answer << " " << Answer_V.size() << endl;
}

void Solve()
{
    Input();
    Solution();
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //    freopen("Input.txt", "r", stdin);
    Solve();

    return 0;
}
