// @leet start

class Trie {
private:
    Trie * map[26];
public:
    Trie() {
        for (int i = 0; i < 26; i++) {
            map[i] = nullptr;
        }
    }

    void add(string s, int idx) {
        if (idx >= s.size()) {
            return;
        }
        if ((this->map[s[idx] - 'a']) == nullptr) {
            this->map[s[idx] - 'a'] = new Trie();
        }
        this->map[s[idx] - 'a']->add(s, idx + 1);
    }

    bool find(string s, int idx, bool skip) {
        if (idx >= s.size()) {
            return skip;
        }

        if (this->map[s[idx] - 'a'] == nullptr) {
            if (skip) {
                return false;
            } else {
                for (int i = 0; i < 26; i++) {
                    if (this->map[i] != nullptr && \
                        this->map[i]->find(s, idx + 1, true)) {
                            return true; 
                        }
                }
                return false;
            }
        } else {
            return this->map[s[idx] - 'a']->find(s, idx + 1, skip);
        }
    }
};

class MagicDictionary {
Trie * map;
public:
    MagicDictionary() {
        this->map = new Trie();
    }
    
    void buildDict(vector<string> dictionary) {
        for (string wrd : dictionary) {
            this->map->add(wrd, 0);
        }
    }
    
    bool search(string searchWord) {
        return this->map->find(searchWord, 0, false);
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */
// @leet end
