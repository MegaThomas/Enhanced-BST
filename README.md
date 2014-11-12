Enhanced-BST
============

Data &amp; Algorithm Lab #4

##Tasks:
Create a Binary Search Tree;   
Output sequence of vertices of Pre-Order, In-Order &amp; Post-Order;  
Output height of the tree;  
Read another tree from input, search this subtree in the former BST, output number of the subtree;  
*Notice: In order to keep the output unique, add `#` to make vertex of 0 or 1 degree a 2-degree-vertice.*  
*In this lab, subtrees only require to be in the same stucture, with vertex value not included.*
##Example
###Input
    9  
    5 3 8 4 2 1 7 6 9  
    4  
    4 3 2 5  
###Output
    5 3 2 1 # # # 4 # # 8 7 6 # # # 9 # #
    # 1 # 2 # 3 # 4 # 5 # 6 # 7 # 8 # 9 #
    # # 1 # 2 # # 4 3 # # 6 # 7 # # 9 8 5
    4  
    2
