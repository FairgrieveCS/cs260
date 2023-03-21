Jonathan Fairgrieve
CS 260
Final Project


  DESIGN:
In a game setting, a graph can serve multiple purposes, including
acting as a representation of the game map, aiding in pathfinding, and facilitating the 
generation of minimum spanning trees for procedurally generated worlds. For instance, 
when designing a game world composed of interconnected locations such as cities or 
dungeons, a graph can effectively illustrate the connections between these locations, using
vertices to represent individual locations and edges to denote paths between them, with
edge weights symbolizing the distance or traversal difficulty. Furthermore, the graph can be
employed for pathfinding, an essential aspect of games that require character or object
navigation within the game world. By utilizing a shortestPath() function like the assignment requires,
the graph enables the determination of the most efficient route between two
points, which can be helpful for AI navigation, devising optimal routes for NPCs, or 
estimating travel times. When constructing a procedurally generated world, a graph
can be employed to establish connections between distinct regions, such as dungeon rooms.
By applying the minSpanTree() function, a minimum spanning tree can be created that guarantees connectivity across all locations 
while minimizing connection costs, ultimately resulting in a well-connected, diverse, and engaging game world.

  COMPLEXITY:
Both of shortestPath() and minSpanTree() have a complexity of O(V^2). The algorithms iterate through all of the vertices.

  REQUIREMENTS:
1. Add vertex: Lines 22-30
2. Add edge: Lines 32-42
3. Shortest Path: Lines 58-95
4. Min Spanning Tree: Lines 112-154
5. Testing (Main Function): 156-188