#pragma once

#include <sstream>
#include <string>
#include <typeinfo>
#include <cmath>

#include "Vertex.h"
#include "Edge.h"

/*
A templated class to represent directed graphs. The vertices of the graph can
store pointers to data of type T, and the edges of the graph can store pointers
to data of type U.
*/
template <typename T, typename U>
class Graph {

protected:

	/*
	This list contains the vertices that are part of this graph.
	*/
	List<Vertex<T>>* vertices;

	/*
	This list contains the edges that are part of this graph.
	*/
	List<Edge<T, U>>* edges;

public:

	/*
	Creates an empty graph: no vertices (and therefore no edges)
	*/
	Graph() {
		this->vertices = new List<Vertex<T>>();
		this->edges = new List<Edge<T, U>>();
	}

	/*
	Returns true if and only if this graph is empty.
	*/
	bool isEmpty() {
		if ((this->vertices->isEmpty()) && (this->edges->isEmpty())) {
			return true;
		}
		else {
			return false;
		}
	}

	/*
	Returns the number of vertices in this graph.
	*/
	int getNumVertices() {
		return this->vertices->getSize();
	}
	/*
	Returns a pointer to a list containing pointers to all the vertices in
	this graph.
	*/
	List<Vertex<T>>* getVertices() {
		return this->vertices;
	}

	/*
	Returns the number of edges in this graph.
	*/
	int getNumEdges() {
		return this->edges->getSize();
	}

	/*
	  Returns a pointer to a list containing pointers to all the edges in
	  this graph.
	   */
	List<Edge<T, U>>* getEdges() {
		return this->edges;
	}


	/*
	Returns the in-degree of the specified vertex, or a negative number if
	the specified vertex is not part of this graph.
	*/
	int getInDegree(Vertex<T>* vertex) {
		int index = this->vertices->getIndex(vertex);
		if (index < 0) {
			return -1;
		}
		else {
			return this->vertex->getInDegree();
		}


	}

	/*
	Returns the out-degree of the specified vertex, or a negative number if
	the specified vertex is not part of this graph.
	*/
	int getOutDegree(Vertex<T>* vertex) {
		int index = this->vertices->getIndex(vertex);
		if (index < 0) {
			return -1;
		}
		else {
			return this->vertex->getOutDegree();
		}
	}

	/*
	Returns a pointer to the vertex with the given index. If no vertex has
	the given index, this method returns the null pointer.
	*/
	Vertex<T>* getVertex(int index) {
		return this->vertices->peek(index);
	}

	/*
	Adds the specified vertex to this graph. Vertices can't be added more than
	once, so if the specified vertex is already part of this graph, this method
	does nothing.
	*/
	void addVertex(Vertex<T>* vertex) {
		int index = this->vertices->getIndex(vertex);
		if (index < 0) {
			this->vertices->insertAtEnd(vertex);
		}

	}

	/*
	Returns true if and only if the specified vertex is part of this graph.
	*/
	bool hasVertex(Vertex<T>* vertex) {
		int index = this->vertices->getIndex(vertex);
		if (index >= 0) {
			return true;
		}
		else {
			return false;
		}

	}

	/*
	Adds a directed edge to this graph, from the "from" vertex to the "to"
	vertex, provided that edge does not already exist. If an edge already
	exists in this graph from the "from" vertex to the "to" vertex, this
	method does nothing. If either of the two input vertices are not already
	part of this graph, they are added. If the "from" and "to" vertices are
	identical, a loop is added to that vertex.
	*/
	void addEdge(Vertex<T>* fromVertex, Vertex<T>* toVertex) {
		//// create an Edge from the specified vertices to see whether this edge
		//// is already part of the graph
		//// returns a negative number if newEdge is not part of this graph
		//int edgeNdx = this->edges->getIndex(newEdge);
		int edgeNdx = -1;
		for (int k = 0; k < this->edges->getSize(); k++) {
			Edge<T, U>* edgeK = this->edges->peek(k);
			if (edgeK->getInitialVertex() == fromVertex && edgeK->getTerminalVertex() == toVertex) {
				edgeNdx = k;
				break;
			}
		}
		// if this edge is already in the graph, do nothing. Otherwise:
		if (edgeNdx < 0) {
			Edge<T, U>* newEdge = new Edge<T, U>(fromVertex, toVertex);
			// need to handle a special case: if the from and to vertices
			// are actually the same, then we're adding a edge from that
			// vertex to itself. Otherwise, we're adding an edge between
			// different vertices
			if (fromVertex == toVertex) {
				// get the indices for the from node (which is the same as
				// the to node). If getIndex returns a negative number, it
				// means that the corresponding vertex is not a member of
				// this graph.
				int fromNdx = this->vertices->getIndex(fromVertex);
				// if the vertex is not in the graph, add it
				if (fromNdx < 0) {
					this->vertices->insertAtEnd(fromVertex);
				}
				// add the new edge to this graph
				this->edges->insertAtEnd(newEdge);
				// manage previousNodes and nextNodes. Since the edge goes
				// from a vertex to itself, the vertex is both an incoming
				// and outgoing vertex of itself.
				fromVertex->addOutVertex(fromVertex);
			}
			else {
				// get the indices for the from and to nodes. If getIndex returns
				// a negative number, it means that the corresponding vertex is
				// not a member of this graph.
				int fromNdx = this->vertices->getIndex(fromVertex);
				int toNdx = this->vertices->getIndex(toVertex);
				// if the from vertex is not in the graph, add it
				if (fromNdx < 0) {
					this->vertices->insertAtEnd(fromVertex);
				}
				// if the to vertex is not in the graph, add it
				if (toNdx < 0) {
					this->vertices->insertAtEnd(toVertex);
				}
				// add the new edge to this graph
				this->edges->insertAtEnd(newEdge);
				// manage previousNodes and nextNodes
				fromVertex->addOutVertex(toVertex);
			}
		}
	}


