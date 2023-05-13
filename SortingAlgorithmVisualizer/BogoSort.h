#pragma once
#include "Sorter.h"
#include <random>
#include <sstream>      // std::ostringstream
#include <vector>

using std::mt19937;
using std::random_device;
using std::vector;

class BogoSort : public Sorter {
    random_device rd;
    mt19937 generator;

public:
    BogoSort(vector<int> data);
    ~BogoSort();

public:
    void SingleComparison();

public:
    string Name();

};