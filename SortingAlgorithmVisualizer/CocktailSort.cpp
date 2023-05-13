#include "CocktailSort.h"

CocktailSort::CocktailSort(vector<int> data) : Sorter(data) {
    if (data.size() < 2) {
        SetDone(true);
    }
    i = -1;
}

CocktailSort::~CocktailSort() {}

void CocktailSort::SingleComparison() {
    if (Found()) {
        i = (towardsRight) ? -1 : Count()-1;
    }

    auto& data = GetData();
    SetFound(false);

    if (towardsRight) {
        if (++i == Count() - 1) {
            SetDone(true);
            return;
        }
    }
    else if (!towardsRight) {
        if (--i == -1) {
            SetDone(true);
            return;
        }
    }

    j = i + 1;

    SetFound(data[i] > data[j]);
    if (Found()) {
        swap(data[i], data[j]);
        towardsRight = !towardsRight;
    }

    IncrementOperations();
}

string CocktailSort::Name() {
    return "Cocktail sort";
}
