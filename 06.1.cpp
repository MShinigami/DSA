#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

const int MAX_CITIES = 10;

int route[MAX_CITIES][MAX_CITIES] = {0};
int nc;
string ap[MAX_CITIES];

void Insert() {
    cout << "\nEnter no. of cities: ";
    cin >> nc;

    for (int i = 0; i < nc; i++) {
        cout << "Enter " << i + 1 << " City : ";
        cin >> ap[i];
    }

    for (int i = 0; i < nc; i++) {
        for (int j = i + 1; j < nc; j++) {
            cout << "Enter distance between " << ap[i] << " and " << ap[j] << " : ";
            cin >> route[i][j];
            route[j][i] = route[i][j];
        }
    }
}

void Display() {
    cout << "\nDisplay cities with airport code: " << endl;

    for (int i = 0; i < nc; i++) {
        cout << "City " << i + 1 << " -> " << ap[i] << endl;
    }
}

void DisplayGraph() {
    cout << "\nAdjacency Matrix representation of graph: " << endl;

    for (int i = 0; i < nc; i++) {
        for (int j = 0; j < nc; j++) {
            cout << route[i][j] << "\t";
        }
        cout << endl;
    }
}

void DFS(int start) {
    bool visited[MAX_CITIES] = {false};
    stack<int> s;

    cout << "\nDFS Traversal: ";

    s.push(start);
    while (!s.empty()) {
        int current = s.top();
        s.pop();
        if (!visited[current]) {
            cout << ap[current] << " ";
            visited[current] = true;

            vector<int> adjacent_cities;
            for (int i = nc; i > 0; i--) {
                if (route[current][i] != 0 && !visited[i]) {
                    adjacent_cities.push_back(i);
                }
            }
            sort(adjacent_cities.begin(), adjacent_cities.end(), 
                [&](int a, int b) { return route[current][a] < route[current][b]; });

            for (int city : adjacent_cities) {
                s.push(city);
            }
        }
    }

    cout << endl;
}

void BFS(int start) {
    bool visited[MAX_CITIES] = {false};
    queue<int> q;
    cout << "\nBFS Traversal: ";
    q.push(start);
   
    while (!q.empty()) {
        int current = q.front();
        q.pop();

        if (!visited[current]) {
            cout << ap[current] << " ";
            visited[current] = true;

            vector<int> adjacent_cities;
            for (int i = 0; i < nc; i++) {
                if (route[current][i] != 0 && !visited[i]) {
                    adjacent_cities.push_back(i);
                }
            }
            sort(adjacent_cities.begin(), adjacent_cities.end(), 
                [&](int a, int b) { return route[current][a] < route[current][b]; });

            for (int city : adjacent_cities) {
                q.push(city);
            }
        }
    }
    cout << endl;
}

int main() {
    Insert();
    Display();
    DisplayGraph();
    
    int start;
    cout << "\nEnter the starting vertex for traversal: ";
    cin >> start;
    BFS(start);
    DFS(start);
    
    cout << "\n\tExiting...\n";

    return 0;
}