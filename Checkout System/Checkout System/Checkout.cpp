#include "Checkout.hpp"

void Checkout::Scan(const Item &item, const unsigned int quantity /*= 1*/)
{
	// Loop over existing scanned items, if it already exists then increase quantity
	for (auto &i : _items)
	{
		// Matched item
		if (i.first.GetSKU() == item.GetSKU())
		{
			i.second += quantity;

			return;
		}
	}

	// Item does not exist currently, add to _items
	_items.push_back(make_pair(item, quantity));
}

void Checkout::Void(const Item &item, const bool voidAll /*= false*/)
{
	// Loop over existing scanned items, remove the item to void if it exists
	for (unsigned int i = 0; i < _items.size(); i++)
	{
		// Matched item
		if (_items[i].first.GetSKU() == item.GetSKU())
		{
			// Check if all items of that type are to be removed or just one
			if (voidAll)
			{ _items.erase(_items.begin() + i); }
			else
			{
				_items[i].second--;

				// Check if after removal there are no items left, if so remove item from scanned items
				if (_items[i].second == 0)
				{ _items.erase(_items.begin() + i); }
			}
		}
	}
}

void Checkout::VoidAll()
{ _items.clear(); }

currency_t Checkout::Total() const
{
	currency_t total = 0;

	// Loop over all scanned items
	for (auto i : _items)
	{
		bool isDiscounted = false;

		// Loop over all pricing rules to check if any scanned items have any special pricing rules
		for (const auto &rule : _pricingRules)
		{
			// Check if the scanned item sku is present in the pricing rules
			if (i.first.GetSKU( ) == rule.sku)
			{
				// Check if the scanned item quantity is large enough to trigger the discount
				if (i.second >= rule.quantity)
				{
					total += rule.price;
					total += (i.second - rule.quantity) * i.first.GetPrice();

					isDiscounted = true;

					break;
				}
			}
		}

		// If it's not discounted then the price needs to added individually without any special price
		if (!isDiscounted)
		{ total += i.second * i.first.GetPrice(); }
	}

	return total;
}

const std::vector<PricingRules> &Checkout::GetPricingRules( ) const
{ return _pricingRules; }

void Checkout::SetPricingRules( const vector<PricingRules> &pricingRules )
{ _pricingRules = pricingRules; }
