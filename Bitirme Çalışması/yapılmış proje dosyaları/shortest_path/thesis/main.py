from collections import namedtuple

inf = float('inf')
Edge = namedtuple('Edge', 'start, end, cost')


def make_edge(start, end, cost=1):
    return Edge(start, end, cost)


class Graph:
    def __init__(self, edges):
        self.edges = [make_edge(*edge) for edge in edges]
        self.total_cost = 0

    @property
    def vertices(self):
        return set(
            sum(
                ([edge.start, edge.end] for edge in self.edges), []
            )
        )

    @property
    def neighbours(self):
        neighbours = {vertex: set() for vertex in self.vertices}
        for edge in self.edges:
            neighbours[edge.start].add((edge.end, edge.cost))

        return neighbours

    @staticmethod
    def floyd_warshall(weights, start, end):

        path = [start + 1]
        w = len(weights)
        distance_matrix = weights
        for k in range(w):
            old_distance_matrix = [list(row) for row in distance_matrix]
            for i in range(w):
                for j in range(w):
                    old_distance_matrix[i][j] = min(distance_matrix[i][j],
                                                    distance_matrix[i][k] + distance_matrix[k][j])
            distance_matrix = old_distance_matrix
            path.append(min(distance_matrix[k]))
        # print(distance_matrix)
        return distance_matrix[start][end], path

    def dijkstra(self, source, dest):
        assert source in self.vertices, 'Such source node doesn\'t exist'
        distances = {vertex: inf for vertex in self.vertices}
        previous_vertices = {
            vertex: None for vertex in self.vertices
        }
        distances[source] = 0
        vertices = self.vertices.copy()
        while vertices:
            current_vertex = min(
                vertices, key=lambda vertex: distances[vertex])
            vertices.remove(current_vertex)
            if distances[current_vertex] == inf:
                break
            for neighbour, cost in self.neighbours[current_vertex]:
                alternative_route = distances[current_vertex] + cost
                if alternative_route < distances[neighbour]:
                    distances[neighbour] = alternative_route
                    previous_vertices[neighbour] = current_vertex
        path, current_vertex = list(), dest
        while previous_vertices[current_vertex] is not None:
            path.append(current_vertex)
            current_vertex = previous_vertices[current_vertex]
        if path:
            path.append(current_vertex)

        distance_between_nodes = 0
        path = path[::-1]
        for index in range(1, len(path)):
            for thing in self.edges:
                if thing.start == path[index - 1] and thing.end == path[index]:
                    distance_between_nodes += thing.cost
        return path, distance_between_nodes



