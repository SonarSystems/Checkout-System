# Checkout System

## Instructions
1. 

## Testing

UT was used for the testing framework due to it's simplicity and ease of use. For a bigger project Google Test or Catch would be used. 
https://boost-ext.github.io/ut/

To enable testing, uncomment the line "#define RUN_TESTS" in main.cpp.

## What Was Missed
- Check on pricing rules to avoid duplicate SKU rules.

## Assumptions
- Assuming SKU's cannot be composed of more than a single character, for example "AB" would be invalid. If this is not the case, then switching the SKU data type from char to string would resolve this.
- unsigned int was used for currency in pence, thus assuming the value of a single item will not got beyond 4294967295p (£42,949,672.95). If a larger value is required then a unsigned long int or unsigned long long int can be used.
- Assuming when an item is discounted, any extra items of the same type bought are added on using the original price. For example, Item A costs £50, a special rule is added for 3 items at a price of £130. If 4 items are about then the 4th item is priced at the full price of £50 with a total price of £180.

## Design Decisions
- typedef was used for variables such as currency and SKU, so they could easily be swapped out later for different data types incase they were not sufficient.
- A struct was used for the pricing rules to allow more complex rules to be added. 
- If an item with the same SKU but different price is added, the new price is ignored. It is assumed to update the price in the current checkout session, all items of that class must be removed and updated one added.
- All the code files were put together, if the project was more complex they would be split into include and src folders. Along with separation of external user added libraries.
