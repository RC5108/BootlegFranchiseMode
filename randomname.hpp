#ifndef RANDOMNAME_HPP
#define RANDOMNAME_HPP

#include <string>
#include <vector>
#include <random>
#include <ctime>
#include <cstdlib>
#include <random>
#include <set>
#include <vector>
using namespace std;


class RandomName {
public:
	static string getRandomName();
	static int generateUniqueNumber(const set<int>& exisitingNumbers);
private:
	// Keep track of names already being used by other players
	static std::set<string> usedNames;
};

#endif // RANDOMNAME_HPP