import RowEchelon: rref

H = [
0 1 0 1 1 0 1 1 0
1 0 1 0 1 0 1 0 1
1 1 0 1 1 0 0 0 0
1 0 0 1 1 1 1 1 1
1 1 1 1 1 1 1 1 0
]

reducedH = rref(H)

A = [
0 1 1 0
1 1 1 1
1 1 1 0
0 1 0 1
1 1 0 1
]