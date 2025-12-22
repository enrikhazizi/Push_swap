*This activity has been created as part of the 42 curriculum by ehazizi, fqose.*

# push_swap

## Description

**push_swap** is a sorting algorithm project which aims to sort a stack of integers using a **limited set of operations** and **two stacks** (`a` and `b`), while producing the **smallest possible number of moves**.

The program takes a list of integers as arguments, initializes stack **a** with them, and outputs a sequence of instructions that sorts the stack in ascending order. Stack **b** starts empty and is used as temporary storage.

## Instructions

### Requirements
- GNU/Linux environment
- `gcc` compiler
- Make

### Compilation

Clone the repository and compile using:

```bash
make
```

This will generate the `push_swap` executable.

### Usage

```bash
./push_swap <number1> <number2> ... <numberN>
```

Example:

```bash
./push_swap 3 2 5 1 4
```

The program will output a list of instructions such as:

```
pb
ra
sa
pa
```

These instructions can be validated using the official checker or a custom checker.

## Algorithms Used

Multiple algorithms were implemented and selected depending on input size in order to balance simplicity and performance.

### Bubble Sort
**Purpose:** Very small input sizes
**Justification:**  
Bubble sort is easy to implement and useful for understanding stack operations and swaps.  
However, it has a time complexity of **O(n²)** and is not suitable for large inputs.

### Insertion Sort
**Purpose:** Small datasets  
**Justification:**  
Insertion sort performs better than bubble sort for nearly sorted data and small input sizes.  
It minimizes unnecessary operations and is efficient for low `n`, still with **O(n²)** complexity.

### Chunk Sort
**Purpose:** Medium to large input sizes  
**Justification:**  
Chunk sort divides the dataset into value ranges (chunks). Elements are pushed to stack **b** chunk by chunk, reducing the number of rotations needed.  
This approach significantly lowers the total number of operations compared to naïve sorting.

### Greedy Chunk Sort
**Purpose:** Optimized version of chunk sorting  
**Justification:**  
This approach improves chunk sort by **greedily selecting the cheapest element to move**, based on the number of operations required to place it correctly.  
It reduces wasted rotations and improves overall efficiency.

### Radix Sort
**Purpose:** Very large input sizes
**Justification:**  
Radix sort uses binary representation and sorts numbers bit by bit.  
It runs in **O(n × k)** where `k` is the number of bits, making it one of the most reliable and consistent strategies for large inputs in `push_swap`.

Radix sort guarantees predictable performance and is commonly used as a benchmark solution for high-volume inputs.

## Resources

### References
- 42 subject PDF: *push_swap*
- Big-O notation overview
- Radix Sort explanations and visualizations
- Stack-based sorting tutorials
- GNU C documentation

### Use of AI

AI tools were used **as a learning and assistance resource**, specifically for:
- Understanding algorithmic concepts (radix sort, greedy strategies)
- Clarifying edge cases and optimizations
- Reviewing logic and explaining complexity trade-offs
- Debugging


#  Detailed explanation and justification of the algorithms selected

## Small Inputs

### Bubble Sort
- Chosen for simplicity and clarity
- Easy to reason about and debug
- Suitable only for very small inputs due to high operation count

### Insertion Sort
- More efficient than bubble sort for small stacks
- Performs well on nearly sorted data
- Generates fewer operations while remaining simple

---

## Medium Inputs

### Chunk Sort
- Divides values into manageable ranges (chunks)
- Reduces unnecessary rotations
- Provides good performance without excessive complexity

### Greedy Chunk Sort
- Optimized version of chunk sort
- Selects the element with the lowest movement cost
- Significantly reduces total operations compared to basic chunk sorting

---

## Large Inputs

### Radix Sort
- Predictable and consistent performance
- Efficient for large datasets
- Binary-based approach avoids costly comparisons
- One of the most reliable strategies under *push_swap* constraints

---

## Conclusion

No single algorithm is optimal for all cases.  
By selecting algorithms based on input size, the project achieves:
- Lower instruction counts
- Better scalability
- Cleaner and more efficient execution

This adaptive strategy is essential for meeting *push_swap* performance requirements.