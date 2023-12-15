#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> bfs(const vector<vector<int>>& tree, int start, int target) {
    vector<bool> visited(tree.size(), false);
    queue<int> q;
    vector<int> traversal;

    q.push(start);

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        traversal.push_back(current);

        for (int child : tree[current]) {
            if (!visited[child]) {
                visited[child] = true;
                q.push(child);
            }
        }

        // If the target node is found, break the loop
        if (current == target) {
            break;
        }
    }

    return traversal;
}

int main() {
    int totalNodes, numChildren, targetNode;

    // Get user input for the total number of nodes and number of children per node
    cout << "Enter the total number of nodes: ";
    cin >> totalNodes;

    cout << "Enter the number of children for each node: ";
    cin >> numChildren;

    // Build the tree structure
    vector<vector<int>> tree(totalNodes);
    for (int i = 0; i < totalNodes; ++i) {
        for (int j = 1; j <= numChildren && i + j < totalNodes; ++j) {
            tree[i].push_back(i + j);
        }
    }

    // Get user input for the target node to visit
    cout << "Enter the node you want to visit: ";
    cin >> targetNode;

    // Perform BFS and get the path to the target node
    vector<int> path = bfs(tree, 0, targetNode);

    // Display the result
    cout << "Visited nodes during BFS up to node " << targetNode << ": ";
    if (find(path.begin(), path.end(), targetNode) != path.end()) {
        for (int node : path) {
            cout << node << " ";
        }
    } else {
        cout << "Node not found. Visited nodes: ";
        for (int node : path) {
            cout << node << " ";
        }
    }
    cout << endl;

    return 0;
}
