#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <list>

using namespace std;

void bfs(int s, const vector<list<int>>& adjList, const vector<string>& arr) {
    int n = adjList.size();
    vector<bool> visited(n, false);
    queue<int> bfsq;

    if (!visited[s]) {
        cout << arr[s] << " ";
        bfsq.push(s);
        visited[s] = true;

        while (!bfsq.empty()) {
            int v = bfsq.front();
            bfsq.pop();

            for (int u : adjList[v]) {
                if (!visited[u]) {
                    cout << arr[u] << " ";
                    visited[u] = true;
                    bfsq.push(u);
                }
            }
        }
    }
}

void displayAlist(const vector<list<int>>& adjList, const vector<string>& arr) {
    cout << "\nAdjacency List representation of graph: " << endl;

    for (int i = 0; i < adjList.size(); i++) {
        cout << arr[i] << " -> ";
        for (int v : adjList[i]) {
            cout << arr[v] << " -> ";
        }
        cout << endl;
    }
}

int main() {
    int nc;
    cout << "\nEnter no. of cities: ";
    cin >> nc;

    vector<string> ap(nc);
    vector<list<int>> adjList(nc); 

    for (int i = 0; i < nc; i++) {
        cout << "Enter " << i + 1 << " City : ";
        cin >> ap[i];
    }

    cout << "\nDisplay cities with airport code: " << endl;
    for (int i = 0; i < nc; i++) {
        cout << "City " << i + 1 << " -> " << ap[i] << endl;
    }

    for (int i = 0; i < nc; i++) {
        for (int j = i + 1; j < nc; j++) {
            int distance;
            cout << "Enter distance between " << ap[i] << " and " << ap[j] << " : ";
            cin >> distance;
            if (distance != 0) {
                adjList[i].push_back(j);
                adjList[j].push_back(i);
            }
        }
    }

    displayAlist(adjList, ap);

    int startVertex;
    cout << "\nEnter the starting vertex for traversal: ";
    cin >> startVertex;

    bfs(startVertex, adjList, ap);

    return 0;
}
