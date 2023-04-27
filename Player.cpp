#include "Player.h"
#include <string>
#include <sstream>
#include <iostream>

/*
Returns the value of the character's age
*/
int Player::getCharacterAge() {
    return characterAge;
}
/*
Returns the player's name
*/
std::string Player::getPlayerName() {
    return playerName;
}
/*
Returns the character's name
*/
std::string Player::getCharacterName() {
    return characterName;
}
/*
Returns the character's description
*/
std::string Player::getCharacterDesc() {
    return characterDesc;
}

CharacterTypes Player::getCharacterType(){
    CharacterTypes type = CharacterTypes(CharacterTypes::CharacterType::Generic);
    return type;
}

List<PlayerActions>* Player::getPlayerActions() {
    this->playerActions = new List<PlayerActions>();
    PlayerActions* p1 = new PlayerActions(PlayerActions::PlayerAction::DoNothing);
    PlayerActions* p2 = new PlayerActions(PlayerActions::PlayerAction::DoAnything);
    this->playerActions->insertAtEnd(p1);
    this->playerActions->insertAtEnd(p2);
    return this->playerActions;
}

bool Player::canPerformAction(PlayerActions anAction) {
    if (anAction.getAction() == PlayerActions::PlayerAction::DoNothing) {
        return true;
    }
    if (anAction.getAction() == PlayerActions::PlayerAction::DoAnything) {
        return true;
    }
    else {
        return false;
    }
}


/*
Sets the character's age to the specified value. If the specified value is
negative, a warning is printed and the character's age not changed.
*/
void Player::setCharacterAge(int age) {
    if (age < 0) {
        std::cout << "Invalid charater age must be 0 or greater!" << std::endl;
    }
    else {
        characterAge = age;
    }
}

/*
Sets the player's name to specified name
*/
void Player::setPlayerName(std::string name) {
    playerName = name;
}

/*
Sets the character's name to specified name
*/
void Player::setCharacterName(std::string name) {
    characterName = name;
}

/*
Sets the character's description to specified description
*/
void Player::setCharacterDesc(std::string desc) {
    characterDesc = desc;
}


// Default Constructor
Player::Player() {
    playerName = "Unamed Player";
    characterName = "Unamed Character";
    characterDesc = "No description available";
    characterAge = 18;
}

// Paramerterized Constructor that takes 3 arguments
Player::Player(std::string pName, std::string cName, int cAge) {
    playerName = pName;
    characterName = cName;
    characterAge = cAge;
}

// toString method
std::string Player::toString() {
    std::ostringstream sout;
    sout << "Player Name: " << this->playerName << std::endl;
    sout << "Character Name: " << this->characterName << std::endl;
    sout << "Character Age: " << this->characterAge << std::endl;
    sout << "Character Description: " << this->characterDesc << std::endl;
    sout << "Character Types: " << this->getCharacterType().toString() << std::endl;
    sout << "Player Actions: DoNothing, DoAnything" << std::endl;
    return sout.str();
}