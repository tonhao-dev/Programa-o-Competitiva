l_matriz, c_matriz = [int(x) for x in str(input()).split()]
matriz = []
copia_matriz = [] * l_matriz

for i in range(l_matriz):
    matriz.append(str(input()))
    copia_matriz = [''] * c_matriz

num_palavras = int(input())
for i in range(num_palavras):
    palavra = str(input())

    ehAnagrama = True
    for letra in palavra:
        for i in range(l_matriz):
            if letra not in matriz[l_matriz]:
                ehAnagrama = False
                break