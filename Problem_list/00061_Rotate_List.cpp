//
//  00061_Rotate_List.cpp
//  
//
//  Created by 용균 on 5/5/26.
//

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
//끊어주고 이어주기만 잘하면 된다. 

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        
        int n = 0;
        ListNode* last = head;
        if(last==nullptr) return head;
        while(1){
            n++;
            if(last->next != nullptr){
                last = last->next;
            } else {
                break;
            }
        }

        int kk = k%n;
        int m = n-kk-1;

        ListNode* first = head;
        ListNode* now = head;
        
        while(m--){
            now = now->next;
        }

        if(now->next != nullptr){
            last->next = first;
            ListNode* start = now->next;
            now->next = nullptr;
            return start;
        } else {
            return head;
        }
        
    }
};
