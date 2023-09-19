#include<iostream>
using namespace std;
int arr[1025][1025];
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int N, M;
    cin >> N >> M;
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> arr[i][j];
            arr[i][j] += arr[i][j - 1];
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            arr[i][j] += arr[i - 1][j];
        }
    }
    for (int i = 0; i < M; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        int ans = arr[x2][y2] - (arr[x2][y1 - 1] + arr[x1 - 1][y2]) + arr[x1 - 1][y1 - 1];
        cout << ans << '\n';

    }
    return 0;
}