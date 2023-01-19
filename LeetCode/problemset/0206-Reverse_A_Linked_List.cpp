#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/* LeetCode submission follows below. */

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // ListNode* ans = nullptr;

        // while (head) {
        //     ListNode* prev = new ListNode(head->val, ans);
        //     ans = prev;
        //     head = head->next;
        // }
        // return ans;

        if (!head) return nullptr;
        ListNode* prev = nullptr;
        while (head) {
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
};