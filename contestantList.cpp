#include "contestantList.h"

ContestantList::ContestantList(){
}


ContestantList::ContestantList(string contestantFile, const PlayerList players){
	ifstream inFile;
	inFile.open(contestantFile);
	if(!inFile){
		cout << "File did not open!" << endl;
		exit(1);
	}

    Contestant tempContestant;
    string name, top, jgl, mid, adc, supp, team;
    double totalPoints, week;

	getline(inFile, name, ',');
	while(!inFile.eof()){
		getline(inFile, top, ',');
		getline(inFile, jgl, ',');
		getline(inFile, mid, ',');
		getline(inFile, adc, ',');
		getline(inFile, supp, ',');
		getline(inFile, team, ','); 
        inFile >> totalPoints;
        inFile.ignore(MAX_CHAR, '\n');

        tempContestant.setPlayer(name, 6);
        tempContestant.setPlayer(top, 0);
        tempContestant.setPlayer(jgl, 1);
        tempContestant.setPlayer(mid, 2);   
        tempContestant.setPlayer(adc, 3);
        tempContestant.setPlayer(supp, 4);   
        tempContestant.setPlayer(team, 5);
        tempContestant.setTotalPoints(totalPoints);
        cTotalList.push_back(tempContestant);      

        getline(inFile, name, ',');                          
	}
    inFile.close();
}

ContestantList::~ContestantList(){
}

bool ContestantList::newContestant(string teamName){
    Contestant tempContestant;
    tempContestant.setPlayer(teamName, 6);
    cTotalList.push_back(tempContestant);
    return true;
}

bool ContestantList::removeContestant(string teamName){
    teamName = toLowerCase(teamName);
    for(int i = 0; i < cTotalList.size(); i++){
        string lower = toLowerCase(cTotalList[i].getCName());
        if(teamName.compare(lower) == 0){
            cTotalList.erase(cTotalList.begin() + i);
            return true;
        }
    }
    return false;
}

bool ContestantList::editContestant(string teamName, string update, int roleInput, PlayerList players){
    bool checkPlayer = false;
    teamName = toLowerCase(teamName);
    
    if(roleInput != 5){
        checkPlayer = players.playerCheck(update, roleInput);        
            if(checkPlayer == false){
                return false;
            }
    }
    
    for(int i = 0; i < cTotalList.size(); i++){
        string lower = toLowerCase(cTotalList[i].getCName());
        if(teamName.compare(lower) == 0){
            cTotalList[i].setPlayer(update, roleInput);
            return true;
        }
    }
    return false;
}

void ContestantList::setTeamPointsAll(){
    int wins;
    for(int i = 0; i < cTotalList.size(); i++){
        cout << "How many wins did " << cTotalList[i].getTeam() << " get?: " << flush;
        cin >> wins;
        cTotalList[i].setTeamPoints(wins);
    }
    cout << "Team Points added!" << endl;
}


void ContestantList::setWPointsAll(PlayerList players){
    for(int i = 0; i < cTotalList.size(); i++){
        cTotalList[i].setWeeklyPoints(players);
    }
    cout << "Weekly Points are set!" << endl;
}

void ContestantList::setTPointsAll(){
    for(int i = 0; i < cTotalList.size(); i++){
        cTotalList[i].addTotalPoints();
    }
    cout << "Total Points are set!" << endl;
}


void ContestantList::printContestantList(){
	cout << endl;
    cout << fixed << setprecision(2);
	cout << left << "Name";
	cout << right << setw(35) << "Weekly Points";
	cout << right << setw(20) << "Total Points" << endl;      

    for(int i = 0; i < cTotalList.size(); i++){
        cTotalList[i].print();
    } 
}

bool ContestantList::printContestantTeam(string conTeam, PlayerList players){
    conTeam = toLowerCase(conTeam);

    for(int i = 0; i < cTotalList.size(); i++){
        string lower = toLowerCase(cTotalList[i].getCName());
        if(conTeam.compare(lower) == 0){
            printConTeam(players, i);
            return true;
        }
    }
    return false;
}

void ContestantList::printConTeam(PlayerList players, int x){
    bool isName = false;
    vector<vector<Players>> totalList = players.getList();
    cout << setprecision(2);
    
    cout << endl;
    players.printTemplate();
    cout << cTotalList[x].getCName() << endl;

    for(unsigned int i = 0; i < totalList.size(); i++){
		for(unsigned int j = 0; j < totalList[i].size(); j++){
            isName = cTotalList[x].compareNames(totalList[i][j].getName());
            if(isName == true){
                totalList[i][j].print();
            }
            isName = false;
		}
	}

    cout << cTotalList[x].getTeam() << right <<setw(61 - cTotalList[x].getTeam().size())
         << cTotalList[x].getTeamPoints() << endl;
}


void ContestantList::toFileC(string fileName){
	ofstream outFile;
	outFile.open(fileName);

    for(int i = 0; i < cTotalList.size(); i++){
        cTotalList[i].printToFile(outFile);
    }

    outFile.close();
}
