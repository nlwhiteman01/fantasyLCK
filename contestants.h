#pragma once
#include "playerlist.h"

class Contestant: public PlayerList{
	public:
		Contestant();
        Contestant(string, string, string, string, string, string, string, double, double, double);
		~Contestant();

        void setPlayer(const string, int);
        void setTotalPoints(const double);
        void setTeamPoints(const int);
        void setWeeklyPoints(const PlayerList);
        void addTotalPoints();
        bool compareNames(string);

        const string getCName() const;
        const string getTeam() const;
        const double getTeamPoints() const;
        const double getWeeklyPoints() const;

        void print();
        void printToFile(ofstream &);


	private:
        string cName;
        string top;
        string jungle;
        string mid;
        string adc;
        string support;
        string team;

        double pointsFromTeam;
        double totalPoints;
        double weeklyPoints;
};