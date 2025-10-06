initial_damage = input("Coloque o dano causado: ")
defense = input("Agora a defesa do inimigo: ")

int_damage = int(initial_damage)
int_defense = int(defense)

if int_damage <= int_defense :
    print("Seu dano não foi o suficiente contra a defesa do inimigo :c")

else :
    final_damage = int_damage - int_defense 
    print(f"O dano causado no final é {final_damage}.")