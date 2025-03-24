[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/9vyB7wZR)
## Homework05: 
## Genetic Tree Construction and Traversal

### 💥 Objective:

In this homework, you will work with binary trees and explore various traversal techniques. You will construct a binary tree from a string representation that encodes genetic data and implement a breadth-first traversal using a queue. The goal is to reinforce your understanding of tree construction, string manipulation, and traversal algorithms in C.

---
### 💥 **Scenario**:
You are part of an elite team of bioinformaticians at a cutting-edge research facility. The lab is working on decoding genetic information to trace familial lineage in humans. The team has discovered a novel way to encode family trees (or pedigrees) in a genetic string format, which can be used to map relationships, inherited traits, and ancestral history.

Your task is to develop a program that takes a genetic string as input and reconstructs the family tree from it. Each character in the string represents a person (a node), and the structure of the string will show the connections between family members (parents and children). A special character \n indicates a missing person (i.e., no child in that position).

After reconstructing the family tree, the team needs to analyze the relationships using different traversal techniques. You will need to traverse the tree to:
  1. Identify the lineage in different orders (preorder, inorder, postorder).
  2. Perform a breadth-first search to discover the generations of the family.
The ultimate goal is to identify key insights about the family's genetic structure and explore how traits have been passed through generations.


---
### 💥 **Tasks**

* Get the [main.c](main.c) file.

1. Tree Construction from Genetic String:
    - Read and Undrestand the function `getFirstChar` that extracts the first character from the genetic string and removes it, representing a family member.
    - Implement the function `constructTree` that takes the genetic string and recursively builds a family tree based on the provided structure.
    - If a character is `\n`, it means that the current family member does not have any children in that position.

2. Preorder, Inorder, and Postorder Traversals:
    - Implement functions for three standard tree traversals: **preorder**, **inorder**, and **postorder**. Each function should take the root of the tree as input and print the names of the family members in the correct order.
    * **Preorder**: Visit the family member (node), then recursively visit the left and right children.
    * **Inorder**: Recursively visit the left child, then the family member (node), and then the right child.
    * **Postorder**: Recursively visit the left and right children, then the family member (node).

3. Breadth-First Traversal Using Queue :
    - Implement the `breadthFirst` function that performs a level-order traversal of the family tree using a queue.
    - The function should print the family members in generations, level by level, starting from the oldest known ancestor (root).

4. Testing and Output:
    - Provide test cases that represent different family structures. Test your code by providing a genetic string and ensure that all four traversal methods (preorder, inorder, postorder, and breadth-first) work correctly.
    - Example Input Genetic String: `"A\nB\nC\n\nD\n\n\n"`
    - Expected Output (for breadth-first traversal): `A B C D`

---
### 💥 **Submission **

Check the Canvas for the sumbission requirements. 
