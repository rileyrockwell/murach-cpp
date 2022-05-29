#include <iostream>
#include <string>

using namespace std;

int main()
{
    cout << "Create Account\n\n";

    // get full name and parse first name
    string full_name;
    string first_name;
    bool valid_name = false;
    while (!valid_name) {
        cout << "Enter full name: ";
        getline(cin, full_name);

        // strip whitespace from front
        int i = full_name.find_first_not_of(" \n\t");
        if (i > -1) {
            full_name = full_name.substr(i);
        }

        // get first name
        int space_index = full_name.find(' ');
        if (space_index == -1) {
            cout << "You must enter your full name. Please try again.\n";
        }
        else {
            first_name = full_name.substr(0, space_index);
            valid_name = true;
        }
    }
    cout << endl;

    // get the password
    string password;
    bool valid_password = false;
    while (!valid_password) {

        // set valid flag
        valid_password = true;

		// get password
        cout << "Enter password: ";
        getline(cin, password);

        // make sure password has at least 8 characters
        if (password.length() < 8) {
            cout << "Password must be at least 8 characters.\n";
            valid_password = false;
        }

        // make sure password includes a number
        int index = password.find_first_of("0123456789");
        if (index == -1) {
            cout << "Password must include a number.\n";
            valid_password = false;
        }

        // make sure password includes a special character
        bool special_character = false;
        for (char c : password) {
            if (ispunct(c)) {
                special_character = true;
                break;                      // exit for loop
            }
        }
        if (!special_character) {
            cout << "Password must include a special character.\n";
            valid_password = false;
        }

        // display message if password is not valid
        if (!valid_password) {
            cout << "Please try again.\n";
        }
    }
    cout << endl;

	// get the email address
	string email;
	bool valid_email = false;
	while (!valid_email) {
		// set valid flag
		valid_email = true;

		// get email
		cout << "Enter email: ";
		getline(cin, email);

		// make sure there is an at sign
		int at_index = email.find('@');
		if (at_index == -1) {
			cout << "The email must include an at character (@).\n";
			valid_email = false;
		}

		// make sure there is a dot character by getting the last dot operator
		int dot_index = email.rfind('.');
		if (dot_index == -1) {
			cout << "The email must include a dot character (.).\n";
			valid_email = false;
		}

		// make sure the remaining characters are alphanumeric
		bool valid_chars = true;
		for (char c : email) {
			if (c != '@' && c != '.' && c != '_' && c!= '-' ) {
				if (!isalnum(c)) {
					valid_chars = false;
					break;
				}
			}
		}
		if (!valid_chars) {
			cout << "The email contains invalid characters.\n";
			valid_email = false;
		}

		// make sure there is at least one character before the at sign
		if (at_index == 0) {
			cout << "The local part of the email must include at least one character.\n";
			valid_email = false;
		}
		
		// make sure there is at least one character before the dot character
		if (dot_index - at_index == 1) {
			cout << "The server name of the email must include at least one character.\n";
			valid_email = false;
		}

		// make sure the domain name has two or three characters
		if (email.length() - dot_index - 1 != 3 && email.length() - dot_index - 1 != 2) {
			cout << "The domain name of the email must have two or three characters.\n";
			valid_email = false;
		}

		// display message if email is not valid
		if (!valid_email) {
			cout << "Please try again.\n";
		}
	}
	cout << endl;

    // make sure first name uses initial cap
    char letter = first_name[0];
    first_name[0] = toupper(letter);
    for (int i = 1; i < first_name.length(); ++i) {
        letter = first_name[i];
        first_name[i] = tolower(letter);
    }

    // display welcome message
    cout << "Hi " << first_name << ",\n"
        << "Thanks for creating an account!\n\n";
}
