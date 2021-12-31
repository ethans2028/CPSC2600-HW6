// NAME: Ethan Sue
// FILE: Digraph.cpp
// DESCRIPTION: Implementation of the Digraph 


#include <iostream>
#include <deque>
#include <fstream>
#include <sstream>
#include "digraph.h"

using namespace std;


// constructors

Digraph::Digraph(int n)
{
	size = n;
	matrix = new int*[size];

    // create an array for each index in the array
    for(int j = 0; j < size; j++) {
        matrix[j] = new int[size];
    }

	// setting all edge values equal to zero
	for(int i = 0; i < size; i++) {
		for(int j = 0; j < size; j++) {
			matrix[i][j] = 0;
		}
	}

    // initialize visited array
	visited = new bool[size];
}

Digraph::Digraph(string filename)
{
	ifstream inFile;
	inFile.open(filename); // open data file
	
	// holds the data to be added
	string tDSize, tT, tH, line;
	int t, h;
	
	// stores the number of vertices in the Digraph (data is in first row)
	getline(inFile, line);
	stringstream s(line);
	getline(s, tDSize, ',');
	size = stoi(tDSize); // convert dsize to int and set size to it
	matrix = new int*[size];

    // create array for each index in the matrix array
    for(int j = 0; j < size; j++) {
        matrix[j] = new int[size];
    }
    
	// setting all edge values equal to zero
	for(int i = 0; i < size; i++) {
		for(int j = 0; j < size; j++) {
			matrix[i][j] = 0;
		}
	}
	
	// read the data for edges from the file
	while(getline(inFile, line)) {
		stringstream s(line);
		getline(s, tT, ',');
		getline(s, tH, ',');
		
		// convert a & b vertex index to int
		t = stoi(tT);
		h = stoi(tH);
		
		// insert edge into the Digraph
		addEdge(t, h);
	}
	
	// initialize visited variable
	visited = new bool[size];
}

// copy constructor
Digraph::Digraph(const Digraph &orig)
{
    size = orig.size;
    matrix = dCopy(orig.matrix, size);
	visited = new bool[size];
	
}

// deep copy
int** Digraph::dCopy(int** matrix,int size) {
    int** tM = new int*[size]; // temporary matrix


    for(int j = 0; j < size; j++) {
        matrix[j] = new int[size]; // create an array for each index in the array
        for (int i = 0; i < size; size++) {
            tM[j][i] = matrix[j][i]; // set each index in the tM to match the value of matrix
        }
    }

    return tM;
}


// destructor
Digraph::~Digraph()
{
	// delete all pointers
	for(int i = 0; i < size; i++) {
        delete [] matrix[i];
	}
	delete [] matrix;
}



void Digraph::addEdge(int a, int b)
{
	// make sure vertices a and b exist is Digraph, are not already an edge, and not the same vertex
	// if true, then add edge
	if (size > a && size > b && 0 <= a  && 0 <= b && !matrix[a][b] && !(a==b))
		matrix[a][b] = 1;
}

void Digraph::display() const
{
	// for each vertex, list the 0's and 1's
    cout << "Original graph:\n";
    for (int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

}

void Digraph::displayDFS(int vertex) {
    // visited array is always false at the start of the program call
    for (int i = 0; i < size; i++) {
        visited[i] = false;
    }

    if (vertex < size && 0 <= vertex) {// check if valid vertex was inputted

        cout << "DFS visit order starting at " << vertex << ":" << endl;
        recursiveDFS(vertex);

        cout << endl;
    }

}

void Digraph::recursiveDFS(int vertex)
{
    // check base case (this vertex has no neighbors or all neighbors have been visited)
    int sumV = 0;
    for (int i = 0; i < size; i++) {
        if(!visited[i])
            sumV+=matrix[vertex][i];
    }
    if (!sumV)
        return;

    for(int j = 0; j < size; j++) {
        if (matrix[vertex][j] && !visited[j]) { // if j is a neighbor of i and has not been visited
            visited[j] = true; // put j vertex in visited list
            cout << j << " "; // print j vertex
            recursiveDFS(j); // visit j vertex
        }
    }
}

Digraph& Digraph::createBFS(int vertex) // use deque
{


    // set all visited elements to false
    for (int i = 0; i < size; i++){
        visited[i] = false;
    }


    Digraph *tD = new Digraph(size); //  temporary Digraph

    if (vertex > size && 0 <= vertex) { // check if valid vertex was inputted
        tD->matrix[0][0] = -1;
        return *tD;
    }

    visited[vertex] = true;
    cout << vertex << " ";

    // starting from vertex, use BFS
	deque <int> mydeque;
    mydeque.push_back (vertex);

    while (!mydeque.empty()) {
        int curV = mydeque.front(); // store current vertex

        // pop visited vertex (current vertex) from mydeque
        mydeque.pop_front();

        for (int i = 0; i < size; i++) { // check which vertices curV points to
            if (matrix[curV][i] && !visited[i]) {
                mydeque.push_back (i); // push curV neighbors that haven't been visited onto the back of mydeque
                visited[i] = true;
                cout << i << " ";
                tD->addEdge(curV, i); // add edge from curV to i to spanning tree
            }
        }
    }

    return *tD;
}

int Digraph::inDegree(int i) const
{
    int IC = 0; // counts in degrees
	if(i < size && i >= 0) { // make sure i is valid vertex
		for (int j = 0; j < size; j++) { // check column i for 1's
			if (matrix[j][i]) // if a 1 is found in column j, IC++
				IC++;
		}
	} else {
        return -1;
    }

    return IC;
}

