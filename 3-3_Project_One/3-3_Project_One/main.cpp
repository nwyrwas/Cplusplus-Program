cout << "Created by Nicholas Wyrwas" << endl;
cout << "Class CS-210-J7354" << endl;
cout << endl;

/**
 * Formats a number as 2 digits, with a leading 0 if needed
 * This method can be useful when converting a time like 9 hours, 12 minutes and 3 seconds to "09:12:03"
 * It's a good building block to help you get that part right and not have to repeat code
 *
 * @param n number to format, assumed between 0 and 59, inclusive
 * @return two digit string representation of number
 */
string twoDigitString(unsigned int n) {
	/**
	 * You may wish to change this function when you bring it into your program.
	 * For now please get it to work here with the existing function signature.
	 * You may assume <string> has been included.
	 */
	
	 // TODO: your code here to implement the method
	if (n < 10) {
		return "0" + to_string(n);
	}
	else {
		return to_string(n);
	}
	 // Numbers between 10 and 59 just need to be converted to a string
	 // Numbers from 0 to 9 need a "O" tacked onto the front of the string representation of the number

	 // Return the two digit string representation of n
}
/**
 * Returns a string of length n, each character a c.
 * For example, nCharString(5, '*') should return "*****"
 *
 * @param n string length, >=0
 * @return string of n c's
 */
string nCharString(size_t n, char c) {
	/**
	 * You may wish to change this function when you bring it into your program
	 * For now please get it to work here with the existing function signature
	 * You may assume <string> has been included
	 */
	 // TODO: your code here to implement the method
	return string(n, c);
	 // return the n character string
}
/**
 * Formats the time in military format

 *
 * @param h, hours 0 to 23
 * @param m, minutes 0 to 59
 * @param s, seconds 0 to 59
 *
 * @return hh:mm:ss
 */
string formatTime24(unsigned int h, unsigned int m, unsigned int s) {
	string hourStr;
	string minuteStr;
	string secondStr;

	// You may assume <string> has been imported and the method twoDigitString works
	// for example, twoDigitString(7) returns "07" and twoDigitString(59) returns "59"
	// That should simplify your work here and help you not repeat code.
	// You need a colon betweeh hours and minutes and between minutes and seconds.
	// Tests will pass in (7, 24, 9) and (23, 0, 59) and expect 07:24:09 and 23:00:59
	// You may change this function in the program you submit, but please get it to work
	// here first, with this function signature.
	// TODO: Your code here
	hourStr = twoDigitString(h);
	minuteStr = twoDigitString(m);
	secondStr = twoDigitString(s);
	return hourStr + ":" + minuteStr + ":" + secondStr;
	// return time as hh:mm:ss
}
//  You may assume include<string> has been included
/**
 * Formats the time in am/pm format
 *
 * @param h, hours 0 to 23
 * @param m, minutes 0 to 59
 * @param s, seconds 0 to 59
 *
 * @return hh:mm:ss A M or hh:mm:ss P M where hh is between 01 and 12, inclusive
 */
string formatTime12(unsigned int h, unsigned int m, unsigned int s) {
	string minuteStr;
	string secondStr;
	string amPm;
	/**
	 * When adding your code below, please leave the method signature alone.
	 *
	 * You may assume that twoDigitString(n) exists and returns a two-digit string repesenation of n.
	 * For example, twoDigitString(7) returns "07" and twoDigitString(12) returns "12".
	 *
	 * Include colons as separators, add one space after seconds then  A M or P M as appropriate
	 */

	 // TODO: Your code here
	string hourStr;
	if (h == 0) {
		hourStr = "12";
	}
	else if (h <= 12) {
		hourStr = twoDigitString(h);
	}
	else {
		hourStr = twoDigitString(h - 12);
	}

	minuteStr = twoDigitString(m);
	secondStr = twoDigitString(s);
	amPm = (h < 12) ? "A M" : "P M";

	return hourStr + ":" + minuteStr + ":" + secondStr + " " + amPm; // replace this placeholder with return of your formatted string
}
// test cases (["Add One Hour", "Add One Minute", "Add One Second", "Exit Program"], 4, 26 or 57)
/**
 * Prints menu
 *
 * @param *strings[], nonempty array of choices
 * @param width, width of each line, will be comfortably bigger than the longest string
 *
 */
