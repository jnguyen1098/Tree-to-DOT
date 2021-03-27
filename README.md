# Tree-to-DOT
This is a proof-of-concept C program that converts integer binary trees into a representation that can be opened in any graph description language compiler (such as [this](https://dreampuf.github.io/GraphvizOnline/)) supporting the [DOT language](https://en.wikipedia.org/wiki/DOT_(graph_description_language)). 

## How to Run

`make run`

Feel free to modify the macro variables to test different scenarios.
- `BALANCE_AVL` determines whether or not the resultant graph will be sorted (`= 1`) or not (`= 0`).
- `NODES` determines the number of nodes in the resultant graph.
- `MAXVAL` is the maximum value of a random number being inserted into the tree. This proof-of-concept uses `rand()`, which does not guard against values already inputted before, so upon insertion of a value that already exists, nothing happens. That means if your `MAXVAL` is less than `NODES`, `NODES` degenerates into the value of `MAXVAL` due to the pigeonhole principle (@Sawada). _Make sure this value is high enough._

Examples of these two variables being changed are shown below.

## Examples

### 10 integers, no balancing [(src)](https://github.com/jnguyen1098/Tree-to-DOT/blob/master/examples/10_no_balance.dot)
![img](https://raw.githubusercontent.com/jnguyen1098/Tree-to-DOT/master/examples/10_no_balance.png)

### 10 integers, AVL balancing [(src)](https://github.com/jnguyen1098/Tree-to-DOT/blob/master/examples/10_balanced.dot)
![img](https://raw.githubusercontent.com/jnguyen1098/Tree-to-DOT/master/examples/10_balanced.png)

### 100 integers, no balancing [(src)](https://github.com/jnguyen1098/Tree-to-DOT/blob/master/examples/100_no_balance.dot)
![img](https://raw.githubusercontent.com/jnguyen1098/Tree-to-DOT/master/examples/100_no_balance.png)

### 100 integers, AVL balancing [(src)](https://github.com/jnguyen1098/Tree-to-DOT/blob/master/examples/100_balanced.dot)
![img](https://raw.githubusercontent.com/jnguyen1098/Tree-to-DOT/master/examples/100_balanced.png)

### 1000 integers, no balancing [(src)](https://github.com/jnguyen1098/Tree-to-DOT/blob/master/examples/1000_no_balance.dot)
![img](https://raw.githubusercontent.com/jnguyen1098/Tree-to-DOT/master/examples/1000_no_balance.png)

### 1000 integers, AVL balancing [(src)](https://github.com/jnguyen1098/Tree-to-DOT/blob/master/examples/1000_balanced.dot)
![img](https://raw.githubusercontent.com/jnguyen1098/Tree-to-DOT/master/examples/1000_balanced.png)

## References
AVL tree insertion code taken from https://www.geeksforgeeks.org/avl-tree-set-1-insertion/
