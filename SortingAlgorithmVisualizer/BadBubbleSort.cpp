#include "BadBubbleSort.h"

BadBubbleSort::BadBubbleSort(vector<int> data) : Sorter(data) {
    if (data.size() < 2) {
        SetDone(true);
    }
}

BadBubbleSort::~BadBubbleSort() {}

void BadBubbleSort::SingleComparison() {
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
        swap(data[i], data[j]);
    }

    IncrementOperations();
}

string BadBubbleSort::Name() {
    return "Bad bubble sort";
}
