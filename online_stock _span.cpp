class StockSpanner {
public:
stack<pair<int,int>>s;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int span=1;
        while(!s.empty() && s.top().first<=price){
            span+=s.top().second;
            s.pop();

        }

        pair<int,int>q;
        q.first=price;
        q.second=span;
        s.push(q);
        return s.top().second;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */