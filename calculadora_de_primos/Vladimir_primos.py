# -*- coding: utf-8 -*-
"""Challenge1 num primos.ipynb

Automatically generated by Colab.

Original file is located at
    https://colab.research.google.com/drive/1kt8ply7UBVbe7sG3AJcnSr1zfqNSFBSS
"""

# Solicito 2 números a y b  e imprimo todos los  números primos entre a y b incluidos
# Salir


a = int(input("Digite un numero: "))
b = int(input("Digite un numero: "))


divisor = 2
es_primo = True  # booleano
cant_divisores=2 # entre 1 y entre si mismo

for i in range(a, b+1):
    if i > 1:
      for j in range(divisor,i+1):
          if i % j == 0:
             es_primo = False # es compuesto
             cant_divisores +=1
             break
          else:
              print(i, "El numero es primo")
          break

## version depurada

import math

def es_primo(n):
    if n < 2:
        return False
    if n == 2:
        return True
    if n % 2 == 0:
        return False

    for i in range(3, int(math.sqrt(n)) + 1, 2):  # revisando impares hasta la raíz cuadrada de n
        if n % i == 0:
            return False
    return True

a = int(input("Digite un número: "))
b = int(input("Digite un número: "))

print(f"Números primos entre {a} y {b}:")
for num in range(a, b + 1):
    if es_primo(num):
        print(num)

##Depurado v2

import math

def es_primo(n):
    if n < 2:
        return False
    if n == 2:
        return True
    if n % 2 == 0:
        return False

    for i in range(3, int(math.sqrt(n)) + 1, 2):  # Revisando impares hasta la raíz cuadrada de n
        if n % i == 0:
            return False
    return True

a = int(input("Digite un número: "))
b = int(input("Digite un número: "))

primos = [num for num in range(a, b + 1) if es_primo(num)]

print(f"Números primos entre {a} y {b}: {primos}")

# depurado v3final

import math
import time

def es_primo(n):
    if n < 2:
        return False
    if n == 2:
        return True
    if n % 2 == 0:
        return False

    for i in range(3, int(math.sqrt(n)) + 1, 2):  # Revisando impares hasta la raíz cuadrada de n
        if n % i == 0:
            return False
    return True


a = int(input("Digite un número: "))
b = int(input("Digite un número: "))


inicio = time.time()

## lista de primos final

primos = [num for num in range(a, b + 1) if es_primo(num)]

# tiempo
fin = time.time()
tiempo_total = fin - inicio


print(f"Números primos entre {a} y {b}: {primos}")
print(f"Tiempo de ejecución: {tiempo_total:.6f} segundos")

## version evitando revisar pares

import math
import time

def es_primo(n):
    if n < 2:
        return False
    if n == 2:
        return True
    if n % 2 == 0:
        return False

    # Solo revisar impares desde 3 hasta raiz de n

    for i in range(3, int(math.sqrt(n)) + 1, 2):
        if n % i == 0:
            return False
    return True

# valores

a = int(input("Digite un número: "))
b = int(input("Digite un número: "))

# tiempo

inicio = time.time()

# Lista final

primos = [2] if a <= 2 <= b else []  # Incluir el 2 si está en el rango
primos += [num for num in range(max(3, a), b + 1, 2) if es_primo(num)]  # Solo verificar impares


# tiempo real

fin = time.time()
tiempo_total = fin - inicio

# resultados
print(f"Números primos entre {a} y {b}: {primos}")
print(f"Tiempo de ejecución: {tiempo_total:.6f} segundos")
