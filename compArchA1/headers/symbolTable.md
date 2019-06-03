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
* +validSymbol(in label:string, in pc:int):bool
* +findSymbol(in label:string):symbol
* +addSymbol(in name:string, in value:short = 0, in type:symbolType = UNKNOWN)
* +printTable(in symbolOut:string = "symbols.csv"):symbol.csv
* +symbolCount():unsigned int
* -pop()
---
### create()

Sets up the symbol with default values. It takes in the name for the log file and starting symbol. They have default values for quick use, but can be changed if needed.

### destroy()

A destructor is needed as this class contains pointers.

### pop()

Is only designed to assist with the destructor