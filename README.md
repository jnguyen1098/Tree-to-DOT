# Tree-to-DOT
This is a C program that converts binary trees into a representation that can be opened in any graph description language compiler (such as [this](https://dreampuf.github.io/GraphvizOnline/)) supporting the [DOT language](https://en.wikipedia.org/wiki/DOT_(graph_description_language)).

## How to Run
Just compile and run it (e.g. `gcc tree_to_dot.c && ./a.out`) and it will output (to `stdout`) the resultant graph (or tree in this case).

Feel free to modify the two macro variables, `BALANCE_AVL` and `NODES`.
- `BALANCE_AVL` determines whether or not the resultant graph will be sorted (`= 1`) or not (`= 0`).
- `NODES` determines the number of nodes in the resultant graph.

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