#include <iostream>

using namespace std;

bool IsLoggedIn() { // Check if user is logged in function
    string username, password;

    cout << "Enter username: "; cin >> username; // Prompt user to enter username
    cout << "Enter password: "; cin >> password; // Prompt user to enter password

    return false;
}

int main() {
    IsLoggedIn();
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
