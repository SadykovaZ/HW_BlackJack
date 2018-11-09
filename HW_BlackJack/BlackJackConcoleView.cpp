#include "BlackJackConcoleView.h"
#include<ctime>


BlackJackConsoleView::BlackJackConsoleView()
	:game(0, 0)
{
	srand(time(NULL));
	cout << "Hello!"<<endl;
	cout << "Welcome to Black Jack game" << endl;
	printAddMoney();
	cout << "\n-------\n";
	printSetBet();
}

void BlackJackConsoleView::start()
{
	int choice = 0;
	while (1) {
		system("cls");
		printScreen();
		cin >> choice;
		//если игры нет
		if (!game.isGameStart()) {
			if (choice == 4) break;

			if (choice == 1) {
				game.startRound();
				continue;
			}
			if (choice == 2) {
				printAddMoney();
				continue;
			}
			if (choice == 3) {
				printSetBet();
				continue;
			}


		}

		if (game.isGameStart()) 
		{
			game.startRound();
			cout << "1 - get new Card, 2 - stop, 3 - exit" << endl;
			//int result = game.checkRound();
			int result;
			cin >> result;
			if (result == 1)
			{
				game.getCard();
				game.getPlayerCards();

			}
			if (result == 2) 
			{
				game.getPlayerCards();
			}
			if(result==3)
			{
				break;
			}

		}
		system("cls");
		cout << "Good bye!\n";
	}
}

void BlackJackConsoleView::printScreen()
{
	cout << "------------------------------\n";
	cout << "diller\'s cards\n";
	for (size_t i = 0; i < game.getDillerCards().size(); i++)
	{
		cout << game.getDillerCards()[i].getInfo() << endl;
	}
	cout << "\ndiller\'s points = " << game.getPoints(game.getDillerCards());
	cout << "\n\nYour cards\n";
	for (size_t i = 0; i < game.getPlayerCards().size(); i++)
	{
		cout << game.getPlayerCards()[i].getInfo() << endl;
	}
	cout << "\nYour points = " << game.getPoints(game.getPlayerCards());
	cout << "\nYour money = " << game.getMoney();
	cout << "\nYour bet = " << game.getBet();
	cout << "\n-----------------\n";
	printMenu();
}

void BlackJackConsoleView::printMenu()
{
	//если игра началась
	if (game.isGameStart()) {
		cout << "1 - get new Card\n2 - stop\n3 - exit"<<endl;
	}
	else {
		//нет нового раунда
		cout << "1 - new game\n2 - Add money\n3 - Set Bet\n4 - exit" << endl;
	}
}

void BlackJackConsoleView::printAddMoney()
{
	cout << "Add money: ";
	int m;
	cin >> m;
	game.addMoney(m);
}

void BlackJackConsoleView::printSetBet()
{
	cout << "Set bet: ";
	int b;
	cin >> b;
	game.setBet(b);
}



