# Coding Task

## Instructions

You will need to write code in C++ that meets the below task specification. When reviewing the submission with us, please be prepared to share the result either in person by bringing a laptop, or by presenting in an online meeting. We will want to talk through it, stepping through using the debugger as required.
It is not necessary for this to be a ‘finished product’, or to cover any edge-cases you might come across. Rather, we are more interested in your overall design, structure of code and how you use the technologies involved. Feel free to use comments to describe missing pieces, extra considerations, future work etc.

It is up to you how long you spend on the task, we suggest a maximum of three hours. If you do run out of time, please just add a few paragraphs of text about what was left to implement and how it would work.

## Task

The goal is to implement the code for a shop checkout system that can scan and void items, as well as calculate their total price. Items are identified using Stock Keeping Units (SKUs), e.g. using individual letters of the alphabet (A, B, C, etc). Goods are either priced individually, or multi-priced: buy N of them, and they’ll cost you X pounds. For example, item ‘A’ might cost £50 individually, but this week’s special offer is buy three ‘A’s and they’ll cost you £130. Some example data might be:-

The checkout accepts items in any order, so that if we scan a B, an A, and another B, we’ll recognize the two B’s and price them at £45 (for a total price so far of £95). Because the pricing changes frequently, we need to be able to pass in a set of pricing rules each time we start handling a checkout transaction.

| Item | Unit Price | Special Price |
| ---- | :--------: | :-----------: |
| A    |    £50     |  3 for £130   |
| B    |    £30     |   2 for £45   |
| C    |    £20     |               |
| D    |    £15     |               |
| E    |     £3     |               |

The final code should be able to be called along the lines of:

```cpp
CheckOut co(pricing_rules);
co.scan(itemA); // add an item of class A
co.scan(itemB); // add an item of class B
auto priceSoFar = co.total(); // get subtotal
co.void(itemB); // remove an item of class B
co.scan(itemD); // add an item of class D
co.scan(itemA); // add an item of class A
auto totalPrice = co.total(); // get final total
```

Things to think about could include class design (e.g. item types), decoupling, testing, flexibility for adding new SKUs and pricing strategies / rules etc.
