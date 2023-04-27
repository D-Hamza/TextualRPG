#pragma once
#include <string>
#include "Graph.h"
#include "Player.h"
#include "List.h"
class GameZero
{
public:
	// Default Constructor
	GameZero();

	// Creates a new game with the specified player.
	GameZero(Player* player);

	// Method to start the game
	void startGame();

	// Method to end the game
	void endGame();

	// Returns a string representation of this game
	std::string toString();


protected:
	// The player in our RPG
	Player* thePlayer;

	// Graph for our RPG
	Graph<List<std::string>, List<std::string>>* theGraph;

	// Function to prompt the game player for character information,
	// and then create the Player object representing the game player
	void getUserInfo();

	// Function to allow the user to (a) provide a response frequently 
	// during the game, and (b) allow the user to exit the game is their
	// response is the word "exit".
	std::string getUserResponse();

	// Builds graph for our RPG
	void buildGameGraph();

	// Simulates fight scene in this RPG
	void simulateFight();

	/*
	   Prints the string data stored in the vertex of the game graph. The method
	   should print one string at a time, then accept user input, then print the
	   next string, and so on, until no more strings are left to print.
	   */
	void printVertexData();



};

