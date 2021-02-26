#include "UnsortedLL.h"

CUnsortedLList::CUnsortedLList()
{
	m_nLength = 0;
	m_nMaxLength = MAX_ITEMS;
	m_pListData = nullptr;
}

CUnsortedLList::CUnsortedLList(int nMax)
{
	m_nLength = 0;
	m_nMaxLength = nMax;
	m_pListData = nullptr;
}

void CUnsortedLList::MakeEmpty()
{
	Node* pTemp = m_pListData; //Create pointer and set on head of list
	Node* pTempTrailer = nullptr;
	while (pTemp != nullptr)
	{
		pTempTrailer = pTemp; //Advance trailer to the node to be deleted.
		pTemp = pTemp->pNext; //Advance pTemp to the next node in the LL.
		delete pTempTrailer; //Deallocate mem. for the current node.
	}

	m_nLength = 0;
	m_pListData = nullptr;
}

bool CUnsortedLList::IsFull() const
{
	return (m_nLength == m_nMaxLength);
}

bool CUnsortedLList::IsEmpty() const
{
	return (m_pListData == nullptr);
}

int CUnsortedLList::GetLength() const
{
	return m_nLength;
}

ItemType CUnsortedLList::Search(ItemType item, bool& found)
{
	found = false;
	Node* pTemp = m_pListData;
	while (pTemp != nullptr)
	{
		if (pTemp->CData.ComparedTo(item) == EQUAL)
		{
			found = true;
			return pTemp->CData;
		}
		
		pTemp = pTemp->pNext;
	}

	return item; //If not found, found flag stays false and original item returned.
}

void CUnsortedLList::PutItem(ItemType item)
{
	if (IsFull() == true)
		throw FullList();

	Node* pTemp = new Node;
	pTemp->CData = item;

	if (m_pListData == nullptr) { //If list is empty at first insertion
		m_pListData = pTemp;
	} else {
		pTemp->pNext = m_pListData;
		m_pListData = pTemp;
	}

	m_nLength++;
	m_pCurrentNode = pTemp;
}

void CUnsortedLList::DeleteItem(ItemType item, bool& found)
{
	found = false;
	Node* pTemp = m_pListData;
	Node* pTempTrailer = nullptr;
	
	if (m_pListData->pNext == nullptr && m_pListData->CData.ComparedTo(item) == EQUAL) { //If only one node.
		found = true;
		m_nLength--;
		delete pTemp;
		m_pListData = nullptr;
	} else if (m_pListData->CData.ComparedTo(item) == EQUAL) { //If node to delete is at front and there is more than one node
		found = true;
		pTempTrailer = pTemp->pNext;
		m_nLength--;
		delete pTemp;
		m_pListData = pTempTrailer;
	} else { //Node is found in the middle of the list.
		while (pTemp != nullptr)
		{
			if (pTemp->CData.ComparedTo(item) == EQUAL) {
				found = true;
				pTempTrailer->pNext = pTemp->pNext;
				m_nLength--;
				delete pTemp;
				pTemp = nullptr;
			} else {
				pTempTrailer = pTemp;
				pTemp = pTemp->pNext;
			}
		}
	}
}

void CUnsortedLList::ResetList()
{
	m_pCurrentNode = m_pListData; //Setting current node pointer back to beginning.
}

ItemType CUnsortedLList::GetCurrentItem()
{
	if (IsEmpty() == true)
		throw EmptyList();

	return m_pCurrentNode->CData;
}

ItemType CUnsortedLList::GetNextItem()
{
	if (IsEmpty() == true)
		throw EmptyList();

	if (m_pCurrentNode->pNext == nullptr) //If at end, wrap to front.
		m_pCurrentNode = m_pListData;
	else
		m_pCurrentNode = m_pCurrentNode->pNext;

	return m_pCurrentNode->CData;
}

CUnsortedLList::~CUnsortedLList()
{
	Node* pTemp = m_pListData;
	Node* pTempTrailer = nullptr;

	while (pTemp != nullptr)
	{
		pTempTrailer = pTemp;
		pTemp = pTemp->pNext;
		delete pTempTrailer;
	}
}