#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

typedef struct node {
  char queryName[SIZE]; // query name
  int queryNumber;      // query count
  struct node *next;    // next node
} NODE;

typedef struct graph {
  int nodeNumber;            // number of nodes
  int nodeBonds[SIZE][SIZE]; // connection relation
  struct node *head;         // starting node
} GRAPH;

// Operation Functions
void merge_graphs(GRAPH *, GRAPH *, GRAPH *);
void list_neighbours(char[SIZE], GRAPH *);
void search_query(char[SIZE], GRAPH *);

// Test Functions
void print_list(GRAPH *);
void print_graph(GRAPH *);

// Helper Functions
int find_bond(char[SIZE], char[SIZE], GRAPH *);
void set_nodes(GRAPH *);
void set_bonds(GRAPH *);
GRAPH *create_graph();
NODE *create_node();

int main() {
  int i, cmd, goOn = 1, merged = 0;
  char query[SIZE];
  GRAPH *graph1 = create_graph();
  GRAPH *graph2 = create_graph();
  GRAPH *newGraph = create_graph();
  NODE *newNode = create_node();

  printf("\n - SEARCH GRAPHS -");
  printf("\n _________________________\n");
  // get the values of the first graph
  printf("\n --- 1st Search Graph ---\n");
  printf("\n --> Number of Query Terms: ");
  scanf("%d", &graph1->nodeNumber);
  set_nodes(graph1);
  set_bonds(graph1);
  printf(" _________________________\n");
  // get the values of the second graph
  printf("\n --- 2nd Search Graph ---\n");
  printf("\n --> Number of Query Terms: ");
  scanf("%d", &graph2->nodeNumber);
  set_nodes(graph2);
  set_bonds(graph2);
  printf(" _________________________\n");
  // choose whether to merge or search
  while (goOn) {
    printf("\n --- Operation Options ---\n");
    printf("\n >>> 1 >>> Search");
    printf("\n >>> 2 >>> Merge Searches");
    printf("\n >>> 0 >>> Exit\n");
    printf("\n --> ");
    scanf("%d", &cmd);
    if (cmd == 1) {
      printf(" _________________________\n");
      printf("\n --- Search Operation\n");
      // merge the graphs if they have not been merged yet
      if (!merged) {
        merge_graphs(graph1, graph2, newGraph);
        printf("\n (!) Queries were merged automatically.\n");
      }
      // search the query
      printf("\n --> Query Word: ");
      scanf(" %s", query);
      search_query(query, newGraph);
      printf(" _________________________\n");
    } else if (cmd == 2) {
      printf(" _________________________\n");
      printf("\n --- Merge Operation\n");
      // merge the graphs
      merge_graphs(graph1, graph2, newGraph);
      merged = 1;
      printf("\n (!) Merge operation completed.\n");
      newNode = newGraph->head;
      // list the neighbors of each node
      for (i = 0; i < (newGraph->nodeNumber); i++) {
        list_neighbours(newNode->queryName, newGraph);
        newNode = newNode->next;
      }
      printf(" _________________________\n");
    } else if (cmd == 0) {
      // exit
      printf("\n (!) Exited.");
      goOn = 0;
    } else {
      // warn on invalid command and return to the start
      printf("\n (!) Wrong command!");
    }
  }
  return 0;
}

