#include<iostream>
#include<cstring>
using namespace std;

int main()
{
   
    int index = 0;
        int N;
        int M;
        cin >> N >> M;
        long** dp;
        dp =new long*[M+ 1];
        for (int i = 0;i < M + 1;i++) {
            dp[i] = new long[N + 1];
        }
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= M; i++) {
            for (int j = 1; j <= N; j++) {
                if (j == 1)dp[i][j] = 1;
                else {
                    for (int k = 1; 2 * k <= i; k++) {
                        dp[i][j] += dp[k][j - 1];
                    }
                }

            }
        }
        long long ans = 0;
        for (int i = 1; i <= M; i++) {
            ans += dp[i][N];
        }
        printf("Case %d: n = %d, m = %d, # lists = %lld\n", ++index, N, M, ans);
        for (int i = 0; i < M + 1; i++)
            delete[]dp[i];
        delete[]dp;
  
    return 0;
}
