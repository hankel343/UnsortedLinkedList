#ifndef ITEMTYPE_H
#define ITEMTYPE_H
typedef int type;

enum RelationType
{
	LESS,
	GREATER,
	EQUAL
};

class ItemType {
public:
	ItemType();
	RelationType ComparedTo(ItemType inputiItem);
	void Set(type inputiItem) { iItem = inputiItem; };
	type Get() { return iItem; };
private:
	type iItem;
};

#endif ITEMTYPE_H