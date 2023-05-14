#pragma once
#include <algorithm>
#include <iostream>
#include <numeric>
#include <random>
#include <ranges>
#include <sstream>
#include <vector>
#include "Sorter.h"
#include "BubbleSort.h"
#include "BadBubbleSort.h"
#include "BogoSort.h"
#include "CocktailSort.h"

using std::cout;
using std::iota;
using std::make_pair;
using std::mt19937;
using std::ostringstream;
using std::pair;
using std::random_device;
using std::ranges::sort;
using std::string;
using std::uniform_int_distribution;
using std::vector;



enum class Sort {
    BubbleSort,
    BadBubbleSort,
    BogoSort,
    CocktailSort
};


Sorter* SortingMethodFactory(Sort method, vector<int> vec) {
    switch (method) {
        case Sort::BubbleSort:      return new BubbleSort(vec);
        case Sort::BadBubbleSort:   return new BadBubbleSort(vec);
        case Sort::BogoSort:        return new BogoSort(vec);
        case Sort::CocktailSort:    return new CocktailSort(vec);
        default: throw "Not implemented here.";
    }
}


vector<int> GenerateRandomIntegers(const size_t count) {
    random_device rd;                          // Random device used as a seed for the random number engine
    mt19937 rng(rd());                         // Mersenne Twister random number engine
    uniform_int_distribution<int> dist(1, 100); // Distribution range for random integers

    vector<int> numbers(count);
    generate_n(numbers.begin(), count, [&]() { return dist(rng); });

    return numbers;
}

vector<int> GenerateList(const size_t count) {
    random_device rd;                          // Random device used as a seed for the random number engine
    mt19937 rng(rd());                         // Mersenne Twister random number engine

    vector<int> numbers(count);
    iota(numbers.begin(), numbers.end(), 0);
    shuffle(numbers.begin(), numbers.end(), rng);
    return numbers;
}



// Just to get a sense of what's happening during the sorting.
void Output(Sorter& s) {
    for (auto& n : s.GetData()) {
        cout << n << " ";
    }

    auto done = s.Sorted();
    auto found = s.Found();

    if (found) {
        auto positions = s.Positions();
        cout << "Found! Swapped " << s.GetData()[positions.second] << 
            " for " << s.GetData()[positions.first] << "!\n";
    }

    if (done) {
        cout << "Done sorting!";
    }

    cout << "\n";
}



vector<pair<bool, Sorter*>> ConstructSortingArray(vector<Sort> methods, vector<int> vec) {
    vector<pair<bool, Sorter*>> contents;

    for (auto& method : methods) {      
        contents.push_back(make_pair(false, SortingMethodFactory(method, vec)));
    }

    return contents;
}


string VectorToString(const vector<int>& numbers) {
    ostringstream oss;
    if (!numbers.empty()) {
        oss << numbers[0];
        for (size_t i = 1; i < numbers.size(); ++i) {
            oss << ", " << numbers[i];
        }
    }
    return oss.str();
}


void Comparison(const vector<Sort> methods, vector<int> vec, const size_t interval = 10000)
{
    vector<pair<bool, Sorter*>> sortingMethods =
        ConstructSortingArray(methods, vec);

    sort(vec);

    bool allDone = false;
    size_t counter = 0;

    cout << "Sorting an array of " << vec.size() << " elements\n";
    cout << "-----------------------------------------------------\n";

    for (auto& method : sortingMethods) {
        cout << method.second->Name() << "\n";
    }

    cout << "-----------------------------------------------------\n";

    while (!allDone) {
        allDone = true;
        for (auto& sort : sortingMethods) {
            if (!sort.first) {
                if (!sort.second->Sorted()) {
                    sort.second->SingleComparison();
                    allDone = false;
                }
                else {
                    cout << "\n";
                    cout << sort.second->Name() << " finished ("
                        << sort.second->OperationsPerformed() << ")\n";
                    sort.first = true;

                    if (vec != sort.second->GetData()) {
                        cout << "Mismatch!\n";
                        cout << "Original list: {" <<
                            VectorToString(vec) << "};";
                        cout << "This list:     {" <<
                            VectorToString(sort.second->GetData()) << "};";
                    }

                    delete sort.second;
                }
            }
        }

        if (counter++ % interval == 0) {
            cout << ".";
        }
    }
}