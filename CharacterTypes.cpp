#include "CharacterTypes.h"
#include<string>
#include<iostream>



CharacterTypes::CharacterTypes() {
	theType = CharacterTypes::CharacterType::Unknown;
}

CharacterTypes::CharacterTypes(CharacterType type) {
	theType = type;
}

CharacterTypes::CharacterType CharacterTypes::getType() {
	return theType;
}

std::string CharacterTypes::toString() {
	return this->typeNames[static_cast<int>(theType)];
}