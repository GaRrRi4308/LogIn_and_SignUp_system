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

    while (true) {
        // Prompt user to select an action from the menu
        cout << "1: Register\n2: Login\n3: Exit\nYour choice: ";
        cin >> choice;

        if (choice == 1) { // If the user chooses to register
            string username, password;

            // Prompt user to enter a username and a password
            cout << "select a username: ";
            cin >> username;
            cout << "select a password: ";
            cin >> password;

            // Save the username and password to a file
            ofstream file;
            file.open("data\\" + username + ".txt");
            file << username << endl << password;
            file.close();
        } else if (choice == 2) { // If the user chooses to log in
            bool status = IsLoggedIn();

            if (!status) {
                // Display error message if login fails
                cout << "False Login!" << endl;
                system("PAUSE");
            } else {
                // Display success message if login succeeds
                cout << "Successfully logged in!" << endl;
            }
        } else if (choice == 3) { // If the user chooses to exit
            break; // Exit the loop and terminate the program
        }
    }

    return 0;
}