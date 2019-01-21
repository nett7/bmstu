[![Build Status](https://travis-ci.org/yokkidack/bstree-.svg?branch=master)](https://travis-ci.org/yokkidack/bstree-)
[![Awesome](https://awesome.re/badge.svg)](https://awesome.re)

## BSTree
My program is a **Binary serch tree** application.
My program: 

1. Outputs the tree to the screen,   
2. Lists the nodes of the tree,   
  a. Direct bypass,   
  b. Transverse bypass,  
  c. Backward traversal,  
3. Adds a node to the tree,  
4. Deletes the node from the tree, 
5. Saves the tree to a file, 
6. Loads the tree from the file, 
7. Checks the presence of the node.  


there is also a biderectional iterator

## Benchmarks

**The benchmark of open methods: (all values are in seconds)**

| Ops | Insert  | Remove  | Print | Print symmetric  | Print direct  | Print reverse | Save  | Load |
|-----|---|---|---|---|---|---|---|---|
|  10   |  0.000111 | 0.000832  | 1.9e-05  | 0.000131  | 4.2e-05 | 6.5e-05 | 0.001479  |  0.000187 |
|  10^2   | 0.000267  | 0.000775  | 0.000216  | 0.000725  | 0.000532 | 0.000587 | 0.011382  |  0.003696 |
|  10^3   | 0.003193  | 0.011264  | 0.002565  | 0.003729  | 0.003292 | 0.004207 | 0.115711  |  0.052276 |
|  10^4   | 0.030514  | 0.059724  | 0.034108  | 0.035524  | 0.024609 | 0.030481 | 1.0009  |  0.50199 |
|  10^5   | 0.336205  | 0.623016  | 0.30035  | 0.34012  | 0.23431 | 0.292763 | 10.571  | 5.09061  |
|  10^6   | 3.02401  | 5.94498  | 3.3313  | 3.24454  | 2.34272 | 2.90705 | 102.002  | 48.3709 |
|  10^7   | 32.0537  | 61.5421  | 37.1172  | 34.5183  | 23.4649 | 29.3299 | 1213.03  | :x:  |
|  10^8   | 319.121  | 622.558  | 364.967  | 248.869  | 237.521 | 294.537 | :x:  | :x:  |

You can look into 
[this file](https://github.com/yokkidack/bstree-/blob/master/EXAMPLE.txt)
for demonstration of how it works.

or

Look in to 
[this one](https://github.com/yokkidack/bstree-/blob/master/HowToBuild.md)
for building instructions
