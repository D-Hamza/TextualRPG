#include <random>
#include <sstream>

#include "GameZero.h"
#include "Vertex.h"



// initialize the player and create the game graph
GameZero::GameZero() {
	this->thePlayer = new Player();
	this->theGraph = nullptr;
	// get player information
	this->getUserInfo();
	std::cout << std::endl << thePlayer->toString() << std::endl;
	// build the game graph
	this->buildGameGraph();

}

// Player Constructor
GameZero::GameZero(Player* player) {
	this->thePlayer = player;
	this->theGraph = nullptr;
	// get player information
	this->getUserInfo();
	std::cout << std::endl << thePlayer->toString() << std::endl;
	// build the game graph
	this->buildGameGraph();
}

void GameZero::startGame() {
	// begin printing story lines
	this->printVertexData();

	// give user option to start game or exit
	std::cout << std::endl << "Type 'start' to begin the fight! Or enter 'exit' to leave the game" << std::endl;
	std::string start;
	
	do {
		std::cin >> start;
		if (start == "start") {
			this->simulateFight();
		}
		if (start == "exit") {
			this->endGame();
		}
		else {
			std::cout << "Invalid response. Please type 'start' to begin the fight. Or enter 'exit' to leave the game." << std::endl;
		}
	} while (start != "start");
	
	
}

void GameZero::endGame() {
	std::cout << "May your travels bring you down this path again soon, goodbye!" << std::endl;
	std::exit(0);
}

std::string GameZero::toString() {
	std::ostringstream sout;
	sout << "GameZero at " << this << std::endl;
	sout << "PLAYER INFORMATION: " << std::endl;
	sout << this->thePlayer->toString();
	sout << "The story in the Dragon's Lair: " << std::endl;
	// get a pointer to the list of strings stored in vertex 0
	List<std::string>* storyList = this->theGraph->getVertexData(0);
	for (int k = 0; k < storyList->getSize(); k++) {
		// get item k from the list 
		std::string* itemK = storyList->peek(k);
		sout << *itemK << std::endl;
	}
	return sout.str();
}

void GameZero::getUserInfo() {
	// get the player's name
	std::cout << "Enter your real name: ";
	std::string playerName = getUserResponse();
	this->thePlayer->setPlayerName(playerName);

	// get the character's name
	std::cout << "Enter your Character's name: ";
	std::string characterName = getUserResponse();
	this->thePlayer->setCharacterName(characterName);
	
	// get the character's age
	std::cout << "Enter your Character's age: ";
	// try/catch block
	
	try {
		int characterAge = std::stoi(getUserResponse());
		this->thePlayer->setCharacterAge(characterAge);

	}
	catch (const std::exception e) {
		std::cout << e.what() << std::endl;
		// set character's age to some default value
		std::cout << "Invaild age string, setting character's age to default of 30." << std::endl;
		this->thePlayer->setCharacterAge(30);

		// try looping the character's age until user provides valid input
		
	}


	// get the character's description
	std::cout << "Enter your Character's description: ";
	std::string characterDesc = getUserResponse();
	this->thePlayer->setCharacterDesc(characterDesc);

}

std::string GameZero::getUserResponse() {
	std::string result = "";
	// allow the user to respond, catch the response using
	// getline
	std::getline(std::cin, result);
	if (result == "exit") {
		this->endGame();
	}
	else {
		return result;
	}
}


void GameZero::buildGameGraph() {
	this->theGraph = new Graph<List<std::string>, List<std::string>>();
	// add a single vertex
	Vertex<List<std::string>>* dragonsLair = new Vertex<List<std::string>>();
	this->theGraph->addVertex(dragonsLair);
	// add some string data to describe the story that occurs in the dragon's lair
	List<std::string>* storyList = new List<std::string>();
	// add some strings to the list
	storyList->insertAtEnd(new std::string("Welcome weary traveler, to the DRAGON'S DUNGEON!"));
	storyList->insertAtEnd(new std::string("I know you have traveled far in wide in search of glourious treasures!"));
	storyList->insertAtEnd(new std::string("And now you have found it!"));
	storyList->insertAtEnd(new std::string("As you enter the dungeon and look around you and see mountains of gleaming gold and glittering jewels!"));
	storyList->insertAtEnd(new std::string("In the center of the mountain of riches is a Dragon guarding all the spoils!"));
	storyList->insertAtEnd(new std::string("As you walk closer, your foot steps on a conveniently placed stick!"));
	storyList->insertAtEnd(new std::string("SNAP! You wake up the Dragon!"));
	storyList->insertAtEnd(new std::string("The Dragon angrily flares their nostrils with firey steam coming out."));
	storyList->insertAtEnd(new std::string("You watch as the Dragon opens their jaw and spits out three flaming angry ghosts!"));
	storyList->insertAtEnd(new std::string("You must fight each ghost, if you defeat all three you win the treasure! Be careful if the ghosts kill you, then it's GAME OVER!"));
	storyList->insertAtEnd(new std::string("Good luck and may fortune ever be in your favor!"));
	
	// store the list in the vertex of this graph
	this->theGraph->storeInVertex(storyList, 0);

}

