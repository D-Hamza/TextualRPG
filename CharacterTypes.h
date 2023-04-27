#pragma once
#include <string>

/*
 A wrapped enum representing the different categories of characters in
 our RPG. An instance of this class represents a single character type.
*/
class CharacterTypes {

public:

    /*
     The raw enum representing the different character types in our RPG.
     The character types are as follows: Barbarian, Bard, Cleric, Fighter
     Monk, Paladin, Ranger, Rogue, Sorcerer, Warlock, Wizard, Generic,
     Other, and Unknown.
    */
    enum class CharacterType {
        Barbarian,
        Bard,
        Cleric,
        Fighter,
        Monk,
        Paladin,
        Ranger,
        Rogue,
        Sorcerer,
        Warlock,
        Wizard,
        Druid,
        Generic,
        Other,
        Unknown
    };

    /*
     The default constructor creates a CharacterTypes of type Unknown.
    */
    CharacterTypes();

    /*
     Creates a CharacterTypes of the specified type.
    */
    CharacterTypes(CharacterType type);

    /*
     Returns the specific type of this CharacterTypes
    */
    CharacterTypes::CharacterType getType();

    /*
     Returns a string representation of this CharacterTypes
    */
    std::string toString();

    /*
     Overload the equality comparison ==. Two CharacterTypes
     are considered equal if they have the same underlying
     raw enum value.
    */
    bool operator==(const CharacterTypes& other) const {
        return this->theType == other.theType;
    }

protected:

    /*
     The type of this CharacterTypes.
    */
    CharacterTypes::CharacterType theType;

    /*
     Array of strings representing each value of the raw type.
    */
    std::string typeNames[15]{
    "Barbarian",
    "Bard",
    "Cleric",
    "Fighter",
    "Monk",
    "Paladin",
    "Ranger",
    "Rogue",
    "Sorcerer",
    "Warlock",
    "Wizard",
    "Druid",
    "Generic",
    "Other",
    "Unknown"
    };

};


