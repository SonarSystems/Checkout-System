#pragma once

#include <tuple>
#include <utility>
#include <Vector>

#include "DEFINITIONS.h"
#include "Item.hpp"

using namespace std;

/**
* \brief Rules for pricing
*/
struct PricingRules
{
	sku_t sku; // Item stock keeping unit
	unsigned int quantity; // Minimum number of items to trigger the discounted price
	currency_t price; // Price of discounted items if quantity is met
};

class Checkout
{
public:
	/**
	* \brief Default class constructor with no pricing rules
	*/
	Checkout() { }

	/**
	* \brief Class constructor
	* 
	* \param pricingRules Price saving rules
	*/
	Checkout(const vector<PricingRules> &pricingRules) : _pricingRules(pricingRules) { }

	/**
	* \brief Default class destructor
	*/
	~Checkout() { }

	/**
	* \brief Scans/adds item to checkout session
	* 
	* \param item Item to be added
	* \param quantity Item quantity. This parameter is optional, if not specified it is set to 1
	*/
	void Scan(const Item &item, const unsigned int quantity = 1);

	/**
	* \brief Voids/removes an item from the checkout session
	* 
	* \param item Item to be removed
	* \param voidAll Are all quantities of the item to be removed. This parameter is optional, if not specified it is set to false
	*/
	void Void(const Item &item, const bool voidAll = false);

	/**
	* \brief Voids/removes all items from the checkout session
	*/
	void VoidAll();
	
	/**
	* \brief Calculates the total cost in pence, including any discounts
	* 
	* \return Returns the total cost of all items in pence
	*/
	[[nodiscard]] currency_t Total() const;

	/**
	* \brief Get the pricing rules
	* 
	* \return Returns the pricing rules vector
	*/
	[[nodiscard]] const vector<PricingRules> &GetPricingRules() const;

	/**
	* \brief Set the pricing rules
	* 
	* \param pricingRules Discount pricing rules
	*/
	void SetPricingRules(const vector<PricingRules> &pricingRules);

private:
	/**
	* \brief Rules for the price savings engine
	*/
	vector<PricingRules> _pricingRules;

	/**
	* \brief Items added for a checkout session
	* 
	* First pair - item object
	* Second pair - item quantity
	*/
	vector<pair<Item, unsigned int>> _items;

};

