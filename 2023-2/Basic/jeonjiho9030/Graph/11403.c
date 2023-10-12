#include <bits/std++.h>
using std::cin;
using std::cout;

int mat[100][100];
int expmat[100][100];
int tmp[100][100];
int ans[100][100];

int main()
{
    std::ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    int x;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> x;
            mat[j][i] = x; // adjacency matrix의 transpose를 저장
            if (i == j) expmat[i][j] = 1; // identity matrix
        }
    }

    for (int _ = 0; _ < N; _++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                for (int k = 0; k < N; k++) {
                    tmp[i][j] += mat[i][k] * expmat[k][j];
                }
            }
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                expmat[i][j] = tmp[i][j];
                if (tmp[i][j] != 0) { // N번만에 i에서 j로 가는 경로가 있다면
                    ans[i][j] = 1; // 일단 저장
                }
                tmp[i][j] = 0;
            }
        }

    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << ans[j][i] << ' '; // adjacency matrix는 다시 transpose해줘야 한다.
        }
        cout << '\n';
    }

    return 0;
}
