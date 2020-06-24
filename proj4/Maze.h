#include <iostream>
#include <limits.h>
#include <list>
#include <fstream>
#include <queue>
#include <vector>
#include <stack>
#include <boost/graph/adjacency_list.hpp>

#include "d_except.h"
#include "d_matrix.h"

#define LargeValue 99999999

using namespace std;
using namespace boost;

class maze
{
public:
    maze(ifstream& fin);
    void print(int, int, int, int);
    bool isLegal(int i, int j);
    void mapMazeToGraph(Graph& g);
    void printPath(Graph::vertex_descriptor end,
        stack<Graph::vertex_descriptor>& s,
        Graph g);
    int numRows() { return rows; };
    int numCols() { return cols; };

private:
    int rows; // number of rows in the maze
    int cols; // number of columns in the maze12 a

    matrix<bool> value;
};

maze::maze(ifstream& fin)
// Initializes a maze by reading values from fin.  Assumes that the
// number of rows and columns indicated in the file are correct.
{
    fin >> rows;
    fin >> cols;

    char x;

    value.resize(rows, cols);
    for (int i = 0; i <= rows - 1; i++)
        for (int j = 0; j <= cols - 1; j++)
        {
            fin >> x;
            if (x == 'O')
                value[i][j] = true;
            else
                value[i][j] = false;
        }

}

void maze::print(int goalI, int goalJ, int currI, int currJ)
// Print out a maze, with the goal and current cells marked on the
// board.
{
    cout << endl;

    if (goalI < 0 || goalI > rows || goalJ < 0 || goalJ > cols)
        throw rangeError("Bad value in maze::print");

    if (currI < 0 || currI > rows || currJ < 0 || currJ > cols)
        throw rangeError("Bad value in maze::print");

    for (int i = 0; i <= rows - 1; i++)
    {
        for (int j = 0; j <= cols - 1; j++)
        {
            if (i == goalI && j == goalJ)
                cout << "*";
            else
                if (i == currI && j == currJ)
                    cout << "+";
                else
                    if (value[i][j])
                        cout << " ";
                    else
                        cout << "X";
        }
        cout << endl;
    }
    cout << endl;
}

bool maze::isLegal(int i, int j)
// Return the value stored at the (i,j) entry in the maze, indicating
// whether it is legal to go to cell (i,j).
{
    if (i < 0 || i > rows || j < 0 || j > cols)
        throw rangeError("Bad value in maze::isLegal");

    return value[i][j];
}

void maze::mapMazeToGraph(Graph& g)
// Create a graph g that represents the legal moves in the maze m.
{
    //int numEdges = num_edges(g);
    Graph::vertex_descriptor u;
    Graph::vertex_descriptor v;
    std::vector<int> node;
    // Loop over all nodes in the graph 
    for (Graph::vertex_iterator vItr = vItrRange.first; vItr != vItrRange.second; ++vItr) {
        node(u, v) = maze::isLegal(int i, int j)

            // Add an edge (u,v) to the graph. newEdge.first is the edge descriptor for the 
            // new edge. newEdge.second is true if the edge didn't already exist, and false otherwise 
            pair<Graph::edge_descriptor, bool> newEdge = add_edge(Graph::vertex_descriptor u, Graph::vertex_descriptor v, Graph & g);
    }

}

// Prints the path represented by the vertices in stack s. Repeatedly calls print() to show each step of the path
void maze::printPath(Graph::vertex_descriptor end, stack<Graph::vertex_descriptor>& s, Graph g)
{
    for (stack << Graph::vertex_descriptor > & s = 0; Graph::vertex_descriptor > & s < Graph::vertex_descriptor> & end; s++) {
        print(Graph::vertex_descriptor);
    }
}

//Mark all nodes in g as not visited.
void maze::clearVisited(Graph& g)
{
    int v = 0;
    // Loop over all nodes in the graph 
    for (Graph::vertex_iterator vItr = vItrRange.first; vItr != vItrRange.second; ++vItr) {
        // Access a property of a node 
        g[v].visited = false;
    }
}

// Set all node weights to w
void maze::setNodeWeights(Graph& g, int w)
{
    // Loop over all nodes in the graph 
    for (Graph::vertex_iterator vItr = vItrRange.first; vItr != vItrRange.second; ++vItr) {
        //put the weight as w, the parameter passed
        boost::put(boost::node_weight_t(), g, ed.first, w);
    }
}

// Unmark all nodes.
void maze::clearMarked(Graph& g)
{
    for (Graph::vertex_iterator vItr = vItrRange.first; vItr != vItrRange.second; ++vItr) {
        g[v].marked = false;
    }
}

// Output operator for the Graph class. Prints out all nodes and their properties, and all edges and their properties.
maze::ostream& operator<<(ostream& ostr, const Graph& g)
{
    // Loop over all nodes in the graph 
    for (Graph::vertex_iterator vItr = vItrRange.first; vItr != vItrRange.second; ++vItr) {
        print(g[v].visited);
        print(g.[v].weight);
    }
    // Loop over all edges in the graph 
    for (Graph::edge_iterator eItr = eItrRange.first; eItr != eItrRange.second; ++eItr) {
        print(g[e].visited); //prints the vistited property
        print(vertex_descriptor target(Graph::edge_descriptor e, Graph & g)); //Prints the target vertex of edge e. 
        print(vertex_descriptor source(Graph::edge_descriptor e, Graph & g)); //Prints the source vertex of edge e.
    }
}