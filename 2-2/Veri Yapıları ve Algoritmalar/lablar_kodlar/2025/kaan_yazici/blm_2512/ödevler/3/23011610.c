#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_PATH "employee.txt"

typedef struct Employee {
  char name[21];
  size_t age;
  size_t salary;
} Employee;

typedef struct Node {
  Employee *employee;
  struct Node *child;
  struct Node *sibling;
} Node;

typedef struct QueueNode {
  Node *data;
  struct QueueNode *next;
} QueueNode;

typedef struct {
  QueueNode *front;
  QueueNode *back;
} Queue;

typedef struct {
  char name[21];
  Node *node;
} NodeInput;

typedef struct {
  size_t totalAge;
  size_t count;
} AgeContext;

typedef struct {
  size_t total;
} PaymentContext;

/**
 * @brief Context function that updates `totalAge` and `count` values with given Node `Employee` data.
 * 
 * @param node: Tree node to get `Employee` data. 
 * @param context: Pointer to contextual struct that holds values to be updated.
 */
void ageAction(Node *node, void *context) {
  AgeContext *ctx = context;
  ctx->totalAge += node->employee->age;
  ++(ctx->count);
}

/**
 * @brief Context function that updates a `total` value with given Node `Employee` data.
 * 
 * @param node: Tree node to get `Employee` data.
 * @param context: Pointer to contextual struct that holds `total` value to be updated.
 */
void paymentAction(Node *node, void *context) {
  PaymentContext *ctx = context;
  ctx->total += node->employee->salary;
}

/* Function pointer declaration */
typedef void (*NodeAction)(Node *node, void *context);

Employee *createEmployee(const char *, const size_t, const size_t);
Node *createNode(Employee *);
void addChild(Node *, Node *);
void countLevelSize(Node *);
void levelorderTraversal(Node *, NodeAction, void *);
size_t getHeight(Node *);
Queue *createQueue();
void enqueue(Queue *, Node *);
Node *dequeue(Queue *);
void countLevels(Node *, size_t);
const double computeAgeAvg(Node *);
const size_t computeTotalPayment(Node *);
void findGreatestNode(Node *);
Node *readData(char[]);
void addNode(NodeInput *, char *, Node *, size_t);
Node *findNode(NodeInput *, char *, size_t);
void freeTree(Node *);

int main() {
  Node *root = readData(FILE_PATH);
  
  fprintf(stdout, "This corp. has a %llu level employee tree.\n", getHeight(root));
  countLevels(root, getHeight(root));
  findGreatestNode(root);
  fprintf(stdout, "Employees have an age average of %.2lf\n", computeAgeAvg(root));
  fprintf(stdout, "Total payment to employees are %llu\n", computeTotalPayment(root));

  freeTree(root);
  return 0;
}

/**
 * @brief Instantiates a dynamic queue with a linked list container.
 * 
 * @return Pointer to created empty queue.
 */
Queue *createQueue() {
  Queue *q = malloc(sizeof(*q));
  q->front = NULL;
  q->back = NULL;

  return q;
}

/**
 * @brief Pushes an element of type `Node` to given Queue.
 * 
 * @param q: Given Queue pointer to be pushed into.
 * @param n: Given Node object pointer to be pushed.
 */
void enqueue(Queue *q, Node *n) {
  QueueNode *newNode = malloc(sizeof(*newNode));
  newNode->data = n;
  newNode->next = NULL;

  if (!q->front) {
    q->front = newNode;
    q->back = newNode;
  } else {
    q->back->next = newNode;
    q->back = newNode;
  }
}

/**
 * @brief Pops the rear element from the Queue.
 * 
 * @param q: Given Queue pointer to be popped from.
 * 
 * @return Pointer to popped `Node` object.
 */
Node *dequeue(Queue *q) {
  if (!q->front) {
    return NULL;
  }
  QueueNode *node = q->front;
  Node *retval = node->data;
  q->front = node->next;

  if (!q->front) {
    q->back = NULL;
  }
  free(node);

  return retval;
}

/**
 * @brief Instantiates an `Employee` object with given arguments.
 * 
 * @param name: Name of the employee.
 * @param age: Age of the employee.
 * @param salary: Salary of the employee.
 * 
 * @return Pointer to instantiated `Employee` object.
 */
