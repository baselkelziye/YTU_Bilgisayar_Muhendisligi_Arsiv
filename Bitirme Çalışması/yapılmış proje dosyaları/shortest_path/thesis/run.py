import main
import sys
import time
import graphs
from time import process_time
source = "1"
dest_8 = "8"
dest_14 = "14"
dest_50 = "50"
path = []
cost = 0
n = 10000
if sys.argv[1] == "8-cross":

    graph_dijkstra = graphs.graph_dijkstra_8
    graph_floyd = graphs.graph_floyd_8

    elapsed_time = 0
    for i in range(n):
        start_floyd = process_time()
        cost, path = main.Graph.floyd_warshall(graph_floyd, int(source) - 1, int(dest_8) - 1)
        end_floyd = process_time()
        elapsed_time += end_floyd - start_floyd
    floyd_time = elapsed_time / n
    print("Floyd result is ", cost, path)
    print("Floyd algorithm for 8-cross", floyd_time, "secs")

    elapsed_time = 0
    for i in range(n):
        start_dijkstra = process_time()
        path, cost = graph_dijkstra.dijkstra(source, dest_8)
        end_dijkstra = process_time()
        elapsed_time += end_dijkstra - start_dijkstra
    dijkstra_time = elapsed_time / n
    print("Dijkstra result is ", path, cost)
    print("Dijkstra algorithm for 8-cross", dijkstra_time, "secs")
    ratio = float(dijkstra_time / floyd_time)

    print("Dijkstra / Floyd metric is: {} ".format(ratio))

if sys.argv[1] == "14-cross":

    graph_dijkstra = graphs.graph_dijkstra_14
    graph_floyd = graphs.graph_floyd_14
    elapsed_time = 0
    for i in range(n):
        start_dijkstra = process_time()
        path, cost = graph_dijkstra.dijkstra(source, dest_14)
        end_dijkstra = process_time()
        elapsed_time += end_dijkstra - start_dijkstra
    dijkstra_time = elapsed_time / n
    print("Dijkstra result is ", path, cost)
    print("Dijkstra algorithm for 14-cross", dijkstra_time, "secs")
    elapsed_time = 0
    for i in range(n):
        start_floyd = process_time()
        cost, path = main.Graph.floyd_warshall(graph_floyd, int(source) - 1, int(dest_14) - 1)
        end_floyd = process_time()
        elapsed_time += end_floyd - start_floyd
    floyd_time = elapsed_time / n
    print("Floyd result is ", path, cost)
    print("Floyd algorithm for 14-cross", floyd_time, "secs")
    ratio = float(dijkstra_time/floyd_time)
    print("Dijkstra / Floyd metric is: {} ".format(ratio))
if sys.argv[1] == "50-cross":

    graph_dijkstra = graphs.graph_dijkstra_50
    graph_floyd = graphs.graph_floyd_50
    elapsed_time = 0
    for i in range(n):
        start_dijkstra = process_time()
        path, cost = graph_dijkstra.dijkstra(source, dest_50)
        end_dijkstra = process_time()
        elapsed_time += end_dijkstra - start_dijkstra
    dijkstra_time = elapsed_time / n
    print("Dijkstra result is", path, cost)
    print("Dijkstra algorithm for 50-cross", dijkstra_time, "secs")
    elapsed_time = 0
    for i in range(n):
        start_floyd = process_time()
        cost, path = main.Graph.floyd_warshall(graph_floyd, int(source) - 1, int(dest_50) - 1)
        end_floyd = process_time()
        elapsed_time += end_floyd - start_floyd
    floyd_time = elapsed_time / n
    print("Floyd result is ", path, cost)
    print("Floyd algorithm for 50-cross", floyd_time, "secs")
    ratio = float(dijkstra_time/floyd_time)
    print("Dijkstra / Floyd metric is: {} ".format(ratio))
