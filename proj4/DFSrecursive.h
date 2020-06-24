#include <iostream>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/graphviz.hpp>
#include <boost/graph/properties.hpp>
#include <boost/property_map/property_map.hpp>
#include <boost/graph/named_function_params.hpp>
#include <boost/graph/depth_first_search.hpp>
#include "maze.h"

#ifndef DFSrecursive_H
#define DFSrecursive_H

using namespace boost;
template < typename TimeMap >
//define the visitor for DFS
class dfs_time_visitor : public default_dfs_visitor
{
    typedef typename property_traits< TimeMap >::value_type T;

public:
    dfs_time_visitor(TimeMap dmap, TimeMap fmap, T& t)
        : m_dtimemap(dmap), m_ftimemap(fmap), m_time(t)
    {
    }
    template < typename Vertex, typename Graph >
    void discover_vertex(Vertex u, const Graph& g) const
    {
        put(m_dtimemap, u, m_time++);
    }
    template < typename Vertex, typename Graph >
    void finish_vertex(Vertex u, const Graph& g) const
    {
        put(m_ftimemap, u, m_time++);
    }
    TimeMap m_dtimemap;
    TimeMap m_ftimemap;
    T& m_time;
};








#endif