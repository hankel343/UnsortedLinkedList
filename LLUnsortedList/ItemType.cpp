#include "ItemType.h"

ItemType::ItemType() {
	iItem = 0;
};

RelationType ItemType::ComparedTo(ItemType iInputItem)
{
	if (iItem > iInputItem.Get()) {
		return GREATER;
	}
	else if (iItem < iInputItem.Get()) {
		return LESS;
	}
	else
		return EQUAL;
}