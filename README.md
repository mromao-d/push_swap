*This project has been created as part of the 42 curriculum by <mromao-s>*

## 📌 Overview

**Push_swap** is a sorting algorithm project from the 42 curriculum.
The goal is to sort a stack of integers using a limited set of operations and two stacks:

* **Stack A** (initial stack)
* **Stack B** (auxiliary stack)

This implementation uses a **binary radix sort algorithm**, optimized for performance and scalability.

---

## ⚙️ “Description”

### Swap

* `sa` → swap the first 2 elements of stack A
* `sb` → swap the first 2 elements of stack B

### Push

* `pa` → push from B to A
* `pb` → push from A to B

### Rotate

* `ra` → shift all elements of A up by 1
* `rb` → shift all elements of B up by 1

### Reverse Rotate

* `rra` → shift all elements of A down by 1
* `rrb` → shift all elements of B down by 1

---

## 🎯 Objective

* Sort stack A in ascending order
* Use only the allowed operations
* Minimize the number of moves

---

## 🧠 Algorithm: Radix Sort (Base 2)

This project uses a **binary radix sort**, which processes numbers bit by bit.

### 🔢 Step 1: Indexing (Normalization)

Since radix sort works best with positive integers:

* Replace each number with its index in the sorted array
* Example:

```
Original:  [-5, 100, 2]
Indexed:   [0, 2, 1]
```

---

### 🔁 Step 2: Bitwise Sorting

For each bit (from least significant to most significant):

1. Iterate through all elements in **stack A**
2. Check the current bit:

   * `0` → `pb` (push to stack B)
   * `1` → `ra` (rotate stack A)
3. Once all elements are processed:

   * Push everything back to stack A using `pa`

Repeat until all bits are processed.

---

### ⚡ Complexity

* Time complexity: **O(n log n)**
* Efficient for large inputs (100–500 numbers)

---

## 🛠️ “Instructions”

```
make
./push_swap "numbers" OR ./push_swap 45 55 ...
```

---
## “Resources”
chatgpt for readme file


## 📚 Skills Learned

* Bitwise operations
* Algorithm optimization
* Data structures (stacks, linked lists)
* Parsing and validation
* Time complexity analysis

---

## 👤 Author

Your Name - 42 Student

---
