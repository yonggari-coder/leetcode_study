//
//  00796_Rotate_String.cpp
//  
//
//  Created by 용균 on 5/3/26.
//

class Solution {
public:
    bool rotateString(string s, string goal) {
        for(int i=0; i<s.length();++i){
            if(s==goal) return true;

            char a = s[0];
            s.erase(s.begin());
            s.push_back(a);
        }
        return false;
    }

};
