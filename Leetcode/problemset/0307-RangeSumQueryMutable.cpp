#include <bits/stdc++.h>
using namespace std;
/* LeetCode submission follows below. */

#define LEFT(i) 2*i + 1
#define RIGHT(i) 2*i + 2

class NumArray {
private:
    vector<int> tree;
    int last;
    void build(int i, int l, int r, vector<int>& nums) {
        if (l == r) {
            tree[i] = nums[l];
            return;
        }
        int m = (l+r)/2;
        build(LEFT(i), l, m, nums);
        build(RIGHT(i), m+1, r, nums);
        tree[i] = tree[LEFT(i)] + tree[RIGHT(i)];
    }

    void u(int curr, int l, int r, int index, int val) {
        if (l == r) {
            assert(index == l);
            tree[curr] = val;
            return;
        }
        int m = (l+r)/2;
        if (index <= m) u(LEFT(curr), l, m, index, val);
        else u(RIGHT(curr), m + 1, r, index, val);
        tree[curr] = tree[LEFT(curr)] + tree[RIGHT(curr)];
    }

    int sum(int curr, int l, int r, int left, int right) {
        if (l == left && r == right)
            return tree[curr];
        int m = (l+r)/2;
        if (right <= m) return sum(LEFT(curr), l, m, left, right);
        else if (left >= m+1) return sum(RIGHT(curr), m+1, r, left, right);
        else return sum(LEFT(curr), l, m, left, m) + sum(RIGHT(curr), m+1, r, m+1, right);
    }
public:
    NumArray(vector<int>& nums) {
        last = nums.size() - 1;
        tree = vector<int>(nums.size() * 4, 0);
        build(0, 0, last, nums);
    }
    
    void update(int index, int val) {
        u(0, 0, last, index, val);
    }
    
    int sumRange(int left, int right) {
        return sum(0, 0, last, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */