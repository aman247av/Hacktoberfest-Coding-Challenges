def floyd_warshall(graph):
    n = len(graph)
    
    dist = [[float('inf')] * n for _ in range(n)]

    for i in range(n):
        for j in range(n):
            dist[i][j] = graph[i][j]

    for i in range(n):
        dist[i][i] = 0

    for k in range(n):
        for i in range(n):
            for j in range(n):
                if dist[i][j] > dist[i][k] + dist[k][j]:
                    dist[i][j] = dist[i][k] + dist[k][j]

    return dist

def get_graph_from_user():
    n = int(input("Enter the number of vertices: "))  
    graph = []

    for i in range(n):
        row = []
        for j in range(n):
            if i == j:
                row.append(0) 
            else:
                weight = input(f"Enter weight of edge from {i} to {j} (enter 'inf' if no edge): ")
                if weight.lower() == 'inf':
                    row.append(float('inf')) 
                else:
                    row.append(int(weight)) 
        graph.append(row)

    return graph

# Main function
if __name__ == "__main__":
    graph = get_graph_from_user()
    shortest_paths = floyd_warshall(graph)

    print("Shortest path matrix:")
    for row in shortest_paths:
        print(row)
