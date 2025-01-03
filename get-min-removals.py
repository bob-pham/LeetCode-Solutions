from collections import Counter

def maxDistinct(arr, max_distinct):
    counts = Counter(arr)
    num_distinct = len(counts)

    if num_distinct <= max_distinct:
        return 0

    sorted_keys = sorted(counts.keys(), key=lambda x: counts[x])

    result = 0
    for i in range(num_distinct - max_distinct):
        result += counts[sorted_keys[i]]
    return result



if __name__ == "__main__":
    arr = [1,2,3,2,1]
    max_distinct = 2
    ans = 1

    assert(maxDistinct(arr, max_distinct) == ans)

    arr = []
    max_distinct = 10
    ans = 0
    assert(maxDistinct(arr, max_distinct) == ans)

    arr = [1,2,3,2,1]
    max_distinct = 10
    ans = 0
    assert(maxDistinct(arr, max_distinct) == ans)

