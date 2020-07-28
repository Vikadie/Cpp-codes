/*
Teams

You are given a list of teams and their members, competing in a league for the Counter-Attack: Globally Offensive game 
(yep, still shamelessly avoiding copyright). A player can be a member of multiple teams in the league, and each team can participate in multiple 
games throughout the league. Player scores are determined by the number of victories their team has throughout the league.
Write a program, which, given a list of teams and the players in those teams, and given another list with the winner for each game played, 
prints out the player scores, sorted by player name.
Input
The first line of the standard input contains a single integer number T – the number of teams.
Each of the following T lines describes a team. Each line begins with the team name (lowercase English characters), followed by a positive integer M 
– the number of players in the team, and followed by M player names (lowercase English characters). These are separated by single spaces.
The next line contains a single integer G – the number of games played in the league.
Each of the following G lines describes the result of a game – i.e. the name of the team that won.
Output
A single line containing integers, separated by single spaces – the scores of the players, ordered by the lexicographical order of the player names.
*/
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

int main() {
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);
	
	int T;
	cin >> T >> ws;
	
	map <string, vector <string> > Players; // player : vector <teamName>
	while (T--) {
		string str;
		getline(cin, str);
		string teamName;
		int numPlayers;
		istringstream in(str);

		in >> teamName >> numPlayers;
		while (numPlayers--) {
			string player;
			in >> player;
			Players[player].push_back(teamName);
		}
	}

	int gamePlayed;
	map <string, int> wonGames; //teamName : won points in games
	cin >> gamePlayed;
	while (gamePlayed--) {
		string winTeam;
		cin >> winTeam;
		wonGames[winTeam]++;
	}

	map <string, int > ranking; // ranking -> player : points
	for (auto i : wonGames) { //teamName : won points in games
		for (auto j : Players) // player : vector <teamName>
			for (auto k : j.second) // k in vector of team's names
				if (k == i.first)
					ranking[j.first] += i.second;
				else
					ranking[j.first] += 0;
	}

	for (auto i : ranking) {
		cout << i.second << " ";
	}

	return 0;
}