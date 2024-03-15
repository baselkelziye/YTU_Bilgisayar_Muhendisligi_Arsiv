class BFSIterator:
    def __init__(self, root):
        self.queue = [root] if root is not None else []

    def __iter__(self):
        return self

    def __next__(self):
        if not self.queue:
            raise StopIteration

        node = self.queue.pop(0)

        if node.left:
            self.queue.append(node.left)
        if node.right:
            self.queue.append(node.right)

        return node