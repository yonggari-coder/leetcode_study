//
//  2833_Furtest_Point_From_Origin.cpp
//  
//
//  Created by 용균 on 4/24/26.
//

class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int left_cnt = 0;
        int right_cnt = 0;
        int middle_cnt = 0;

        for(int i=0;i<moves.length(); ++i){
            if(moves[i]=='R') right_cnt++;
            else if(moves[i]=='L') left_cnt++;
            else middle_cnt++;
        }

        return abs(right_cnt- left_cnt) + middle_cnt;
    }
};
