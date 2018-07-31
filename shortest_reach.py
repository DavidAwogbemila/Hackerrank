"""
Consider an undirected graph consisting of n nodes where each node is labeled from 1 to n and the edge between any two nodes is
always of length 6. We define node s to be the starting position for a BFS.

Given q queries in the form of a graph and some starting node, s, perform each query by calculating the shortest distance from 
starting node s to all the other nodes in the graph. Then print a single line of n-1 space-separated integers listing node s's 
sshortest distance to each of the n-1 other nodes (ordered sequentially by node number); if s is disconnected from a node, 
print -1 as the distance to that node.
This times out on one case in hackerrank. haven't really been able to figure out ways to make it faster :(.
"""
from queue import Queue

number_of_queries = int(input())

def showDistances(distances, start):
    s = ""
    for i in range(1, len(distances)):
        if i != start:
            s += str(distances[i])
            if i != (len(distances) - 1):
                s+= " "
    print(s)

def shortestReach(start_node, graph, n, e) :
    # distances = [-1 for _ in range(n+1)]
    distances = [-1] * (n+1)
    distances[start_node] = 0
    # q = PriorityQueue()
    q = Queue()
    # q.put((distances[start_node], start_node))
    q.put(start_node)
    # visited = [False for _ in range(n+1)]
    visited = [False] * (n+1)
    visited[start_node] = True

    while (not q.empty()) :
        # currentNode = q.get()[1
        currentNode = q.get()
        neighbours = graph[currentNode]
        for node in neighbours:
            if not visited[node]:
                if distances[node] == -1:
                    # q.put((distances[currentNode]+6, node))
                    q.put(node)
                    distances[node] = distances[currentNode]+6
                elif 6 + distances[currentNode] < distances[node]:
                    # q.put((distances[currentNode]+6, node))
                    distances[node] = distances[currentNode]+6
                    q.put(node)
                else:
                    # q.put((distances[node], node))
                    q.put(node)
        visited[currentNode] = True
        
    showDistances(distances, start_node)
        
for i in range(number_of_queries):
    numNodes_numEdges = input().split(' ')
    number_of_nodes = int(numNodes_numEdges[0])
    nodes = [i+1 for i in range(number_of_nodes)]
    number_of_edges = int(numNodes_numEdges[1])
    graph = dict()
    for i in nodes:
        graph[i] = []
    for i in range(number_of_edges):
        node1_node2 = input().split(' ')
        node1 = int(node1_node2[0])
        node2 = int(node1_node2[1])
        graph[node1].append(node2)
        graph[node2].append(node1)
    start_node = int(input())
    shortestReach(start_node, graph, number_of_nodes, number_of_edges)
    

        
