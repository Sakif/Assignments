# symbolTable.hpp

Name: Sakif Zaman

Dal ID: B00756635

Last Modified: 2019 June 3

## Description

Will be filled out soon

---
* -logfileName:string
* -startSymbolFile:string
* -start:symbol
* -count:unsigned int
---
* +create(in logFile:string = "firstPass.log", in startSymbols:string = "StartSymbols.csv"):symbolTable
* +destroy()
* +findSymbol(in label:string):symbol
* +addSymbol(in name:string, in value:short = 0, in type:symbolType = UNKNOWN)
* +printTable(in symbolOut:string = "symbols.csv"):symbol.csv
* +symbolCount():unsigned int
* -pop()
---
### create

It takes in the name for the log file and the location of the starting symbols (the starting registers, and their values). They have default values for quick use, but can be changed if needed. It sets initializes the symbol count to 0.

### destroy

A destructor is needed as this class contains pointers.

### pop

Is only designed to assist with the destructor

### findSymbol

Finds the symbol that matches the string passed into the input parameter. This is a linear search.

### addSymbol

Creates a symbol node and adds it to the list. Increments the symbol count.

### printTable

Exports the symbol table into a csv file.

### symbolCount

Just returns the number of symbols in the symbol table.