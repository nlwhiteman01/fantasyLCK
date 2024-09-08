#include "playerlist.h"

//Default Constructor
PlayerList::PlayerList(){
}

//Constructs List
PlayerList::PlayerList(string playerFile){
	ifstream inFile;
	inFile.open(playerFile);
	if(!inFile){
		cout << "File did not open!" << endl;
		exit(1);
	}

	
	Players tempPlayer;
	string name, teamName, lane;
	int kills, deaths, assists, cs;

	getline(inFile, name, ',');
	while(!inFile.eof()){
		
		getline(inFile, teamName, ',');
	
		getline(inFile, lane, ',');
		
		inFile >> kills;
		inFile.ignore(5, ',');

        inFile >> deaths;
        inFile.ignore(5, ',');

        inFile >> assists;
		inFile.ignore(5, ',');

		inFile >> cs;
		inFile.ignore(MAX_CHAR, '\n');
		
		//Building tempPlayer
		tempPlayer.setName(name);
		tempPlayer.setTeamName(teamName);
		tempPlayer.setLane(lane);
		tempPlayer.setKills(kills);
		tempPlayer.setDeaths(deaths);
		tempPlayer.setAssists(assists);
		tempPlayer.setCS(cs);
		loadData("data.txt", tempPlayer);
		addPlayer(tempPlayer);

		getline(inFile, name, ',');
	}
	inFile.close();	

	//Pushing team vectors to list
	totalList.push_back(dplusKia);
	totalList.push_back(drx);
	totalList.push_back(fearX);
	totalList.push_back(genG);
	totalList.push_back(hanwha);	
	totalList.push_back(ktRolster);
	totalList.push_back(kdf);
	totalList.push_back(nsRedforce);
	totalList.push_back(okBro);
	totalList.push_back(t1);
}



//Destructor
PlayerList::~PlayerList(){
}


vector<vector<Players>> PlayerList::getList() const{
	return totalList;
}

//Sets strings to lower case
string PlayerList::toLowerCase(const string teamName){
	string newStr = teamName;
	for(unsigned int i = 0; i < teamName.size(); i++){
		newStr[i] = tolower(teamName[i]);
	}
	return newStr;
}



//Creates a new player and passes it into totalList and team vector
bool PlayerList::newPlayer(string userName, string userTeam, string userLane){
	Players tempPlayer;

	bool lane = laneCheck(userLane);

	if(lane == false){
		return false;
	}

	tempPlayer.setName(userName);
	tempPlayer.setTeamName(userTeam);
	tempPlayer.setLane(userLane);

	string lower = toLowerCase(tempPlayer.getTeamName());
	for(unsigned int i = 0; i < totalList.size(); i++){
		string lowerTeam = toLowerCase(totalList[i][1].getTeamName());
		if(lower.compare(lowerTeam) == 0){
			loadData("data.txt", tempPlayer);			
			totalList[i].push_back(tempPlayer);
			addPlayer(tempPlayer);
			return true;
		}
	}
	return false;
}



//Checks is lane is real
bool PlayerList::laneCheck(string userLane){
	userLane = toLowerCase(userLane);

	if(userLane.compare("top") != 0 && userLane.compare("jungle") != 0 &&
		userLane.compare("mid") != 0 && userLane.compare("adc") != 0 &&
		userLane.compare("support") != 0){
			return false;
		}
	else{
		return true;
	}
}


//Checks is player is real
bool PlayerList::playerCheck(string userName, int role){
	userName = toLowerCase(userName);
	string userRole;

	switch(role){
		case 0:
			userRole = "top";
			break;
		case 1:
			userRole = "jungle";
			break;
		case 2: 
			userRole = "mid";
			break;
		case 3:
			userRole = "adc";
			break;
		case 4:
			userRole = "support";
			break;
	}


	for(unsigned int i = 0; i < totalList.size(); i++){
		for(unsigned int j = 0; j < totalList[i].size(); j++){
			string lower = toLowerCase(totalList[i][j].getName());
			string playerRole = toLowerCase(totalList[i][j].getLane());
			if(userName.compare(lower) == 0 && userRole.compare(playerRole) == 0){
				return true;
			}
		}
	}
	return false;

}



