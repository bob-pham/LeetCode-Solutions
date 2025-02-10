// @leet start
class TrieNode {
public:
    bool is_end = false;
    TrieNode * child[26] = { nullptr };
};


class Trie {
private:
    TrieNode * root;
public:
    Trie() {
        this->root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode * curr_node = this->root;
        for (char c : word) {
            int idx = c - 'a';
            if (curr_node->child[idx] == nullptr) {
                curr_node->child[idx] = new TrieNode();
            }
            curr_node = curr_node->child[idx];
        }
        curr_node->is_end = true;
    }
    
    bool search(string word) {
        TrieNode * curr_node = this->root;
        for (char c : word) {
            int idx = c - 'a';
            if (curr_node->child[idx] == nullptr) {
                return false;
            }
            curr_node = curr_node->child[idx];
        }
        return curr_node->is_end;
    }
    
    bool startsWith(string prefix) {
        TrieNode * curr_node = this->root;
        for (char c : prefix) {
            int idx = c - 'a';
            if (curr_node->child[idx] == nullptr) {
                return false;
            }
            curr_node = curr_node->child[idx];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @leet end
