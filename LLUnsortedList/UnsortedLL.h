#ifndef UNSORTEDLINKED_H
#define UNSORTEDLINKED_H
#define MAX_ITEMS 5

#include "ItemType.h"

class FullList {};
class EmptyList {};

struct Node
{
	ItemType CData;
	Node* pNext = nullptr;
};

class CUnsortedLList
{
private:
	int m_nLength;
	int m_nMaxLength;
	Node* m_pListData;
	Node* m_pCurrentNode;

public:
	CUnsortedLList();
	CUnsortedLList(int nMax);
	
	//Methods:
	void MakeEmpty();
	bool IsFull() const;
	bool IsEmpty() const;
	int GetLength() const;
	ItemType Search(ItemType item, bool& found);
	void PutItem(ItemType item);
	void DeleteItem(ItemType item, bool& found);
	void ResetList();
	ItemType GetCurrentItem();
	ItemType GetNextItem();

	
	~CUnsortedLList();
	
};

#endif UNSORTEDLINKED_H