	/*
	Returns true if and only if this graph contains an edge from the "from"
	vertex to the "to" vertex.
	*/
	bool hasEdge(Vertex<T>* from, Vertex<T>* to) {
		Edge<T, U>* holder = new Edge<T, U>(from, to);
		//// TO DO: want to compare holder to edgeWeight, data, and intial/terminsl vertices
		//int edgeIndex = this->edges->getIndex(holder);
		//if (edgeIndex >= 0) {
		//	// TO DO: add comparison for edgeWeight, data, intial/terminal vertices
		//	return true;
		//}
		//else {
		//	return false;
		//}
		bool result = false;
		for (int k = 0; k < this->edges->getSize(); k++) {
			Edge<T, U>* ek = this->edges->peek(k);
			if (*holder == *ek) {
				result = true;
				break;
			}
		}
		return result;
	}

	/*
	Returns a list of the outgoing vertices from the specified vertex. If the
	specified vertex is not part of list.
	*/
	List<Vertex<T>>* getOutgoingVertices(Vertex<T>* vertex) {
		int index = this->vertices->getIndex(vertex);
		if (index >= 0) {
			List<Vertex<T>>* r = new List<Vertex<T>>();
			int degree = vertex->getOutDegree();
			for (int k = 0; k < degree; k++) {
				r->insertAtEnd(vertex->getOutVertex(k));

			}
			return r;
		}
		else {
			List<Vertex<T>>* n = new List<Vertex<T>>();
			return n;
		}
	}

	/*
	Returns a list of the incoming vertices form the specified vertex. If the
	specified vertex is not part of this graph, this method returns the empty
	list.
	*/
	List<Vertex<T>>* getIncomingVertices(Vertex<T>* vertex) {
		int index = this->vertices->getIndex(vertex);
		if (index != -1) {
			List<Vertex<T>>* r = new List<Vertex<T>>();
			int degree = vertex->getInDegree();
			for (int k = 0; k < degree; k++) {
				r->insertAtEnd(vertex->getInVertex(k));
			}
			return r;
		}
		else {
			List<Vertex<T>>* n = new List<Vertex<T>>();
			return n;
		}
	}

	/*
		Returns the weight of the specified edge. If the specified edge is not
		part of this graph, this method returns NaN (not a number) as a double.
	*/
	double getEdgeWeight(Vertex<T>* from, Vertex<T>* to) {
		Edge<T, U>* newEdge = new Edge<T, U>(from, to);
		if (hasEdge(newEdge) == true) {
			double weight = newEdge->getEdgeWeight();
			return weight;
		}
		else {
			double weight = std::nan("");
			return weight;
		}

	}

	/*
	Returns the weight of the edge with the given index. If no edge in this
	graph has the given index, this method returns NaN (not a number) as a
	double.
	*/
	double getEdgeWeight(int index) {
		Edge<T, U>* newEdge = this->edges->peek(index);
		if (hasEdge(newEdge) == true) {
			double weight = newEdge->getEdgeWeight();
			return weight;
		}
		else {
			double weight = std::nan("");
			return weight;
		}
	}

	/*
	Sets the weight of the specified edge. If the specified edge is not
	part of this graph, this method does nothing. If the set operation is
	successful this method returns 0. If it is unsuccessful it returns a
	negative number.
	*/
	int setEdgeWeight(double weight, Vertex<T>* from, Vertex<T>* to) {
		int result = -1;
		Edge<T, U>* newEdge = new Edge<T, U>(from, to);
		bool holder = hasEdge(from, to);
		/*	if (holder == true) {
				newEdge->setEdgeWeight(weight);
			}*/
		for (int k = 0; k < this->edges->getSize(); k++) {
			Edge<T, U>* ek = this->edges->peek(k);
			if (*newEdge == *ek) {
				ek->setEdgeWeight(weight);
				if (ek->getEdgeWeight() == weight) {
					result = 0;
					break;
				}
			}

		}
		return result;

	}

	/*
	Sets the weight of the edge with the given index. If no edge in this
	graph has the given index, this method does nothing. If the set
	operation is successful this method returns 0. If it is unsuccessful
	it returns a negative number.
	*/
	int setEdgeWeight(double weight, int index) {
		Edge<T, U>* newEdge = this->edges->peek(index);
		if (index > 0) {
			newEdge->setEdgeWeight(weight);
			if (weight == newEdge->getEdgeWeight()) {
				return 0;
			}
			else {
				return -1;
			}
		}
	}

