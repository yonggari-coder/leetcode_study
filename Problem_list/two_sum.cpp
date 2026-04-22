//
//  two_sum.cpp
//  
//
//  Created by 용균 on 4/22/26.
//

#include <algorithm>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<pair<int,int>> v;
        v.clear();
        for(int i=0; i<nums.size();++i){
            v.push_back({nums[i], i});
        }
        
        sort(v.begin(), v.end());

        int st = 0;
        int en = nums.size()-1;

        while(v[st].first+v[en].first!=target){
            if(v[st].first+v[en].first < target){
                st++;
            }
            else{
                en--;
            }
        }

        vector<int> temp;
        temp.clear();
        temp.push_back(v[st].second);
        temp.push_back(v[en].second);

        return temp;
    }
};
