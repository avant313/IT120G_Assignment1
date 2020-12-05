#include <iostream>
#include <string>
#include <ctime>;
using namespace std;
//Author Eric


int getRandomNumer() {
	int number;
	srand(time(0));
	number = rand() % 36 + 1;

	return number;
}

string whatColorWon(int blackNumbers[18], int redNumbers[18], int winningNumber, string chosenColor) {
	string winningColor = "black";

	if (chosenColor == "red") {
		for (int i = 0; i < 18; i++) {
			if (winningNumber == redNumbers[i]) {
				winningColor = "red";
			}
		}
	}
	
	return winningColor;
}

int game(int balance) {
	int blackNumbers[18] = { 2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36 };
	int redNumbers[18] = { 1,3,5,7,9,11,13,15,17,19,21,23,25,27,29,31,33,35 };
	int bet;
	int attemptedBet;
	string gameMode;
	int chosenNumber;
	string chosenColor;
	int winningNumber;
	string winningColor;

	cout << "Bet on number or color? (number/color) \n";
	cin >> gameMode;
	cout << "How much you want to bet? \n";
	cin >> attemptedBet;

	if (attemptedBet <= balance) {
		bet = attemptedBet;
		attemptedBet = 0;
		balance -= bet;
	}
	else {
		cout << "You don't have enough money. \n";
		return balance;
	}

	
	winningNumber = getRandomNumer();
	
	if (gameMode == "color") {
		cout << "What color do you wanna bet on? (red/black) \n";
		cin >> chosenColor;
		winningColor = whatColorWon(blackNumbers, redNumbers, winningNumber, chosenColor);
		cout << "Winning color was: ";
		cout << winningColor;
		cout << "\n";
		
		if (winningColor == chosenColor){
			cout << "Congratz, you won. \n";
			balance += bet * 2;
		}
		else {
			cout << "Sorry, you lost. Try again. \n";
		}
	}

	else if (gameMode == "number") {
		cout << "What number do you wanna bet on? (1-36) \n";
		cin >> chosenNumber;
		cout << "Winning number was: ";
		cout << winningNumber;
		cout << "\n";
		if (chosenNumber == winningNumber) {
			cout << "Congratz, you won. \n";
			balance += bet * 10;
		}
		else {
			cout << "Sorry, you lost. Try again. \n";
		}
	}
	else {
		cout << "Technical error, try again. huehuehue \n";
		balance += bet;
	}

	return balance;
}

int main() {
	int balance = 0;
	int newDeposit;
	string stop;
	while (true) {
		cout << "Your current balance is: ";
		cout << balance;
		cout << "\n";
		cout << "How much do you want to deposit? \n";
		cin >> newDeposit;
		balance += newDeposit;
		cout << "Your current balance is: ";
		cout << balance;
		cout << "\n";
		balance = game(balance);
		
		cout << "Play again? (y/n) ";
		cin >> stop;
		if (stop == "n") {
			break;
		}
	}


	return 0;
}


