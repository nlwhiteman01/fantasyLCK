#include "contestants.h"

Contestant::Contestant(){
    top = "no player";
    jungle = "no player";
    mid = "no player";
    adc = "no player";
    support = "no player";
    team = "no team";
    totalPoints = 0;
    weeklyPoints = 0;
}

Contestant::Contestant(string newCName, string newTop, string newJungle, 
                        string newMid, string newADC,string newSupport, 
                        string newTeam, double newTPoints, double newTotal, double newWeekly){
    cName = newCName;                     
    top = newTop;
    jungle = newJungle;
    mid = newMid;
    adc = newADC;
    support = newSupport;
    team = newTeam;
    pointsFromTeam = newTPoints;
    totalPoints = newTotal;
    weeklyPoints = newWeekly;
}

Contestant::~Contestant(){

}

void Contestant::setPlayer(const string newLane, int role){
    switch(role){
        case 0:
            top = newLane;
            break;
        case 1:
            jungle = newLane;
            break;
        case 2:
            mid = newLane;
            break;
        case 3:
            adc = newLane;
            break;
        case 4:
            support = newLane;
            break;
        case 5:
            team = newLane;
            break;
        case 6:
            cName = newLane;
            break;
    }
}

void Contestant::setWeeklyPoints(const PlayerList everything){
    double newPoints;
    bool isName = false;
    vector<vector<Players>> totalList = everything.getList();

	for(unsigned int i = 0; i < totalList.size(); i++){
		for(unsigned int j = 0; j < totalList[i].size(); j++){
            isName = compareNames(totalList[i][j].getName());
            if(isName == true){
                newPoints += totalList[i][j].getPoints();
            }
            isName = false;
		}
	}

    weeklyPoints = newPoints + pointsFromTeam;	

}

void Contestant::setTeamPoints(const int wins){
    pointsFromTeam = wins * 2.5;
}

void Contestant::setTotalPoints(const double newPoints){
    totalPoints = newPoints;
}

void Contestant::addTotalPoints(){
    totalPoints += weeklyPoints;
}


bool Contestant::compareNames(string listName){
    listName = toLowerCase(listName);
    string tempTop = toLowerCase(top);
    string tempJungle = toLowerCase(jungle);
    string tempMid = toLowerCase(mid);
    string tempADC = toLowerCase(adc);
    string tempSupport = toLowerCase(support);

    if(tempTop.compare(listName) == 0 || tempJungle.compare(listName) == 0 ||
        tempMid.compare(listName) == 0 || tempADC.compare(listName) == 0 ||
        tempSupport.compare(listName) == 0){
            return true;
        }
    return false;

}

const string Contestant::getCName() const{
	return cName;
}

const string Contestant::getTeam() const{
	return team;
}

const double Contestant::getWeeklyPoints() const{
    return weeklyPoints;
}

const double Contestant::getTeamPoints() const{
    return pointsFromTeam;
}

void Contestant::print(){
	cout << fixed << setprecision(2);
	cout << left << cName << ":";
	cout << right << setw(35 - cName.size()) << weeklyPoints;
	cout << right << setw(20) << totalPoints << endl;   
}

void Contestant::printToFile(ofstream &outFile){
    outFile << fixed << setprecision(2);
    outFile << cName << ","  << top << "," << jungle << "," << mid << ","
            << adc << "," << support << "," << team << "," << totalPoints << endl;
}