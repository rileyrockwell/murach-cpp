#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

struct FileNotFound {
	string message;
	string filename;
};

vector<string> load_words(string filename);
map<string, int> get_word_count(const vector<string>& words);

string get_fulll_path() {
    // set a full path to the correct directory
    const char* home = getenv("HOME");
    string user_home = "";
    if (home) {
        user_home = home;
    }
    else {
        // if home isn't found, edit 'username' so it's correct for your system
        user_home = "/Users/username";
    }
    string file_path = "/Documents/murach/cpp/files/";
    return user_home + file_path;
}

int main() {
	cout << "The Word Counter program\n\n";

	string filename = "";
	cout << "Enter a file name: ";
	cin >> filename;

	vector<string> words;

	try {
		words = load_words(get_fulll_path() + filename);
	}
	catch (const FileNotFound e) {
		cout << e.message << "\n";
		cout << "You entered: " << e.filename << ".\n";
		cout << "Exiting program...\n\n";
		return 0;
	}
	catch (...) {
		cout << "An unexpected error occurred!\n\n";
		throw;
	}

	cout << endl;
	cout << words.size() << " WORDS: ";
	for (string word : words) {
		cout << word << ' ';
	}
	cout << endl << endl;

	auto word_count = get_word_count(words);

	cout << word_count.size() << " UNIQUE WORDS: ";
	for (auto pair : word_count) {
		cout << pair.first << ' ';
	}
	cout << endl << endl;

	cout << "COUNT PER WORD: ";
	for (auto pair : word_count) {
		cout << pair.first << '=' << pair.second << ' ';
	}
	cout << endl << endl;
}

vector<string> load_words(string filename) {
	vector<string> words;
	ifstream infile(filename);

	if (infile) {
		string word;
		while (infile >> word) {

			string new_word = "";
			for (char c : word) {
				if (c == '.' || c == ',') {
					continue;               // remove punctuation
				}
				else if (isupper(c)) {
					new_word += tolower(c); // convert to lowercase
				}
				else {
					new_word += c;
				}
			}
			words.push_back(new_word);      // add word 
		}
		infile.close();
		return words;
	}
	else {
		FileNotFound error;
		error.message = "File not found.";
		error.filename = filename;
		throw error;
	}
}

map<string, int> get_word_count(const vector<string>& words) {
	map<string, int> word_count{};

	for (string word : words) {
		auto search = word_count.find(word);
		if (search == word_count.end()) {
			word_count[word] = 1;   // not found - add word with count of 1
		}
		else {
			word_count[word] += 1;  // found - increment count for word
		}
	}
	return word_count;
}
