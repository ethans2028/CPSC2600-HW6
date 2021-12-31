// NAME: Ethan Sue
// FILE: hw6.cpp
// DESCRIPTION: Tests Diagraph class

#include <iostream>
#include "digraph.h"

using namespace std;

int main()
{

    string fileName;
    char choice = 'y';

    // test size n constructor
    Digraph tempD(10);

    // test addEdge
    tempD.addEdge(3, 9); // yes
    tempD.addEdge(0, 6); // yes
    tempD.addEdge(-7, 8); // no
    tempD.addEdge(4, 10); // yes
    tempD.addEdge(3, 5); // yes
    tempD.addEdge(3, 9); // no
    tempD.addEdge(9, 5); // yes
    tempD.addEdge(7, 4); // yes
    tempD.addEdge(4, 7); // yes
    tempD.addEdge(1, 1); // no
    tempD.display();

    while (choice == 'y') {
        cout << "Input a test file: ";
        cin >> fileName;

        // test filename constructor
        Digraph d1(fileName);

        // test display
        d1.display();

        // test inDeg
        cout << "Deg-(" << 3 << ") = " << d1.inDegree(3) << endl;
        cout << "Deg-(" << 5 << ") = " << d1.inDegree(5) << endl;
        cout << "Deg-(" << 1000 << ") = " << d1.inDegree(1000) << endl;
        cout << "Deg-(" << -1 << ") = " << d1.inDegree(-1) << endl;
        cout << endl;

        // test copy constructor
        tempD = d1;
        cout << endl << "tempD = d1";
        tempD.display();

        // test displayDFS
        d1.displayDFS(0);
        d1.displayDFS(5);
        d1.displayDFS(10);
        d1.displayDFS(-1);

        // test createBFS
        Digraph d2 = d1.createBFS(0);
        d2.display();
        Digraph d3 = d1.createBFS(5);
        d2.display();
        Digraph d4 = d1.createBFS(10);
        d2.display();
        Digraph d5 = d1.createBFS(-1);
        d2.display();

        do {
            cout << "Choose another test file (y/n)? ";
            cin >> choice;
        } while(choice != 'y' && choice != 'n');
    }


}