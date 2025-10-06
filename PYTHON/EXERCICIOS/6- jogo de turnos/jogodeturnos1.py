import random

player_life = 100
monster_life = 80

def dice_roll(dice, bonus=0):  
    roll = random.randint(1, dice)
    final_roll = roll + bonus
    return final_roll

while player_life > 0 and monster_life > 0:
    print(f"Sua vida: {player_life} | Vida do monstro: {monster_life}")
    action = input("O quer quer fazer? (escreva 'atacar' para atacar ou 'curar' para se curar): ").lower().strip()
    
    if action == "atacar":
        player_atack = dice_roll(20)
        monster_life = monster_life - player_atack
        print(f"Você atacou o monstro e causou {player_atack} de dano!")
    elif action == "curar":
        player_heal = dice_roll(12)
        player_life = player_life + player_heal
        print(f"Você se curou e recuperou {player_heal} de vida!")
    else:
        print("Ação inválida! Tente novamente.")
        continue
    
    if monster_life > 0:
        monster_atack = dice_roll(18)
        player_life = player_life - monster_atack
        print(f"O monstro atacou você e causou {monster_atack} de dano!")


if player_life <= 0:
     print("Você foi derrotado pelo monstro!")
else:
     print("Parabéns! Você derrotou o monstro!")
    