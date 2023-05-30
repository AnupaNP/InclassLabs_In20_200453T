#include <iostream>
using namespace std;

#define INF 9999
#define NUM_CITIES 6

// Function to print shortest distances
void printDist(int src, int dist[]) {
    for (int v = 0; v < NUM_CITIES; v++) {
        if (v != src)
            cout << src << " - " << v << " --> " << dist[v] << endl;
    }
}

// Dijkstra's Algorithm
void dijkstra(int graph[NUM_CITIES][NUM_CITIES], int src) {
    bool visited[NUM_CITIES];
    int dist[NUM_CITIES];

    for (int v = 0; v < NUM_CITIES; v++) {
        visited[v] = false;
        dist[v] = INF;
    }

    dist[src] = 0;

    for (int count = 0; count < NUM_CITIES - 1; count++) {
        int minDist = INF, minVertex = -1;

        for (int v = 0; v < NUM_CITIES; v++) {
            if (!visited[v] && dist[v] <= minDist) {
                minDist = dist[v];
                minVertex = v;
            }
        }

        visited[minVertex] = true;

        for (int v = 0; v < NUM_CITIES; v++) {
            if (!visited[v] && graph[minVertex][v] &&
                dist[minVertex] != INF &&
                dist[minVertex] + graph[minVertex][v] < dist[v]) {
                dist[v] = dist[minVertex] + graph[minVertex][v];
            }
        }
    }

    printDist(src, dist);
}

int main() {
    int graph[NUM_CITIES][NUM_CITIES] = {
        {0, 10, 0, 0, 15, 5},
        {10, 0, 10, 30, 0, 0},
        {0, 10, 0, 12, 5, 0},
        {0, 30, 12, 0, 0, 20},
        {15, 0, 5, 0, 0, 0},
        {5, 0, 0, 20, 0, 0}
    };

    int source_city = 5; // Change source city here (0 to 5)

    cout << "Shortest distances from city " << source_city << ":" << endl;
    dijkstra(graph, source_city);

    return 0;
}
