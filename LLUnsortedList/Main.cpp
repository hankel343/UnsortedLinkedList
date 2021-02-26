#include <iostream>
#include "UnsortedLL.h"

using namespace std;

void ProgramMenu(CUnsortedLList& ListObj);
void ProcessSelection(CUnsortedLList& ListObj, char cSelection);
void InsertCase(CUnsortedLList& ListObj);
void SearchCase(CUnsortedLList& ListObj);
void DeleteCase(CUnsortedLList& ListObj);

int main()
{
	char cConstructorPrompt = ' ';
	cout << "Would you like to specify the list maximum? \n";
	cout << "If not, the default list size of 5 will be used.\n";
	cout << "Y/N: ";
	cin >> cConstructorPrompt;

	if (toupper(cConstructorPrompt) == 'Y') {
		system("cls");
		int nSize = 0;
		cout << "What is the maximum size of your list?\n";
		cout << "Size: ";
		cin >> nSize;
		CUnsortedLList ParameterizedList(nSize);
		ProgramMenu(ParameterizedList);
	} else {
		CUnsortedLList UnparameterizedList;
		ProgramMenu(UnparameterizedList);
	}

	cout << "Goodbye...\n"; 

	return 0;
}

void ProcessSelection(CUnsortedLList& ListObj, char cSelection)
{
	switch (toupper(cSelection))
	{
	case '1':
		InsertCase(ListObj);
		break;

	case '2':
		SearchCase(ListObj);
		break;

	case '3':
		try
		{
			cout << ListObj.GetNextItem().Get() << " is the next item in the list.\n";
			cout << "Is is also now the current item.\n\n";
		} catch (EmptyList) {
			cerr << "Exception caught: The list is currently empty.\n\n";
		}
		
		break;

	case '4':
		cout << "The list currently has " << ListObj.GetLength() << " items in it.\n\n";
		break;

	case '5':
		DeleteCase(ListObj);
		break;

	case '6':
		ListObj.ResetList();
		cout << "The current item pointer has been returned to the front of the list.\n\n";
		break;

	case '7':
		ListObj.MakeEmpty();
		cout << "The list has been made empty.\n\n";
		break;

	case 'Q':
		break;

	default:
		cout << "Unrecognized input - Please try again.\n\n";
		break;
	}
}

void InsertCase(CUnsortedLList& ListObj)
{
	int nNewData = 0;
	ItemType CNewItem;
	cout << "Enter the data that you would like to add to the list.\n";
	cout << "Data: ";
	cin >> nNewData;
	CNewItem.Set(nNewData);

	try 
	{
		ListObj.PutItem(CNewItem);
		cout << CNewItem.Get() << " has been added to the list.\n\n";
	} catch (FullList) {
		cerr << "Exception caught: The list is currently full.\n\n";
	}
}

void SearchCase(CUnsortedLList& ListObj)
{
	bool found;
	int nData;
	ItemType CSearchItem;
	cout << "Enter the data that you are searching for in the list.\n";
	cout << "Data: ";
	cin >> nData;
	CSearchItem.Set(nData);

	ListObj.Search(CSearchItem, found);

	if (found == true) {
		cout << nData << " was found in the list.\n\n";
	} else {
		cout << nData << " was not found in the list.\n\n";
	}
}

void DeleteCase(CUnsortedLList& ListObj)
{
	bool found;
	int nData;
	ItemType CItemToDelete;
	cout << "Enter the data that you would like to delete from the list.\n";
	cout << "Data: ";
	cin >> nData;
	CItemToDelete.Set(nData);

	ListObj.DeleteItem(CItemToDelete, found);

	if (found == true)
		cout << nData << " has been deleted from the list.\n";
	else
		cout << nData << " was not found in the list.\n";
}

void ProgramMenu(CUnsortedLList& ListObj)
{
	char cSelection = ' ';
	do
	{
		cout << "Enter the operation that you would like to perform on the list.\n";
		cout << "1 - Insert an item.\n";
		cout << "2 - Search for an item.\n";
		cout << "3 - Get the next item in the list.\n";
		cout << "4 - Get the length of the list.\n";
		cout << "5 - Delete an item from the list.\n";
		cout << "6 - Reset the list to the beginning.\n";
		cout << "7 - Make the list empty.\n";
		cout << "Q - Quit.\n";
		cout << "Selection: ";
		cin >> cSelection;

		system("cls");
		ProcessSelection(ListObj, cSelection);

	} while (toupper(cSelection) != 'Q');
}