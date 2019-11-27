#include <stdio.h>
#include <errno.h>
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
void deleteFile(char* fileName);
void renameFile(char* fileName, char* newName);
void copyFile(char* src, char* dest);
void moveFile(char* src, char* dest);

//Main Function to test POFM operations:
int main() {

	//Menu System:
	string command;

	cout << " Welcome to LakeheadU Portable File Manager! Please enter one of the commands below to begin." << endl << endl;
	openHelpMenu();

	do {
		cout << "  >> ";
		cin >> command;
		cout << endl;

		if (!command.empty()) {

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
				cout << " Unrecognized command. Type 'help' for a list of commands and their usages." << endl;

		}
		else {
			cout << "  >> ";
		}

	} while (true);

	return 0;
}

//Test Run Methods:

//1. Test Create a file:
void testFileCreation() {

	FILE* filePointer;

	char* fileName = (char*)malloc(sizeof(char) * 255);

	cout << "Please enter the desire name of the file. It will be created in the same directory as this process." << endl;
	cout << "  >> ";
	cin >> fileName;

	if (fileName != NULL) {
		filePointer = createFile(fileName);
		cout << "File creation complete." << endl;
		fclose(filePointer);
	} else
		cout << "Failed. Please enter a valid file name." << endl;

}

//2. Test Delete a file:
void testFileDeletion() {

	char* fileName = (char*)malloc(sizeof(char) * 255);

	cout << "Please enter the filename of the file you wish to delete." << endl;
	cout << "Note: if the file is not in the same directory as this process, you must specify the full document path." << endl;
	cout << "  >> ";
	cin >> fileName;

	deleteFile(fileName);

}

//3. Test Rename a file:
void testFileRenaming() {

	char* fileName = (char*)malloc(sizeof(char) * 255);
	char* newName = (char*)malloc(sizeof(char) * 255);

	cout << " Please enter the current file name of the file you wish to rename." << endl;
	cout << " Note: if the file is not in the same directory as this process, you must specify the full document path." << endl;
	cout << "  >> ";
	cin >> fileName;

	cout << " Please enter the desired new file name for " << fileName << ". " << endl;
	cout << "  >> " << endl;
	cin >> newName;

	renameFile(fileName, newName);

}

//4. Test Copy a file:
void testFileCopy() {

	char* fileSrc = (char*)malloc(sizeof(char) * 255);
	char* fileDest = (char*)malloc(sizeof(char) * 255);

	cout << " Please enter the document path of the file you wish to copy: " << endl;
	cout << "  >> ";
	cin >> fileSrc;
	
	cout << " Please enter the destination path including the filename that you want to create: " << endl;
	cout << "  >> ";
	cin >> fileDest;

	copyFile(fileSrc, fileDest);

}

//5. Test Move a file:
void testFileMove() {

	char* fileSrc = (char*)malloc(sizeof(char) * 255);
	char* fileDest = (char*)malloc(sizeof(char) * 255);

	cout << " Please enter the document path of the file you wish to move." << endl;
	cout << "  >> ";
	cin >> fileSrc;

	cout << " Please enter the desired new location path for " << fileSrc << ". " << endl;
	cout << "  >> " << endl;
	cin >> fileDest;

	moveFile(fileSrc, fileDest);

}

//6: Test Edit a file:
void testFileEdit() {

	char fileName[255];

	cout << " Please enter the file name of the file you wish to edit." << endl;
	cout << " Note: if it does not exist in this directory, you must specify the full document path." << endl;
	cout << "  >> ";
	cin >> fileName;

	//if success (fileName is valid):
	cout << " Please enter the type of edit you wish to make: " << endl;
	cout << "\t 1. Read" << endl;
	cout << "\t 2. Append" << endl;
	cout << "\t 3. Insert" << endl;
	cout << "\t 4. Remove" << endl;

}

//Help Menu Interface:
void openHelpMenu() {

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

//1. Create a File:
FILE* createFile(char* fileName) {

	if (fileName != NULL)
		return fopen(fileName, "w");
	else
		return fopen("default.txt", "w");
}

//2. Delete a File:
void deleteFile(char* fileName) {

	FILE* tempFilePointer;
	 
	//Ensure the fileName is valid, not empty:
	if (fileName != NULL) {

		//Check to ensure the file exists before trying to delete:
		tempFilePointer = fopen(fileName, "r");
		if (tempFilePointer != NULL) {
			fclose(tempFilePointer);
			remove(fileName);
			cout << "File " << fileName << " was successfully removed." << endl;

		}
		else {
			fclose(tempFilePointer);
			cout << "Error opening the file. Check to make sure you spelled the file name correctly." << endl;
		}

	}
	else
		cout << "You must enter a valid file name to delete." << endl;

	return;

}

//3. Rename a File:
void renameFile(char* fileName, char* newName) {

	if (newName != NULL && fileName != NULL) {
		if (rename(fileName, newName) == 0)
			cout << " File name successfully changed from " << fileName << " to " << newName << ". " << endl;
		else
			cout << "Error: " << strerror(errno) << endl;
			//cout << " File renaming was unsuccessful. This is probably because you do not have the correct permissions or the filename was misspelled." << endl;
	}
	else {
		cout << " Failed. You must enter valid file names." << endl;
	}

}

//4. Copy a File:
void copyFile(char* src, char* dest) {

	FILE *srcPointer, *destPointer;
	char ch;
	int pos;

	srcPointer = fopen(src, "r");

	//Ensure the source file exists and is available to copy:
	if (srcPointer == NULL) {
		cout << "Error opening " << src << ". Check to make sure the name is spelled correctly." << endl;
		return;
	}
	else
		cout << "File " << src << " opened for copying." << endl;

	destPointer = fopen(dest, "w");

	fseek(srcPointer, 0L, SEEK_END);
	pos = ftell(srcPointer);
	fseek(srcPointer, 0L, SEEK_SET);

	while (pos--) {
		ch = fgetc(srcPointer);
		fputc(ch, destPointer);
	}

	cout << "Finished copying " << src << " to " << dest << ". " << endl;

	//Close all open file streams
	fcloseall();

	return;

}

//5: Move a File:
void moveFile(char* fileSrc, char* fileDest) {

	if (fileSrc != NULL && fileDest != NULL) {
		if (rename(fileSrc, fileDest) == 0)
			cout << " File successfully moved from " << fileSrc << " to " << fileDest << ". " << endl;
		else
			cout << "Error: " << strerror(errno) << endl;
		//cout << " File renaming was unsuccessful. This is probably because you do not have the correct permissions or the filename was misspelled." << endl;
	}
	else {
		cout << " Failed. You must enter valid file names." << endl;
	}

}

//6: Edit a File:
//TODO

