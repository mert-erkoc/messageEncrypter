#include <iostream>
#include <string>
#include <thread>
using namespace std;

// Message Crypting and Solving with CaesarCrypting Method / by Mert Erkoç
// it is simple but, can improve or change..

//crypting function
string crypting(const string& message, int slide) {
	string cryptedMessage = message;

	for (char& character : cryptedMessage) {
		if (isalpha(character)) {
			character = (character - 'a' + slide) % 26 + 'a';
		}
	}
	return cryptedMessage;
}

//solving function
string solving(const string& cryptedMessage, int slide) {
	return crypting(cryptedMessage, 26 - slide);  // 26 - kaydirma ile çözme iþlemi
}




int main() {
	cout << "-----------------------------------------------" << endl;
	cout << "Welcome to the Meto Encrypting System!" << endl;
	cout << "-----------------------------------------------" << endl;
	cout << endl;
	cout << endl;

	string message;
	int slide;

	string cryptedMessage;
	string solvedMessage;

	int choice1;

	cout << "[1] for Message Encrypting" << endl;
	cout << "[2] for Solving Enrypted Message" << endl << endl;
	cout << "Make your selection : ";
	cin >> choice1;

	cin.ignore();

	if (choice1 == 1) {
		cout << "Enter your message... (English Characters Only!): ";
		getline(cin, message);

		cout << "How many should be slid... : ";
		cin >> slide;

		cout << endl;
		cout << endl;
		cout << endl;

		//Mesaji Sifreleme
		cryptedMessage = crypting(message, slide);

		cout << "Your Message Has Been Successfully Encrypted" << endl << "Your Message = " << cryptedMessage;

		cout << endl;
		cout << endl;
		cout << endl;

		this_thread::sleep_for(chrono::seconds(3));

		main();
	}

	else if (choice1 == 2) {

		cout << "Enter your encrypted message for solving... : ";
		getline(cin, cryptedMessage);

		cout << "How did slide this message... : ";
		cin >> slide;

		cout << endl;
		cout << endl;
		cout << endl;


		solvedMessage = solving(cryptedMessage, slide);

		cout << "Solved Message = " << solvedMessage << endl;

		cout << endl;
		cout << endl;
		cout << endl;

		this_thread::sleep_for(chrono::seconds(3));

		main();
	}


}