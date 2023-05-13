#pragma once
#include "Sorter.h"

class BubbleSort : public Sorter {

public:
    BubbleSort(vector<int> data);
    ~BubbleSort();

public:
    void SingleComparison();

public:
    string Name();
};

