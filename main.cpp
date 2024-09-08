#include "contestantList.h"

void printMenu();
void runCMD(char, PlayerList &, ContestantList &);

void theEditListFunction(PlayerList &);
void cmdEditPlayerList(char, PlayerList &);

void theEditCFunction(ContestantList &, PlayerList players);
void cmdEditContestantList(char userInput, ContestantList &contestants, PlayerList players);

void thePointEditFunction(ContestantList &contestants, PlayerList players);
void cmdPoints(char userInput, ContestantList &contestants, PlayerList players);

void thePrintFunction(PlayerList &);
void cmdPrintPlayers(char, PlayerList &);

void thePrintCFunction(ContestantList &, PlayerList);
void cmdPrintCPlayers(char, ContestantList &, PlayerList);

void saveFile(ContestantList &, PlayerList &);

int main(){
	PlayerList players("players.txt");
	ContestantList contestants("contestantList.txt", players);
	char cmd = ' ';

	do{
		printMenu();
		cout << "Enter Command: " << flush;
		cin >> cmd;
		cmd = tolower(cmd);
		cin.ignore();
		runCMD(cmd, players, contestants);
	}while(cmd != 'q');


	return 0;
}

void printMenu(){
	cout << endl;
	cout << "a. Edit Player List" << endl;
	cout << "b. Edit Contestant List" << endl;
	cout << "c. Calculate Points" << endl;
	cout << "d. Print Player List" << endl;
	cout << "e. Print Contestant List" << endl;
	cout << "f. Save Files" << endl;
	cout << "q. Quit Program" << endl;
}

void runCMD(char cmd, PlayerList &players, ContestantList &contestants){
	switch(cmd){
		case 'a':
			theEditListFunction(players);
			break;
		case 'b':
			theEditCFunction(contestants, players);
			break;
		case 'c':
			thePointEditFunction(contestants, players);
			break;
		case 'd':
			thePrintFunction(players);
			break;
		case 'e':
			thePrintCFunction(contestants, players);
			break;
		case 'f':
			saveFile(contestants, players);
			break;
		case 'q':
			break;
		default:
			cout << "Invalid Input!" << endl;
	}

}

void theEditListFunction(PlayerList &players){
	char userInput = ' ';
	do{
		cout << endl;
		cout << "What would you like to edit" << endl;
		cout << "a. Add Player" << endl;
		cout << "b. Remove Player" << endl;	
		cout << "q. Quit" << endl;
		cout << ">> " << flush;
		cin >> userInput;
		userInput = tolower(userInput);
		cin.ignore();


		cmdEditPlayerList(userInput, players);

	}while(userInput != 'q');
}

void cmdEditPlayerList(char userInput, PlayerList &players){
	string userPlayer;
	string userTeam;
	string userLane;
	bool didAdd = false;
	bool didRemove = false;

	switch(userInput){
		case 'a':
			cout << "Enter player name to add: " << flush;
			getline(cin, userPlayer);

			cout << "Enter that player's team: " << flush;
			getline(cin, userTeam);

			cout << "Enter that player's lane: " << flush;
			getline(cin, userLane);

			didAdd = players.newPlayer(userPlayer, userTeam, userLane);

			if(didAdd == true){
				cout << "Success! Player was added to the list" << endl;
			}
			else{
				cout << "Failed! That lane/team does not exist" << endl;
			}

			break;
		case 'b':
			cout << "Enter player to remove: " << flush;
			getline(cin, userPlayer);

			cout << "Enter that player's team: " << flush;
			getline(cin, userTeam);

			didRemove = players.removePlayer(userPlayer, userTeam);
			if(didRemove == true){
				cout << "Success! Player was removed from list" << endl;
			}
			else{
				cout << "Failed! Player not found in list" << endl;
			}
			break;
		case 'q':
			break;
		default:
			cout << "Invalid Input!" << endl;
	}
}

void theEditCFunction(ContestantList &contestants, PlayerList players){
	char userInput = ' ';
	do{
		cout << endl;
		cout << "What would you like to edit" << endl;
		cout << "a. Add Contestant" << endl;
		cout << "b. Remove Contestant" << endl;	
		cout << "c. Edit Role/Team" << endl;
		cout << "q. Quit" << endl;
		cout << ">> " << flush;
		cin >> userInput;
		userInput = tolower(userInput);
		cin.ignore();


		cmdEditContestantList(userInput, contestants, players);

	}while(userInput != 'q');
}