// Operation Functions
void merge_graphs(GRAPH *g1, GRAPH *g2, GRAPH *new_g) {
  int i, j;
  int found, found2;
  char name1[SIZE], name2[SIZE];

  // Create the required nodes.
  NODE *tmp = create_node();
  NODE *tmp2 = create_node();
  NODE *tmp3 = create_node();

  // (1) Copy the starting values of the first graph to the new graph.
  new_g->head = g1->head;
  new_g->nodeNumber = g1->nodeNumber;

  // (2) Add the different nodes of the second graph to the list.
  tmp3 = new_g->head;
  // find the last node of the new graph
  while (tmp3->next != NULL) {
    tmp3 = tmp3->next;
  }
  // search for the node in the new graph
  tmp2 = g2->head;
  for (i = 0; i < (g2->nodeNumber); i++) {
    found = 0;
    tmp = new_g->head;
    while ((!found) && tmp != NULL) {
      if (strcmp(tmp->queryName, tmp2->queryName) == 0) {
        found = 1;
      } else {
        tmp = tmp->next;
      }
    }
    // if not found, add it to the end as a new node
    // increase the node count
    if (!found) {
      tmp3->next = create_node();
      strcpy(tmp3->next->queryName, tmp2->queryName);
      tmp3->next->queryNumber = tmp2->queryNumber;
      tmp3 = tmp3->next;
      tmp3->next = NULL;
      new_g->nodeNumber++;
    }
    tmp2 = tmp2->next;
  }

  // (3) Reset the connection values of the new graph.
  for (i = 0; i < (new_g->nodeNumber); i++) {
    for (j = 0; j < (new_g->nodeNumber); j++) {
      new_g->nodeBonds[i][j] = 0;
    }
  }

  // (4) Update the values of all nodes.
  tmp = new_g->head;
  tmp2 = new_g->head;
  for (i = 0; i < (new_g->nodeNumber); i++) {
    // The row starting point changes each time.
    // For this reason, I keep the tmp3 variable.
    tmp2 = tmp->next;
    for (j = i + 1; j < (new_g->nodeNumber); j++) {
      // create a connection if either of the other two lists has one
      found = find_bond(tmp->queryName, tmp2->queryName, g1);
      found2 = find_bond(tmp->queryName, tmp2->queryName, g2);
      if (found || found2) {
        new_g->nodeBonds[i][j] = 1;
        new_g->nodeBonds[j][i] = 1;
      }
      tmp2 = tmp2->next;
    }
    tmp = tmp->next;
  }
}
void list_neighbours(char name[SIZE], GRAPH *newGraph) {
  int i = 0, j = 0, k, found = 0;
  NODE *newNode = create_node();
  NODE *tmp = create_node();
  // check whether the name exists
  newNode = newGraph->head;
  while ((!found) && j < (newGraph->nodeNumber)) {
    // if the name exists, mark it as found
    if (strcmp(name, newNode->queryName) == 0) {
      found = 1;
    }
    // otherwise increase i by 1 and move to the next node
    if (!found) {
      i++;
      newNode = newNode->next;
    }
    j++;
    // (the i variable is the position of the searched name in the list)
  }
  // if found, print the connected ones
  printf("\n --- Query: '%s'", name);
  printf("\n --- Related Queries:");
  if (found) {
    printf("\n >>>");
    for (j = 0; j < (newGraph->nodeNumber); j++) {
      // check the connection of each query in the list with the searched query
      // if a connection exists (value is 1), print it
      if (newGraph->nodeBonds[i][j]) {
        tmp = newGraph->head;
        // find the connected query
        for (k = 0; k < j; k++) {
          tmp = tmp->next;
        }
        // print
        printf(" %s -", tmp->queryName);
      }
    }
    printf("\n");
  } else {
    // if the query does not exist, warn and do nothing
    printf("\n (!) Query not found.\n");
  }
}
void search_query(char query[SIZE], GRAPH *newGraph) {
  int i, j = 0, k, found = 0;
  NODE *newNode = create_node();
  NODE *tmp = create_node();
  NODE *mostSearched[3];
  for (i = 0; i < 3; i++) {
    mostSearched[i] = create_node();
    strcpy(mostSearched[i]->queryName, " ");
    mostSearched[i]->queryNumber = 0;
    mostSearched[i]->next = NULL;
  }
  // check whether the query exists
  i = 0;
  newNode = newGraph->head;
  while ((!found) && j < (newGraph->nodeNumber)) {
    // if the query exists, mark it as found and increase its count by 1
    if (strcmp(query, newNode->queryName) == 0) {
      found = 1;
      newNode->queryNumber++;
    }
    // otherwise increase i by 1 and move to the next node
    if (!found) {
      i++;
      newNode = newNode->next;
    }
    j++;
    // (the i variable is the position of the searched query in the list)
  }
  // if found, print the connected ones
  if (found) {
    printf("\n --- Query Count = %d\n", newNode->queryNumber);
    printf("\n (!) Top 3 Most Searched Related Queries:");
    for (j = 0; j < (newGraph->nodeNumber); j++) {
      // check the connection of each query in the list with the searched query
      // if a connection exists (value is 1), check its query count
      if (newGraph->nodeBonds[i][j]) {
        tmp = newGraph->head;
        // find the connected query
        for (k = 0; k < j; k++) {
          tmp = tmp->next;
        }
        // check the query count ////////////////
        if ((mostSearched[0]->queryNumber) <= (tmp->queryNumber)) {
          strcpy(mostSearched[2]->queryName, mostSearched[1]->queryName);
          mostSearched[2]->queryNumber = mostSearched[1]->queryNumber;

          strcpy(mostSearched[1]->queryName, mostSearched[0]->queryName);
          mostSearched[1]->queryNumber = mostSearched[0]->queryNumber;

          strcpy(mostSearched[0]->queryName, tmp->queryName);
          mostSearched[0]->queryNumber = tmp->queryNumber;
        } else if ((mostSearched[1]->queryNumber) <= (tmp->queryNumber)) {
          strcpy(mostSearched[2]->queryName, mostSearched[1]->queryName);
          mostSearched[2]->queryNumber = mostSearched[1]->queryNumber;

          strcpy(mostSearched[1]->queryName, tmp->queryName);
          mostSearched[1]->queryNumber = tmp->queryNumber;
        } else if ((mostSearched[2]->queryNumber) <= (tmp->queryNumber)) {
          strcpy(mostSearched[2]->queryName, tmp->queryName);
          mostSearched[2]->queryNumber = tmp->queryNumber;
        }
      }
    }
    for (j = 0; j < 3; j++) {
      printf("\n >>> %d - '%s' - Query Count: %d", j,
             mostSearched[j]->queryName, mostSearched[j]->queryNumber);
    }
    printf("\n");
  } else {
    // if the query does not exist, warn and do nothing
    printf("\n (!) No such query exists.\n");
  }
}

