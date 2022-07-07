#include "Item.hpp"

sku_t Item::GetSKU() const
{ return _sku; }

void Item::SetSKU(const sku_t sku)
{ _sku = sku; }

currency_t Item::GetPrice( ) const
{ return _price; }

void Item::SetPrice( const currency_t price )
{ _price = price; }
