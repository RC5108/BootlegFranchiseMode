/*
Marc Baldwin
Program that simulates what it takes to be a General Manager of a hockey team
*/

#include <iostream>
#include <fstream>
#include <chrono>
#include <thread>
#include "team.hpp"
#include "schedule.hpp"

using namespace std;

// Function to save your team to an output file
void saveTeamData(const std::string& filename, const Team& team) {
	ofstream outFile(filename);
	if (!outFile.is_open()) {
		cerr << "Failed to open file: " << filename << std::endl;
		return;
	}
	team.saveToFile(outFile);
	outFile.close();
}

// Function to provide a new menu when the user creates/loads a team
void inSeasonMenu(Team& team) {
	int option;
	bool cont = true;
	cout << "Generating team..." << endl;
	this_thread::sleep_for(chrono::seconds(2));
	cout << "Signing players..." << endl;
	this_thread::sleep_for(chrono::seconds(2));
	cout << "Building schedule..." << endl;
	this_thread::sleep_for(chrono::seconds(2));
	cout << endl;
	cout << "Season ready to begin!" << endl;
	while (cont) {
		cout << "-------------------" << endl;
		cout << "1. Simulate next game" << endl;
		cout << "2. View upcoming games" << endl;
		cout << "3. View standings" << endl;
		cout << "4. View roster" << endl;
		cout << "5. Display stats" << endl;
		cout << "6. Exit" << endl;
		cout << "-------------------" << endl;
		cin >> option;
		switch (option) {
		case 1:
			break;
		case 2:
			team.viewUpcomingGames(3);
			break;
		case 3:
			break;
		case 4:
			cout << "Team Roster:" << endl;
			for (const Player& player : team.getPlayers()) {
				cout << player.getPosition() << " " << player.getName();
				cout << endl;
			}
			break;
		case 5:
			cout << "Team Stats:" << endl;
			team.displayTeam();
			break;
		case 6:
			cout << "You have exited the current season" << endl;
			cout << "Saving team..." << endl;
			this_thread::sleep_for(chrono::seconds(2));
			cout << "Exiting to main menu..." << endl;
			this_thread::sleep_for(chrono::seconds(2));
			cont = false;
			break;
		}
	}
}


int main() {
	// Folder path to store all of the teams in the same location
	string folderPath = "C:\\Users\\RC_5108\\source\\repos\\HockeySimulator\\HockeySimulator\\TeamFolder\\";
	int option;
	bool cont = true;
	string filepath;
	string fileName;
	string userTeamName;
	Team blueTeam;
	Team greenTeam;
	Team redTeam;
	Team userTeam;
	ifstream inFile;
	// Non-user opponents 
	saveTeamData(folderPath + "blueTeam_data.txt", blueTeam);
	saveTeamData(folderPath + "greenTeam.txt", greenTeam);
	saveTeamData(folderPath + "redTeam.txt", redTeam);


	cout << "Bootleg Franchise Mode" << endl;
	cout << "Version 23.12.6" << endl;
	// Main menu that the user can select options from
	while (cont) {
		cout << "-------------------" << endl;
		cout << "1. Create new team" << endl;
		cout << "2. Load team" << endl;
		cout << "3. Exit" << endl;
		cout << "-------------------" << endl;
		// User selection if they wish to create a new team or load one from a txt file
		cout << "Enter an option: " << endl;
		cin >> option;

		switch (option) {
		case 1:
			cout << "You have selected create a new team." << endl;
			cout << "Enter your team name: " << endl;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			getline(cin, userTeamName);
			fileName = folderPath + userTeamName + ".txt";
			saveTeamData(fileName, userTeam);
			inSeasonMenu(userTeam);
			break;
		case 2:
			cout << "You have selected load team." << endl;
			cout << "Enter the file path containing your team: " << endl;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear the input buffer
			getline(cin, filepath);  // Use getline to allow for spaces in the path
			// Remove quote marks if present
			if (!filepath.empty() && filepath.front() == '\"' && filepath.back() == '\"') {
				filepath = filepath.substr(1, filepath.length() - 2);
			}
			inFile.open(filepath);
			if (inFile.is_open()) {
				inFile.close();  // Close the file after loading the data
				inSeasonMenu(userTeam);
			}
			else {
				// Handle the error, such as notifying the user and/or returning to the menu
				cout << "Failed to open file: " << filepath << endl;
			}
			break;
		case 3:
			cout << "Exiting..." << endl;
			cont = false;
			break;
		}
	}


	return 0;
}


