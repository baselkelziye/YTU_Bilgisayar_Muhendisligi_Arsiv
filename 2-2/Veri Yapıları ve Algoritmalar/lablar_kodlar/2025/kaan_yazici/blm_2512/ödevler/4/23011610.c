#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_PATH "input.txt"

typedef struct GraphNode {
  int name;
  struct GraphNode *next;
} GraphNode;

typedef struct {
  size_t vertices;
  GraphNode **nodes;
} Graph;

Graph *readInput(char *);
GraphNode *createGraphNode(int);
Graph *createGraph(size_t);
void addEdge(Graph *, int, int);
void printGraph(Graph *);
void printNodes(Graph *, int *);
void printMostFeasible(Graph *, int *);
void searchGraph(Graph *, int);
void checkAdjacency(GraphNode *, int *, int);
int allNeighborsChecked(GraphNode *, int *);
void freeGraph(Graph *);

int main() {
  Graph *graph = readInput(FILE_PATH);
  
  int prize;
  fputs("Enter prize node: ", stdout);
  fscanf(stdin, "%d", &prize);
  fputc('\n', stdout);

  searchGraph(graph, prize);

  freeGraph(graph);
  return 0;
}

/**
 * Creates a Graph Node with given name.
 *
 * @param name Name of the node.
 *
 * @return Newly created node.
 */
GraphNode *createGraphNode(int name) {
  GraphNode *node = malloc(sizeof(*node));
  node->name = name;
  node->next = NULL;

  return node;
}

/**
 * Creates a graph with given vertex count.
 *
 * @param vertices Vertex count of the graph.
 *
 * @return Pointer to newly created Graph object.
 */
Graph *createGraph(size_t vertices) {
  Graph *graph = malloc(sizeof(*graph));
  graph->vertices = vertices;
  graph->nodes = malloc(vertices * sizeof(*graph->nodes));

  size_t i = 0;
  for (; i < vertices; ++i) {
    graph->nodes[i] = NULL;
  }

  return graph;
}

/**
 * Creates an edge between two node pairs.
 *
 * @param u, v Name of the nodes around the edge.
 */
void addEdge(Graph *g, int u, int v) {
  if (u == v) {
    return;
  }

  GraphNode *node = createGraphNode(v);
  node->next = g->nodes[u];
  g->nodes[u] = node;
}

/**
 * Prints the graph with all its vertices and adjacent vertices to it. 
 * 
 * @param g Pointer to the graph object to be printed.
 */
void printGraph(Graph *g) {
  size_t i = 0;
  for (; i < g->vertices; ++i) {
    GraphNode *temp = g->nodes[i];
    fprintf(stdout, "%llu: ", i);
    while (temp) {
      fprintf(stdout, "%d -> ", temp->name);
      temp = temp->next;
    }
    fputs("NULL\n", stdout);
  }
}

/**
 * Prints vertices of a graph that are possible `prize` vertices.
 * 
 * @param g Pointer to the graph object to be printed.
 * @param feasible Array that lists all vertices' being `prize` vertex probability.
 */
void printNodes(Graph *g, int *feasible) {
  size_t i = 0;
  for (; i < g->vertices; ++i) {
    if (feasible[i] != -1) {
      fprintf(stdout, "%llu ", i);
    }
  }
}

/**
 * Out of feasible list, prints the vertices with the most probability. It may be more than one vertex.
 * 
 * @param g Pointer to the graph object to be printed.
 * @param feasible Array that lists all vertices' being `prize` vertex probability.
 */
void printMostFeasible(Graph *g, int *feasible) {
  int mostFeasible = feasible[0];

  size_t i = 0;
  for (; i < g->vertices; ++i) {
    mostFeasible = (feasible[i] > mostFeasible) ? feasible[i] : mostFeasible;
  }
  for (i = 0; i < g->vertices; ++i) {
    if (feasible[i] == mostFeasible) {
      fprintf(stdout, "%llu ", i);
    }
  }
}

/**
 * Checks and returns true if a vertex's adjacent vertices' are all non-feasible for being the `prize` vertex.
 * 
 * @param node Pointer to graph node object to be checked.
 * @param feasible Array that lists all vertices' being `prize` vertex probability.
 * 
 * @return True if all non-feasible, false if not.
 */