void GameZero::printVertexData() {
	List<std::string>* storyList = this->theGraph->getVertexData(0);
	for (int k = 0; k < storyList->getSize(); k++) {
		// get item k from the list 
		std::string* itemK = storyList->peek(k);
		std::cout << *itemK << std::endl;
		this->getUserResponse();
	}
}

void GameZero::simulateFight() {
	std::cout << std::endl << "READY? FIGHT!" << std::endl << std::endl;
	// build random number generators (PRNGs)
	std::random_device r;
	std::default_random_engine engn(r());
	std::uniform_real_distribution<double> prng(0.0, 1.0);

	// Player vitality, hit point values, and hit probability
	int playerVitality = 100;
	int playerDamagerPerHit = 10;
	double playerHitProbability = 0.6;

	// Ghosts vitality, hit point values, and hit probability
	int ghostVitality[3] = {30, 30, 30};
	int ghostDamagePerHit = 5;
	double ghostHitProbability = 0.35;

	// fight will proceed in rounds. Need round counter
	int roundNumber = 1;

	// main simulation loop
	while (playerVitality > 0) {
		std::cout << "Round " << roundNumber << std::endl;
		
		// for each ghost that remains alive, check (a) if the Player's blow lands on the ghost,
		// and (b) if the ghost's blow lands on the player.
		for (int k = 0; k < 3; k++) {
			if (ghostVitality[k] > 0) {
				// check to see if the player lands a blow on the ghost.
				// If so, update vitality points for ghost k, and print 
				// a message to the console.
				double randVal = prng(engn);
				if (randVal <= playerHitProbability) { // Player's blow landed!
					// decrement ghost k vitality points
					ghostVitality[k] -= ghostDamagePerHit;
					std::cout << std::endl << "WOOOO! " << this->thePlayer->getCharacterName() << " lands hit on ghost " << k << ", ghost " << k << " vitality is now " << ghostVitality[k];
					this->getUserResponse();
				} 
				// if ghost k is still alive check to see if they land a blow 
				// on the player
				if (ghostVitality[k] > 0) {
					// check if ghost k lands a blow on the player, if so,
					// update points and print the message
					randVal = prng(engn);
					if (randVal <= ghostHitProbability) {
						playerVitality -= playerDamagerPerHit;
						std::cout << std::endl << "AHHHH! Ghost " << k << "'s attack on " << this->thePlayer->getCharacterName() << " is successful, " << this->thePlayer->getCharacterName() << "'s vitality is now " << playerVitality;
						this->getUserResponse();
						if (playerVitality <= 0) {
							std::cout << "GAME OVER! " << this->thePlayer->getCharacterName() << " is dead! Vitality is " << playerVitality << std::endl;
							this->endGame();
						}
					}
				}
			}
		}
		// check to see if any ghost remain alive, if not the player has won
		if (ghostVitality[0] <= 0 && ghostVitality[1] <= 0 && ghostVitality[2] <= 0) {
			std::cout << std::endl << this->thePlayer->getCharacterName() << " wins and grabs the treasure! All 3 ghosts are dead!" << std::endl;
			std::cout << this->thePlayer->getCharacterName() << " runs out of the DRAGON'S DUNGEON, escaping yet another brush with death!" << std::endl;
			this->getUserResponse();
			this->endGame();
		}

		// increment roundNumber
		roundNumber++;
		std::cout << std::endl << std::endl;
	}
	


}