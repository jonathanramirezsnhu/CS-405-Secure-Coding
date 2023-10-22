// BufferOverflow.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iomanip>
#include <iostream>
#include <string.h>

int main()
{
	std::cout << "Buffer Overflow Example" << std::endl;

	// TODO: The user can type more than 20 characters and overflow the buffer, resulting in account_number being replaced -
	//  even though it is a constant and the compiler buffer overflow checks are on.
	//  You need to modify this method to prevent buffer overflow without changing the account_order
	//  varaible, and its position in the declaration. It must always be directly before the variable used for input.

	const std::string account_number = "CharlieBrown42";
	char user_input[20];
	std::cout << "Enter a value: ";
	std::cin >> user_input;
	//Compare the size of the user input if its more than 20 characters
	if (sizeof(user_input) >= 20) {
		//if user input is more than 20 charcters a messaged is thrown and the program aborts
		std::cout << "Overflow Detected!!" << std::endl;
		abort();
	}
	//otherwise it shows the user the number they entered and their account
	else {
		std::cout << "You entered: " << user_input << std::endl;
		std::cout << "Account Number = " << account_number << std::endl;
	}
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
