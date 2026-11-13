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
                cout << " -> Maintenance track leads to station " << neighbor.first << " ("
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
                    cout << " -> Delay spreads to next zone: Station " << neighbor.first << " (" 
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
                if (dist[v] > dist[u] + weight) {
                    dist[v] = dist[u] + weight;
                    pq.push(make_pair(dist[v], v));
                }
            }
        }
        cout << "Shortest Path from node " << start << " (" << stationNames[start] << "):" << endl;
        for (int i = 0; i < SIZE; i++) {
            if (dist[i] == INF) {
                cout << start << " -> " << i << " : Unreachable" << endl;
            } else {
                cout << start << " -> " << i << " : " << dist[i] << " minutes" << endl;
            }
        }
        cout << endl;
    }

    void MST(int start) {
        priority_queue<Pair , vector<Pair>, greater<Pair>> pq;
        vector<int> key(SIZE, INF);
        vector<int> parent(SIZE, -1);
        vector<bool> inMST(SIZE, false);

        pq.push(make_pair(0, start));
        key[start] = 0;
        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();
            inMST[u] = true;
            for (auto& neighbor : adjList[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;
                if (!inMST[v] && weight < key[v]) {
                    key[v] = weight;
                    pq.push(make_pair(key[v], v));
                    parent[v] = u;
                }
            }
        }
        cout << "Minimum Spanning Tree Edges:" << endl;
        for (int i = 0; i < SIZE; i++) {
            if (i != start && parent[i] != -1) {
                cout << "Edge from " << parent[i] << " to " << i << " with capacity " << key[i] << " units ("
                << stationNames[parent[i]] << " <-> " << stationNames[i] << ")" << endl; 
            }
        }
        cout << endl;
    }
};

void gameMenu(Graph& subwayNetwork);

int main() {
    vector<string> stationNames = {
        "Central Hub", "North Park", "University Campus", "Tech District", "Waterfront", "Historical Center",
        "Financial Hub", "Airport Terminal", "Sports Arena"
    };

    // Creates a vector of graph edges/weights
    vector<Edge> edges = {
        // (x, y, w) —> edge from x to y having weight w
        {0,1,8}, {0,2,10}, {1,2,7}, {1,3,5}, {1,4,4}, {2,7,11}, {2,8,7}, {3,4,9}, {5,6,5}, {5,7,10}, {5,8,8},
        {6,7,3}, {6,8,7}
    };

    // Creates graph
    Graph subwayNetwork(edges, stationNames);

    gameMenu(subwayNetwork);

    return 0;
}

void gameMenu(Graph& subwayNetwork) {
    int choice = -1;
    while (choice != 0) {
        cout << "Subway Transit Network Menu:\n[1] Display subway transit network"
        << "\n[2] Check service area spread (BFS)\n[3] Plan track inspection route (DFS)"
        << "\n[4] Calculate shortest paths\n[5] Find Minimum Spanning Tree\n[0] Exit\n";
        cout << "Enter your choice: ";
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "\nInvalid input. Please enter a number from from 0-5.\n\n";
            continue;
        }
        switch(choice) {
            case 1:
                subwayNetwork.printNetwork();
                break;
            case 2:
                subwayNetwork.BFS(0);
                break;
            case 3:
                subwayNetwork.DFS(0);
                break;
            case 4:
                subwayNetwork.shortestPathDijkstra(0);
                break;
            case 5:
                subwayNetwork.MST(0);
                break;
            case 0:
                cout << "\nExiting system..." << endl;
                break;
            default:
                cout << "\nInvalid choice. Please try again.\n\n";
                break;
        }
    }
}