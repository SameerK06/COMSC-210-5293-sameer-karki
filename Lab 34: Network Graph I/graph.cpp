#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>

using namespace std;

const int SIZE = 9;
const int INF = 1e9;

struct Edge {
    int src, dest, weight;
};

typedef pair<int, int> Pair;  // Creates alias 'Pair' for the pair<int,int> data type

class Graph {
public:
    // a vector of vectors of Pairs to represent an adjacency list
    vector<vector<Pair>> adjList;
    vector<string> stationNames;

    // Graph Constructor
    Graph(vector<Edge> const &edges, vector<string> const &name) {
        // resize the vector to hold SIZE elements of type vector<Edge>
        adjList.resize(SIZE);
        stationNames = name;

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
    void printNetwork() {
        cout << "Subway Transit Network Topology" << endl;
        for (int i = 0; i < adjList.size(); i++) {
            cout << "Station " << i << "(" << stationNames[i] << ") connects to: " << endl;
            for (Pair v : adjList[i])
                cout << " -> Station " << v.first << " (" << stationNames[v.first] << ") - Travel Time: "
                << v.second << " minutes" << endl;
            cout << endl;
        }
    }

    // DFS heper
    void dfsHelper(int vertex, vector<bool>& visited) {
        visited[vertex] = true;
        cout << "Inspecting Station " << vertex << " (" << stationNames[vertex] << ")" << endl;
        for (Pair& neighbor : adjList[vertex]) {
            if (!visited[neighbor.first]) {
                cout << " -> Maintance track leads to station " << neighbor.first << " ("
                << " (" << stationNames[neighbor.first] << ") - Time: " << neighbor.second << " minutes" << endl;
                dfsHelper(neighbor.first, visited);
            }
        }
    }

    // Depth-First Search
    // Purpose: Tracing contiguous rail lines for emergency maintenance inspection
    void DFS(int start) {
        cout << "Network Track Trace (DFS) starting from station " << start << "(" << stationNames[start] << "):" << endl;
        vector<bool> visited(SIZE, false);
        dfsHelper(start, visited);
        cout << endl;
    }

    // Breadth-First Search
    // Purpose: Analyzing passenger impact zones expanding outward from a central delay
    void BFS(int start) {
        cout << "Layer-by-Layer Service Inspection (BFS) starting from station " << start << " (" 
        << stationNames[start] << "):" << endl;
        vector<bool> visited(SIZE, false);
        queue<int> q;
        q.push(start);
        visited[start] = true;
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            cout << "Checking Station " << curr << " (" << stationNames[curr]  << ")" << endl;
            for (Pair& neighbor : adjList[curr]) {
                if (!visited[neighbor.first]) {
                    visited[neighbor.first] = true;
                    cout << " -> Deplay spreads to next zone: Station " << neighbor.first << " (" 
                    << stationNames[neighbor.first] << ") - Connection: " << neighbor.second << " minutes" << endl;
                    q.push(neighbor.first);
                }
            }
        }
        cout << endl;
    }

    void shortestPathDijkstra(int start) {
        priority_queue<Pair, vector<Pair>, greater<Pair>> pq;
        vector<int> dist(SIZE, INF);
        pq.push(make_pair(0, start));
        dist[start] = 0;
        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();
            for (auto& neighbor : adjList[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;
                
            }
        }
    }

};

int main() {
    vector<string> stationNames = {
        "Central Hub", "North Park", "University Campus", "Tech District", "Waterfront", "Historical Center",
        "Financial Hub", "Airport Terminal", "Sports Arena"
    };

    // Creates a vector of graph edges/weights
    vector<Edge> edges = {
        // (x, y, w) —> edge from x to y having weight w
        {0,1,8}, {0,2,21}, {1,2,6}, {1,3,5}, {1,4,4}, {2,7,11}, {2,8,8}, {3,4,9}, {5,6,10}, {5,7,15}, {5,8,5},
        {6,7,3}, {6,8,7}
    };

    // Creates graph
    Graph subwayNetwork(edges, stationNames);

    // Prints adjacency list representation of graph
    subwayNetwork.printNetwork();
    subwayNetwork.DFS(0);
    subwayNetwork.BFS(0);

    return 0;
}