//Adds player to team vector
void PlayerList::addPlayer(Players tempPlayer){
	string lower = toLowerCase(tempPlayer.getTeamName());
	if(lower.compare("dplus kia") == 0){
		dplusKia.push_back(tempPlayer);
	}
	else if(lower.compare("drx") == 0){
		drx.push_back(tempPlayer);
	}
	else if(lower.compare("fearx") == 0){
		fearX.push_back(tempPlayer);
	}
	else if(lower.compare("geng") == 0){
		genG.push_back(tempPlayer);
	}
	else if(lower.compare("hanwha life") == 0){
		hanwha.push_back(tempPlayer);
	}
	else if(lower.compare("kt rolster") == 0){
		ktRolster.push_back(tempPlayer);
	}
	else if(lower.compare("kwangdong freecs") == 0){
		kdf.push_back(tempPlayer);
	}
	else if(lower.compare("ns redforce") == 0){
		nsRedforce.push_back(tempPlayer);
	}
	else if(lower.compare("ok brion") == 0){
		okBro.push_back(tempPlayer);
	}
	else{
		t1.push_back(tempPlayer);
	}
}



//Removes player from totalList and team vector
bool PlayerList::removePlayer(string playerName, string teamName){
	string lowerName = toLowerCase(playerName);
	string lowerTeam = toLowerCase(teamName);

	for(unsigned int i = 0; i < totalList.size(); i++){

		for(unsigned int j = 0; j < totalList[i].size(); j++){
			string passName = toLowerCase(totalList[i][j].getName());

			if(lowerName.compare(passName) == 0){
				string passTeam = toLowerCase(totalList[i][j].getTeamName());

				if(lowerTeam.compare(passTeam) != 0){
					return false;
				}

				totalList[i].erase(totalList[i].begin() + j);
				if(lowerTeam.compare("dplus kia") == 0){
					for(unsigned int i = 0; i < dplusKia.size(); i++){
						string sectionName = toLowerCase(dplusKia[i].getName());
						if(lowerName.compare(sectionName) == 0){
							dplusKia.erase(dplusKia.begin() + i);
						}
					}
				}
				else if(lowerTeam.compare("drx") == 0){
					for(unsigned int i = 0; i < drx.size(); i++){
						string sectionName = toLowerCase(drx[i].getName());
						if(lowerName.compare(sectionName) == 0){
							drx.erase(drx.begin() + i);
						}
					}
				}
				else if(lowerTeam.compare("fearx") == 0){
					for(unsigned int i = 0; i < fearX.size(); i++){
						string sectionName = toLowerCase(fearX[i].getName());
						if(lowerName.compare(sectionName) == 0){
							fearX.erase(fearX.begin() + i);
						}
					}
				}
				else if(lowerTeam.compare("geng") == 0){
					for(unsigned int i = 0; i < genG.size(); i++){
						string sectionName = toLowerCase(genG[i].getName());
						if(lowerName.compare(sectionName) == 0){
							genG.erase(genG.begin() + i);
						}
					}
				}
				else if(lowerTeam.compare("hanwha life") == 0){
					for(unsigned int i = 0; i < hanwha.size(); i++){
						string sectionName = toLowerCase(hanwha[i].getName());
						if(lowerName.compare(sectionName) == 0){
							hanwha.erase(hanwha.begin() + i);
						}
					}
				}
				else if(lowerTeam.compare("kt rolster") == 0){
					for(unsigned int i = 0; i < ktRolster.size(); i++){
						string sectionName = toLowerCase(ktRolster[i].getName());
						if(lowerName.compare(sectionName) == 0){
							ktRolster.erase(ktRolster.begin() + i);
						}
					}
				}
				else if(lowerTeam.compare("kwangdong freecs") == 0){
					for(unsigned int i = 0; i < kdf.size(); i++){
						string sectionName = toLowerCase(kdf[i].getName());
						if(lowerName.compare(sectionName) == 0){
							kdf.erase(kdf.begin() + i);
						}
					}
				}
				else if(lowerTeam.compare("ns redforce") == 0){
					for(unsigned int i = 0; i < nsRedforce.size(); i++){
						string sectionName = toLowerCase(nsRedforce[i].getName());
						if(lowerName.compare(sectionName) == 0){
							nsRedforce.erase(nsRedforce.begin() + i);
						}
					}
				}
				else if(lowerTeam.compare("ok brion") == 0){
					for(unsigned int i = 0; i < okBro.size(); i++){
						string sectionName = toLowerCase(okBro[i].getName());
						if(lowerName.compare(sectionName) == 0){
							okBro.erase(okBro.begin() + i);
						}
					}
				}
				else{
					for(unsigned int i = 0; i < t1.size(); i++){
						string sectionName = toLowerCase(t1[i].getName());
						if(lowerName.compare(sectionName) == 0){
							t1.erase(t1.begin() + i);
						}
					}
				}
				return true;
			}
		}
	}
	return false;
}



//Loads data from file
void PlayerList::loadData(string dataFile, Players &tempPlayer){
	string lower = toLowerCase(tempPlayer.getName());
	ifstream inFile;
    inFile.open(dataFile);
    if(!inFile){
        cout << "File did not open!" << endl;
        exit(1);
    }

    string name, teamName, tempName;
    int kills, deaths, assists, cs;
	int totalKills = 0, totalDeaths = 0, totalAssists = 0, totalCS = 0;
    getline(inFile, name, ',');
    while(!inFile.eof()){
			
		tempName = toLowerCase(name);
        getline(inFile, teamName, ',');

        inFile >> kills;
        inFile.ignore(5, ',');
        inFile >> deaths;
        inFile.ignore(5, ',');

        inFile >> assists;
        inFile.ignore(5, ',');

        inFile >> cs;
        inFile.ignore(MAX_CHAR, '\n');

		if(lower.compare(tempName) == 0){
			totalKills += kills;
			totalDeaths += deaths;
			totalAssists += assists;
			totalCS += cs;
		}

        getline(inFile, name, ',');
    }
    inFile.close();

	tempPlayer.setKills(totalKills);
	tempPlayer.setDeaths(totalDeaths);
	tempPlayer.setAssists(totalAssists);
	tempPlayer.setCS(totalCS);
	tempPlayer.setPoints(totalKills, totalDeaths, totalAssists, totalCS);

}	



//Prints totalList
void PlayerList::printList(){
	int counter = 0;
	cout << endl;
	printTemplate();
	for(unsigned int i = 0; i < totalList.size(); i++){
		for(unsigned int j = 0; j < totalList[i].size(); j++){
			counter++;
			if(counter == 1){
				cout << totalList[i][j].getTeamName() << endl;
			}
			totalList[i][j].print();
		}
		cout << endl;
		counter = 0;
	}
}



//Prints team vector
void PlayerList::printTeam(string team){
	string lower = toLowerCase(team);
	cout << endl;
	printTemplate();
	if(lower.compare("dplus kia") == 0){
		for(unsigned int i = 0; i < dplusKia.size(); i++){
			dplusKia[i].print();
		}
	}
	else if(lower.compare("drx") == 0){
		for(unsigned int i = 0; i < drx.size(); i++){
			drx[i].print();
		}
	}
	else if(lower.compare("fearx") == 0){
		for(unsigned int i = 0; i < fearX.size(); i++){
			fearX[i].print();
		}
	}
	else if(lower.compare("geng") == 0){
		for(unsigned int i = 0; i < genG.size(); i++){
			genG[i].print();
		}
	}
	else if(lower.compare("hanwha life") == 0){
		for(unsigned int i = 0; i < hanwha.size(); i++){
			hanwha[i].print();
		}
	}
	else if(lower.compare("kt rolster") == 0){
		for(unsigned int i = 0; i < ktRolster.size(); i++){
			ktRolster[i].print();
		}
	}
	else if(lower.compare("kwangdong freecs") == 0){
		for(unsigned int i = 0; i < kdf.size(); i++){
			kdf[i].print();
		}
	}
	else if(lower.compare("ns redforce") == 0){
		for(unsigned int i = 0; i < nsRedforce.size(); i++){
			nsRedforce[i].print();
		}
	}
	else if(lower.compare("ok brion") == 0){
		for(unsigned int i = 0; i < okBro.size(); i++){
			okBro[i].print();
		}
	}
	else if(lower.compare("t1") == 0){
		for(unsigned int i = 0; i < t1.size(); i++){
			t1[i].print();
		}
	}
	else{
		cout << "Team does not exist!" << endl;
	}
	cout << endl;
}



