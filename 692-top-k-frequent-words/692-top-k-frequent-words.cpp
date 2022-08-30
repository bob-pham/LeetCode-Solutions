class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> counts;
        vector<pair<int, string>> pairs;
        vector<string> result;
        
        for (string wrd : words)
            counts[wrd]++;
        
        for (const auto p : counts) {
            pairs.push_back(pair<int, string>(-p.second, p.first));
        }
        
        make_heap(pairs.begin(), pairs.end(), greater<pair<int, string>>());
                
        while (k--) {
            result.push_back(pairs.front().second);
            pop_heap(pairs.begin(), pairs.end(), greater<pair<int, string>>());
            pairs.pop_back();
        }
        
        return result;
        
    }
};