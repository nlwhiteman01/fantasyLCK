#pragma once
#include "contestants.h"


class ContestantList:public Contestant{
    public: 
        ContestantList();
        ContestantList(string, const PlayerList);
        ~ContestantList();

        bool newContestant(string);
        bool removeContestant(string);
        bool editContestant(string, string, int, PlayerList);
        void setTeamPointsAll();
        void setWPointsAll(PlayerList players);
        void setTPointsAll();

        void printContestantList();
        bool printContestantTeam(string, PlayerList);
        void printConTeam(PlayerList, int);
        void toFileC(const string);

    private:
        vector<Contestant> cTotalList;
};