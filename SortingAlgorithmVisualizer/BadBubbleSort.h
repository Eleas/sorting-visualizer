#pragma once
#include "Sorter.h"

class BadBubbleSort : public Sorter {

public:
    BadBubbleSort(vector<int> data);
    ~BadBubbleSort();

public:
    void SingleComparison();

public:
    string Name();
};

