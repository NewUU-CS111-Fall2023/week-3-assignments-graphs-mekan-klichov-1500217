# * Author: Mekan Klichov
# * Date: 31.10.2023

def restore_genome(n, fragments):
    genome = fragments[0]

    for i in range(1, n):
        fragment = fragments[i]
        overlap = 0

        while overlap < len(fragment) and fragment[overlap:] in genome:
            overlap += 1

        genome += fragment[overlap:]

    return genome

def main():
    n = int(input())
    fragments = [input() for i in range(n)]

    result = restore_genome(n, fragments)
    print(result)

if __name__ == "__main__":
    main()
