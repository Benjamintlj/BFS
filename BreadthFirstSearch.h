//
// Created by Benjamin Lewis-Jones on 05/02/2022.
//

#ifndef BFS_BREADTHFIRSTSEARCH_H
#define BFS_BREADTHFIRSTSEARCH_H

//////////////////////////////////////////////////////////////////
// dependencies
#include <list>
#include <map>
#include <queue>
#include <iostream>

using namespace std;

//////////////////////////////////////////////////////////////////
// class definition

template<typename T>
class BreadthFirstSearch {

    // attributes
private:
    map<T, list<T>> mapOfNodes;


    // methods
public:
    // adds a new bidirectional node
    void bidirectionalNewNode(T primary, T secondary);

    // searches all nodes for a given value, from a sourceNode
    void search(T value, T sourceNode);
};



//////////////////////////////////////////////////////////////////
// template definitions



template<typename T>
void BreadthFirstSearch<T>::bidirectionalNewNode(T primary, T secondary) {
    mapOfNodes[primary].push_back(secondary);
    mapOfNodes[secondary].push_back(primary);
}



template<typename T>
void BreadthFirstSearch<T>::search(T value, T sourceNode) {

    // check that source node is the value
    if(sourceNode == value) {
        cout << "value exists" << endl;
        return;
    }

    // vars
    map<T, bool> visited;
    queue<T> nextNode;

    // push source node onto the queue
    nextNode.push(sourceNode);
    visited[sourceNode] = true;

    // loop while not at the end of the nodes
    while(!nextNode.empty()) {

        // pop the current node
        T currentNode = nextNode.front();
        nextNode.pop();

        cout << currentNode << endl;

        // loop through all neightbour nodes
        for(auto neighbour : mapOfNodes[currentNode]) {

            // if neighbour has not been visited
            if (!visited[neighbour]) {
                // check if neighbour is the value
                if(neighbour == value) {
                    cout << "value exists" << endl;
                    return;
                }

                // push the unvisited neighbour into the queue
                nextNode.push(neighbour);
                visited[neighbour] = true;
            }
        }
    }
}


#endif //BFS_BREADTHFIRSTSEARCH_H
