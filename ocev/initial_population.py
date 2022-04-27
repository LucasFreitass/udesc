from random import random, randint

COD = 'INT'        # BIN, INT, INT-PERM, REAL
POP=10                          # Tamanho da população
DIM=15                          # Dimensão, tamanho do cromossomo, L
#RUN=                           # Número de execuções
#GEN=                           # Número de iterações (gerações)
#Bounds
Li = -5
Ui = 10

# Se COD = REAL, Bounds [-10,10]

def initial_population():
    population = []
    for i in range(POP):
        cromossomo = []
        for j in range(DIM):
            cromossomo.append(randint(Li,Ui))
        population.append(cromossomo)
    return (population)


def main ():

    population = initial_population()
    print (population)

if __name__ == "__main__":
    main()  