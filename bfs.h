#pragma once

#include "graph.h"
#include "edge.h"
#include <vector>
#include <algorithm>
#include <string>

class BFS {
    public:
        BFS();
        BFS(string node_filename, string neighbor_filename);
        void traversal(Vertex start);
    private:
        const static int INF;
        const static int EMPTY_VERTEX;

        int numVertices_;
        vector<Vertex> adj_;
        Graph g_;
};