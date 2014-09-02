trick of implementing this folder files
========================================

1. divide and conquer essence (new name: divide & conquer & combine(DCC))
-------------------------------------------------------------------------

1. how to divide? -> followed by conquer each subproblem recursively
2. how to handle base case?
3. how to combine each subproblem result to build current problem result?

---------------------------------
1. long size = right - left + 1;
2. int p = rand() % size + left;
3. segmentation fault(out of array boundary)


4. how to implement base case
5. how to write nice recursive function

list of content
=========================================

1. binary search (recursive and iterative version)
---------------------------------------------------
