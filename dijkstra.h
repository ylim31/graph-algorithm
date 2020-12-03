#pragma once

#include "graph.h"
#include "edge.h"
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>

class Dijkstra {
    public:
        Dijkstra();
        Dijkstra(string node_filename, string neighbor_filename);
        vector<Vertex> find_shortest_path(Vertex start, Vertex end);
        vector<Vertex> backtrack(unordered_map<Vertex, Vertex> prev_vertex_, Vertex start, Vertex end);
        Vertex get_shortest_distance(vector<Vertex> neighbor);
    private:
        const static int INF;
        const static int EMPTY_VERTEX;

        unordered_map<Vertex, bool> is_visited_;
        unordered_map<Vertex, int> shortest_distance_from_start_;
        unordered_map<Vertex, Vertex> prev_vertex_;
        Graph g_;
};
