#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
  int vertex;
  char name[16];
  char surname[16];
  struct node* next;
}; typedef struct node node;


struct Graph {
  int numVertices;
  struct node** adjLists;
  int* visited;
}; typedef struct Graph Graph;


int count_node(char* filename);
size_t tokenize(char *inputString, const char *delim, char **argv, size_t maxtokens);
node* createNode(int, char*, char*);
Graph* createGraph(int vertices);
void printGraph(Graph* graph);
void add_edge(Graph* graph, char* src, char* dest);
void insert_node(Graph* graph, char* vertices);
void delete_node(Graph *graph, int target);
void dfs(Graph* graph, int vertex, int* count);
int find_in_degree(Graph *g, int vertex);
void elimination(Graph *graph, int threshold);
Graph* reverse_graph(Graph* graph);
void get_information(Graph* graph, int src, int, int, int);
node* create_reversed_node(int v);
void add_reversed_edge(Graph* graph, int d, int s);


int main() {
    char filename[16];
    // Get file name from user. The file should be
    // either in current folder or complete path should be provided
    printf("Enter file name: ");
    scanf("%s", filename);
    int input_count = count_node(filename)/2;
    Graph* graph = createGraph(input_count+1);
    int M, X, Y;
    printf("\nEnter M, X and Y thresholds: ");
    scanf("%d %d %d", &M, &X, &Y);
  
    int i=0, j=0, mode;
    char buffer[64], vertices[64][64], destinations[64][64]; 

    /*************** READ FROM FILE ***************/
    int binary_line = 0;
    FILE *fp = fopen(filename, "r");
    size_t ntokens;
    while (fgets(buffer, 64, fp)){
        if(binary_line % 2 == 0){
            strcpy(vertices[i], buffer);
            i++;
        }        
        else if (j<input_count){
            strcpy(destinations[j], buffer);  
            j++;
        }
    binary_line++;
    }
    fclose(fp);
    /*************** READ FROM FILE ***************/


    /*   BEGIN - INITIALIZE GRAPH   */
    for(i=0; i<input_count; i++)
        insert_node(graph, vertices[i]);

    for(i=0; i<input_count; i++)
        add_edge(graph, vertices[i], destinations[i]);
    /*   END - INITIALIZE GRAPH   */


    int indegree[graph->numVertices], post_indegree[graph->numVertices]; 
    int successors[graph->numVertices], count = 0;
    Graph* r_graph; // my trick to calc successors
    char tmp;
    printf("\n  Choose mode:  \n1) Normal Mode\n2) Detailed Mode\nChoice: ");
    scanf("%d", &mode);
    scanf("%c", &tmp); //escape for enter char
    switch (mode){
        
    case 1:
        /* BEGIN - Calculate In-Degree Values*/
        for(i=1; i<graph->numVertices; i++)
            indegree[i] = find_in_degree(graph, i); 

        elimination(graph, M); 
        r_graph = reverse_graph(graph); // my trick to calc successors

        for(i=1; i<graph->numVertices; i++)
            post_indegree[i] = find_in_degree(graph, i);
        /* END - Calculate In-Degree Values*/


        /* BEGIN - USE DFS TO OBTAIN ALL SUCCESSORS */
        for (i = 1; i < graph->numVertices; i++)
            successors[i] = 0;

        for (i = 1; i < graph->numVertices; i++) 
            if(r_graph->adjLists[i] != NULL){
                dfs(r_graph, i, &count);
                successors[i] = count;
                count = 0;
                for (j = 1; j < graph->numVertices; j++) 
                    r_graph->visited[j] = 0;
            }
        /* END - USE DFS TO OBTAIN ALL SUCCESSORS */

        printf("\n\n----------------         INFLUENCERS        ----------------\n");
        for(i=1; i<graph->numVertices; i++)
            if(graph->adjLists[i] != NULL && post_indegree[i] >= X && successors[i] >= Y)
                get_information(graph, i, post_indegree[i], successors[i], mode=0);
        printf("\n-------------------------------------------------------------\n\n");
        
        break;

    case 2:
        /* BEGIN - Calculate In-Degree Values */
        for(i=1; i<graph->numVertices; i++)
            indegree[i] = find_in_degree(graph, i); 
        /* END - Calculate Pre In-Degree Values */


        printf("\n\n\n     ---------     DETAILED INFORMATION      ---------\n");
        
        printf("\n\n------- FIRST STATE OF THE FOLLOWER (In-Degree) COUNTs -------\n");
        for(i=1; i<graph->numVertices; i++)
            if(graph->adjLists[i] != NULL)
                get_information(graph, i, indegree[i], successors[i], mode=1);
        printf("\n--------------------------------------------------------------\n");

        elimination(graph, M); 
        r_graph = reverse_graph(graph); // my trick to calc successors

        for(i=1; i<graph->numVertices; i++)
            post_indegree[i] = find_in_degree(graph, i);
        /* END - Calculate In-Degree Values*/

        /* BEGIN - USE DFS TO OBTAIN ALL SUCCESSORS */
        for (i = 1; i < graph->numVertices; i++)
            successors[i] = 0;

        for (i = 1; i < graph->numVertices; i++) 
            if(r_graph->adjLists[i] != NULL){
                dfs(r_graph, i, &count);
                successors[i] = count;
                count = 0;
                for (j = 1; j < graph->numVertices; j++) 
                    r_graph->visited[j] = 0;
            }
        /* END - USE DFS TO OBTAIN ALL SUCCESSORS */


        printf("\n-------------   REMOVED < M VALUES - NEW STATE   --------------\n");
        for(i=1; i<graph->numVertices; i++)
            if(graph->adjLists[i] != NULL)
                get_information(graph, i, post_indegree[i], successors[i], mode=0);
            
        printf("\n--------------------------------------------------------------\n");
      

        printf("\n\n----------------        INFLUENCERS        ----------------\n");
        for(i=1; i<graph->numVertices; i++)
            if(graph->adjLists[i] != NULL && post_indegree[i] >= X && successors[i] >= Y)
                get_information(graph, i, post_indegree[i], successors[i], mode=0);
        printf("\n--------------------------------------------------------------\n");
        
       
        break;
    
    default:
        printf("Not an available choice.");
        break;
    }
    return 0;
}






