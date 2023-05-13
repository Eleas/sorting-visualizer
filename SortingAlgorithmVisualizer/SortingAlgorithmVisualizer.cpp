#include <iostream>

#include "Sorter.h"
#include "BubbleSort.h"
#include "BadBubbleSort.h"
#include "BogoSort.h"

#include "SortingUtilities.h"

using std::cout;
using std::pair;
using std::ranges::sort;
using std::vector;



int main() {
    Comparison(
        {
            Sort::BadBubbleSort,
            Sort::BubbleSort,
            Sort::CocktailSort
        },
        GenerateRandomIntegers(100));

    return 0;
}
