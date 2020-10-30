#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

int main(){
    int n;
    int t = 0;
    while(cin >> n && n){
        int arr[n+1];
        memset(arr, 0, sizeof(arr)); 
        for(int i = 1; i <= n; i++)
		    cin >> arr[i];
        long long dp[n+1][n+1];
        memset(dp, 0, sizeof(dp));
        for(int i = 2; i <= n; i += 2){
            for(int j = 1; j + i -1 <= n; j++){
                if(i == 2){
                    dp[i][j] = abs(arr[j+1] - arr[j]);
                }
                else{
                    int ans1 = 0, ans2 = 0;
                    if(arr[j+1] >= arr[j+i-1]){          //if先手取左
                        ans1 = arr[j]-arr[j+1]+dp[i-2][j+2]; 
                    }
                    else{
                        ans1 = arr[j]-arr[j+i-1]+dp[i-2][j+1];
                    }
                    if(arr[j] >= arr[j+i-2]){            // if先手取右端
                        ans2 = arr[j+i-1] - arr[j] + dp[i-2][j+1];
                    }
                    else{
                        ans2 = arr[j+i-1] - arr[j+i-2] + dp[i-2][j];
                    }
                    
                    dp[i][j] = max(ans1, ans2);
                }
            }
        }

        printf("先手win %lld points.\n", dp[n][1]);
    }
} 
