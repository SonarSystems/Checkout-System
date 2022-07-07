#pragma once

#include "acutest.h"

#include "Checkout.hpp"
#include "Item.hpp"

#include "DEFINITIONS.h"

#ifdef RUN_TESTS
void Test_1_Item()
{
	Item itemA('A', 7000);

	Checkout co;

	co.Scan(itemA);
	co.Scan(itemA);

	TEST_CHECK(co.Total() == 14000);
}

void Test_2_Items()
{
	Item itemA('A', 5000);
	Item itemB('B', 3000);

	Checkout co;

	co.Scan(itemA);
	co.Scan(itemA);
	co.Scan(itemA);
	co.Scan(itemB);
	co.Scan(itemB);
	co.Scan(itemB);

	TEST_CHECK(co.Total() == 24000);
}

void Test_5_Items()
{
	Item itemA('A', 5000);
	Item itemB('B', 3000);
	Item itemC('C', 2000);
	Item itemD('D', 1500);
	Item itemE('E', 300);

	Checkout co;

	co.Scan(itemA);
	co.Scan(itemB);
	co.Scan(itemC);
	co.Scan(itemD);
	co.Scan(itemE);

	TEST_CHECK(co.Total() == 11800);
}

void Test_1_Item_Void()
{
	Item itemA('A', 5000);
	Item itemB('B', 3000);
	Item itemC('C', 2000);
	Item itemD('D', 1500);
	Item itemE('E', 300);

	Checkout co;

	co.Scan(itemA);
	co.Scan(itemB);
	co.Scan(itemB);
	co.Scan(itemB);
	co.Scan(itemC);
	co.Scan(itemD);
	co.Scan(itemE);
	co.Void(itemB);

	TEST_CHECK(co.Total() == 14800);
}

void Test_All_Items_Void()
{
	Item itemA('A', 5000);
	Item itemB('B', 3000);
	Item itemC('C', 2000);
	Item itemD('D', 1500);
	Item itemE('E', 300);

	Checkout co;

	co.Scan(itemA);
	co.Scan(itemB);
	co.Scan(itemB);
	co.Scan(itemB);
	co.Scan(itemC);
	co.Scan(itemD);
	co.Scan(itemE);

	co.VoidAll();

	TEST_CHECK(co.Total() == 0);
}

void Test_1_Pricing_Rule()
{
	Item itemA('A', 5000);
	Item itemB('B', 3000);
	Item itemC('C', 2000);
	Item itemD('D', 1500);
	Item itemE('E', 300);

	vector<PricingRules> pricingRules;
	pricingRules.push_back({ itemA.GetSKU(), 3, 13000 });

	Checkout co(pricingRules);

	co.Scan(itemA);
	co.Scan(itemA);
	co.Scan(itemA);
	co.Scan(itemB);
	co.Scan(itemC);
	co.Scan(itemD);
	co.Scan(itemE);

	TEST_CHECK(co.Total() == 19800);
}

void Test_2_Pricing_Rules()
{
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
	co.Scan(itemC);
	co.Scan(itemD);
	co.Scan(itemE);

	TEST_CHECK(co.Total() == 21300);
}

TEST_LIST =
{
	{ "Test_1_Item", Test_1_Item },
	{ "Test_2_Items", Test_2_Items },
	{ "Test_5_Items", Test_5_Items },
	{ "Test_1_Item_Void", Test_1_Item_Void },
	{ "Test_All_Items_Void", Test_All_Items_Void },
	{ "Test_1_Pricing_Rule", Test_1_Pricing_Rule },
	{ "Test_2_Pricing_Rules", Test_2_Pricing_Rules },
	{ 0 }
};
#endif