int allNeighborsChecked(GraphNode *node, int *feasible) {
  GraphNode *temp = node;
  while (temp) {
    if (feasible[temp->name] != -1) {
      return 0;
    }
    temp = temp->next;
  }
  return 1;
}

/**
 * Checks all adjacent vertices of a graph node and updates their feasibleness by asking if the node is a neighbor to `prize` node.
 * 
 * @param[in] node Pointer to graph node object to be checked.
 * @param[out] feasible Array that lists all vertices' being `prize` vertex probability.
 * @param[in] prize Name of the `prize` node.
 */
void checkAdjacency(GraphNode *node, int *feasible, int prize) {
  GraphNode *temp = node;

  /* If an adjacent vertex is the `prize` node, mark node adjacent to prize. */
  int prizeAdjacent = 0;
  while (temp) {
    if (temp->name == prize) {
      prizeAdjacent = 1;
    }
    temp = temp->next;
  }
  
  /* 
   * If the node is adjacent to prize, update it's neighbors' feasibleness; if not, mark them all -1
   * since they cannot be the `prize` node.
   */
  temp = node;
  if (!prizeAdjacent) {
    while (temp) {
      feasible[temp->name] = -1;
      temp = temp->next;
    }
  } else {
    while (temp) {
      (feasible[temp->name] != -1) ? ++feasible[temp->name] : feasible[temp->name];
      temp = temp->next;
    }
  }
  prizeAdjacent ? fputs("Adjacent", stdout) : fputs("Not adjacent", stdout);
  free(temp);
}

/**
 * Searches the graph vertices and prints possible `prize` candidates in each loop. 
 * Prechecks if a vertex's neighbors are all handled and known to be not `prize`, then skips that node.
 * 
 * @param g Pointer to graph object to be searched.
 * @param feasible Array that lists all vertices' being `prize` vertex probability.
 */
void searchGraph(Graph *g, int prize) {
  int *feasible = calloc(g->vertices, sizeof(*feasible));

  fputs("Graph:\n", stdout);
  printGraph(g);

  size_t i = 0;
  for (; i < g->vertices; ++i) {  
   if (!allNeighborsChecked(g->nodes[i], feasible)) {
     fputs("\nProbable nodes: ", stdout);
     printNodes(g, feasible);
     fputc('\n', stdout);
     fprintf(stdout, "Checking adj for node %llu: ", i);
     checkAdjacency(g->nodes[i], feasible, prize);
     fputc('\n', stdout);
   }
  }

  fputs("\nChosen node is in: ", stdout);
  printMostFeasible(g, feasible);
}

/**
 * Frees the graph and all the pointers to vertices inside.
 * 
 * @param g Pointer to graph object to be freed.
 */
void freeGraph(Graph *g) {
  if (!g) {
    return;
  }

  size_t i = 0;
  for (; i < g->vertices; ++i) {
    GraphNode *node = g->nodes[i];
    while (node) {
      GraphNode *temp = node;
      node = node->next;
      free(temp);
    }
  }

  free(g->nodes);
  free(g);
}

/**
 * Creates a graph structure with edge relations read from a file input.
 * 
 * @param file_name Name of the file to be read.
 * 
 * @return Pointer to newly created Graph object.
 */
Graph *readInput(char *file_name) {
  FILE *fp = fopen(file_name, "r");

  size_t vertices;
  fscanf(fp, "%llu", &vertices);
  fgetc(fp);

  Graph *graph = createGraph(vertices);

  size_t i = 0;
  for (; i < vertices; ++i) {
    char *line = calloc(5 * vertices, sizeof(*line));
    int *numbers = calloc(vertices, sizeof(*numbers));
    size_t count = 0;

    fgets(line, 5 * vertices, fp);
    char *token = strtok(line, " \n\t");
    while (token) {
      numbers[count++] = atoi(token);
      token = strtok(NULL, " \n\t");
    }

    size_t j;
    for (j = 0; j < count; ++j) {
      addEdge(graph, numbers[0], numbers[j]);
    }

    free(line);
    free(numbers);
  }

  fclose(fp);
  return graph;
}
