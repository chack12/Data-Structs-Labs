#include <vector>
<<<<<<< HEAD
#include "../TemplatesAndClassesDLL/Party.h"
=======
#include "Party.h"
>>>>>>> 0c5c40f8d6ca8138a718cf249a579b71b3fecd0e

template<class ItemType>
	void Party<ItemType>::addChar(const ItemType& newCharacter) {
		 
		// For Back row of Party.
		if (std::vector<ItemType>backRow.size() < 1) {
			backRow.push_back(newCharacter);
		}
		else {
			cout << "Your Party's back row is full." << endl;
		}

		// For Front row of Party

		if (std::vector<ItemType>frontRow.size() < 1) {
			frontRow.push_back(newCharacter);
		}
		else {
			cout << "Your Party's front row is full."
		}
}

template<class ItemType>
Party<ItemType>::Party() {}
