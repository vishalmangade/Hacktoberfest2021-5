#include <iostream>
using namespace std;

class Stack
{
    int
        *ptr;
    int
        size;
    int top;

public:
    Stack();
    Stack(int);
    ~Stack();
    void
    push(int);
    int
    pop();
    bool isempty() const;
    bool isfull() const;
};

class Node
{
public:
    int data;
    Node
        *next;
};
class LinkList
{
    Node *head;

public:
    LinkList();
    ~LinkList();
    void Display();
    void insert(int);
    bool search(int);
};

class Graph
{
    int Vertices;
    LinkList *adjVertices;

public:
    Graph(int);
    ~Graph();
    void insert(int, int);
    void display(int);
    void display();
    void DFS(int);
};

Graph::Graph(int n)
{
    Vertices = n;
    adjVertices = new LinkList[Vertices + 1];
    cout << "Insert vertices " << endl;
}
Graph::~Graph()
{
    for (int i = 0; i <= Vertices;
         i++)
    {
        adjVertices[i].~LinkList();
    }
    delete[] adjVertices;
}
void Graph::insert(int a, int b)
{
    if (a < 1 || a > this->Vertices)
    {
        cout << "Vertex " << a << " does not exist\n";
        return;
    }
    if (b < 1 || b > this->Vertices)
    {
        cout << "Vertex " << b << " does not  exist\n ";
        return;
    }
    adjVertices[a].insert(b);
    adjVertices[b].insert(a);
}
void Graph::display(int vertex)
{
    if (vertex < 1 || vertex > this->Vertices)
    {
        cout << "Vertex " << vertex << " does not  exist\n\n ";
        return;
    }
    cout << "Vertex : " << vertex << ", adjacent vertices: ";
    adjVertices[vertex].Display();
}
void Graph::display()
{
    cout << "Displaying the graph\n";
    for (int i = 1; i <= Vertices;
         i++)
    {
        display(i);
        cout << "\n";
    }
}
void Graph::DFS(int s)
{
    bool *visited = new bool[Vertices + 1];
    for (int i = 1; i <= Vertices; i++)
    {
        visited[i] = false;
    }
    Stack *stack = new Stack(Vertices);
    stack->push(s);
    while (!stack->isempty())
    {
        s = stack->pop();
        if (!visited[s])
        {
            cout << s << "  ";
            visited[s] = true;
        }
        for (int i = 1; i <= Vertices; i++)
        {
            if (adjVertices[s].search(i) &&
                !visited[i])
            {
                stack->push(i);
            }
        }
    }
}
