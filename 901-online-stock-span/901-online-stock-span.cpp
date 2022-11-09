class StockSpanner {
public:
    
    vector<pair<int,int>> spans;
    
    StockSpanner() {
        spans = vector<pair<int,int>>();
    }
    
    int next(int price) {
        
        int curr_span = 0;
        int i = spans.size() - 1;
        
        while (i >= 0 && spans[i].first <= price){
            curr_span += spans[i].second;
            i -= spans[i].second;
        }
        
        curr_span++;
        
        spans.push_back(pair<int,int>(price, curr_span));
        
        return curr_span;
        
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */