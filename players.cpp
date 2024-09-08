#include "players.h"

Players::Players(){
	name = "no player";
	teamName = "no team";
	lane = "no lane";
	kills = 0;
	deaths = 0;
	assists = 0;
	cs = 0;
	playerPoints = 0;
}

Players::Players(string newName, string newTeamName, string newLane,
				int newKills, int newDeaths, int newAssists, int newCS){
	name = newName;
	teamName = newTeamName;
	lane = newLane;
	kills = newKills;
	deaths = newDeaths;
	assists = newAssists;
	cs = newCS;
	playerPoints = 0;
}

Players::~Players(){
}

void Players::setName(const string newName){
	name = newName;
}

void Players::setTeamName(const string newTeamName){
	teamName = newTeamName;
}

void Players::setLane(const string newLane){
	lane = newLane;
}

void Players::setKills(const int newKills){
	kills = newKills;
}

void Players::setDeaths(const int newDeaths){
	deaths = newDeaths;
}

void Players::setAssists(const int newAssists){
	assists = newAssists;
}
	
void Players::setCS(const int newCS){
	cs = newCS;
}

void Players::setPoints(const int totalKills, int totalDeaths, int totalAssists, int totalCS){
	if(lane.compare("top") == 0 || lane.compare("jungle") == 0){
		playerPoints = (totalKills * .4) + (totalAssists * .2) + (totalCS * 0.002) - (totalDeaths * .15);
	}
	else if(lane.compare("mid") == 0 || lane.compare("adc") == 0){
		playerPoints = (totalKills * .4) + (totalAssists * .15) + (totalCS * 0.0015) - (totalDeaths * .2);
	}
	else{
		playerPoints = (totalKills * .3) + (totalAssists * .25) + (totalCS * 0.003) - (totalDeaths * .1);
	}
}

const string Players::getName() const{
	return name;
}

const string Players::getTeamName() const{
	return teamName;
}

const string Players::getLane() const{
	return lane;
}

const double Players::getPoints() const{
	return playerPoints;
}

void Players::print(){
	cout << setprecision(2);
	cout << left << name << ":";
	cout << right << setw(20 - name.size()) << kills;
	cout << right << setw(10) << deaths; 
	cout << right << setw(10) << assists;
	cout << right << setw(10) << cs;
	cout << right << setw(10) << playerPoints << endl;
}	

void Players::printFile(ofstream &outFile){
	outFile << name << "," << teamName << "," << lane << "," << "0,0,0,0" << endl;
}
