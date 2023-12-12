#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>

using namespace std;

void bfs(const vector<vector<int>>& graph, int startNode) {
    queue<int> q;
    unordered_set<int> visited;

    q.push(startNode);
    visited.insert(startNode);

    while (!q.empty()) {
        int currentNode = q.front();
        q.pop();
        cout << currentNode << " "; // Process the current node

        for (int neighbor : graph[currentNode]) {
            if (visited.find(neighbor) == visited.end()) {
                q.push(neighbor);
                visited.insert(neighbor);
            }
        }
    }
}

int main() {
    // Example graph represented as an adjacency list
    vector<vector<int>> graph = {{1, 2}, {0, 3, 4}, {0, 4}, {1}, {1, 2}};

    cout << "BFS starting from node 0: ";
    bfs(graph, 0);

    return 0;
}

