import itertools


num_caixas, max_caixas = [int(x) for x in str(input()).split()]
caixas = [x for x in str(input()).split()]
min_intervalo, max_intervalo = [int(x) for x in str(input()).split()]

caixas = [int(x) for x in caixas if len(x) <= len(str(max_intervalo))]

num_combinations = 0
caixas.sort()

permutations = list(itertools.combinations(caixas, max_caixas))
for permutation in permutations:

    if min_intervalo <= sum(permutation) and sum(permutation) <= max_intervalo:
        num_combinations += 1

print(num_combinations)
