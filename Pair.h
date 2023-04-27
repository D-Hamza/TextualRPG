#pragma once

#include <sstream>
#include <string>


/*
 A class to represent paired data. A Pair has a first element and
 a second element. These attributes are publicly accessible, and
 the types of the first and second element can be arbitrary.
 */
template <typename T, typename U>
class Pair {

public:

    /*
     Pointers to the data in this pair.
     */
    T* first;
    U* second;

    /*
     Creates an empty pair.
     */
    Pair() {
        this->first = nullptr;
        this->second = nullptr;
    }

    /*
     Creates a pair whose first and second elements are the specified data.
     */
    Pair(T* first, U* second) {
        this->first = first;
        this->second = second;
    }

    /*
     Returns true if and only if both elements of this pair are null.
     */
    bool isEmpty() {
        if ((this->first == nullptr) && (this->second == nullptr)) {
            return true;
        }
        else {
            return false;
        }
    }

    /*
     Returns true if and only if both elements of this pair are non-null.
     */
    bool isComplete() {
        if ((this->first != nullptr) && (this->second != nullptr)) {
            return true;
        }
        else {
            return false;
        }
    }

    /*
     Swaps the elements of the pair.
     */
    Pair<U, T>* swap() {
        U* newFirst = this->second;
        T* newSecond = this->first;

        return new Pair<U, T>(newFirst, newSecond);
    }

    /* Returns a string representation of this pair. Returns a string
       containing three lines of text giving the addresses of the pair,
       its first attribute, and its second attribute. If either attribute
       is null, the string should say so.

       Example 1: a complete Pair would have the following string representation:

           Pair at <memory address>
           First element at <memory address>
           Second element at <memory address>

       Example 2: An empty Pair would have the following string representation:

           Pair at <memory address>
           No first element
           No second element

       Example 3: a Pair with a first element but no second element would have the string representation:

           Pair at <memory address>
           First element at <memory address>
           No second element

       Example 4: a Pair with no first element but a second element would have the string representation:

           Pair at <memory address>
           No first element
           Second element at <memory address>
    */
    std::string toString() {
        std::ostringstream sout;
        // Example 1: a complete Pair would have the following string representation:
        if (isComplete() == true) {
            sout << "Pair at " << this << std::endl;
            sout << "First Element is at: " << this->first << std::endl;
            sout << "Second Element is at: " << this->second << std::endl;
            sout << "First Element in Pair is: " << *this->first << std::endl;
            sout << "Second Element in Pair is: " << *this->second << std::endl;
        }
        // Example 2: An empty Pair would have the following string representation:
        else if (isEmpty() == true) {
            sout << "Pair at " << this << std::endl;
            sout << "No First Element" << std::endl;
            sout << "No Second Element" << std::endl;
        }
        //  Example 3: a Pair with a first element but no second element would have the string representation:
        else if ((this->first != nullptr) && (this->second == nullptr)) {
            sout << "Pair at " << this << std::endl;
            sout << "First Element is at: " << this->first << std::endl;
            sout << "First Element in Pair is: " << *this->first << std::endl;
            sout << "No Second Element" << std::endl;
        }
        // Example 4: a Pair with no first element but a second element would have the string representation:
        else if ((this->first == nullptr) && (this->second != nullptr)) {
            sout << "Pair at " << this << std::endl;
            sout << "No First Element" << std::endl;
            sout << "Second Element is at: " << this->second << std::endl;
            sout << "Second Element in Pair is: " << *this->second << std::endl;
        }
        // If none of the cases are met, throw and error message
        else {
            sout << "Error! There is a problem with the pair." << this << std::endl;
        }
        return sout.str();
    }

}; // end template Pair

/*
 Overload operator== to compare two Pairs. This will return
 true if and only if lhs.first and rhs.first both point to the
 same data item AND lhs.second and rhs.second both point to the
 same data item.
 */
template <typename T, typename U>
bool operator==(Pair<T, U>& lhs, Pair<T, U>& rhs) {
    //    std::cout << "operator== here" << std::endl;
    return (lhs.first == rhs.first && lhs.second == rhs.second);
}