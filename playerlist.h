#pragma once
#include "players.h"

class PlayerList{
	public:
		PlayerList();
		PlayerList(string);
		~PlayerList();

		//Edit Functions
		string toLowerCase(const string);
		vector<vector<Players>> getList() const;
		bool newPlayer(string, string, string);
		bool laneCheck(string);
		bool playerCheck(string userName, int role);
		void addPlayer(Players);
		bool removePlayer(string, string);
		void loadData(const string, Players &);
		void topScorers();

		//Print Functions
		void printList();
		void printTeam(string);
		void printTemplate();
		bool printPlayer(string);
		void printTop(vector<Players>);
		void toFile(const string);


	private:
		vector<Players> dplusKia;
		vector<Players> drx;
		vector<Players> fearX;
		vector<Players> genG;
		vector<Players> hanwha;
		vector<Players> ktRolster;
		vector<Players> kdf;
		vector<Players> nsRedforce;
		vector<Players> okBro;
		vector<Players> t1;

		vector<vector<Players>> totalList;
};
