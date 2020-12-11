#pragma once

#include "cs225/graph.h"
#include "cs225/edge.h"
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>

class BFS {
    public:
        BFS();
        BFS(string node_filename);
        vector<Vertex> traversal(Vertex start);
        vector<vector<Vertex>> connectedComp();
        pair<Vertex, int> parse(string input);
        int numNodes();
    private:
        unordered_map<Vertex, bool> is_visited_;
        int numVertices;
        Graph g_;
};