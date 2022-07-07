# Checkout System

## Instructions
An object of Checkout must be created to use it. For example, with a Checkout object called co, the following commands can be used:

- co.Scan(Item, optionalQuantity) - adds an item to the checkout session
- co.Void(Item, voidAll) - removes an item from the checkout, with the option to remove all quantity of that item
- co.VoidAll() - removes all items from the checkout session
- co.Total() - calculates the total of all items including any discounts

## Testing

Acutest was used for the testing framework due to its simplicity and ease of use. For a bigger project, Google Test or Catch would be used. 
https://github.com/mity/acutest

To enable testing, uncomment the line "#define RUN_TESTS" in DEFINITIONS.h.

## What Was Missed
- Check on pricing rules to avoid duplicate SKU rules.

## Assumptions
- Assuming SKUs cannot be composed of more than a single character, for example, "AB" would be invalid. If this is not the case, then switching the SKU data type from char to string would resolve this.
- unsigned int was used for currency in pence, thus assuming the value of a single item will not go beyond 4294967295p (£42,949,672.95). If a larger value is required then an unsigned long int or unsigned long long int can be used.
- Assuming when an item is discounted, any extra items of the same type bought are added on using the original price. For example, Item A costs £50, and a special rule is added for 3 items at a price of £130. If 4 items are bought then the 4th item is priced at the full price of £50 with a total price of £180.

## Design Decisions
- typedef was used for variables such as currency and SKU, so they could easily be swapped out later for different data types in case they were not sufficient.
- A struct was used for the pricing rules to allow more complex rules to be added. 
- If an item with the same SKU but a different price is added, the new price is ignored. It is assumed to update the price in the current checkout session, all items of that class must be removed and the updated one added.
- All the code files were put together, if the project was more complex they would be split into include and src folders. Along with the separation of external user-added libraries.
