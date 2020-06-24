//.cpp file for function findPathDFSStack()
//@author Vanessa Hadlock
//@date June 22nd, 2020
//@brief Project 4

#include "findPathDFSStack.h"
#include "maze.h"
#include <vector>
#include <stack>
#include<bits/stdc++.h> 

using namespace std;


/* Public member function of maze called findPathDFSStack() that takes in the starting vertice
 * and the goal vertice using depth first search iteratively with a stack. The algorithm creates
 * a stack of the nodes and an array of the visited nodes to keep track. It then inserts the start
 * node into the stakck and runs the while node s is not equal to the goal node. The element from
 * the stack is oppped and printed if it has not been visited yet. A for loop runs to mark every
 * adjacent and unvisited node of the current nodes and insert it into the stack.
 * @param       int start, int goal - the starting and ending vertices of the maze
 * @return      none
 */

void maze::findPathDFSStack(int start, int goal) {

    //initially mark all the vertices in the maze as not visited
    vector<bool> visited(V, false);

    //Create a stack for iterative Depth First Search

    stack<int> stack;

    //push the source node into the stack

    stack.push(start);

    //while the stack is still not empty//

    while (s != goal) {

        //Pop a vertex from the stack

        start = stack.top();
        stack.pop();

        //if the vertex is already discovered, then ignore it
        //Only need to print the popped item if it is not visited 
        if (!visited[start]) {

            cout << start << " ";
            visited[start] = true;
        }

        //Get all the adjacent vertices of the popped starting vertex 
        //If an adjacent has not net been visited, then push it to the stack

        for (auto i = adj[start].begin(); i != adj[start].end(); ++i)
            if (!visited[*i])
                stack.push(*i);
    }
}