# GRAPH COLORING

# Definition:
A graph consisting of a set of vertices and a set of edges, assigning a color to each vertex such that no adjacent vertex has the same color. 

# History of Graph coloring

Graph coloring originated from a natural problem in cartography: given some map, how can we color each area to distinguish it, without two neighboring areas having the same colors. This was first observed by Francis Guthrie. He had noticed that he could color the counties of England using four different colors. 

Later years Fredrick, who was a mathematics student, informed his professor Augustus De Morgan, which introduced graph coloring to academic circles. This resulted in the four-color theorem: any planar graph can be colored using four colors. 

While the conjecture was easy to encounter in practice but it demonstrated to be difficult to be proven.  The First supposed proof in 1890, by Alfred Bray Kempe stood for 10 years until was disproved by Percy John Heawood. It took until 1976 for the theorem to finally be proven.  This proof used a thousand cases, for which it required computer assistance, no human was able to verify the correctness of the proof. 

This four-color theorem sparked the first major research on graph coloring. From this, it was logical step to extend planar graph coloring to coloring any given graph, determining the minimum number of colors such that a proper coloring of some graph exists with that number of colors.

# VERTEX COLORING:

Vertex coloring is a concept in graph theory that refers to assigning colors to the vertices of a graph in such a way that no two adjacent vertices have the same color.

Formally the vertex coloring of a graph is an assignment of colors. We usually represent the colors by numbers. The minimum number of colors required to color a graph is known as Chromatic number. Generally this number is always greater than one. However the chromatic number is equal to one only when the graph contains a single vertex.

Finding the chromatic number of a graph is difficult and it belongs to the NP- complete class. Hence it is unlikely that there's an efficient way to solve it for all graphs. 

# APPROACHES TO SOLVING THE VERTEX COLORING PROBLEM

The most basic approach is brute force search. A brute force search algorithm involves trying all possible coloring of the graph and selecting the one with the minimum number of colors. While this algorithm is guaranteed to find the optimal solution, its computationally expensive. This approach is only feasible for small graphs.

The second approach is local search. Local search algorithms iteratively improve an existing solution by making small local changes. In the case of the vertex coloring problem, a local search algorithm might swap colors of two adjacent vertices. Additionally it may try to recolor a single vertex. These algorithms are effective especially when combined with other techniques.

We can also formulate the vertex coloring problem as an integer linear program. This approach can find exact solutions to the program. It can be computationally expensive for large graphs.

# APPLICATIONS OF VERTEX COLORING 

Vertex coloring is an important problem in graph theory. Additionally, it has many applications in computer science, operations research, and other fields. Some of the most common applications of the vertex coloring problem include scheduling, routing, register allocation, and wireless frequency assignment.

# Scheduling problem:
In the scheduling problem, we must assign resources to the available tasks and avoid conflicts. To solve this problem, we can represent each task as a vertex and each resource as a color in a graph. Furthermore, we can determine the chromatic number from this graph. Hence, the chromatic number represents the minimum number of resources needed to complete all tasks without conflicts.

# Network routing problem:
Let’s talk about the network routing problem. In routing, data packets must be routed through a network of nodes without conflicts. Furthermore, we can use vertex coloring to model this problem, with each node representing a vertex and each path representing a color in the graph. Additionally, the chromatic number denotes the least possible number of paths required to route all packets without conflicts.

# Compilers:
In compilers, variables in a program must be assigned to registers in a computer’s processor. We can utilize vertex coloring and chromatic number concepts in order to provide the least possible number of registers needed to execute the program.

Finally, in wireless network communication, the vertex coloring problem can be used for the frequency assignment of wireless channels for devices to avoid interference.






# Example
Lets take a graph with 8 nodes

Lets color the first node with green












Lets color the 2nd node with red cause it can not be green


Lets color the 3rd node with green cause it cannot be red

Lets color the 4th node with red 


Lets color the 5th node with green 


Lets color the 6th node with red

Lets color the 7th node with blue because it cannot be colored with either red or green because it is connected to 5th and 6th















Lets color the node 8 with red

the colored graph in docx


What is vertex coloring of a graph?
**a) A condition where any two vertices having a common edge should not have same color**
b) A condition where any two vertices having a common edge should always have same color
c) A condition where all vertices should have a different color
d) A condition where all vertices should have same color
2.Minimum number of unique colors required for vertex coloring of a graph is called?
a) vertex matching
b) chromatic index
**c) chromatic number**
d) color number

How many unique colors will be required for proper vertex coloring of an empty graph having n vertices?
 a) 0
 **b) 1**
 c) 2
 d) n
How many unique colors will be required for proper vertex coloring of a bipartite graph having n vertices?
 a) 0
 b) 1
 **c) 2**
 d) n

