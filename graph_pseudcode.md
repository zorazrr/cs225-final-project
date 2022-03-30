constructor:
	reads through file & creates list of nodes
	for each node, push back a blank vector into connections_
	reads through file & creates list of edges
	calls createConnections

createConnections:
	takes in list of edges & uses it to complete connections_
	for i in range(len(edges)):
		sees a = starting node --> connections_.at(a).push_back(edges.at(i)))
		b = ending node --> connections_.at(b).push_back(edges.at(i))
	