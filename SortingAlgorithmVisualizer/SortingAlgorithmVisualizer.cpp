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


#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"

// Override base class with your custom functionality
class Example : public olc::PixelGameEngine
{
public:
	Example()
	{
		// Name your application
		sAppName = "Example";
	}

public:
	bool OnUserCreate() override
	{
		// Called once at the start, so create things here
		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
		// Called once per frame, draws random coloured pixels
		for (int x = 0; x < ScreenWidth(); x++)
			for (int y = 0; y < ScreenHeight(); y++)
				Draw(x, y, olc::Pixel(rand() % 256, rand() % 256, rand() % 256));
		return true;
	}
};


int main() {
    Comparison(
        {
            Sort::BadBubbleSort,
            Sort::BubbleSort,
            Sort::CocktailSort
        },
        GenerateList(100));

	Example demo;
	if (demo.Construct(256, 240, 4, 4))
		demo.Start();
	return 0;
}