Employee *createEmployee(const char *name, const size_t age, const size_t salary) {
  Employee *newEmployee = malloc(sizeof(*newEmployee));
  strncpy(newEmployee->name, name, sizeof(newEmployee->name) - 1);
  newEmployee->name[sizeof(newEmployee->name) - 1] = '\0';
  newEmployee->age = age;
  newEmployee->salary = salary;
  
  return newEmployee;
}

/**
 * @brief Instantiates a linked list node with given `Employee` data.
 * 
 * @param employee: Pointer to given employee object.
 * 
 * @return Pointer to populated linked list node.
 */
Node *createNode(Employee *employee) {
  Node *newNode = malloc(sizeof(*newNode));
  newNode->employee = employee;
  newNode->child = NULL;
  newNode->sibling = NULL;

  return newNode;
}

/** 
 * @brief Creates a new child for given `parent` tree node.
 * 
 * @param parent: Tree node that represents a parent.
 * @param child: Tree node that is to be inserted below given `parent`.
 */
void addChild(Node *parent, Node *child) {
  if (!parent->child) {
    parent->child = child;
  } else {
    Node *temp = parent->child;
    while (temp->sibling) {
      temp = temp->sibling;
    }
    temp->sibling = child;
  }
}

/**
 * @brief For a given n-ary tree, computes the height 
 * recursively by traversing every child.
 * 
 * @param root: Root node for the tree.
 * 
 * @return Computed height value.
 */
size_t getHeight(Node *root) {
  if (!root) {
    return 0;
  }
  size_t maxChildHeight = 0;
  Node *child = root->child;

  while (child) {
    size_t childHeight = getHeight(child);
    maxChildHeight = (childHeight > maxChildHeight) ? childHeight : maxChildHeight;
    child = child->sibling;
  }

  return maxChildHeight + 1;
}

/**
 * @brief Traverses the tree level by level, and for each node,
 * executes given action.
 * 
 * @param root: Root node of given tree.
 * @param action: Pointer to function to be executed while traversing the tree.
 * @param context: Pointer that points to structs that hold different contextual data.
 */
void levelorderTraversal(Node *root, NodeAction action, void *context) {
  if (!root) {
    return;
  }
  Queue *q = createQueue();
  enqueue(q, root);

  while (q->front) {
    Node *curr = dequeue(q);
    action(curr, context);

    Node *child = curr->child;
    while (child) {
      enqueue(q, child);
      child = child->sibling;
    }
  }

  free(q);
}

/**
 * @brief Computes and prints how many tree nodes are in each level.
 * 
 * @param root: Root node of tree to be traversed.
 * @param height: Height of given tree.
 */
void countLevels(Node *root, size_t height) {
  if (!root) {
    return;
  }
  size_t *levelCounts = calloc(height, sizeof(*levelCounts));

  Queue *q = createQueue();
  enqueue(q, root);

  size_t currLevel = 0;
  size_t nodesInCurrLevel = 1;

  while (nodesInCurrLevel > 0) {
    size_t nodesInNextLevel = 0;

    size_t i;
    for (i = 0; i < nodesInCurrLevel; ++i) {
      Node *curr = dequeue(q);
      ++levelCounts[currLevel];

      Node *child = curr->child;
      while (child) {
        enqueue(q, child);
        ++nodesInNextLevel;
        child = child->sibling;
      }
    }
    nodesInCurrLevel = nodesInNextLevel;
    ++currLevel;
  }

  for (currLevel = 0; currLevel < height; ++currLevel) {
    fprintf(stdout, "Level %llu: %llu ", currLevel+1, levelCounts[currLevel]);
  }
  free(levelCounts);
  free(q);

  fputc('\n', stdout);
}

/**
 * @brief Traversing level by level, computes age average of employees. 
 * Uses `levelorderTraversal` function with a function pointer passed into it.
 * 
 * @param root: Root node of given tree to be traversed.
 * 
 * @return Computed age average value.
 */
const double computeAgeAvg(Node *root) {
  /* Instantiating struct that holds total age and count values. */
  AgeContext context = {0, 0};
  /* Passing `ageAction` function pointer into traversal function. */
  levelorderTraversal(root, ageAction, &context);

  return context.count ? (double)context.totalAge / context.count : 0.0;
}

/**
 * @brief Traversing level by level, computes total salaries of employees.
 * Uses `levelorderTraversal` function with a function pointer passed into it.
 * 
 * @param root: Root node of a given tree to be traversed.
 * 
 * @return Computed total salary value.
 */
