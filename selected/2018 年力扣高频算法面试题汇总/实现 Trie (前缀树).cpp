#include<iostream>
#include<vector>
using namespace std;

struct TrieNode {
    char val;
    vector<TrieNode*> next;
    bool isWord;
};

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        insert(word, 0, root);
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* curr = root;
        int pos = 0;
        while (true) {
            bool flag = false;
            for (int i = 0; i < curr->next.size(); i++) {
                if (curr->next[i]->val == word[pos]) {
                    if (pos == word.size() - 1) {
                        if (curr->next[i]->isWord) {
                            return true;
                        } else {
                            return false;
                        }
                    }
                    flag = true;
                    pos++;
                    curr = curr->next[i];
                    break;
                }
            }
            if (!flag)
                return false;
        }
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        int pos = 0;
        while (true) {
            bool flag = false;
            for (int i = 0; i < curr->next.size(); i++) {
                if (curr->next[i]->val == prefix[pos]) {
                    if (pos == prefix.size() - 1) {
                        return true;
                    }
                    flag = true;
                    pos++;
                    curr = curr->next[i];
                    break;
                }
            }
            if (!flag)
                return false;
        }
    }
private:
    TrieNode* root;
    void insert(string word, int pos, TrieNode* root) {
        for (int i = 0; i < root->next.size(); i++) {
            if (word[pos] == root->next[i]->val) {
                if (pos == word.size() - 1) {
                    root->next[i]->isWord = true;
                } else {
                    insert(word, pos + 1, root->next[i]);
                }
                return;
            }
        }
        TrieNode* node = new TrieNode;
        node->isWord = false;
        node->val = word[pos];
        root->next.push_back(node);
        if (pos == word.size() - 1) {
            root->next[root->next.size()-1]->isWord = true;
        } else {
            insert(word, pos + 1, root->next[root->next.size()-1]);
        }
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */