def getRelativeRating(skill, rating, k):
    l = len(skill)
    result = [0 for _ in range(l)]
    skill_rating = [(s, r, i) for i, (s,r) in enumerate(zip(skill, rating))]
    skill_rating.sort(key=lambda x: (x[0], x[1]))

    print(skill_rating)

    curr = 0
    for idx in range(k):
        _, r, i = skill_rating[idx]
        result[i] = curr
        curr += r

    for idx in range(k, l):
        _, r, i = skill_rating[idx]
        result[i] = curr
        curr += r
        curr -= skill_rating[idx - k][1]

    return result

if __name__ == "__main__":
    skill = [1, 7, 5]
    rating = [0, 0, 1]
    k = 1
    ans = [0, 1, 0]

    assert(getRelativeRating(skill, rating, k) == ans)

    skill = [1, 7, 5]
    rating = [0, 0, 1]
    k = 2
    ans = [0, 1, 0]
    assert(getRelativeRating(skill, rating, k) == ans)
