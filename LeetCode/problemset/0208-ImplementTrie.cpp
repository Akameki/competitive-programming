#include <bits/stdc++.h>
using namespace std;
/* LeetCode submission follows below. */

class Trie {
    Trie *children[26] = {nullptr};
    bool valid = false;
public:
    Trie() {}
    
    void insert(string word) {
        if (word.empty()) {
            valid = true;
            return;
        }

        Trie *child = children[word[0] - 'a'];

        if (child) return child->insert(word.substr(1));
        
        child = children[word[0] - 'a'] = new Trie();
        child->insert(word.substr(1));
    }
    
    bool search(string word) {
        if (word.empty()) return valid;

        Trie *child = children[word[0] - 'a'];
        return child && child->search(word.substr(1));
    }
    
    bool startsWith(string prefix) {
        if (prefix.empty()) return true;

        Trie *child = children[prefix[0] - 'a'];
        return child && child->startsWith(prefix.substr(1));
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */