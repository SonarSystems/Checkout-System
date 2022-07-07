#pragma once

#include "DEFINITIONS.h"

class Item
{
public:
    /**
    * \brief Default class constructor - If used, ensure the sky and price variables are set
    */
    Item() { };

    /**
    * \brief Class constructor with SKU
    * 
    * \param sku SKU to set
    */
    Item(const sku_t sku, const currency_t price) : _sku(sku), _price(price) { }

    /**
    * \brief Class destructor
    */
    ~Item() { }

    /**
    * \brief Get the SKU
    * 
    * \return Returns the SKU variable
    */
    [[nodiscard]] sku_t GetSKU() const;
    /**
    * \brief Set the SKU
    * 
    * \param sku SKU to set
    */
    void SetSKU(const sku_t sku);

    /**
    * \brief Get the price in pence
    * 
    * \return Returns the price variable
    */
    [[nodiscard]] currency_t GetPrice() const;
    /**
    * \brief Set the price
    * 
    * \param price Price to set
    */
    void SetPrice(const currency_t price);

private:
    /**
    * \brief Stock Keeping Unit
    */
    sku_t _sku;

    /**
    * \brief Price of item in pence
    */
    currency_t _price;

};

