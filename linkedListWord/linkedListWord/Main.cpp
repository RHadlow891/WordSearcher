#include "LinkedWord.h"
#include <string>
#include <iostream>
#include <regex>

using namespace std;
void saveToFile(WordList* words);
void WordSearch();
void DisplayWords();

void menu()
{
	char selection;
	

	do
	{
		cout << "Welcome to the word finding program" << endl;
		cout << " ==================================== " << endl;
		cout << "1. List all words" << endl;
		cout << "2. Search for words" << endl;
		cout << "3. Exit program" << endl;
		cin >> selection;
		//Main menu text

		switch (selection)
		{
		case '1':
			cout << "List of all words in file: " << endl;
			DisplayWords();
			break;

		case '2':
			cout << "search any key term to find word: " << endl;
			WordSearch();
			break;

		case '3':
			cout << "Exit" << endl;
			exit(selection);
			break;

		default:
			cout << "Enter a number from 1 to 3" << endl << endl;
			break;
		} //Switch case menu
	} while (selection != 3);

	
}

int main()
{	

	menu(); //Running of the main program

	system("pause");
	return 0;
}

void DisplayWords()
{
	WordList* wordList = new WordList(); //initiaton of word list

	wordList->addFirstWord("shape");
	wordList->addWordAtEnd("cape");
	wordList->addWordAtEnd("ape");
	wordList->addWordAtEnd("hate");
	wordList->addWordAtStart("ate");
	//List of statically created words
	wordList->listAllWords(cout);
	//Function to list all the words
}

void WordSearch()
{
	string line;

	
	WordList* wordList = new WordList(); //Word list used for search
	WordList* searchList = new WordList(); // Search list used for search

	wordList->addFirstWord("shape");
	wordList->addWordAtEnd("cape");
	wordList->addWordAtEnd("ape");
	wordList->addWordAtEnd("hate");
	wordList->addWordAtStart("ate");
	wordList->listAllWords(cout);

	cout << "Enter letters: ";
	cin >> line;

	WordNode* word;
	word = wordList->getStart(); //Finds the starting point of linked list

	while (word)
	{

		if (word->getWord().find(line) != std::string::npos) {
			searchList->addWordAtEnd(word->getWord());
		}

		word = word->getNext();
		//Runs through linked list adding next word
	}
	searchList->listAllWords(cout);

	saveToFile(searchList); //Saves the searched words to file

}


void saveToFile(WordList* words)
{
	ofstream newFile("WordList.txt");


	if (newFile.is_open() == false)
	{
		cout << "Error opening file \n";
	}
	else
	{
		words->listAllWords(newFile);


	}
	newFile.close();
	//Creates new file under "WordList.txt"
}