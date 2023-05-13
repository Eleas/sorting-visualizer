#pragma once
#include "Sorter.h"

class CocktailSort : public Sorter {
    bool towardsRight = true;
public:
    CocktailSort(vector<int> data);
    ~CocktailSort();

public:
    void SingleComparison();

public:
    string Name();
};

