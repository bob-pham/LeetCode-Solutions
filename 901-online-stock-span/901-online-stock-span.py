class StockSpanner:

    def __init__(self):
        self.spans = []
        # self.spans[n] = (price, span, start)

    def next(self, price: int) -> int:
        span = 0
        i = len(self.spans) - 1
        
        if i >= 0:
            curr = self.spans[i]
        
        while (i >= 0 and curr[0] <= price):
            span += curr[1]
            i = curr[2]
            curr = self.spans[i]
        
        span += 1
        
        self.spans.append((price, span, i))
        
        return span


# Your StockSpanner object will be instantiated and called as such:
# obj = StockSpanner()
# param_1 = obj.next(price)