	/*
	Stores the specified data in the specified vertex of this graph. If the
	specified vertex is not in this graph, then this method does nothing. If
	the store operation is successful, this method returns 0. If it is
	unsuccessful, this method returns a negative number.
	*/
	int storeInVertex(T* data, Vertex<T>* vertex) {
		if (hasVertex(vertex) == true) {
			vertex->setData(data);
			if (data == vertex->getData()) {
				return 0;
			}
			else {
				return -1;
			}

		}
		else {
			return -1;
		}
	}

	/*
	Stores the specified data in the vertex of this graph with the specified
	index. If no vertex of this graph has the specified index, this method
	does nothing.If the store operation is successful, this method returns 0.
	If it is unsuccessful, this method returns a negative number.
	*/
	int storeInVertex(T* data, int index) {
		Vertex<T>* holder = this->vertices->peek(index);
		holder->setData(data);
		if (data == holder->getData()) {
			return 0;
		}
		else {
			return -1;
		}
	}

	/*
	Retrieves a pointer to the data that is stored in the specified vertex.
	If the specified vertex is not part of this graph, or if there is no data
	stored in the vertex, this method returns the null pointer.
	*/
	T* getVertexData(Vertex<T>* vertex) {
		if (hasVertex(vertex) == true) {
			return vertex->getData();
		}
		else {
			return nullptr;
		}

	}

	/*
	Retrieves a pointer to the data that is stored in the vertex with the
	specified index. If no vertex of this graph has the specified index, or
	if there is no data stored in the vertex, this method returns the null
	pointer.
	*/
	T* getVertexData(int index) {
		Vertex<T>* holder = this->vertices->peek(index);
		if (hasVertex(holder) == true) {
			return holder->getData();
		}
		else {
			return nullptr;
		}

	}

	/*
	Stores the specified data in the specified edge of this graph. If the
	specified edge is not in this graph, then this method does nothing. If
	the store operation is successful, this method returns 0. If it is
	unsuccessful, this method returns a negative number.
	*/
	int storeInEdge(U* data, Vertex<T>* from, Vertex<T>* to) {
		int position = getEdgeIndex(from, to);
		this->edges->peek(position)->setData(data);
		if (data == this->edges->peek(position)->getData()) {
			return 0;
		}
		else {
			return -1;
		}
	}

	/*
	Stores the specified data in the the edge of this graph with the specified
	index. If no edge of this graph has the specified index, this method does
	nothing. If the store operation is successful, this method returns 0. If it
	is unsuccessful, this method returns a negative number.
	*/
	int storeInEdge(U* data, int index) {
		this->edges->peek(index)->setData(data);
		if (data == this->edges->peek(index)->getData()) {
			return 0;
		}
		else {
			return -1;
		}

	}

	/*
	Retrieves a pointer to the data that is stored in the specified edge.
	If the specified edge is not part of this graph, or if there is no data
	stored in the edge, this method returns the null pointer.
	*/
	U* getEdgeData(Vertex<T>* from, Vertex<T>* to) {

		U* result;
		int position = getEdgeIndex(from, to);
		if (position >= 0) {
			result = this->edges->peek(position)->getData();
		}
		else
		{
			result = nullptr;
		}
		return result;
	}

	/*
	Retrieves a pointer to the data that is stored in the edge with the
	specified index. If no edge of this graph has the specified index, or
	if there is no data stored in the edge, this method returns the null
	pointer.
	*/
	U* getEdgeData(int index) {
		if (index >= 0) {
			return this->edges->peek(index)->getData();
		}
		else {
			return nullptr;
		}



	}

	/*
	   Returns the index of the specified vertex in this graph. If the specified
	   vertex is not part of this graph, this method returns a negative number.
	   */
	int getVertexIndex(Vertex<T>* vertex) {
		int index = this->vertices->getIndex(vertex);
		return index;
	}

	/*
	Returns the index of the specified edge in this graph. If the specified
	edge is not part of this graph, this method returns a negative number.
	*/
	int getEdgeIndex(Vertex<T>* from, Vertex<T>* to) {
		int index = -1;
		for (int k = 0; k < this->edges->getSize(); k++) {
			Edge<T, U>* edgeK = this->edges->peek(k);
			if (edgeK->getInitialVertex() == from && edgeK->getTerminalVertex() == to) {
				index = k;
				break;
			}
		}
		return index;
	}

	/*
	Returns a string representation of this graph.
	*/
	std::string toString() {
		std::ostringstream sout;
		sout << "Graph at: " << this << std::endl;
		sout << "Edges at: " << this->edges << std::endl;
		sout << "Vertices at: " << this->vertices << std::endl;
		sout << "Number of vertices: " << this->getNumVertices() << std::endl;
		sout << "Number of edges: " << this->getNumEdges() << std::endl;
		sout << "Storing data of type: " << typeid(T).name() << " in vertices" << std::endl;
		sout << "Storing data of type: " << typeid(U).name() << " in edges" << std::endl;
		return sout.str();
	}

};