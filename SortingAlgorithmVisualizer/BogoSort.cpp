#include "BogoSort.h"

BogoSort::BogoSort(vector<int> data) : Sorter(data) {
    if (data.size() < 2) {
        SetDone(true);
    }

    generator = mt19937(rd());
}

BogoSort::~BogoSort() {}

void BogoSort::SingleComparison() {
    if (Found()) { // Start new pass.
        i = 0;
        j = 0;
        SetFound(false);
    }

    if (j == Count() - 1) {

        if (Found() == false && i == Count() - 2) {
            SetDone(true);
            return;
        }

        j = ++i;
    }

    ++j;
    auto& data = GetData();

    SetFound(data[i] > data[j]);
    if (Found()) {
        shuffle(data.begin(), data.end(), generator);
    }

    IncrementOperations();
}

string BogoSort::Name() {
    return "BogoSort";
}
