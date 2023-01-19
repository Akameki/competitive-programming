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
    void reorderList(ListNode* head) {
        // O(n) space O(n) time
        vector<ListNode *> list;
        while (head) {
            list.push_back(head);
            head = head->next;
        }
        int l = 0, r = list.size() - 1;
        while (l < r - 1) {
            list[r]->next = list[l]->next;
            list[l]->next = list[r];
            ++l; --r;
        }
        list[r]->next = nullptr;
    }
};

    // void reorderList(ListNode* head) {
        // O(1) space O(n^2)
        // while (head->next && head->next->next) {
        //     // iterate to one before 
        //     ListNode *before_last = head;
        //     while (before_last->next->next) before_last = before_last->next;
        //     ListNode *last = before_last->next;

        //     last->next = head->next;
        //     head->next = last;
        //     before_last->next = nullptr;

        //     head = last->next;
        // }
    // }