/**
 * @brief This function eliminate the users who below the M (threshold) value, recursively.
 * 
 * @param graph 
 * @param threshold 
 */
void elimination(Graph *graph, int threshold){
    int i=1, stop_condition = 0;

    while(i != graph->numVertices){
        if(graph->adjLists[i] != NULL && find_in_degree(graph, i) < threshold){
            //printf("\nFollower count (in-degree) found as %d for user %d", find_in_degree(graph, i), i);
            delete_node(graph, i);
            stop_condition = 1;
        }
        i++;
    }
    if (stop_condition){
        elimination(graph, threshold);
    }
}


/**
 * @brief Function for finding number of followers of a user
 * 
 * @param g 
 * @param vertex 
 * @return int 
 */
int find_in_degree(Graph *g, int vertex){
    int i, degree = 0;

    for(i=1; i<g->numVertices; i++){
        //printf("\ncurrent vertex: %d\n", g->adjLists[i]->vertex);
        if(g->adjLists[i] != NULL){
            node *iter = g->adjLists[i];
            while(iter->next != NULL){
                //printf("\niter %d", iter->vertex);
                if (iter->vertex == vertex){
                    degree++;
                    //printf("degree %d of %d", degree, iter->vertex);
                }
                iter = iter->next;
        }
    }
     }
    return degree;
}


/**
 * @brief Get the information of user
 * 
 * @param graph 
 * @param src 
 * @param indegree 
 * @param successors 
 * @param mode 
 */
