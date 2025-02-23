class ProductOfNumbers:

    def __init__(self):
        self.num_queue = []
        

    def add(self, num: int) -> None:
        if num == 0:
            self.num_queue = []
        else:
            for i in range(len(self.num_queue)):
                self.num_queue[i] *= num
            self.num_queue.append(num)
        

    def getProduct(self, k: int) -> int:
        if k > len(self.num_queue):
            return 0

        return self.num_queue[len(self.num_queue) - k]
        


# Your ProductOfNumbers object will be instantiated and called as such:
# obj = ProductOfNumbers()
# obj.add(num)
# param_2 = obj.getProduct(k)
# @leet end
