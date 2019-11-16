; org $1000 ; org test
shortLabel;garbage
lower_case_label ;garbage
UPPER_CASE_LABEL; garbage
aVeryLongLabelWithOnlyAlphabeticCharactersThatAreOverTheLimit
LabelWith_
_Label
labelWithNumber1
ASD*;this should be ignored
_1 ; this is valid label
; symbol table should all have a value of 0
; or 1000 if org is uncommented