void get_information(Graph* graph, int src, int indegree, int successors, int mode){
    node* iter = graph->adjLists[src];

    while(iter->next != NULL && iter->vertex != src)
        iter = iter->next;
    
    if(mode==0)
        printf("\n ID: %d, In-Degree: %d, Successors: %d, Name: %s, Surname: %s",  iter->vertex, indegree, successors, iter->name, iter->surname);
    else if(mode==1)
        printf("\n ID: %d, In-Degree: %d, Name: %s, Surname: %s", iter->vertex, indegree, iter->name, iter->surname);   
}



/**
 * @brief DFS algorithm to find all successors
 * 
 *        My main idea is that if we reverse the original graph,
 *        and if we count the every possible node on the path
 *        we will get the all successors of the selected node
 * 
 * @param graph 
 * @param vertex 
 */
void dfs(Graph* graph, int vertex, int* count) {
    node* temp = graph->adjLists[vertex];
    
    graph->visited[vertex] = 1;
    //printf("\ncount %d", count);
    //printf("\nVisited %d", vertex);
    while (temp != NULL) {
        int connectedVertex = temp->vertex;
        if (graph->visited[connectedVertex] == 0) { 
            *count = *count + 1;
            dfs(graph, connectedVertex, count);
        }
        
        temp = temp->next;
    }
}


/**
 * @brief This function creates one way relationship: 
 *             - src follows dest on intagram
 * 
 * @param graph 
 * @param src 
 * @param dest 
 */
void add_edge(struct Graph* graph, char* src, char* dest) {
    char* tokens[48];
    char* vertex[48];
    int i=0;
    size_t ntokens, _;

    _ = tokenize(src, ",", vertex , 48);
    int to_id, from_id = atoi(vertex[0]);
    
    
    ntokens = tokenize(dest, ",", tokens , 48);
 
    while(i < ntokens){
        to_id = atoi(tokens[i]);
        // Add edge from source to dest
        
        if(to_id != 0){
            node* new_node = createNode(to_id, graph->adjLists[to_id]->name, graph->adjLists[to_id]->surname);
            new_node -> next = graph->adjLists[from_id];
            graph->adjLists[from_id] = new_node; 
        }
        i++;
    }
    //printf("Now person %s follow -> %s\n", graph->adjLists[from_id]->name, graph->adjLists[to_id]->name);
}



/**
 * @brief Create a reversed node object
 *        Original function is specilized to read from file
 *        so to create reversed graph, this func will help
 * @param v 
 * @return node* 
 */
node* create_reversed_node(int v){
    node* new_node = malloc(sizeof(node));
    new_node->vertex = v;
    new_node->next = NULL;
    return new_node;
}

/**
 * @brief Add reversed edge
 *        Original function is specilized to read from file
 *        so to create reversed graph, this func will help
 * 
 * @param graph 
 * @param d 
 * @param s 
 */
void add_reversed_edge(Graph* graph, int d, int s) {
    // Add edge from s to d
    node* new_node = create_reversed_node(d);
    new_node->next = graph->adjLists[s];
    graph->adjLists[s] = new_node;
}



/**
 * @brief Delete user from the graph
 * 
 * @param graph 
 * @param target 
 */
void delete_node(Graph *graph, int target) {
    int i, res = 0;
    for (i = 0; i < graph->numVertices; i++) {
        node *first = graph->adjLists[i];
        node *n = first;
        while (first && first->vertex == target) {
            first = first->next;
            free(n);
            res++;
            n = first;
        }
        while (n && n->next) {
            node *next= n->next;
            if (next->vertex == target) {
                n->next = next->next;
                free(next);
                res++;
            }
            n = n->next;
        }
        graph->adjLists[i] = first;
    }
    //printf("\nUser id %d is removed from possible list of influencers\n", target);
    free(graph->adjLists[target]);
    graph->adjLists[target] = NULL;
}

/**
 * @brief insert function for adding (independent) new user to the graph
 *              - user starts with following nobody
 * 
 * @param table 
 * @param key 
 * @param value 
 * @param mode 
 */
