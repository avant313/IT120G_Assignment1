#include <iostream>
#include <string>
#include <ctime>;
using namespace std;
//Author Eric

//funktion för att generera ett "random" vinnande nummer.
int getRandomNumer() {
	int number;
	srand(time(0));
	number = rand() % 36 + 1;

	return number;
}

/*
* Funktion för att kontrollera vilken färg som det vinnade numret tillhör och därmed returnerar den vinnande färgen.
* Funktionen antar att black är den vinnande färgen och kontrollerar istället ifall numret finns i arrayn för den röda färgen. Finns numret sätts istället röd som vinnade färg.
*/
string whatColorWon(int blackNumbers[18], int redNumbers[18], int winningNumber) {
	string winningColor = "black";

	for (int i = 0; i < 18; i++) {
		if (winningNumber == redNumbers[i]) {
		winningColor = "red";
		}
	}
	
	
	return winningColor;
}
/*
* Spelets huvudfunktion där själva spelet och dess "gameModes" utförs.
* Spelet består huvudsakligen av följande steg.
* 1. Användaren väljer om denne vill spela på nummer eller färg
* 2. Användaren försöker lägga in ett bet och spelet kontrollerar ifall det är ett giltigt bet.
*	Vid ogiltigbet återgår spelet till "main" där användaren kan spela igen genom att returnera "balance".
* 3. Ett vinnade nummer genereras genom funktionen "getRandomNumber".
* 4.1. Om användaren valt färg så får denne välja vilken färg och funktionen för att avgöra vilken färg som vunnit åkallas.
*	Om användaren vunnit adderas vinstsumman till användarens "balance" och skickas tillbaka till "main" för att spela igen eller avsluta.
* 4.2. Om användaren valt nummer så kontrollerar spelet om denne valt det vinnande numret.
*	Om så är fallet adderas vinstsumman till balance och användaren återgår till "main" för att fortsätta spela eller avsluta. Om inte sätts användarens bet tillbaka och spelet spelet till "main".
* 5. Efter första spelomgången kontrolleras ifall användaren vill spela igen. Om så är fallet kontrolleras om användaren har pengar kvar och användaren ges alternativet att börja om på 1000.
*/
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

	// Steg 1.
	cout << "Bet on number or color? (number/color) \n";
	cin >> gameMode;
	// Steg 2.
	cout << "How much you want to bet? (100, 200, 500) \n";
	cin >> attemptedBet;
	if (attemptedBet <= balance && attemptedBet == 100 || attemptedBet == 200 || attemptedBet == 500) {
		bet = attemptedBet;
		attemptedBet = 0;
		balance -= bet;
	}
	else {
		cout << "Sorry, you made an invalid bet. \n";
		return balance;
	}

	//Steg 3.
	winningNumber = getRandomNumer();
	
	//Steg 4.1.
	if (gameMode == "color") {
		cout << "What color do you wanna bet on? (red/black) \n";
		cin >> chosenColor;
		winningColor = whatColorWon(blackNumbers, redNumbers, winningNumber);
		cout << "Winning color was: ";
		cout << winningColor << "\n";
		
		if (winningColor == chosenColor){
			cout << "Congratz, you won " << bet * 2 << endl;
			balance += bet * 2;
		}
		else {
			cout << "Sorry, you lost. Try again. \n";
		}
	}

	//Steg 4.2.
	else if (gameMode == "number") {
		cout << "What number do you wanna bet on? (1-36) \n";
		cin >> chosenNumber;
		cout << "Winning number was: ";
		cout << winningNumber << "\n";
		if (chosenNumber == winningNumber) {
			cout << "Congratz, you won " << bet * 10 << endl;
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
	int balance = 1000;
	string stop;
	string goAgain;
	while (true) {
		cout << "Your current balance is: ";
		cout << balance << "\n";
		balance = game(balance);
		
		//Steg 5.
		cout << "Play again? (y/n) ";
		cin >> stop;
		if (stop == "n") {
			break;
		}
		if (balance == 0) {
			cout << "Sorry, you are out of funds. Do you wanna deposit another 1000 and continue playing? (y/n) ";
			cin >> goAgain;
			if (goAgain == "y") {
				balance = 1000;
				cout << endl;
			}
			else {
				break;
			}
		}
	}


	return 0;
}