// Test Functions
void print_graph(GRAPH *newGraph) {
  int i, j;
  int limit = newGraph->nodeNumber;
  printf("\n");
  for (i = 0; i < limit; i++) {
    printf("\n");
    for (j = 0; j < limit; j++) {
      printf("\t%d", newGraph->nodeBonds[i][j]);
    }
  }
  printf("\n");
}
void print_list(GRAPH *graph) {
  NODE *tmp = graph->head;
  printf("\n\n");
  while (tmp != NULL) {
    printf("\t%s", tmp->queryName);
    tmp = tmp->next;
  }
  printf("\n");
}

// Helper Functions
int find_bond(char name1[SIZE], char name2[SIZE], GRAPH *newGraph) {
  int i = 0, j = 0, k = 0;
  int found1 = 0, found2 = 0;
  NODE *newNode = create_node();
  // check whether the names exist
  newNode = newGraph->head;
  while (((!found1) || (!found2)) && k < (newGraph->nodeNumber)) {
    // does the first name exist?
    if (strcmp(name1, newNode->queryName) == 0) {
      found1 = 1;
    }
    // does the second name exist?
    if (strcmp(name2, newNode->queryName) == 0) {
      found2 = 1;
    }
    // if not found, keep increasing their values
    if (!found1) {
      i++;
    }
    if (!found2) {
      j++;
    }
    k++;
    newNode = newNode->next;
  }
  // if both are found, return their connection status
  // if either is missing, return 0 because there is no connection
  if (found1 && found2) {
    return newGraph->nodeBonds[i][j];
  } else {
    return 0;
  }
}
void set_nodes(GRAPH *newGraph) {
  int i;
  NODE *tmp = create_node();
  NODE *tmp2;
  printf("\n --- Queries:");
  // create the first node
  newGraph->head = create_node();
  printf("\n --> Query No. 1: ");
  scanf(" %[^\n]s", newGraph->head->queryName);
  newGraph->head->queryNumber = 0;
  newGraph->head->next = NULL;
  // create the following nodes
  tmp = newGraph->head;
  for (i = 1; i < (newGraph->nodeNumber); i++) {
    tmp2 = create_node();
    printf(" --> Query No. %d: ", i + 1);
    scanf(" %[^\n]s", tmp2->queryName);
    tmp2->queryNumber = 0;
    tmp2->next = NULL;
    // move to the next node
    tmp->next = tmp2;
    tmp = tmp2;
  }
}
void set_bonds(GRAPH *newGraph) {
  int i, j;
  // reset the whole table
  for (i = 0; i < (newGraph->nodeNumber); i++) {
    for (j = 0; j < (newGraph->nodeNumber); j++) {
      newGraph->nodeBonds[i][j] = 0;
    }
  }
  // if the node count is greater than 1, ask for connections
  if ((newGraph->nodeNumber) > 1) {
    printf("\n --- Connections:");
    printf("\n (!) Enter 1 for connected queries,");
    printf("\n     and 0 for unconnected queries.\n\n");
    // read connection values into the upper-right triangle of the table
    for (i = 0; i < (newGraph->nodeNumber); i++) {
      for (j = i + 1; j < (newGraph->nodeNumber); j++) {
        printf(" ---> Connection of Query %d and Query %d = ", i + 1, j + 1);
        scanf("%d", &newGraph->nodeBonds[i][j]);
        // make the table symmetric
        newGraph->nodeBonds[j][i] = newGraph->nodeBonds[i][j];
      }
    }
  }
}
GRAPH *create_graph() { return (GRAPH *)malloc(sizeof(GRAPH)); }
NODE *create_node() { return (NODE *)malloc(sizeof(NODE)); }
