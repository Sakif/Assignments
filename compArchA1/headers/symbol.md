# symbol.hpp

Name: Sakif Zaman

Dal ID: B00756635

Last Modified: 2019 June 3

## Description

There are two items in this file:
* an enum symbolType
* a class symbol

## symbolType

This enum defined the possible values of symbol type:
* Unknown
* Label
* Register

## symbol

Defines the symbol node for use in Symbol Table.

---
* +name:string
* +value:short
* +type:symbolType
* +next:symbol
---
* +create(in n:string, in v;short, in t:symbolType, in nextSymbol:symbol = nullptr):symbol
* +update(in v:short, in t:symbolType)
---