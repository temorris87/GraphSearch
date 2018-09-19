//
// Created by tyson on 9/15/18.
//

#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <queue>

#include "Graph.h"

Graph::Graph (int n) {
    total_nodes = n;
    for (int i = 0; i < n; i++) {
        node temp;
        temp.id = i;
        temp.parent = nullptr;
        temp.cost = 0;
        temp.in_fringe = false;
        nodes.push_back(temp);
    }
};

void Graph::add_edge(int n, int to_node, double weight) {
    edge temp;
    temp.from_node = n;
    temp.to_node = to_node;
    temp.weight = weight;

    nodes[n].edges.push_front(temp);
}

void Graph::add_node_to_fringe(node * n) {
    fringe.push(n);
}

void Graph::empty_fringe() {
    while (fringe_has_nodes()) {
        get_node_from_fringe();
    }

    for (int i = 0; i < total_nodes; i++)
        nodes[i].in_fringe = false;
}

node * Graph::get_node_from_fringe() {
    node * n = nullptr;

    while (fringe_has_nodes()) {
        n = fringe.top();
        fringe.pop();
        if (not n->in_closed)
            return n;
    }

    return n;
}

bool Graph::fringe_has_nodes() {
    return fringe.size() != 0;
}

void Graph::remove_all_nodes_from_closed() {
    for (int i = 0; i < total_nodes; i++) {
        nodes[i].in_closed = false;
    }
}

std::forward_list<int> * Graph::astar(int start_node, int end_node) {
    nodes[start_node].cost = 0;
    nodes[start_node].parent = &nodes[start_node];
    empty_fringe();
    nodes[start_node].cost = heuristic_cost(start_node, end_node);
    add_node_to_fringe(&nodes[start_node]);
    remove_all_nodes_from_closed();

    while (fringe_has_nodes()) {
        node * s = get_node_from_fringe();
        if (s == &nodes[end_node]) {
            return build_path(&nodes[start_node], &nodes[end_node]);
        }
        s->in_closed = true;
        for (auto it = s->edges.begin(); it != s->edges.end(); it++) {
            if (not nodes[it->to_node].in_closed) {
                if (not nodes[it->to_node].in_fringe) {
                    nodes[it->to_node].cost = std::numeric_limits<double>::infinity();
                    nodes[it->to_node].parent = nullptr;
                }
                update_vertex(&nodes[it->from_node], &nodes[it->to_node], &nodes[end_node], *it);
            }
        }
    }

    return nullptr;
}

void Graph::update_vertex(node * s, node * t, node * goal, edge e) {
    double h_cost = heuristic_cost(t->id, goal->id);
    if (s->cost + e.weight + h_cost < t->cost) {
        t->cost = s->cost + e.weight + h_cost;
        t->parent = s;
        add_node_to_fringe(t);
    }
}

std::forward_list<int> * Graph::build_path(node * start_node, node * end_node) {
    std::forward_list<int> * path = new std::forward_list<int>;
    node * temp = end_node;

    while (temp != start_node) {
        path->push_front(temp->id);
        temp = temp->parent;
    }

    path->push_front(temp->id);

    return path;
}

void Graph::set_coordinates(int s_id, int x, int y) {
    nodes[s_id].x = x;
    nodes[s_id].y = y;
}

double Graph::heuristic_cost(int s_id, int t_id) {
    return sqrt(std::pow(nodes[s_id].x - nodes[t_id].x, 2) + std::pow(nodes[s_id].y - nodes[t_id].y, 2));
}

void Graph::print_graph() {
    for (auto it_node = nodes.begin(); it_node != nodes.end(); it_node++) {
        std::cout << "Node " << it_node->id << ": ";
        for (auto it_edge = it_node->edges.begin(); it_edge != it_node->edges.end(); it_edge++) {
            std::cout << it_edge->to_node << " ";
        }
        std::cout << std::endl;
    }
}

void Graph::print_graph_with_weights() {
    for (auto it_node = nodes.begin(); it_node != nodes.end(); it_node++) {
        std::cout << "Node " << it_node->id << ": ";
        for (auto it_edge = it_node->edges.begin(); it_edge != it_node->edges.end(); it_edge++) {
            std::cout << "(" << it_edge->to_node << ", " << it_edge->weight << ") ";
        }
        std::cout << std::endl;
    }
}