void printMenu(char* strings[], unsigned int numStrings, unsigned char width) {
	string separator;
	string itemNumber;
	string menuLine;
	int spacesNeeded;
	/**
	 * In your own program feel free to change the function signature. For now, please first get it to work as is.
	 * You may assume <string> and <iostream> have been imported.
	 * You may assume a function nCharString has been implemented, and you will want to call it for stars and spaces.
	 * string nCharString(size_t n, char c) produces a string of n c's. For example, nCharString(5, '*') returns "*****"
	 * and nCharString (7,' ') will return 7 spaces.
	 */
	 // TODO: Your code here. Use the comments to see the expected format of the menu.
	separator = nCharString(width, '*');
	cout << separator << endl;

	for (unsigned int i = 0; i < numStrings; i++) {
		itemNumber = to_string(i + 1);
		menuLine = "*" + nCharString(1, ' ') + itemNumber + " - " + strings[i];
		spacesNeeded = width - menuLine.length() - 1;
		menuLine += nCharString(spacesNeeded, ' ') + "*";
		cout << menuLine << endl;

		if (i != numStrings - 1) {
			cout << "*" << nCharString(width - 2, ' ') << "*" << endl;
		}
	}

	cout << separator << endl;
	 // first print width *'s followed by an endl

	 /** Next, for each string s in the array:
	  * cout a star, a space, the item Number a space a hyphen another space, s,
	  * and enough spaces to get to a length of width - 1 (enough will depend on the length of the current menu item).
	  * Close the line with a star and an endl. The goal is that the stars on the right align with each other and each line
	  * has the same width, passed in as a parameter.
	  * (Hint: calculate the needed number of spaces and use nCharString to produce them)
	  * Skip a line after each line except the last line
	  */

	  // outside the loop print another width *s followed by an endl

}
// test cases (["Add One Hour", "Add One Minute", "Add One Second", "Exit Program"], 4, 26 or 57)
/**
 * Prints menu
 *
 * @param *strings[], nonempty array of choices
 * @param width, width of each line, will be comfortably bigger than the longest string
 *
 */

unsigned int getMenuChoice(unsigned int maxChoice) {
	/**
	 * You may change this in your program, but first please get it working here with this function signature.
	 * TIPS: take the input in a loop, check that it is in range, and exit the loop only once it is.
	 * You will handle clearing the screen and printing the menu elsewhere,
	 * so here just get character(s) or number(s) from the user and do not print error messages.
	 */
	 // TODO: your code here, 
	unsigned int choice;
	while (true) {
		cin >> choice;
		if (choice >= 1 && choice <= maxChoice) {
			return choice;
		}
		// Optionally, you can handle invalid input here.
	}
	 // return the value
}
/**
* Display the clocks
*
* @param h, hours 0 to 23
* @param m, minutes 0 to 59
* @param s, seconds 0 to 59
*/
void displayClocks(unsigned int h, unsigned int m, unsigned int s) {
	// The code in your submitted program may vary. For now, please get this to work with the given
	// function signature.
	// You may assume you have a working nCharString and formatTime24 and formatTime12 and <iostream> has been imported
	//
	// nCharString(27,'*') gives a string of 27 stars. nCharString(3,' ') gives 3 spaces
	// formatTime12(h, m, s) and formatTime24(h, m, s) give the formatted time as specified in the assignment	
	// test will pass in (0, 59, 9)
	// TODO: Your code here, follow the comments for each line
	// cout 27 stars + 3 spaces + 27 stars + endl
	// cout 1 star + 6 spaces + 12-HOUR CLOCK + 6 spaces + 1 star + 3 spaces
	// cout 1 star + 6 spaces + 24-HOUR CLOCK + 6 spaces + 1 star + endl
	// cout an endl for a blank line
	// cout 1 star + 6 spaces + formatTime12(h, m, s) + 7 spaces + 1 star + 3 spaces
	// cout 1 star + 8 spaces + formatTime24(h, m, s) + 9 spaces + 1 star + endl
	// cout 27 stars + 3 spaces + 27 stars + endl
	string starsAndSpaces;
	string twentyFourHourClock;
	string twelveHourClock;

	string starsAndSpaces = nCharString(27, '*') + nCharString(3, ' ') + nCharString(27, '*');
	cout << starsAndSpaces << endl;

	twelveHourClock = "*" + nCharString(6, ' ') + "12-HOUR CLOCK" + nCharString(6, ' ') + "*";
	twentyFourHourClock = "*" + nCharString(6, ' ') + "24-HOUR CLOCK" + nCharString(6, ' ') + "*";
	cout << twelveHourClock << endl;
	cout << twentyFourHourClock << endl;
	cout << "*" << nCharString(3, ' ') + formatTime12(h, m, s) + nCharString(7, ' ') + "*" << nCharString(3, ' ') << endl;
	cout << "*" << nCharString(4, ' ') + formatTime24(h, m, s) + nCharString(9, ' ') + "*" << endl;
	cout << starsAndSpaces << endl;
}
/**
 * repeats getting the user's choice and taking the appropriate action until the user chooses 4 for exit
 */
