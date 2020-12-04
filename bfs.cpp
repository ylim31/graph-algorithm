#include "bfs.h"
#include "graph.h"
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <string.h>
#include <iostream>
#include <fstream>

using namespace std;

BFS::BFS() : g_(true, false) {}

BFS::BFS(string node_filename, string neighbor_filename) : g_(true, false) {
ifstream lastfm_file;
ifstream lastfm_neighbor_file;
lastfm_file.open(node_filename);
lastfm_neighbor_file.open(neighbor_filename);

while (lastfm_file.good()) {
    string node_label;
    getline(lastfm_file, node_label, ',');
    g_.insertVertex(node_label); 
}

lastfm_file.close();

size_t i = 0;
while (lastfm_neighbor_file.good()) {
        string each;
        string node_neighbor;
        getline(lastfm_neighbor_file, node_neighbor, ']');
        char node_neighbor_char[node_neighbor.size()];
        strcpy(node_neighbor_char, node_neighbor.c_str());
        
        char* piece = strtok(node_neighbor_char, " , \" \t []");

        while (piece != NULL) { 

            g_.insertEdge(to_string(i), piece);
            piece = strtok(NULL, ", \" []");      
        }
        i++;
    }

lastfm_neighbor_file.close();
}

void BFS::traversal(Vertex start) {
    unordered_map<Vertex, bool> is_visited_;

    /**
    bool *visited = new bool[V]; 
    for(int i = 0; i < V; i++) 
        visited[i] = false; 
  
    list<int> queue; 
  
    visited[s] = true; 
    queue.push_back(s); 

    list<int>::iterator i; 
  
    while(!queue.empty()) 
    {  
        s = queue.front(); 
        cout << s << " "; 
        queue.pop_front(); 
  
        for (i = adj[s].begin(); i != adj[s].end(); ++i) 
        { 
            if (!visited[*i]) 
            { 
                visited[*i] = true; 
                queue.push_back(*i); 
            } 
        } 
    } **/

}

