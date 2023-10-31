# * Author: Mekan Klichov
# * Date: 31.10.2023

from collections import deque

def transform(a, b):
    visited = set()
    queue = deque([(a, [a])])

    while queue:
        current, path = queue.popleft()

        if current == b:
            return path

        double = current * 2
        append_1 = current * 10 + 1

        if double <= b and double not in visited:
            queue.append((double, path + [double]))
            visited.add(double)

        if append_1 <= b and append_1 not in visited:
            queue.append((append_1, path + [append_1]))
            visited.add(append_1)

    return None

def main():
    a, b = map(int, input().split())
    path = transform(a, b)

    if path:
        print("YES")
        print(len(path))
        print(*path)
    else:
        print("NO")

if __name__ == "__main__":
    main()
