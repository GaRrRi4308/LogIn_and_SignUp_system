#include <iostream>
#include <fstream>

using namespace std;

bool IsLoggedIn() { // Check if user is logged in function
    string username, password, un, pw;

    cout << "Enter username: "; cin >> username; // Prompt user to enter username
    cout << "Enter password: "; cin >> password; // Prompt user to enter password

    ifstream read("data\\" + username + ".txt"); // Opens file with the given username
    getline(read, un); // Reads the first line from the file which contains the username
    getline(read, pw); // Reads the second line from the file which contains the password

    if (un == username && pw == password) // If the entered data matches the data in the file
    {
        return true; // Returns true, which means successful login
    }
    else
    {
        return false; // Returns false, which means unsuccessful login
    }
}

int main() {
    int choice;

    cout << "1: Register\n2: Login\nYour choice: "; cin >> choice; // Displays menu to select an action
    if (choice == 1) // If the user chooses to register
    {
        string username, password;

        cout << "select a username: "; cin >> username; // Prompts user to enter a username
        cout << "select a password: "; cin >> password; // Prompts user to enter a password

        // TODO: add code to save the username and password to a file
    }
    else if (choice == 2) // If the user chooses to log in
    {
        IsLoggedIn(); // Calls the function to check if the user is logged in
    }
}
