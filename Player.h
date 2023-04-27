#pragma once
#include <string>
#include "CharacterTypes.h"
#include "PlayerActions.h"
#include "List.h"


/*
 A class to model players in an RPG.
 */

class Player
{

protected:
    /*
    The age of the character in years
    */
    int characterAge;
    // The name of the player
    std::string playerName;
    // The name of the character
    std::string characterName;
    // The description of the character
    std::string characterDesc;
    /*
    List to hold the actions this player is capable of.
    */
    List<PlayerActions>* playerActions;


public:

    /*
    Returns the value of the character's age
    */
    int getCharacterAge();
    /*
    Returns the player's name
    */
    std::string getPlayerName();
    /*
    Returns the character's name
    */
    std::string getCharacterName();
    /*
    Returns the character's description
    */
    std::string getCharacterDesc();

    /*
    Returns the character type of this player. For the base class
    Player, the character type should be CharacterType::Generic
    */
    virtual CharacterTypes getCharacterType();

    /*
    Returns a list of the actions this player is capable of. For
    the base class Player, this method returns a list containing
    two actions: PlayerAction::DoAnything and PlayerAction::doNothing.
    */
    virtual List<PlayerActions>* getPlayerActions();

    /*
     Returns true if and only if this player is capable of the specified action.
     For the base class Player this method returns true if and only if the
     specified action is either PlayerAction::DoAnything or PlayerAction::DoNothing.
     */
    virtual bool canPerformAction(PlayerActions anAction);


    /*
    Sets the character's age to the specified value. If the specified value is
    negative, a warning is printed and the character's age not changed.
    */
    void setCharacterAge(int age);

    /*
   Sets the player's name to specified name
   */
    void setPlayerName(std::string name);

    /*
    Sets the character's name to specified name
    */
    void setCharacterName(std::string name);

    /*
    Sets the character's description to specified description
    */
    void setCharacterDesc(std::string desc);


    // Default Constructor
    Player();

    // Paramerterized Constructor that takes 3 arguments
    Player(std::string pName, std::string cName, int cAge);

    //toString method
    virtual std::string toString();

};

