#ifndef LISTOFWORDS_H
#define LISTOFWORD_H

#include <string>
#include <iostream>
#include <ostream>
#include <fstream>
#include <string>

using namespace std;

class WordNode
{
private:
	string * wordName;          // word's name    
	WordNode* next;            // link to next
public:
	WordNode();                // no argument constructor
	WordNode(string word);
	void setNext(WordNode* nextNode);	//Sets the next word node
	WordNode* getNext();	//Links to next word
	string getWord();
};


class WordList
{
private:
	WordNode * start, *end; //Finds the start and end points of a node
public:
	WordList();	//Constructor
	bool isEmpty();	//Checks if the word node is empty
	void addFirstWord(string name);
	void addWordAtEnd(string name);
	void addWordAtStart(string name);
	void listAllWords(std::ostream& os);
	
	WordNode* getStart();

};
#endif
