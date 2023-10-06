#Jogo da Forca em Python

import os

palavra = input("Escolha uma palavra para a forca: ")
os. system('cls')

chutes = []
chances = 3
resultado = 0

while True:
    
    for letra in palavra:
        if letra.lower() in chutes:
            print(letra, end=" ")
        else: 
            print("_", end=" ")

    print(f"Você tem {chances} chances restantes!")

    tentativa = input("Escolha uma letra: ")

    chutes.append(tentativa.lower())

    if tentativa.lower() not in palavra.lower():
        chances -= 1
        
    resultado = 1

    for letra in palavra:
        if letra.lower() not in chutes:
            resultado = 0

    if chances == 0 or resultado:
        break

if resultado:
    print(f"Parabéns, você ganhou. A palavra era: {palavra}")

else:
    print(f"Ish, não foi dessa vez! A palavra era: {palavra}")