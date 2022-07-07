#include <iostream>

#include "DEFINITIONS.h"
#include "Checkout.hpp"
#include "Item.hpp"

#ifdef RUN_TESTS
#include "TESTING.hpp"
#else
int main()
{
	// Set to UTF-8
	setlocale(LC_ALL, "");

	Item itemA('A', 5000);
	Item itemB('B', 3000);
	Item itemC('C', 2000);
	Item itemD('D', 1500);
	Item itemE('E', 300);

	vector<PricingRules> pricingRules;
	pricingRules.push_back({ itemA.GetSKU(), 3, 13000 });
	pricingRules.push_back({ itemB.GetSKU(), 2, 4500 });

	Checkout co(pricingRules);
	co.Scan(itemA);
	co.Scan(itemA);
	co.Scan(itemA);
	co.Scan(itemB);
	co.Scan(itemB);
	co.Scan(itemB);

	auto priceSoFar = co.Total();
	std::cout << '£' << priceSoFar * 0.01f << std::endl;

	co.Void(itemB);
	co.Scan(itemD);
	co.Scan(itemA);

	auto totalPrice = co.Total();
	std::cout << "£" << totalPrice * 0.01f << std::endl;

	return EXIT_SUCCESS;
}
#endif