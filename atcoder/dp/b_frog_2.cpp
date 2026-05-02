//
//  b_frog_2.cpp
//
//
//  Created by 용균 on 5/2/26.
//

#include <iostream>
#include <cstring>

using namespace std;

int N, K;
int arr[100005];
int dp[100005];
const int INF = 2e9;

//시간복잡도 : O(NK)

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin>>N>>K;
    
    fill_n(dp, 100005, INF);
    
    for(int i=1; i<=N;++i) cin>>arr[i];
    
    dp[1] = 0;
    
    for(int i=2; i<=N; ++i){
        for(int j=1; j<=K; ++j){
            if(i-j <=0) continue;
            
            dp[i] = min(dp[i], dp[i-j]+abs(arr[i]-arr[i-j]));
        }
    }
    
    cout<<dp[N];
}


