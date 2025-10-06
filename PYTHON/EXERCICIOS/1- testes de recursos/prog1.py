nome = input("Coloque seu nome: ")
print(f"Ola, {nome}!")

numero = int(input("coloque um numero: "))
if numero <= 10:
    numero = numero * 2
    print(numero)
numero = numero + 5
print(f"{nome}, seu numero mais 5 é: {numero}")