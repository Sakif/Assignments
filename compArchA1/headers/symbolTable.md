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
* +printTable(in symbolOut:string):Symbol Table csv
* +symbolCount():unsigned int
* -pop()
---