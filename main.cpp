#include <iostream>
#include <fstream>
#include "cs225/PNG.h"
#include "graph.h"

using namespace std;
int main(){
    Graph g_(true, true);

    ifstream lastfm_file;
    lastfm_file.open("lastfm_node.csv");
    ifstream lastfm_file;
    lastfm_file.open("lastfm_neighbor.csv");

    while (lastfm_file.good()) {
        string node_label;
        getline(lastfm_file, node_label, ',');
        //std::cout << "NODEs: " << node_label;
        g_.insertVertex(node_label);
        
        while (lastfm_file.good()) {
            string ss;
            string node_neighbor;
            getline(lastfm_file, node_neighbor, ']');
            stringstream s(node_neighbor);
            while (getline(s, ss, ',')) {
            
            }
        }

    }
    lastfm_file.close();

    
    
}