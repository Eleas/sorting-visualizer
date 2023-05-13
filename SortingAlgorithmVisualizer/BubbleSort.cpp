#include "BubbleSort.h"

BubbleSort::BubbleSort(vector<int> data) : Sorter(data) {
    if (data.size() < 2) {
        SetDone(true);
    }
    i = -1;
}

BubbleSort::~BubbleSort() {}

void BubbleSort::SingleComparison() {
    if (Found()) {
        i = -1;
    }

    auto& data = GetData();
    SetFound(false);

    if (++i == Count() - 1) {
        SetDone(true);
        return;
    }

    j = i + 1;

    SetFound(data[i] > data[j]);
    if (Found()) {
        swap(data[i], data[j]);
    }

    IncrementOperations();
}

string BubbleSort::Name() {
    return "Bubble sort";
}
