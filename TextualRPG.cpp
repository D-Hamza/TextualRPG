// TextualRPG.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "GameZero.h"
#include "CharacterTypesTester.h"

int main()
{
    std::cout << "Hello TextualRPG!\n";

    GameZero* theGame = new GameZero();
    //std::cout << theGame->toString() << std::endl;
    theGame->startGame();

    /*TestResults* r0 = CharacterTypesTester::runAllTests();
    std::cout << "Charactertypes TESTER OVERALL RESULTS:" << std::endl;
    std::cout << r0->toString() << std::endl;*/


}