void mainMenu() {
	/** You may assume you have a working getMenuChoice(n), addOneHour(), addOneMinute(), and addOneSecond().
	 * The test will hit 1\n2\n2\n3\n3\n3\n4\n, and expect the adding functions to be called the right number of times.
	 * getMenuChoice(4) will handle the input and return 1, 2, 3, or 4.
	 * Feel free to change things around in your program, but for now get this to work with these function signatures.
	 */
	 // TODO: Your Code here
	char* choices[] = { "Add One Hour", "Add One Minute", "Add One Second", "Exit Program" };
	unsigned int choice;
	unsigned int hours = 0;
	unsigned int minutes = 0;
	unsigned int seconds = 0;

	do {
		printMenu(choices, 4, 26);
		choice = getMenuChoice(4);

		switch (choice) {
		case 1:
			addOneHour(hours);
			break;
		case 2:
			addOneMinute(minutes);
			break;
		case 3:
			addOneSecond(seconds);
			break;
		default:
			break;
		}

		displayClocks(hours, minutes, seconds);
	} while (choice != 4);
	 // nothing to return, just call the appropriate methods
}
/**
 * Adds one second
 */
void addOneSecond() {
	/** assume you have working getSecond(), setSecond(s), and addOneMinute()
	 * addOneMinute will take care of the hours if necessary
	 * Feel free to change things around in your program, but for now please make this work with these function signatures.
	 * if getSecond() is between 0 and 58 inclusive, add 1 and setSecond()
	 * if getSecond() is 59, seconds wrap around to 0 and you need to call addOneMinute()
	 * test will set minutes to 4 and seconds to 0, then addOneSecond 60 times
	 */
	int s;
	int m;
	int h;

	 // TODO: your code here
	if (s < 59) {
		s += 1;
	}
	else {
		s = 0;
		addOneMinute(m, h);
	}
	 // nothing to return, just call setSecond() with the right value and addOneMinute() when needed
}
/**
 * Adds one minute
 */
void addOneMinute() {
	/**assume you have working getMinute(), setMinute(m), and addOneHour()
	 * Feel free to change these in your program, but for now please get things to work with
	 * these function signatures.
	 * if getMinute() is between 0 and 58 inclusive, add 1 and setMinute() to the new value
	 * if getMinute() is 59 the minutes must be set to 0 and you must call addOneHour()
	 * test will set hours and minutes to 0, then addOneMinute 60 times
	 */
	 //TODO: Your code here
	int m;
	int h;

	if (m < 59) {
		m += 1;
	}
	else {
		m = 0;
		addOneHour(h);
	}
	 // nothing to return, just setMinute to the appropriate value and use addOneHour if needed
}
/**
 * Adds one hour
 */
void addOneHour() {
	/** Assume you have a working getHour() and setHour(h)
	 * Feel free to change things around in your code, but first please get it working here
	 * with these function signatures.
	 * if getHour() is between 0 and 22 inclusive, add 1 and setHour() to that
	 * if getHour() is 23 the next value for hour is 0 so setHour() to that
	 * test will check values of hours from 0 to 23 from getHour()
	 */
	 // TODO: Your code here
	int h;

	if (h < 23) {
		h += 1;
	}
	else {
		h = 0;
	}
	 // nothing to return, just setHour to the appropriate value
}