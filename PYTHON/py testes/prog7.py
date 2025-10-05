import random

def dice_roll(dice, bonus=0):  
    roll = random.randint(1, dice)
    final_roll = roll + bonus
    return final_roll

dice = int(input("Digite o número de lados do dado (ex: 6 para um d6): "))
bonus = int(input("Digite o bônus a ser adicionado: "))

if dice > 0:
    result = dice_roll(dice, bonus)
    
    if bonus != 0:
        print(f"Você rolou um d{dice} com bônus de {bonus}, seu resultado foi: {result}")
    else:
        print(f"Você rolou um d{dice} seu resultado foi: {result}")
else :
    print("Número inválido de lados para o dado.")
