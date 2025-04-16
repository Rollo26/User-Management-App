#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Structure to store member details
struct Member {
    string fullName;
    string contactNumber;
    string experienceLevel;
};

// Global vector to store members
vector<Member> members;

// Function to add a new member
void addMember() {
    if (members.size() >= 150) {
        cout << "Member limit reached. Cannot add more members.\n";
        return;
    }

    Member newMember;
    cout << "Enter full name: ";
    cin.ignore(); // Clear input buffer
    getline(cin, newMember.fullName);
    cout << "Enter contact number: ";
    getline(cin, newMember.contactNumber);
    cout << "Enter programming experience level: ";
    getline(cin, newMember.experienceLevel);

    members.push_back(newMember);
    cout << "Member added successfully.\n";
}

// Function to search for a member by name
void searchMember() {
    string name;
    cout << "Enter the name of the member to search: ";
    cin.ignore(); // Clear input buffer
    getline(cin, name);

    for (const auto& member : members) {
        if (member.fullName == name) {
            cout << "Member found:\n";
            cout << "Name: " << member.fullName << "\n";
            cout << "Contact Number: " << member.contactNumber << "\n";
            cout << "Experience Level: " << member.experienceLevel << "\n";
            return;
        }
    }
    cout << "Member not found.\n";
}

// Function to view all members
void viewMembers() {
    if (members.empty()) {
        cout << "No members registered.\n";
        return;
    }

    cout << "List of all members:\n";
    for (const auto& member : members) {
        cout << "Name: " << member.fullName << "\n";
        cout << "Contact Number: " << member.contactNumber << "\n";
        cout << "Experience Level: " << member.experienceLevel << "\n";
        cout << "--------------------------\n";
    }
}

// Function to exit the program
void exitProgram() {
    cout << "Exiting the program. Goodbye!\n";
    exit(0);
}

// Main function
int main() {
    int choice;

    do {
        cout << "\nTech Innovation Hub Member Management System\n";
        cout << "1. Add Member\n";
        cout << "2. Search Member\n";
        cout << "3. View All Members\n";
        cout << "4. Exit Program\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addMember();
            break;
        case 2:
            searchMember();
            break;
        case 3:
            viewMembers();
            break;
        case 4:
            exitProgram();
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (true);

    return 0;
}
