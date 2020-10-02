#include<iostream>
#include <list>
using namespace std;

class Graph {
    int vertex;
    list <int> * adj;
    
    
public:
    Graph(int vertex);
    void addEdge(int vertex, int w);
    void BFS();
    
};

Graph::Graph(int vertex){
    this->vertex = vertex;
    adj = new list<int>[vertex];
}

void Graph::addEdge(int vertex, int w) {
    this->adj[vertex].push_back(w); // push back to add to the linked list
}


void Graph::BFS(){
    queue <int> myQueue;
    int * visited = new int[vertex];
    for(int i = 0; i < vertex; i++)
        visited[i] = 0;
    
    if (visited[0] == 0) {
        
        myQueue.push(0);
        visited[0] = 1;
        while (!myQueue.empty()) {
            list<int>::iterator i;
            int node = myQueue.front();
            for (i = adj[node].begin(); i != adj[node].end(); i++) {
                if (!visited[*i]) {
                    cout << *i <<endl;
                    visited[*i] = 1;
                    myQueue.push(*i);
                }

            }
            myQueue.pop();
        }
    }   
}