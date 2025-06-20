#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function to register a new user
void register_user() {
    cout << "=== Registration ===" << endl;
    string username, password, confirm_password;

    cout << "Enter a username: ";
    cin >> username;

    // Check if the username already exists
    ifstream user_file(username + ".txt");
    if (user_file) {
        cout << "Error: Username already exists. Please choose a different username." << endl;
        return;
    }
    user_file.close();

    cout << "Enter a password: ";
    cin >> password;

    cout << "Confirm your password: ";
    cin >> confirm_password;

    if (password != confirm_password) {
        cout << "Error: Passwords do not match. Registration failed." << endl;
        return;
    }

    // Store user credentials securely (in plain text for this example)
    ofstream out_file(username + ".txt");
    out_file << password;  // Storing password in plain text
    out_file.close();

    cout << "Registration successful! You can now log in." << endl;
}

// Function to log in an existing user
void login_user() {
    cout << "=== Login ===" << endl;
    string username, password;

    cout << "Enter your username: ";
    cin >> username;

    ifstream user_file(username + ".txt");
    if (!user_file) {
        cout << "Error: Username does not exist." << endl;
        return;
    }

    cout << "Enter your password: ";
    cin >> password;

    string stored_password;
    getline(user_file, stored_password);
    user_file.close();

    // Verify the password
    if (password == stored_password) {
        cout << "Login successful! Welcome back." << endl;
    }
    else {
        cout << "Error: Incorrect password. Login failed." << endl;
    }
}

// Main function
int main() {
    while (true) {
        cout << "\n=== Welcome to the Login System ===" << endl;
        cout << "1. Register" << endl;
        cout << "2. Login" << endl;
        cout << "3. Exit" << endl;

        int choice;
        cout << "Choose an option (1/2/3): ";
        cin >> choice;

        switch (choice) {
        case 1:
            register_user();
            break;
        case 2:
            login_user();
            break;
        case 3:
            cout << "Exiting the system. Goodbye!" << endl;
            return 0;
        default:
            cout << "Invalid option. Please try again." << endl;
        }
    }
}
