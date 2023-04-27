#include "PlayerActions.h"

// Default Constructor
PlayerActions::PlayerActions() {
	this->theAction = PlayerActions::PlayerAction::DoNothing;
}

// Constructor that sets theAction to the given action
PlayerActions::PlayerActions(PlayerAction action) {
	this->theAction = action;
}

// Constructor to see if given actionString exists in the actions enum
// if so, set theAction to that value.
PlayerActions::PlayerActions(std::string actionString) {
	// loop through to find if the position in the actionNames 
	// equals the given action string
	for (int k = 0; k < 48; k++) {
		if (this->actionNames[k] == actionString) {
			// static cast to type player action 
			this->theAction = static_cast<PlayerAction>(k);
		}
	}
}

// Returns the current action
PlayerActions::PlayerAction PlayerActions::getAction() {
	return this->theAction;
}

// return the string of the action from the position 
// of the action as an integer after static cast
std::string PlayerActions::toString() {
	return this->actionNames[static_cast<int>(theAction)];
}
