# String and language operations
## Two strings can be compared, determining if they are equal, if one of them is a substring of the other or vice versa, or they are simply different strings:
  - If w1 == w2, then the two strings have exactly the same symbols in the same order.
  - Yes w1! = w2, so the strings are not the same (they differ by at least one symbol within the sequence).
  - If w1 > w2, then w2 is a substring of w1.
  - If w1 < w2, then w1 is a substring of w1.

## Concatenation
Given two strings w1 and w2, we could calculate the string resulting from the concatenation w1 · w2

## Addition 
Given a string w, we can calculate the string resulting from the power operation wn

## Compilation
`make`

`g++ -std=c++11 -g -Wall cya-P03-Strings.cc String.cc Alphabet.cc Symbol.cc -o p03_strings`
