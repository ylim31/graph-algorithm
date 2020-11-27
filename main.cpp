#include <iostream>
#include <fstream>
#include "cs225/PNG.h"
#include "graph.h"
#include <string.h>

using namespace std;
int main(){
    Graph g_(true, false);

    ifstream lastfm_file;
    lastfm_file.open("lastfm_node.csv");
    ifstream lastfm_neighbor_file;
    lastfm_neighbor_file.open("lastfm_neighbor.csv");
    //lastfm_neighbor_file.open("testss.csv");
    //lastfm_file.open("test.csv");
    //lastfm_neighbor_file.open("test_neighbor.csv");

    while (lastfm_file.good()) {
        string node_label;
        getline(lastfm_file, node_label, ',');
        //std::cout << "Node" << node_label << std::endl;
        g_.insertVertex(node_label);
    }
    lastfm_file.close();
    size_t i = 0;
    
    while (lastfm_neighbor_file.good()) {
        
        string each;
        string node_neighbor;

        
        getline(lastfm_neighbor_file, node_neighbor, ']');
        char node_neighbor_char[node_neighbor.size() + 1];
        strcpy(node_neighbor_char, node_neighbor.c_str());
        
        char* piece = strtok(node_neighbor_char, " , \" \t []");
        //std::cout << "DOOO" << piece << std::endl;
        while (piece != NULL) {
            
            //string str(piece);
            g_.insertEdge(to_string(i), piece);
            piece = strtok(NULL, ", \" []");
            
            
        }
        
        i++;
    }

    lastfm_neighbor_file.close();

    vector<Vertex> ex = g_.getAdjacent(to_string(0));
    for (unsigned i = 0; i < ex.size(); i++) {
        std::cout << "NODEs: " << ex[i] << std::endl;
    }

    vector<Vertex> ex1 = g_.getAdjacent(to_string(1));
    for (unsigned i = 0; i < ex1.size(); i++) {
        //std::cout << "NODEs 1: " << ex1[i] << std::endl;
    }

    vector<Vertex> ex2 = g_.getAdjacent(to_string(2));
    for (unsigned i = 0; i < ex2.size(); i++) {
        //std::cout << "NODEs 2: " << ex2[i] << std::endl;
    }

    vector<Vertex> ex3 = g_.getAdjacent(to_string(3));
    for (unsigned i = 0; i < ex3.size(); i++) {
        //std::cout << "NODEs 3: " << ex3[i] << std::endl;
    }

    vector<Vertex> ex4 = g_.getAdjacent(to_string(4));
    for (unsigned i = 0; i < ex4.size(); i++) {
        //std::cout << "NODEs 4: " << ex4[i] << std::endl;
    }
    
    

    
}