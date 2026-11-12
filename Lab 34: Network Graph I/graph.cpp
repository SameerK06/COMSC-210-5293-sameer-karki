#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

const int SIZE = 9;

struct Edge {
    int src, dest, weight;
};

typedef pair<int, int> Pair;  // Creates alias 'Pair' for the pair<int,int> data type

class Graph {
public:
    // a vector of vectors of Pairs to represent an adjacency list
    vector<vector<Pair>> adjList;

    // Graph Constructor
    Graph(vector<Edge> const &edges) {
        // resize the vector to hold SIZE elements of type vector<Edge>
        adjList.resize(SIZE);

        // add edges to the directed graph
        for (auto &edge: edges) {
            int src = edge.src;
            int dest = edge.dest;
            int weight = edge.weight;

            // insert at the end
            adjList[src].push_back(make_pair(dest, weight));
            // for an undirected graph, add an edge from dest to src also
            adjList[dest].push_back(make_pair(src, weight));
        }
    }

    // Print the graph's adjacency list
    void printGraph() {
        cout << "Graph's adjacency list:" << endl;
        for (int i = 0; i < adjList.size(); i++) {
            cout << i << " --> ";
            for (Pair v : adjList[i])
                cout << "(" << v.first << ", " << v.second << ") ";
            cout << endl;
        }
    }

    // DFS heper
    void dfsHelper(int vertex, vector<bool>& visited) {
        visited[vertex] = true;
        cout << vertex << " ";
        for (Pair& neighbor : adjList[vertex]) {
            if (!visited[neighbor.first]) {
                dfsHelper(neighbor.first, visited);
            }
        }
    }

    // Depth-First Search
    void DFS(int start) {
        cout << "DFS starting from vertex " << start << ":" << endl;
        vector<bool> visited(SIZE, false);
        dfsHelper(start, visited);
        cout << endl;
    }

    // Breadth-First Search
    void BFS(int start) {
        cout << "BFS starting from vertex " << start << ":" << endl;
        vector<bool> visited(SIZE, false);
        queue<int> q;
        q.push(start);
        visited[start] = true;
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            cout << curr << " ";
            for (Pair& neighbor : adjList[curr]) {
                if (!visited[neighbor.first]) {
                    visited[neighbor.first] = true;
                    q.push(neighbor.first);
                }
            }
        }
        cout << endl;
    }

};

int main() {
    // Creates a vector of graph edges/weights
    vector<Edge> edges = {
        // (x, y, w) —> edge from x to y having weight w
        {0,1,8}, {0,2,21}, {1,2,6}, {1,3,5}, {1,4,4}, {2,7,11}, {2,8,8}, {3,4,9}, {5,6,10}, {5,7,15}, {5,8,5},
        {6,7,3}, {6,8,7}
    };

    // Creates graph
    Graph graph(edges);

    // Prints adjacency list representation of graph
    graph.printGraph();

    cout << "DFS Test Driver" << endl;
    graph.DFS(0);
    cout << "BFS Test Driver" << endl;
    graph.BFS(0);
    

    return 0;
}
