class Node:
    """
    Represents a node in a Huffman tree.

    Attributes:
    - char: The character associated with the node.
    - freq: The frequency of the character.
    - left: The left child node.
    - right: The right child node.
    """

    def __init__(self, char: str, freq: int):
        """
        Initializes a new instance of the Node class.

        Parameters:
        - char: The character associated with the node.
        - freq: The frequency of the character.
        """
        self.char = char
        self.freq = freq
        self.left = None
        self.right = None

    def __lt__(self, other: 'Node') -> bool:
        """
        Compares two nodes based on their frequencies.

        Parameters:
        - other: The other node to compare.

        Returns:
        - True if the frequency of this node is less than the frequency of the other node, False otherwise.
        """
        return self.freq < other.freq
    
    def nextNode(self, bit: str) -> 'Node':
        """
        Returns the next node based on the given bit.

        Parameters:
        - bit: The bit value ('0' or '1').

        Returns:
        - The next node in the Huffman tree based on the given bit.
        - None if the current node is a leaf node.
        """
        if self.isLeaf():
            return None
        elif bit == "0":
            return self.left
        else:   
            return self.right
    
    def isLeaf(self) -> bool:
        """
        Checks if the current node is a leaf node.

        Returns:
        - True if the current node is a leaf node, False otherwise.
        """
        return self.left is None and self.right is None