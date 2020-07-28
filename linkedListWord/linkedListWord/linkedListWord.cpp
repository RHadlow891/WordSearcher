#include "LinkedWord.h"
#include <fstream>

WordNode::WordNode()
{
	wordName = NULL;
	next = NULL;
}

WordNode::WordNode(string word)
{
	wordName = new string(word);
	next = NULL;
}

void WordNode::setNext(WordNode* nextWord)
{
	next = nextWord;
}

WordNode* WordNode::getNext()
{
	return next;	//Returns next word node
}

WordNode* WordList::getStart()
{
	return start;	//Returns starting word on node
}

string WordNode::getWord()
{
	return* wordName;
}

WordList::WordList()
{
	start = NULL;
	end = NULL;
}

bool WordList::isEmpty()
{
	return start == NULL;	//Reverts back to the start of the node
}

void WordList::addFirstWord(string word)
{
	WordNode* current;
	current = new WordNode(word);
	start = current;
	end = current;
}

void WordList::addWordAtEnd(string word)
{

	WordNode* current;

	if (end == NULL)
		addFirstWord(word);
	else
	{
		current = new WordNode(word);   // allocate memory
		end->setNext(current);          // change end's next
		end = current;
	}
}

void WordList::listAllWords(std::ostream& os)
{
	WordNode* current;

	if (!isEmpty())
	{
		os << "Start of List" << endl;
		current = start;
		while (current != NULL)
		{
			os << "Next word is: " << (current->getWord()) << endl;
			current = current->getNext();
		}
		os << "End of List" << endl << endl;
	}
	else
		os << "List empty" << endl << endl;
}

void WordList::addWordAtStart(string name)
{


	WordNode* current;

	if (end == NULL)
		addFirstWord(name);
	else
	{
		current = new WordNode(name);
		current->setNext(start);
		start = current;
	}
}