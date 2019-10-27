# Lab 1
Starting from the first lab we practice C++ programming. The first tasks will be very simple and then me move the more complicated tasks.

You are encouraged to participate and practice and ask questions to me and out TAs.

## Task 1

Create a program which takes a positive integer number N as an input. The program needs to output Fibonacci numbers F(1), F(2), ..., F(N)

For example:

N=5

Output: 1,1,2,3,5

--------------

N=8

Output: 1,1,2,3,5,8,13,21

## Task 2

Create a program which takes a positive integer number N as an input. The program needs to output all prime factors of this number. In other words, the software needs to perform prime factorization of N.

For example:

N=5

Output: 5

--------------

N=8

Output: 2,2,2

--------------

N=20

Output: 2,2,5

Once most of the people complete a task a solution will be posted.

# Lab 2
## Task 1

Create a program which takes an integer m as an input and outputs prime number number m. For example:

for m = 1 output 2

for m = 2 output 3

for m = 3 output 5 etc.

## Task 2

You are given a file student.txt which contains student records. The first row contains the number of records. The latter rows contains records themselves in the form

Name

Family name

GPA

U for undergraduate/ or G for graduate

F for female/ M for male

ID number

(no empty rows)

An example of file is attached (TBD). Your task, read the file and count how many undergraduate students are there, and how many females.

## Task 3

Create a program which performs prime number decomposition (as in lab 1), but uses a recursive function which calls itself, but with smaller parameter values.

# Lab 3

See Task 2, from Lab 2, the problem about student records.

Write a problem which reads the student records file and outputs another file where the records are sorted alphabetically according to the student's last name. (can use strcmp function to compare strings)

# Lab 4

See Task 2, from Lab 2, the problem about student records.

Write a problem which reads the student records file and outputs another file where the records are sorted alphabetically according to the student's last name. (can use strcmp function to compare strings)

Perform the above task by creating a type Student class where the data are private fields, while we use methods to set data and get data.

# Lab 5, formula parser

This lab starts a series of labs where we will be working with parsing mathematical formulas. The symbolic formulas are parsed by compilers for the purpose of using them for computations. For example

x+y+z

Can be represented by a tree

+

/ \

x +

/ \

y z

Once we substitute known values instead of the variables we use the tree to evaluate the formula.

You need to use classes to create formula trees. An example of the base class is attached in the Formula file.

You can see a class "adder" derived from formula which can add two formulas. You can use it to create a formula tree by parsing formulas that, for now, only consist of additions.

z + x+ b

Task: modify the adder class or create another class to perform subtractions.