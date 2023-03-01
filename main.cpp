#include <iostream> // Include input/output stream library
#include <fstream> // Include file stream library
#include <conio.h> // Include console input/output library

using namespace std; // Use standard namespace

bool IsLoggedIn() { // Check if user is logged in function
    string username, password, un, pw; // Declare string variables for username, password, and file data

    cout << "Enter username: "; cin >> username; // Prompt user to enter username
    cout << "Enter password: "; cin >> password; // Prompt user to enter password

    ifstream read(username + ".txt"); // Opens file with the given username
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

int main() { // Main function
    int choice; // Declare integer variable for user's choice

    while (true) { // Loop while true
        // Prompt user to select an action from the menu
        cout << "1: Register\n2: Login\n3: Exit\nYour choice: ";
        cin >> choice; // Read user's choice

        if (choice == 1) { // If the user chooses to register
            string username, password; // Declare string variables for username and password

            // Prompt user to enter a username and a password
            cout << "select a username: ";
            cin >> username;
            cout << "select a password: ";
            cin >> password;

            ifstream file(username + ".txt"); // Open file with the given username

            if (!file.good()) { // If the file does not exist
                // Save the username and password to a file
                ofstream newfile(username + ".txt"); // Create new file with the given username
                newfile << username << endl << password; // Write username and password to the file
                newfile.close(); // Close the file
                cout << "Registration successful" << endl; // Display success message
                _getch(); // Wait for user input
            }
            else if (file.good()) { // If the file exists
                cout << "User with such username already exists" << endl; // Display error message
                _getch(); // Wait for user input
            }
        } else if (choice == 2) { // If the user chooses to log in
            bool status = IsLoggedIn(); // Call IsLoggedIn() function and save the result to status variable

            if (!status) { // If login fails
                // Display error message if login fails
                cout << "False Login!" << endl;
                _getch(); // Wait for user input
            } else { // If login succeeds
                // Display success message if login succeeds
                cout << "Successfully logged in!" << endl;
                _getch(); // Wait for user input
                return 1; // Exit the program with code 1
            }
        } else if (choice == 3) { // If the user chooses to exit
            break; // Exit the loop and terminate the program
        }
    }

    return 0; // Exit the program with code 0
}
