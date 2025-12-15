#!/bin/bash

# Path to your push_swap executable
PS="./push_swap"

echo "=== Testing push_swap ==="

function sep {
    echo "----------------------------------------"
}

# Test 1: No arguments → should output nothing
sep
echo "Test 1: No arguments"
$PS
echo "Expected: nothing"

# Test 2: Already sorted → nothing
sep
echo "Test 2: Already sorted input"
$PS 1 2 3 4
echo "Expected: nothing"

# Test 3: Simple swap needed
sep
echo "Test 3: Swap two elements"
$PS 2 1
echo "Expected: sa"

# Test 4: Small random input
sep
echo "Test 4: Small unsorted input"
$PS 3 1 2
echo "Expected: sequence of operations"

# Test 5: Non-integer → Error
sep
echo "Test 5: Non-integer input"
$PS 1 a 3
echo "Expected: Error"

# Test 6: Out of range → Error
sep
echo "Test 6: Integer out of range"
$PS 2147483648
echo "Expected: Error"

# Test 7: Selector flags
sep
echo "Test 7: Simple flag"
$PS --simple 5 3 2 1
echo "Expected: operations using simple algo"

sep
echo "Test 8: Medium flag"
$PS --medium 5 3 2 1
echo "Expected: operations using medium algo"

sep
echo "Test 9: Complex flag"
$PS --complex 5 3 2 1
echo "Expected: operations using complex algo"

sep
echo "Test 10: Adaptive flag"
$PS --adaptive 5 3 2 1
echo "Expected: operations using adaptive algo"

# Test 11: Invalid flag → Error
sep
echo "Test 11: Invalid flag"
$PS --banana 1 2 3
echo "Expected: Error"

# Test 12: Single element → nothing
sep
echo "Test 12: Single element"
$PS 42
echo "Expected: nothing"

# Test 13: Large input
sep
echo "Test 13: Large input (1-10)"
$PS 10 9 8 7 6 5 4 3 2 1
echo "Expected: operations sequence"

# ===== Numbers inside a single string =====

# Test 14: Already sorted in one string → nothing
sep
echo "Test 14: Already sorted, numbers in single string"
$PS "1 2 3 4"
echo "Expected: nothing"

# Test 15: Unsorted numbers in single string
sep
echo "Test 15: Unsorted numbers in single string"
$PS "3 1 2"
echo "Expected: operations sequence"

# Test 16: Flag + numbers in single string
sep
echo "Test 16: Flag + numbers in single string"
$PS --simple "5 3 2 1"
echo "Expected: operations using simple algo"

# ===== Badly formatted inputs =====

sep
echo "Test 17: Leading and trailing spaces"
$PS "   3 2 1   "
echo "Expected: operations sequence"

sep
echo "Test 18: Multiple spaces between numbers"
$PS "3    1   2"
echo "Expected: operations sequence"

sep
echo "Test 19: Empty string as argument"
$PS ""
echo "Expected: nothing (treated as no input)"

sep
echo "Test 20: Mixed invalid characters"
$PS "1 2 a 4"
echo "Expected: Error"

sep
echo "Test 21: Only spaces"
$PS "     "
echo "Expected: nothing (treated as no input)"

echo "=== Tests completed ==="
