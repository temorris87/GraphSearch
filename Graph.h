//
// Created by tyson on 9/15/18.
//

#ifndef INC_01_PATHPLANNING_GRAPH_H
#define INC_01_PATHPLANNING_GRAPH_H

#include <forward_list>
#include <queue>
#include <vector>

struct edge {
    int from_node;
    int to_node;
    double weight;
};

struct node {
    int id;
    int x;
    int y;
    std::forward_list<edge> edges;

    // For use with searching algorithms.
    struct node * parent;
    double cost;
    bool in_fringe;
    bool in_closed;
};

struct min_comparator {
    bool operator() (const node * n1, const node * n2) const {
        return n1->cost > n2->cost;
    }
};

class Graph {
    int total_nodes;
    std::vector<node> nodes;
    std::priority_queue<node*, std::vector<node*>, min_comparator> fringe;
public:
    Graph (int n);
    void add_edge(int n, int to_node, double weight);
    void add_node_to_fringe(node * n);
    void empty_fringe();
    node * get_node_from_fringe();
    bool fringe_has_nodes();
    std::forward_list<int> * astar(int start_node, int end_node);
    void update_vertex(node * s, node * t, node * goal, edge e);
    std::forward_list<int> * build_path(node * start_node, node * end_node);
    void remove_all_nodes_from_closed();
    void set_coordinates(int s_id, int x, int y);
    double heuristic_cost(int s_id, int t_id);
    void print_fringe();
    void print_graph();
    void print_graph_with_weights();

};

#endif //INC_01_PATHPLANNING_GRAPH_H
