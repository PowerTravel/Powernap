#ifndef _DAGRAPH_H
#define _DAGRAPH_H
template <typename T>


// DAGraph is much like a tree. It has a position marker that can be put to the root 
// Implemented som fält av lista.
class DAGraph{
	public:
		enum TraversalFlag{
			WIDTH_FIRST
			DEPTH_FIRST
		};

		DAGraph();
		~DAGraph();

		// Modification
		void addChild(); // Adds empty child node to current node.
		void addChild(T data); // A node with data.
		void removeNode(); // Removes
		void getData();
		
		bool isEmpty(); // Check if graph is empty
		
		// Traversal
		void root(); // Revert graph to point to head, sets all nodes to unvisited.
		void traverse(TraversalFlag = DEPTH_FIRST); // Move one step of t
		
	private:
		
		class Node{
			public:
				Node();
				~Node();
		};
};

/* "oficiellt" gränssnitt. Bör modifieras att likna ett träd för acyklisk graf, bör implementeras som fält av lista dock.

	DAGraph() - Skapar en tom graf
	void insert_node(Node n) - lägger till en nod
	void insert_edge(Edge e) - lägger till en båge
	bool isEmpty(); - Kollar om grafen är tom
	bool hasNoEdges(Node n) - Kollar om nod n har några bågar
	void/Node chooseNode() - Välj ut en nod ur grafen  // Kan kanske ersättas med "head" för en acyclic graf
	NeighbourList Neighbours(Node n) - Mängden av noder  som är andra elementet i en båge där N är första element
	void deleteNode(Node n) - Tar bort noden n ur grafen
	void delete-edge(Edge e) - Tar bort bågen e ur grafen g

*/

#endif // _DAGRAPH_H