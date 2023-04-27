#include <sstream>
#include<iostream>
#include "Paladin.h"

Paladin::Paladin() {
	this->playerName = "Unammed Player";
	this->characterName = "Unammed Character";
	this->characterAge = 0;
	this->characterDesc = "No description available";
	// create the list of player actions that a paladin is capable of
	this->playerActions = new List<PlayerActions>();
	this->playerActions->insertAtEnd(new PlayerActions(PlayerActions::PlayerAction::Fight));
	this->playerActions->insertAtEnd(new PlayerActions(PlayerActions::PlayerAction::SwordFight));
	this->playerActions->insertAtEnd(new PlayerActions(PlayerActions::PlayerAction::CastSpell));
	this->playerActions->insertAtEnd(new PlayerActions(PlayerActions::PlayerAction::RideHorse));
	this->playerActions->insertAtEnd(new PlayerActions(PlayerActions::PlayerAction::PutOnArmor));
	this->playerActions->insertAtEnd(new PlayerActions(PlayerActions::PlayerAction::TakeOffArmor));
}

Paladin::Paladin(std::string playerName, std::string characterName, int age) {
	this->playerName = playerName;
	this->characterName = characterName;
	this->characterAge = age;
	this->characterDesc = "No description available";
	// create the list of player actions that a paladin is capable of
	this->playerActions = new List<PlayerActions>();
	this->playerActions->insertAtEnd(new PlayerActions(PlayerActions::PlayerAction::Fight));
	this->playerActions->insertAtEnd(new PlayerActions(PlayerActions::PlayerAction::SwordFight));
	this->playerActions->insertAtEnd(new PlayerActions(PlayerActions::PlayerAction::CastSpell));
	this->playerActions->insertAtEnd(new PlayerActions(PlayerActions::PlayerAction::RideHorse));
	this->playerActions->insertAtEnd(new PlayerActions(PlayerActions::PlayerAction::PutOnArmor));
	this->playerActions->insertAtEnd(new PlayerActions(PlayerActions::PlayerAction::TakeOffArmor));
}

CharacterTypes Paladin::getCharacterType() {
	CharacterTypes* result = new CharacterTypes(CharacterTypes::CharacterType::Paladin);
	return *result;
}

List<PlayerActions>* Paladin::getPlayerActions() {
	return this->playerActions;
}

bool Paladin::canPerformAction(PlayerActions anAction) {
	bool result = false;
	for (int k = 0; k < this->playerActions->getSize(); k++) {
		PlayerActions* actionK = this->playerActions->peek(k);
		if (anAction == *actionK) {
			result = true;
			break;
		}
	}
	return result;
}

std::string Paladin::toString() {
	std::ostringstream sout;
	sout << "Player Name: " << this->playerName << std::endl;
	sout << "Character Name: " << this->characterName << std::endl;
	sout << "Character Age: " << this->characterAge << std::endl;
	sout << "Character Description: " << this->characterDesc << std::endl;
	sout << "Character Type: Paladin" << std::endl;
	sout << "Player Actions: Fight" << std::endl;
	sout << "Player Actions: SwordFight" << std::endl;
	sout << "Player Actions: CastSpell" << std::endl;
	sout << "Player Actions: RideHorse" << std::endl;
	sout << "Player Actions: PutOnArmor" << std::endl;
	sout << "Player Actions: TakeOffArmor" << std::endl;
	return sout.str();
}

void Paladin::fight() {
	std::cout << "En Gaurde, you rascal!" << std::endl;
}

/*
	Implements the PlayerAction::RideHorse action.
	*/
void Paladin::rideHorse() {
	std::cout << "Giddy Up!" << std::endl;
}

/*
Implements the PlayerAction::PutOnArmor action.
*/
void Paladin::putOnArmor() {
	std::cout << "Protection made from the richest of metals!" << std::endl;
}

/*
Implements the PlayerAction::TakeOffArmor action.
*/
void Paladin::takeOffArmor() {
	std::cout << "Whew! All in a days work, this armor is strating to get heavy." << std::endl;
}