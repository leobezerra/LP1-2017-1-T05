import sys, string

fptr = open(sys.argv[1], 'r')
alunos = []
for line in fptr:
    alunos.append(line)

n_grupos = int(len(alunos) / 4)
grupos = [[] for i in range(0,n_grupos)]

for i in range(0, int(len(alunos) / 2)):
    grupos[i % n_grupos].append(alunos[0])
    grupos[i % n_grupos].append(alunos[-1])
    alunos = alunos [1:-1]

print("\n\n".join(["\n".join([string.capwords(x) for x in g]) for g in grupos]))
        #f.write("\n".join([" ".join(["{:.5f}".format(w) for w in wv]) for wv in front ]))