const size_t computeTotalPayment(Node *root) {
  /* Instantiating struct that holds total salary value. */
  PaymentContext context = {0};
  /* Passing `paymentAction` function pointer into traversal function. */
  levelorderTraversal(root, paymentAction, &context);

  return context.total;
}

/**
 * @brief Finds which node has the most children in a given level and prints its info.
 * 
 * @param root: Root node of a given tree to be traversed.
 */
void findGreatestNode(Node *root) {
  if (!root) {
    return;
  }

  /* User input of which level to be searched. */
  size_t level;
  printf("Enter level to search (1-based): ");
  fscanf(stdin, "%llu", &level);

  if (level < 1) {
    fprintf(stderr, "Level must be greater than 0.\n");
    exit(EXIT_FAILURE);
  }

  size_t height = getHeight(root);
  if (level > height) {
    fprintf(stderr, "Level exceeds tree height (%llu).\n", height);
    exit(EXIT_FAILURE);
  }

  Queue *q = createQueue();
  enqueue(q, root);

  size_t currLevel = 1;
  size_t nodesInCurrLevel = 1;

  /* Level order traversal to desired level. */
  while (currLevel < level && nodesInCurrLevel > 0) {
    size_t nodesInNextLevel = 0;
    size_t i;
    for (i = 0; i < nodesInCurrLevel; ++i) {
      Node *curr = dequeue(q);
      Node *child = curr->child;
      while (child) {
        enqueue(q, child);
        ++nodesInNextLevel;
        child = child->sibling;
      }
    }
    nodesInCurrLevel = nodesInNextLevel;
    ++currLevel;
  }

  Node *greatestNode = NULL;
  size_t maxChildren = 0;

  /* Computing the node with most children in desired level. */
  size_t i = 0;
  for (; i < nodesInCurrLevel; ++i) {
    Node *curr = dequeue(q);
    size_t childCount = 0;

    Node *child = curr->child;
    while (child) {
      ++childCount;
      child = child->sibling;
    }

    if (childCount > maxChildren) {
      maxChildren = childCount;
      greatestNode = curr;
    }
  }

  if (greatestNode) {
    fprintf(stdout, "Node with greatest children at level %llu is %s with %llu children.\n", level, greatestNode->employee->name, maxChildren);
  } else {
    fprintf(stdout, "No children found at level %llu.\n", level);
  }

  free(q);
}

/**
 * @brief Creates a n-ary tree that holds `Employee` objects as data from an input file.
 * 
 * @param filePath: Path to input file to be read.
 * 
 * @return Pointer to root node of created n-ary tree.
 */
Node *readData(char filePath[]) {
  FILE *fp = fopen(filePath, "r");

  size_t count;
  fscanf(fp, "%llu", &count);

  NodeInput *nodeInput = malloc(count * sizeof(*nodeInput));
  Node *root = NULL;

  size_t i = 0;
  for (; i < count; ++i) {
    char nameBuf[21], parentBuf[21];
    size_t age, salary;

    fscanf(fp, "%20s %llu %llu %20s", nameBuf, &age, &salary, parentBuf);
    Node *node = createNode(createEmployee(nameBuf, age, salary));

    strcpy(nodeInput[i].name, nameBuf);
    nodeInput[i].node = node;

    if (strcmp(parentBuf, "NULL") == 0) {
      root = node;
    } else {
      Node *parent = findNode(nodeInput, parentBuf, i);
      if (parent) {
        addChild(parent, node);
      } else {
        fputs("Parent not found.", stdout);
      }
    }
  }
  free(nodeInput);

  return root;
}

/**
 * @brief Linearly finds the location of a node with given name.
 * 
 * @param nodeInput: An array of Nodes to be searched from.
 * @param name: Name of the node to be compared.
 * @param count: Number of nodes in given `nodeInput` array.
 * 
 * @return Pointer that points to either found Node or NULL.
 */
Node *findNode(NodeInput *nodeInput, char *name, size_t count) {
  size_t i = 0;
  for (; i < count; ++i) {
    if (strcmp(nodeInput[i].name, name) == 0) {
      return nodeInput[i].node;
    }
  }
  return NULL;
}

/**
 * @brief Frees memory of given tree and its nodes.
 * 
 * @param root: Root node of the given tree to be cleaned.
 */
void freeTree(Node *root) {
  if (!root) {
    return;
  }

  freeTree(root->child);
  freeTree(root->sibling);

  free(root->employee);
  free(root);
}
