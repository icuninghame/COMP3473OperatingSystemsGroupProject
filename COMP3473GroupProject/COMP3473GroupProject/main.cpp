#include <stdio.h>
#include <iostream>
#include <string>
//Allows usage of fopen() in MS Visual Studio:
#ifdef _MSC_VER
#pragma warning(disable:4996)
#endif


/*
	COMP-3473 Operating Systems Group Project
	Ian Cuninghame, Kris Luszczynski
	Lakehead University 2019
*/

/*
	POFM must perform:

		1) Create a new file
		2) Delete a file
		3) Rename a file
		4) Copy a file
		5) Move a file from one directory to another
		6) Text file operations:
			i)   append text to the end of a file
			ii)  insert text at a specific char position
			iii) remove all text in a file
			iv)  show the content of a text file, displaying a certain # of lines at once defined by the user.

	- Must not use any system() calls

*/

using namespace std;

//Function prototypes to be defined later:
void testFileCreation();
void testFileDeletion();
void testFileRenaming();
void testFileCopy();
void testFileMove();
void testFileEdit();
void openHelpMenu();

FILE* createFile(char* fileName);

//Main Function:
int main() {

	//Main function to test POFM operations

	//Menu System:

	bool menuOpen = true;
	string command = "";

	do {

		cout << ">>";
		cin >> command;

		if (command != "") {

			if (command == "create")
				testFileCreation();
			else if (command == "delete")
				testFileDeletion();
			else if (command == "rename")
				testFileRenaming();
			else if (command == "copy")
				testFileCopy();
			else if (command == "move")
				testFileMove();
			else if (command == "edit")
				testFileEdit();
			else if (command == "exit")
				exit(0);
			else if (command == "help")
				openHelpMenu();
			else 
				cout << "Unrecognized command. Type 'help' for a list of commands and their usages.";

		}


	} while (menuOpen);

	return 0;
}

//Test Run Methods:

//1. Create a file:
void testFileCreation() {

	FILE* filePointer;

	char* fileName = (char*)malloc(sizeof(char) * 255);

	cout << "Please enter the desire name of the file. It will be created in the same directory as this process." << endl;
	cout << ">>";
	cin >> fileName;

	if (fileName != NULL)
		filePointer = createFile(fileName);
	else
		cout << "Failed. Please enter a valid file name." << endl;

}

//2. Delete a file:
void testFileDeletion() {



}

//3. Rename a file:
void testFileRenaming() {


}

//4. Copy a file:
void testFileCopy() {


}

//5. Move a file:
void testFileMove() {


}

//6: Edit a file:
void testFileEdit() {

	char fileName[255];

	cout << "Please enter the file name of the file you wish to edit." << endl;
	cout << "Note: if it does not exist in this directory, you must specify the full document path." << endl;
	cout << ">>";
	cin >> fileName;

	//if success (fileName is valid):
	cout << "Please enter the type of edit you wish to make: " << endl;
	cout << "\t 1. Read" << endl;
	cout << "\t 2. Append" << endl;
	cout << "\t 3. Insert" << endl;
	cout << "\t 4. Remove" << endl;

}

//Help Menu Interface:
void openHelpMenu() {

	cout << endl;
	cout << " Commands:" << endl;
	cout << "\t 1. create" << "\t - Create a new file" << endl;
	cout << "\t 2. delete" << "\t - Delete a specific file" << endl;
	cout << "\t 3. rename" << "\t - Rename a specific file" << endl;
	cout << "\t 4. copy" << "\t - Copy a file from one directory to another" << endl;
	cout << "\t 5. move" << "\t - Move a file from one directory to another" << endl;
	cout << "\t 6. edit" << "\t - Edit a text file (Read, Append, Insert, Remove)" << endl;
	cout << "\t 7. exit" << "\t - Exit this program" << endl;
	cout << " Usage:\n\t enter a command word verbatim as above (no parameters), then enter the required info when prompted." << endl << endl;

	return;

}

//Utility Methods:

FILE* createFile(char* fileName) {

	if (fileName != NULL)
		return fopen(fileName, "w");
	else
		return fopen("default.txt", "w");
}
