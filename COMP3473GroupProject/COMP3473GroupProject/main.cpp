#include <stdio.h>
#include <iostream>

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

//1. Create a file method:
FILE* createFile(char* fileName) {

	if (fileName != NULL)
		return fopen(fileName, "w");
	else
		return fopen("default.txt", "w");
}

//Main Function:
int main() {

	//Main function to test POFM operations

	//Menu System:

	bool menuOpen = true;

	do {

		//Menu system for command-line command interpretation


	} while (menuOpen);

	//1. Create a file:
	
	FILE* filePointer;

	char* fileName = (char*) malloc (sizeof(char)*255);

	

	//2. Delete a file:

	//3. Rename a file:

	if (filePointer != NULL) {



	}

	//4. Copy a file:

	//5. Move a file:

	//6. Text file operations:

	return 0;
}

