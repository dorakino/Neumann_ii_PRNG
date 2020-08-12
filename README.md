# Neumann_ii_PRNG

This project is related to the drawbacks of using **Neumann's Second PseudoRandom Number Generator** method.
It calculates the length of initiatory line, the length of period, and the number of their appearance in all of the cases.

It takes the beginning 2 elements from 0..99.
The method takes 2 two digit long integers (e.g. 5 = 05), multiply them, hence we got a 4 digit long number (e.g. 11*11 = 121 = 0121), and finally we take the middle two digits (in case of numbers 11 and 11, the result is 12).

Header neumann.h contains the used class, source file neumann.cpp is the code containing the calculations.

The final results can be seen in an added txt file.

Some radical changes were made comparing to the first result.

