#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include <iomanip>

using namespace std;

const int MAX_CHAR = 101;

class Players{
	public:
		Players();
		Players(string, string, string, int, int, int, int);
		~Players();
		
		void setName(const string);
		void setTeamName(const string);
		void setLane(const string);
		void setKills(const int);
		void setDeaths(const int);
		void setAssists(const int);
		void setCS(const int);
		void setPoints(const int totalKills, int totalDeaths, int totalAssists, int totalCS);
		const string getName() const;
		const string getTeamName() const;
		const string getLane() const;
		const double getPoints() const;

		void print();
		void printFile(ofstream &);
	private:
		string name;
		string teamName;
		string lane;
		int kills;
		int assists;
		int deaths;
		int cs;
		double playerPoints;
};

