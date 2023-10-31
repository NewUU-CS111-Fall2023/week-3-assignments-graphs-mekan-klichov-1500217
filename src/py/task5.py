# * Author: Mekan Klichov
# * Date: 31.10.2023

from collections import defaultdict

def dfs(node, parent, distance, x):
    if node == x:
        return distance

    for child in tree[node]:
        if child != parent:
            return dfs(child, node, distance + 1, x)

def total_moves(n, x, edges):
    global tree
    tree = defaultdict(list)

    for a, b in edges:
        tree[a].append(b)
        tree[b].append(a)

    distance = dfs(1, -1, 0, x)
    return 2 * distance

def main():
    n, x = map(int, input().split())
    edges = [tuple(map(int, input().split())) for _ in range(n-1)]

    moves = total_moves(n, x, edges)
    print(moves)

if __name__ == "__main__":
    main()
