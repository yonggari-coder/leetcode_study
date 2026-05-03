//
//  c_vacation.cpp
//  
//
//  Created by 용균 on 5/3/26.
//

#include <iostream>
using namespace std;

int n;
int d[3];
int now[3];
int arr[3];

//처음 시도 : 공간복잡도 O(N)
//공간복잡도를 O(1)으로 줄인 코드.

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin>>n;
    
    while(n--){
        for(int i=0; i<3; ++i){
            now[i] = d[i];
        }
        
        for(int i=0; i<3; ++i){
            cin>>arr[i];
        }
        
        d[0] = max(now[1] + arr[0], now[2]+arr[0]);
        d[1] = max(now[0] + arr[1], now[2]+arr[1]);
        d[2] = max(now[0] + arr[2], now[1]+arr[2]);
    }
    
    cout<<max({d[0],d[1],d[2]});
}
