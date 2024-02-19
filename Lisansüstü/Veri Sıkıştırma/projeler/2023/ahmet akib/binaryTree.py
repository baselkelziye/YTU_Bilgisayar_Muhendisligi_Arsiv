import heapq
from graphviz import Digraph
from Node import Node

from typing import Dict, Optional

class BinaryTree:
    """
    Represents a binary tree used for data compression.

    Attributes:
        root: The root node of the binary tree.

    Methods:
        findNode(bits): Finds a node in the binary tree based on the given bits.
        assign_codes_to_pixels(node, prefix="", codes={}): Assigns codes to pixels in the binary tree.
    """

    def __init__(self, freq: Dict[str, int]):
        """
        Initializes a new instance of the BinaryTree class.

        Parameters:
        freq (Dict[str, int]): A dictionary containing the frequencies of characters.

        Returns:
        None
        """
        self.root = self.__build_huffman_tree(freq)
        self.huffmanCodes = self.__assign_nodes(self.root)
        self.visualize_tree()


    def __build_huffman_tree(self, freq: Dict[str, int]) -> Node:
        """
        Builds a Huffman tree based on the given frequency dictionary.

        Args:
            freq (dict): A dictionary containing characters as keys and their frequencies as values.

        Returns:
            Node: The root node of the Huffman tree.
        """
        heap = [Node(char, freq[char]) for char in freq]
        heapq.heapify(heap)
        while len(heap) > 1:
            node1 = heapq.heappop(heap)
            node2 = heapq.heappop(heap)
            merged = Node(None, node1.freq + node2.freq)
            merged.left = node1
            merged.right = node2
            heapq.heappush(heap, merged)
        return heap[0]

    def findNode(self, bits: str) -> Optional[str]:
        """
        Finds a node in the binary tree based on the given bits.

        Args:
            bits (str): A string representing the bits to search for.

        Returns:
            Optional[str]: The found node if it exists, None otherwise.
        """
        node = self.root
        for index in range(len(bits)):
            bit = bits[index]
            next_node = node.nextNode(bit)
            if node is None:
                if bits[index:] == "0" * (len(bits) - index):
                    print("Warning: Found Padding...")
                    return node
                print("Error: Node not found")
                return None
            node = next_node
        return node.char

    def __assign_nodes(self, node: Optional[Node], prefix: str = "", codes: Dict[str, str] = {}) -> Dict[str, str]:
        """
        Assigns codes to pixels in the binary tree.

        Args:
            node (Optional[Node]): The current node being processed.
            prefix (str): The prefix code for the current node.
            codes (Dict[str, str]): A dictionary to store the assigned codes.

        Returns:
            Dict[str, str]: The dictionary containing the assigned codes.
        """
        if node is not None:
            if node.char is not None:
                codes[node.char] = prefix
            self.__assign_nodes(node.left, prefix + "0", codes)
            self.__assign_nodes(node.right, prefix + "1", codes)
        return codes
    
    def visualize_tree(self, filename='tree.gv'):
        """
        Visualizes the binary tree using Graphviz.

        Args:
            filename (str): The name of the file to save the visualization.

        Returns:
            None
        """
        def add_nodes_edges(node, graph, node_id):
            if node is None:
                return

            left_id = f"{node_id}L"
            right_id = f"{node_id}R"

            if node.char is not None:
                label = f"val:{node.char}, freq{node.freq}\ncode:{self.huffmanCodes[node.char]}"
            else:
                label = f"{node.freq}"

            graph.node(node_id, label)

            if node.left is not None:
                graph.edge(node_id, left_id)
                add_nodes_edges(node.left, graph, left_id)

            if node.right is not None:
                graph.edge(node_id, right_id)
                add_nodes_edges(node.right, graph, right_id)

        graph = Digraph()
        add_nodes_edges(self.root, graph, 'root')
        graph.render(filename, view=True)
        

