//Class notes from 4/17/2023 regarding Graph Traversal
//This file contains pseudocode versions of common graph algorithms.
#include <iostream>
#include <queue> //for std::priority_queue
using namespace std;
//Depth-First Search
//Go "all the way down each road" before checking closer vertices
//Recursive solution, using an implicit stack
int depthFirstSearch(int v)
{
    /*
    Let V be a set                          //Alternatively, V can be a Boolean array of size(numVertices)
    V.add(v)                                //V lists the vertices that have been visited already.
    for all edges leaving v to w do
        if vertex w is not in V then 
            recursively call depthFirstSearch(w)
    */
}
//Iterative solution, using an explicit stack
int depthFirstSearch(int v)
{
    /*
    Let V be a set                          //V = "visited"
    Let T be a stack                        //T = "to-do"
    T.push(v)
    while not empty(T) do
        v = T.pop()
        if v is not in V then
            V.add(v)
            for all edges leaving v to w do
                T.push(w)
    */
}

//Breadth-First Search
//Check vertices in first in, first out
//Iterative solution. Identical to DFS, but uses a queue
int breadthFirstSearch(int v)
{
    /*
    Let V be a set                          //V = "visited"
    Let T be a queue                        //T = "to-do"
    T.push(v)
    while not empty(T) do
        v = T.pop()
        if v is not in V then
            V.add(v)
            for all edges leaving v to w do
                T.push(w)
    */
}

//Minimum Spanning Tree
//Identical to BFS, but uses a minimum-edge cost priority queue
//Traverse array by following along lowest cost edges 
int minimumSpanningTree(int v)
{
    /*
    Let V be a set                          //V = "visited"
    Let T be a priority queue               //T = "to-do"
    T.push(v)                               //priority queue needs to be used "backwards" to return smallest cost first
    while some v is not in V do
        v = T.pop()
        if v is not in V then
            V.add(v)
            for all edges leaving v to w do
                T.push(v-w edge cost)
    */
}

//(Single-source) Shortest Path
//Prioritize shortest path by tracking distance between vertices
int shortestPath(int v)
{
   /*
    Let D be an array/map with initial values of (infinity)
    D[v] = 0
    Let T be a priority queue               //T = "to-do"
    T.push(v)                               //priority queue needs to be used "backwards" to return smallest cost first
    while some v is not in V do
        v = T.pop()
        if v is not in V then
            V.add(v)
            for all edges leaving v to w do
                
                if d = D[w]
                    D[w] = d
                T.push(v-w edge cost)
    */
}
