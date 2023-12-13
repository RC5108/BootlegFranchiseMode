#include "randomname.hpp"



set<string> RandomName::usedNames = {};

//pre: Generates a random name from a predefined list
//post: Returns a unique name that hasn't been used in the current context
string RandomName::getRandomName() {

    static vector<string> names = {
        "John Doe", "Gary Smith", "Alex Johnson", "Curtis Brown",
        "Michael Davis", "Tomas Hertl", "Bryan Wilson", "David Martinez",
        "James Taylor", "Joey Anderson", "Erik Eriksson", "Lars Lagesson",
        "Sergei Federov", "Mike Carcone", "Nick Suzuki", "Kaapo Kahkonen", "Quinten Musty",
        "William Eklund"
    };

    if (usedNames.size() >= names.size()) {
        usedNames.clear();
    }

    // Seed the random number generator
    static bool seeded = false;
    if (!seeded) {
        std::srand(static_cast<unsigned int>(std::time(nullptr)));
        seeded = true;
    }
    string name;
    do {
        size_t index = std::rand() % names.size();  // Generate a random index
        name = names[index];
    } while (usedNames.find(name) != usedNames.end()); // Check if the name has already been used

    usedNames.insert(name); // Insert the new unique name into the set of used names
    return name;
}

//pre: Generates a unique number not present in the given set
//post: Returns a unique number between 1 and 98
int RandomName::generateUniqueNumber(const std::set<int>& existingNumbers) {
    srand(static_cast<unsigned int>(std::time(nullptr)));
    // Infinite loop: Keep generating numbers until we find a unique one
    while (true) {
        // Generate a random number within the specified range
        int randomNumber = rand() % 98 + 1;

        // Check if the generated number is already in the set of existing numbers
        if (existingNumbers.find(randomNumber) == existingNumbers.end()) {
            // If the number is not found in the set, it is unique; return it
            return randomNumber;
        }
        // If the number is found, the loop continues, generating a new number
    }
}