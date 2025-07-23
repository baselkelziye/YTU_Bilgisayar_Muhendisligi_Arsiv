#include <stdio.h>
#include <stdlib.h>

typedef struct Employee
{
    char name[20];
    int age;
    int salary;
} Employee;

typedef struct Node
{
    Employee employee;
    struct Node *first_child;
    struct Node *next_sibling;
} Node;

Node *createNode(Employee emp);
void addChild(Node *parent, Node *child);
void printTree(Node *node, int level);
int calculateHeight(Node *root, int level);
void calculate_employee(Node *node, int level, int *level_arr);
int calculate_ageAvg(Node *node);
int calculate_totalSalary(Node *node);

Node *findSiblingWithMostChildren(Node *node, int level);

int main()
{
    Employee employees[12] = {
        {"A1", 50, 100000},
        {"B1", 40, 80000},
        {"B2", 42, 85000},
        {"B3", 38, 78000},
        {"B4", 45, 90000},
        {"C1", 30, 50000},
        {"C2", 32, 52000},
        {"C3", 31, 51000},
        {"C4", 29, 48000},
        {"C5", 28, 47000},
        {"C6", 33, 53000},
        {"C7", 34, 54000}};

    Node *A1 = createNode(employees[0]);
    Node *B1 = createNode(employees[1]);
    Node *B2 = createNode(employees[2]);
    Node *B3 = createNode(employees[3]);
    Node *B4 = createNode(employees[4]);
    Node *C1 = createNode(employees[5]);
    Node *C2 = createNode(employees[6]);
    Node *C3 = createNode(employees[7]);
    Node *C4 = createNode(employees[8]);
    Node *C5 = createNode(employees[9]);
    Node *C6 = createNode(employees[10]);
    Node *C7 = createNode(employees[11]);

    addChild(A1, B1);
    addChild(A1, B2);
    addChild(A1, B3);
    addChild(A1, B4);

    addChild(B1, C1);
    addChild(B1, C2);
    addChild(B1, C3);

    addChild(B2, C4);
    addChild(B2, C5);

    addChild(B3, C6);

    addChild(B4, C7);

    printTree(A1, 0);

    int level = calculateHeight(A1, 1);
    printf("Height of tree: %d\n", level);

    int *level_arr;
    level_arr = (int *)calloc(level, sizeof(int));

    calculate_employee(A1, 0, level_arr);

    int i;

    for (i = 0; i < level; i++)
        printf("level(%d):%d\n", i + 1, level_arr[i]);

    int avg_age = calculate_ageAvg(A1);

    printf("Average of age %d\n", avg_age);

    int total_salary = calculate_totalSalary(A1);

    printf("Average of age %d\n", total_salary);

    int targetLevel = 2;
    Node *siblingWithMostChildren = findSiblingWithMostChildren(A1, targetLevel);

    if (siblingWithMostChildren != NULL)
        printf("Sibling with most children at level %d: %s\n", targetLevel, siblingWithMostChildren->employee.name);

    else
        printf("No sibling with children found at level %d.\n", targetLevel);
}

Node *createNode(Employee emp)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->employee = emp;
    newNode->first_child = NULL;
    newNode->next_sibling = NULL;
    return newNode;
}

void addChild(Node *parent, Node *child)
{

    if (parent->first_child == NULL)
    {
        parent->first_child = child;
    }

    else
    {
        Node *temp = parent->first_child;

        while (temp->next_sibling != NULL)
        {
            temp = temp->next_sibling;
        }
        temp->next_sibling = child;
    }
}

void printTree(Node *node, int level)
{
    if (node == NULL)
        return;

    for (int i = 0; i < level; i++)
        printf("  ");
    printf("%s\n", node->employee.name);

    printTree(node->first_child, level + 1);
    printTree(node->next_sibling, level);
}

int calculateHeight(Node *root, int level)
{
    int tmp_level, max;
    max = level;
    if (root == NULL)
    {
        return level;
    }

    else
    {
        Node *tmp = root->first_child;
        while (tmp != NULL)
        {
            // printf("%s\n", tmp->employee.name);
            tmp_level = calculateHeight(tmp, level + 1);
            tmp = tmp->next_sibling;

            if (tmp_level > max)
                max = tmp_level;
        }
        return max; 
    }
}

void calculate_employee(Node *node, int level, int *level_arr)
{
    if (node == NULL)
        return;

    level_arr[level]++;

    calculate_employee(node->first_child, level + 1, level_arr);
    calculate_employee(node->next_sibling, level, level_arr);
}

int calculate_ageAvg(Node *node)
{
    static int ctr;
    static int age_mean;

    if (node == NULL)
        return 0;

    ctr++;
    age_mean += node->employee.age;

    calculate_ageAvg(node->first_child);
    calculate_ageAvg(node->next_sibling);

    return age_mean / ctr;
}

int calculate_totalSalary(Node *node)
{
    static int total_salary;

    if (node == NULL)
        return 0;

    total_salary += node->employee.salary;

    calculate_ageAvg(node->first_child);
    calculate_ageAvg(node->next_sibling);

    return total_salary;
}

Node *findSiblingWithMostChildren(Node *node, int targetLevel)
{
    if (node == NULL || targetLevel < 1)
        return NULL;

    if (targetLevel == 1)
    {
        Node *current = node;
        Node *siblingWithMostChildren = NULL;
        int maxChildren = 0;

        while (current != NULL)
        {
            int childCount = 0;
            Node *child = current->first_child;

            while (child != NULL)
            {
                childCount++;
                child = child->next_sibling;
            }

            if (childCount > maxChildren)
            {
                maxChildren = childCount;
                siblingWithMostChildren = current;
            }

            current = current->next_sibling;
        }

        if (siblingWithMostChildren != NULL)
        {
            printf("Sibling with most children at level %d: %s has %d children.\n", targetLevel, siblingWithMostChildren->employee.name, maxChildren);
        }

        return siblingWithMostChildren;
    }
    else
    {
        Node *child = node->first_child;
        while (child != NULL)
        {
            Node *result = findSiblingWithMostChildren(child, targetLevel - 1);
            if (result != NULL)
                return result;

            child = child->next_sibling;
        }
    }

    return NULL;
}