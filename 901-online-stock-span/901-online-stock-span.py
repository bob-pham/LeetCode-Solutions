class StockSpanner:

    def __init__(self):
        self.spans = []
        # self.spans[n] = (price, span, start)

    def next(self, price: int) -> int:
        span = 0
        i = len(self.spans) - 1
        
        while (i >= 0 and self.spans[i][0] <= price):
            span += self.spans[i][1]
            i = self.spans[i][2]
        
        span += 1
        
        self.spans.append((price, span, i))
        
        return span


# Your StockSpanner object will be instantiated and called as such:
# obj = StockSpanner()
# param_1 = obj.next(price)