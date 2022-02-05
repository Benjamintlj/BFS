#include "BreadthFirstSearch.h"

int main() {
    BreadthFirstSearch<int> bfs;


/*
 *  1 ---- 0
 *  |      |
 *  3 ---- 2
 *  |
 *  4 ---- 5
*/

    // level 1
    bfs.bidirectionalNewNode(0, 1);
    bfs.bidirectionalNewNode(0, 2);

    // level 2
    bfs.bidirectionalNewNode(1, 3);
    bfs.bidirectionalNewNode(2, 3);

    // level 3
    bfs.bidirectionalNewNode(3, 4);

    // level 4
    bfs.bidirectionalNewNode(4, 5);



    // search
    bfs.search(5,0);
}
