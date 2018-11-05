#pragma once
#include <iostream>
#include "BlackJack.h"
using namespace std;

class BlackJackConsoleView
{
	BlackJack game;
public:
	BlackJackConsoleView();
	void start();
	void printScreen();
	void printMenu();
	void printAddMoney();
	void printSetBet();
};

