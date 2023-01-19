#include <bits/stdc++.h>
using namespace std;
/* LeetCode submission follows below. */

class Task {
public:
    int id;
    int enqueue;
    int processing;
    Task(int a, int b, int c) {
        id = a;
        enqueue = b;
        processing = c;
    }
};

class Compare_Enqueue {
public:
    bool operator() (Task a, Task b) {
        return a.enqueue > b.enqueue;
    }
};

class Compare_Processing {
public:
    bool operator() (Task a, Task b) {
        if (a.processing > b.processing) {
            return true;
        } else if (a.processing == b.processing) {
            return a.id > b.id;
        } else {
            return false;
        }
    }
};

class Solution {

public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        priority_queue<Task, vector<Task>, Compare_Enqueue> to_enqueue;
        priority_queue<Task, vector<Task>, Compare_Processing> to_run;
        long long t = 0;
        vector<int> ans;
        for (int i = 0; i < tasks.size(); ++i) {
            to_enqueue.push(Task { i, tasks[i][0], tasks[i][1] });
        }
        while (!to_enqueue.empty() || !to_run.empty()) {
            // pop all tasks <= t from to_queue
            while (true) { // move from to_enqueue to to_run
                if (!to_enqueue.empty() && to_enqueue.top().enqueue <= t) {
                    to_run.push(to_enqueue.top());
                    to_enqueue.pop();
                } else break;
            }
            if (to_run.empty()) {
                t = to_enqueue.top().enqueue;
            } else {
                ans.push_back(to_run.top().id);
                t += to_run.top().processing;
                to_run.pop();
            }
        }
        return ans;
    }
};