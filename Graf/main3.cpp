#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

// Function to perform BFS and find the shortest path
vector<string> bfs(const unordered_map<string, vector<string>>& graph, const string& start, const string& end) {
    unordered_map<string, string> parent;
    queue<string> q;
    unordered_set<string> visited;

    q.push(start);
    visited.insert(start);
    parent[start] = "";

    while (!q.empty()) {
        string current = q.front();
        q.pop();

        if (current == end) {
            // Reconstruct the path
            vector<string> path;
            for (string at = end; !at.empty(); at = parent[at]) {
                path.push_back(at);
            }
            reverse(path.begin(), path.end());
            return path;
        }

        for (const string& neighbor : graph.at(current)) {
            if (visited.find(neighbor) == visited.end()) {
                q.push(neighbor);
                visited.insert(neighbor);
                parent[neighbor] = current;
            }
        }
    }

    return {}; // Return an empty path if no route is found
}

int main() {
    int n;
    cin >> n;
    cin.ignore();

    vector<string> stops(n);
    for (int i = 0; i < n; ++i) {
        cin >> stops[i];
    }

    int m;
    cin >> m;
    cin.ignore();

    unordered_map<string, vector<string>> graph;
    for (const string& stop : stops) {
        graph[stop] = vector<string>();
    }

    for (int i = 0; i < m; ++i) {
        string line;
        getline(cin, line);
        stringstream ss(line);

        string lineName, stop;
        ss >> lineName;
        vector<string> lineStops;
        while (ss >> stop) {
            lineStops.push_back(stop);
        }

        for (size_t j = 0; j < lineStops.size(); ++j) {
            for (size_t k = j + 1; k < lineStops.size(); ++k) {
                graph[lineStops[j]].push_back(lineStops[k]);
                graph[lineStops[k]].push_back(lineStops[j]);
            }
        }
    }

    string start, end;
    cin >> start >> end;

    vector<string> result = bfs(graph, start, end);

    if (result.empty()) {
        cout << "NO ROUTE" << endl;
    } else {
        for (const string& stop : result) {
            cout << stop << " ";
        }
        cout << endl;
    }

    return 0;
}
