// NAME: Ethan Sue
// FILE: Digraph.h
// DESCRIPTION: Definition of Digraph class


#ifndef DIGRAPH_H
#define DIGRAPH_H


#include <iostream>
using namespace std;

class Digraph {
	
private:
	int** matrix; // two-dime array for storing the edges
	int size; // the number of vertices in the graph
	bool* visited; // an array of bool used for the traversal functions

    int** dCopy(int** matrix, int size); // deep copy function to create a matrix
    void recursiveDFS(int vertex); // recursive depth first search

public:
	Digraph(); //  default constructor
	
	// A constructor that creates a graph consisting of n vertices and no edges.
	Digraph(int n);
	
	// A constructor that creates the graph using the file passed into the 
	// function. The format of the file is described later in this document.
	Digraph(string filename);
	
	Digraph(const Digraph &orig); // copy constructor

	~Digraph(); // destructor
	
	
	
	void addEdge(int a, int b); // Adds the edge (a, b) to the graph.
	
	// Displays the graph's adjacency matrix to the screen using this format
	void display() const; 
	
	//  Displays the result of a depth first search starting at the 
	// provided vertex
	void displayDFS(int vertex);
	
	// Returns the resulting spanning tree of a breadth first search.
	// Also displays the vertices as they are visited
	Digraph& createBFS(int vertex);
	
	// Returns the in-degree of vertex i
	int inDegree(int i) const;
	
	
};

#endif
