from collections import deque
class Queue:
    def __init__(self):
        self.data=deque()
    def enqueue(self,node):
        self.data.append(node)
    def dequeue(self):
        self.data.popleft()