void insert_node(Graph* graph, char* vertices) {
    char* vertex[48];
    
    size_t _;
    _ = tokenize(vertices, ",", vertex , 48);
    // Create the item
    // vertex[0] -> int id
    // vertex[1] -> char name
    // vertex[2] -> char surname
    
    int v = atoi(vertex[0]);
    node* node = createNode(v, vertex[1], strtok(vertex[2], "\n"));
    graph->adjLists[v] = node;
    printf("New user is added: %d %s %s\n", graph->adjLists[v]->vertex, graph->adjLists[v]->name, graph->adjLists[v]->surname);
}


/**
 * @brief Create a Node object
 * 
 * @param v 
 * @param name 
 * @param surname 
 * @return node* 
 */
node* createNode(int v, char* name, char* surname) {
    node* newNode = malloc(sizeof(node));
    newNode->vertex = v;
    strcpy(newNode->name, name);
    strcpy(newNode->surname, surname);
    newNode->next = NULL;
    return newNode;
}

/**
 * @brief Create a Graph object
 * 
 * @param vertices 
 * @return Graph* 
 */
Graph* createGraph(int vertices) {
    Graph* graph = malloc(sizeof(Graph));
    graph->numVertices = vertices;

    graph->adjLists = malloc(vertices * sizeof(node*));
    graph->visited = malloc(vertices * sizeof(int));

    int i;
    for (i = 0; i < vertices; i++) {
      graph->adjLists[i] = NULL;
      graph->visited[i] = 0;
    }

    return graph;
}


/**
 * @brief Reverse graph to get successors by dfs
 * 
 * @param graph 
 * @return Graph* 
 */
Graph* reverse_graph(Graph* graph){
    int i, j;
    Graph* r_graph = createGraph(graph->numVertices);

   
    for(i=0; i< graph->numVertices; i++){
        if(graph->adjLists[i] != NULL){
            node* temp = graph->adjLists[i];
            int src = i;

            while(temp->next != NULL) {
                int destination = temp->vertex;
                
                add_reversed_edge(r_graph, src, destination);   
                temp = temp->next; 
            }
        }
    }
    return r_graph;
}



/**
 * @brief Display the current graph
 * 
 * @param graph 
 */
void printGraph(struct Graph* graph) {
    int v;
    for (v = 1; v < graph->numVertices; v++) {
        if(graph->adjLists[v] != NULL){
            struct node* temp = graph->adjLists[v];
            printf("\n Vertex %d\n: ", v);
            while (temp) {
                printf("%d -> ", temp->vertex);
                temp = temp->next;
            }
            printf("\n");
        }
    }
}


/**
 * @brief Split any string input into tokens to be able to
 *        utilize user follow information easily
 *        
 * 
 * @param inputString 
 * @param delim 
 * @param argv 
 * @param maxtokens 
 * @return size_t -> as return it provides token count, perfect utilization
 */
size_t tokenize(char *inputString, const char *delim, char **argv, size_t maxtokens) 
{
    size_t ntokens = 0;
    char *tokenized = strdup(inputString);
    if(tokenized){
        argv[0] = tokenized;
        while(*tokenized){
            if(strchr(delim, *tokenized)){
                *tokenized = 0;
                ntokens++;
                if(ntokens == maxtokens - 1)
                    break;
                
                argv[ntokens] = tokenized + 1;
            }
            tokenized++;
        }
    }
    return ntokens + 1;
}


/**
 * @brief Counts how many individual user we have in the file to be able to
 *        determine size of the graph beforehand
 *        
 * @return int 
 */
int count_node(char* filename){
    FILE *fp;
    int count = 0;  // Line counter (result)
    char c;  // To store a character read from file
 
    // Open the file
    fp = fopen(filename, "r");
 
    // Check if file exists
    if (fp == NULL){
        printf("Could not open file %s", filename);
        return 0;
    }
 
    // Extract characters from file and store in character c
    for (c = getc(fp); c != EOF; c = getc(fp))
        if (c == '\n') // Increment count if this character is newline
            count = count + 1;
 
    // Close the file
    fclose(fp);
    return count;
}