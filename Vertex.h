#pragma once

#include <sstream>
#include <string>

#include "List.h"

/*
 A Vertex is a container that supports multiple previous nodes (called
 incoming vertices) and multiple next nodes (called outgoing vertices).
 */
template <typename T>
class Vertex {

protected:

    /*
     Pointer to the data stored in this vertex.
     */
    T* data;

    /*
     List of incoming vertices.
     */
    List<Vertex<T>>* previousNodes;

    /*
     List of outgoing vertices.
     */
    List<Vertex<T>>* nextNodes;

public:

    /*
     Creates an empty vertex: no data, no incoming nodes, no outgoing nodes.
     */
    Vertex() {
        this->data = nullptr;
        this->previousNodes = new List<Vertex<T>>();
        this->nextNodes = new List<Vertex<T>>();
    }

    /*
     Creates a vertex containing the specified data, but with no incoming or
     outgoing vertices.
     */
    Vertex(T* data) {
        this->data = data;
        this->previousNodes = new List<Vertex<T>>();
        this->nextNodes = new List<Vertex<T>>();
    }

    /*
     Returns a pointer to the data stored in this vertex.
     */
    T* getData() {
        return this->data;
    }

    /*
     Sets the data stored by this node to the specified value.
     */
    void setData(T* data) {
        this->data = data;
    }

    /*
     Returns the number of incoming vertices to this one.
     */
    int getInDegree() {
        return this->previousNodes->getSize();
    }

    /*
     Returns the number of outgoing vertices from this one.
     */
    int getOutDegree() {
        return this->nextNodes->getSize();
    }

    /*
     Returns true if and only if the specified vertex is an incoming vertex
     to this one.
     */
    bool hasInVertex(Vertex<T>* vertex) {
        int position = this->previousNodes->getIndex(vertex);
        if (position != -1) {
            this->previousNodes->peek(position);
            return true;
        }
        else {
            return false;
        }


    }

    /*
     Retrieves the incoming vertex with the specified index. Note that
     indices are assigned to incoming vertices in the order that they
     are added: the first incoming vertex added to this one has index
     0, the second has index 1, and so on.
     */
    Vertex<T>* getInVertex(int index) {
        return this->previousNodes->peek(index);
    }

    /*
     Adds the specified vertex to the list of incoming vertices to this
     vertex. Note that indices are assigned to incoming vertices in the
     order that they are added: the first incoming vertex added to this
     one has index 0, the second has index 1, and so on.
     */
    void addInVertex(Vertex<T>* inVertex) {
        int position = this->previousNodes->getIndex(inVertex);
        if (position != -1) {
            this->previousNodes->insertAtEnd(inVertex);
            inVertex->nextNodes->insertAtEnd(this);
        }


    }

    /*
     Removes the specified vertex from the list of incoming vertices to
     this one. Note that this will change the indices of subsequent
     incoming vertices.
     */
    T* removeInVertex(int index) {
        T* catchData = this->previousNodes->removeFromPosition(index);
        return catchData;
    }

    /*
     Returns true if and only if the specified vertex is an outgoing vertex
     from this one.
     */
    bool hasOutVertex(Vertex<T>* vertex) {
        int position = this->nextNodes->getIndex(vertex);
        if (position != -1) {
            this->nextNodes->peek(position);
            return true;
        }
        else {
            return false;
        }
    }

    /*
     Adds the specified vertex to the list of outgoing vertices to this
     vertex. Note that indices are assigned to outgoing vertices in the
     order that they are added: the first outgoing vertex added to this
     one has index 0, the second has index 1, and so on.
     */
    Vertex<T>* getOutVertex(int index) {
        Vertex<T>* holder = this->nextNodes->peek(index);
        return holder;
    }

    /*
     Adds the specified vertex to the list of outgoing vertices to this
     vertex. Note that indices are assigned to outgoing vertices in the
     order that they are added: the first outgoing vertex added to this
     one has index 0, the second has index 1, and so on.
     */
    void addOutVertex(Vertex<T>* outVertex) {
        int position = this->nextNodes->getIndex(outVertex);
        /*
        if position >= 0, outVertices is already an outgoing vertex, so
        we do nothing. Otherwise, we add the outVertex to our list
        of outgoing vertices.
        */
        if (position == -1) {
            this->nextNodes->insertAtEnd(outVertex);
            outVertex->previousNodes->insertAtEnd(this);
        }

    }

    /*
     Removes the specified vertex from the list of outgoing vertices to
     this one. Note that this will change the indices of subsequent
     outgoing vertices.
     */
    T* removeOutVertex(int index) {
        T* catchData = this->nextNodes->removeFromPosition(index);
        return catchData;
    }

    /*
     Returns a string representation of this vertex.

     Example output:

        For a Vertex with data:

           Vertex at <address of this vertex>
           Indegree is <num incoming nodes>
           Outdegree is <num outgoing nodes>
           Data at <address of data>

        For a Vertex with no data:

           Vertex at <address of this vertex>
           Indegree is <num incoming nodes>
           Outdegree is <num outgoing nodes>
           No data

     */
    std::string toString() {
        std::ostringstream sout;
        sout << "Vertex at " << this << std::endl;
        sout << "Indegree is " << getInDegree() << std::endl;
        sout << "Outdegree is " << getOutDegree() << std::endl;

        if (this->data != nullptr) {
            sout << "Data at " << this->data << std::endl;
        }
        else {
            sout << "No data" << std::endl;
        }
        return sout.str();
    }

};