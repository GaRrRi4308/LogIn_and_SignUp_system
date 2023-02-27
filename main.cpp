#include <iostream>
#include <fstream>
#include <QApplication>
#include <QFile>
#include <QTextStream>
#include <QInputDialog>

using namespace std;

bool IsLoggedIn() { // Check if user is logged in function
    string username, password, un, pw;

    cout << "Enter username: "; cin >> username; // Prompt user to enter username
    cout << "Enter password: "; cin >> password; // Prompt user to enter password

    ifstream read("c\\" + username + ".txt"); // Opens file with the given username
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

int main(int argc, char *argv[]) {
    // Initialize the Qt application
    QApplication app(argc, argv);

    //Loop until the user chooses to exit
    while (true) {
        // Show a menu with option to register, login, or exit
        QStringList options;
        options << "Register" << "Login" << "Exit";
        QString choice = QInputDialog::getItem(nullptr, "Menu", "Select an action:", options);

        if (choice == "Register") {
            // Prompt user to enter a username and a password
           QString username = QInputDialog::getText(nullptr, "Register", "Select a username:");
           QString password = QInputDialog::getText(nullptr, "Register", "Select a password:");

            // Save the username and password to a file
            QFile file("data/" + username + ".txt");
            if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
                QTextStream out(&file);
                out << username << "/n" << password;
                file.close();
            }

        } else if (choice == "Login") { // If the user chooses to log in
            bool status = IsLoggedIn();

            if (!status) {
                // Display error message if login fails
                cout << "False Login!" << endl;
                system("PAUSE");
            } else {
                // Display success message if login succeeds
                cout << "Successfully logged in!" << endl;
                system("PAUSE");
                return 1;
            }
        } else if (choice == "Exit") { // If the user chooses to exit
            break; // Exit the loop and terminate the program
        }
    }

    return 0;
}