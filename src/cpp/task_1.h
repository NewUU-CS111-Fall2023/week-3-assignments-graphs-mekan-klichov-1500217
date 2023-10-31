/*
 * Author: Mekan Klichov
 * Date: 31.10.2023
 * Name: Mekan Klichov
 */
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 1e9;

struct Edge {
    int to, weight;
};

void task1(){
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<Edge>> graph(n + 1);
    vector<int> forbidden(k);

    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back({y, 1});
        graph[y].push_back({x, 1});
    }

    for (int i = 0; i < k; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        forbidden[i] = a;
    }

    vector<int> distance(n + 1, INF);
    vector<int> parent(n + 1, -1);
    vector<bool> visit(n + 1, false);
    priority_queue<pair<int, int>> pq;
    pq.push({0, 1});
    distance[1] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (visit[u]) continue;
        visit[u] = true;

        for (Edge& edge : graph[u]) {
            int v = edge.to;
            int weight = edge.weight;

            if (!visit[v] && distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
                parent[v] = u;
                pq.push({-distance[v], v});
            }
        }
    }

    if (distance[n] == INF) {
        cout << -1 << endl;
    } else {
        vector<int> path;
        int current = n;
        while (current != -1) {
            path.push_back(current);
            current = parent[current];
        }

        reverse(path.begin(), path.end());

        for (int i = 0; i < path.size() - 2; ++i) {
            int a = path[i];
            int b = path[i + 1];
            int c = path[i + 2];
            if (find(forbidden.begin(), forbidden.end(), a) != forbidden.end() &&
                find(forbidden.begin(), forbidden.end(), b) != forbidden.end() &&
                find(forbidden.begin(), forbidden.end(), c) != forbidden.end()) {
                cout << -1 << endl;
            } else{
                cout << path.size() - 1 << endl;
                for (int node : path) {
                    cout << node << " ";
                }
                cout << endl;
            }
        }


    }
}