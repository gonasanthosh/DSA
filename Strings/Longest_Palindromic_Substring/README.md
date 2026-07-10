# 5. Longest Palindromic Substring

## Problem
Given a string `s`, return the longest palindromic substring in `s`.

## Approach
Used the **Expand Around Center** technique.

- Every palindrome has a center.
- For each index:
  - Expand around `(i, i)` for odd-length palindromes.
  - Expand around `(i, i + 1)` for even-length palindromes.
- Track the starting index and maximum palindrome length.

## Time Complexity
- **O(n²)**

## Space Complexity
- **O(1)**

## Concepts Used
- Strings
- Two Pointers
- Expand Around Center
- C++ Lambda Function