void cmdEditContestantList(char userInput, ContestantList &contestants, PlayerList players){
	string userPlayer;
	string update;
	int roleInput;
	bool didAdd = false;
	bool didRemove = false;
	bool didEdit = false;

	switch(userInput){
		case 'a':
			cout << "Enter player name to add: " << flush;
			getline(cin, userPlayer);

			didAdd = contestants.newContestant(userPlayer);

			if(didAdd == true){
				cout << "Success! Player was added to the list" << endl;
			}
			else{
				cout << "Failed! That lane/team does not exist" << endl;
			}

			break;
		case 'b':
			cout << "Enter player to remove: " << flush;
			getline(cin, userPlayer);

			didRemove = contestants.removeContestant(userPlayer);
			if(didRemove == true){
				cout << "Success! Player was removed from list" << endl;
			}
			else{
				cout << "Failed! Player not found in list" << endl;
			}
			break;
		
		case 'c':
			cout << "Enter player to edit: " << flush;
			getline(cin, userPlayer);

			do{
				cout << "Enter role/team to edit (Top: 0, JGL: 1, Mid: 2, ADC: 3, Supp: 4, Team: 5): " << flush;
				cin >> roleInput;
				cin.ignore();
			}while(roleInput < 0 || roleInput > 5);

			cout << "Enter new player/team: " << flush;
			getline(cin, update);

			didEdit = contestants.editContestant(userPlayer, update, roleInput, players);

			if(didEdit == true){
				cout << "Success! Role/Team was edited" << endl;
			}
			else{
				cout << "Failed! Role/Team not edited" << endl;
			}
			break;
		case 'q':
			break;
		default:
			cout << "Invalid Input!" << endl;
	}
}

void thePointEditFunction(ContestantList &contestants, PlayerList players){
	char userInput = ' ';
	do{
		cout << endl;
		cout << "What points do you want to edit?" << endl;
		cout << "a. Set Team Points" << endl;
		cout << "b. Set Weekly Points" << endl;
		cout << "c. Set Total Points (DO THIS LAST)" << endl;
		cout << "q. Quit" << endl;
		cout << ">> " << flush;
		cin >> userInput;
		userInput = tolower(userInput);
		cin.ignore();


		cmdPoints(userInput, contestants, players);

	}while(userInput != 'q');
}

void cmdPoints(char userInput, ContestantList &contestants, PlayerList players){
	switch(userInput){
		case 'a':
			contestants.setTeamPointsAll();
			break;
		case 'b':
			contestants.setWPointsAll(players);
			break;
		case 'c':
			contestants.setTPointsAll();
			break;
		case 'q':
			break;
		default:
			cout << "Invalid Input!" << endl;
	}
}

void thePrintFunction(PlayerList &players){
	char userInput = ' ';
	do{
		cout << endl;
		cout << "What would you like to print?" << endl;
		cout << "a. All players and stats" << endl;
		cout << "b. Players by team" << endl;
		cout << "c. Print player" << endl;
		cout << "d. Top scorer per role" << endl;		
		cout << "q. Quit" << endl;
		cout << ">> " << flush;
		cin >> userInput;
		userInput = tolower(userInput);
		cin.ignore();


		cmdPrintPlayers(userInput, players);

	}while(userInput != 'q');
}

void cmdPrintPlayers(char userInput, PlayerList &players){
	string theUserChoice;
	bool isPlayer = false;
	switch(userInput){
		case 'a':
			players.printList();
			break;

		case 'b':
			cout << "Enter team name: " << flush;
			getline(cin, theUserChoice);
			players.printTeam(theUserChoice);
			break;

		case 'c':
			cout << "Enter player name: " << flush;
			getline(cin, theUserChoice);
			isPlayer = players.printPlayer(theUserChoice);
			if(isPlayer == false){
				cout << "Player not found!" << endl;
			}
			break;

		case 'd':
			players.topScorers();
			break;
			
		case 'q':
			break;
		default:
			cout << "Invalid Input!" << endl;
	}
}

void thePrintCFunction(ContestantList &contestants, PlayerList players){
	char userInput = ' ';
	do{
		cout << endl;
		cout << "What would you like to print?" << endl;
		cout << "a. All players" << endl;
		cout << "b. Contestant Team" << endl;		
		cout << "q. Quit" << endl;
		cout << ">> " << flush;
		cin >> userInput;
		userInput = tolower(userInput);
		cin.ignore();


		cmdPrintCPlayers(userInput, contestants, players);

	}while(userInput != 'q');
}

void cmdPrintCPlayers(char userInput, ContestantList &contestants, PlayerList players){
	string theUserChoice;
	bool isPlayer = false;
	switch(userInput){
		case 'a':
			contestants.printContestantList();
			break;

		case 'b':
			cout << "Enter player name: " << flush;
			getline(cin, theUserChoice);
			isPlayer = contestants.printContestantTeam(theUserChoice, players);
			if(isPlayer == false){
				cout << "Player not found!" << endl;
			}
			break;
			
		case 'q':
			break;

		default:
			cout << "Invalid Input!" << endl;
	}
}

void saveFile(ContestantList &contestants, PlayerList &players){
	players.toFile("players.txt");
	contestants.toFileC("contestantList.txt");
	cout << "Saved!" << endl;
}