bool PlayerList::printPlayer(string userPlayer){
	userPlayer = toLowerCase(userPlayer);

	for(unsigned int i = 0; i < totalList.size(); i++){
		for(unsigned int j = 0; j < totalList[i].size(); j++){
			string lower = toLowerCase(totalList[i][j].getName());
			if(userPlayer.compare(lower) == 0){
				cout << endl;
				printTemplate();
				cout << totalList[i][j].getTeamName() << endl;
				totalList[i][j].print();
				cout << endl;
				return true;
			}
		}
	}
	return false;
}

void PlayerList::topScorers(){
	vector<Players> topPoints;

	for(unsigned int i = 0; i < totalList.size(); i++){
		for(unsigned int j = 0; j < totalList[i].size(); j++){
			string lower = toLowerCase(totalList[i][j].getLane());
			if(lower.compare("top") == 0){
				if(topPoints.empty() == true){
					topPoints.push_back(totalList[i][j]);
				}
				else{
					if(topPoints[0].getPoints() < totalList[i][j].getPoints()){
						topPoints[0] = totalList[i][j];
					}
				}
			}
		}
	}

	for(unsigned int i = 0; i < totalList.size(); i++){
		for(unsigned int j = 0; j < totalList[i].size(); j++){
			string lower = toLowerCase(totalList[i][j].getLane());
			if(lower.compare("jungle") == 0){
				if(topPoints.size() < 2){
					topPoints.push_back(totalList[i][j]);
				}
				else{
					if(topPoints[1].getPoints() < totalList[i][j].getPoints()){
						topPoints[1] = totalList[i][j];
					}
				}
			}
		}
	}
	for(unsigned int i = 0; i < totalList.size(); i++){
		for(unsigned int j = 0; j < totalList[i].size(); j++){
			string lower = toLowerCase(totalList[i][j].getLane());
			if(lower.compare("mid") == 0){
				if(topPoints.size() < 3){
					topPoints.push_back(totalList[i][j]);
				}
				else{
					if(topPoints[2].getPoints() < totalList[i][j].getPoints()){
						topPoints[2] = totalList[i][j];
					}
				}
			}
		}
	}	
	for(unsigned int i = 0; i < totalList.size(); i++){
		for(unsigned int j = 0; j < totalList[i].size(); j++){
			string lower = toLowerCase(totalList[i][j].getLane());
			if(lower.compare("adc") == 0){
				if(topPoints.size() < 4){
					topPoints.push_back(totalList[i][j]);
				}
				else{
					if(topPoints[3].getPoints() < totalList[i][j].getPoints()){
						topPoints[3] = totalList[i][j];
					}
				}
			}
		}
	}
	for(unsigned int i = 0; i < totalList.size(); i++){
		for(unsigned int j = 0; j < totalList[i].size(); j++){
			string lower = toLowerCase(totalList[i][j].getLane());
			if(lower.compare("support") == 0){
				if(topPoints.size() < 5){
					topPoints.push_back(totalList[i][j]);
				}
				else{
					if(topPoints[4].getPoints() < totalList[i][j].getPoints()){
						topPoints[4] = totalList[i][j];
					}
				}
			}
		}
	}	

	printTop(topPoints);
}



void PlayerList::printTop(vector<Players> topPoints){
	cout << fixed << setprecision(2);
	cout << endl;
	cout << left << "Name";
	cout << right << setw(20) << "Lane";
	cout << right << setw(20) << "Points" << endl;

	for(unsigned int i = 0; i < topPoints.size(); i++){
		cout << fixed; 
		cout << left << topPoints[i].getName();
		cout << right << setw(24 - topPoints[i].getName().size()) << topPoints[i].getLane();
		cout << right << setw(20) << topPoints[i].getPoints();
		cout << endl;
	}
}



//Just a template
void PlayerList::printTemplate(){
	cout << fixed;
	cout << left << "Name";
    cout << right << setw(20) << "Kills";
    cout << right << setw(10) << "Deaths";
    cout << right << setw(10) << "Assists";
	cout << right << setw(7) << "CS";
    cout << right << setw(10) << "Points" << endl;
}

void PlayerList::toFile(const string fileName){
	ofstream outFile;
	outFile.open(fileName);
	
	for(unsigned int i = 0; i < totalList.size(); i++){
		for(unsigned int j = 0; j < totalList[i].size(); j++){
			totalList[i][j].printFile(outFile);
		}
	}

	outFile.close();
}
