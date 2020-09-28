#include <bits/stdc++.h>

// Definition for singly-linked list.
struct ListNode {
int val;
ListNode *next;
ListNode() : val(0), next(nullptr) {}
ListNode(int x) : val(x), next(nullptr) {}
ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    
    ListNode* rec(ListNode* prev, ListNode* cur) {
        if (cur == NULL) return prev;
        ListNode* head = rec(cur, cur->next);
        cur->next = prev;
        return head;
    }
    
    ListNode* reverseList(ListNode* head) {
        return rec(NULL, head);
    }
};