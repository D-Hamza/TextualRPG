#pragma once
#include<string>
#include<sstream>
#include "Vertex.h"
#include "Pair.h"
/*
template representing an edge in a graph
Typename T represents the data type stored in vertices
Typename U represents the data type stored in edges
*/
template <typename T, typename U>
class Edge
{
protected:
	// Pair of vertices represents the edge.
	// The first memeber of the pair is the initial vertex of the edge
	// The second memeber of the pair is the terminal vertex of the edge
	Pair<Vertex<T>, Vertex<T>>* theEdge;

	// Edgeweight parameter. Can be used to represent distance
	// between vertice, etc.
	double edgeWeight;

	// Pointer to data stored in this edge
	U* data;

public:
	// creates an edge with the given intial and terminal vertices
	// The edge contains no data. The default edge weight is one.
	Edge(Vertex<T>* initialVertex, Vertex<T>* terminalVertex) {
		this->theEdge = new Pair<Vertex<T>, Vertex<T>>(initialVertex, terminalVertex);
		this->edgeWeight = 1;
		this->data = nullptr;
	}

	// get the data
	U* getData() {
		return this->data;
	}

	// set the data
	void setData(U* data) {
		this->data = data;
	}

	// peek at the intial vertex value
	Vertex<T>* getInitialVertex() {
		return this->theEdge->first;
	}

	// peek at the terminal vertex value
	Vertex<T>* getTerminalVertex() {
		return this->theEdge->second;
	}

	// get the edgeWeight
	double getEdgeWeight() {
		return this->edgeWeight;
	}

	// set the edgeWeight
	void setEdgeWeight(double weight) {
		this->edgeWeight = weight;
	}

	// check to see if the intial vertex equals the terminal vertex.
	// if it does return true
	// if not return false
	bool isLoop() {
		if (this->theEdge->first == this->theEdge->second) {
			return true;
		}
		else {
			return false;
		}
	}

	// print out information about the Edge class
	std::string toString() {
		std::ostringstream sout;
		sout << "Edge at: " << this << std::endl;
		sout << "Initial Vertex at: " << getInitialVertex() << std::endl;
		sout << "Terminal Vertex at: " << getTerminalVertex() << std::endl;
		sout << "Current Edge Weight is: " << this->edgeWeight << std::endl;
		sout << "Data stored at: " << this->data << std::endl;
		return sout.str();
	}



};

/*
	overloading == as a non-member function
*/
template <typename T, typename U>
bool operator==(Edge<T, U>& lhs, Edge<T, U>& rhs) {
	// check to see if the edges have the same terminal, intial, and data pointers 
	// as well as the same edge weight; if so return true
	if ((lhs.getTerminalVertex() == rhs.getTerminalVertex()) && (lhs.getInitialVertex() == rhs.getInitialVertex()) && (lhs.getEdgeWeight() == rhs.getEdgeWeight()) && (lhs.getData() == rhs.getData())) {
		return true;

	}
	else {
		return false;
	}
}


/*
	overloading != as a non-member function
*/
template <typename T, typename U>
bool operator!=(Edge<T, U>& lhs, Edge<T, U>& rhs) {
	return !(lhs == rhs);
}



