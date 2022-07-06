# Checkout System

## Instructions
1. 

## Testing

UT was used for the testing framework due to it's simplicity and ease of use. For a bigger project Google Test or Catch would be used. 
https://boost-ext.github.io/ut/

To enable testing, uncomment the line "#define RUN_TESTS" in main.cpp.

## What Was Missed

- 

## Assumptions
- Assuming SKU's cannot be composed of more than a single character, for example "AB" would be invalid. If this is not the case, then switching the SKU data type from char to string would resolve this.
- typedef was used for variables such as currency and SKU, so they could easily be swapped out later for different data types incase they were not sufficient

## Design Decisions
- 
