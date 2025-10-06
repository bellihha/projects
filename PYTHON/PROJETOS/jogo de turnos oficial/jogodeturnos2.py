import random
import json
import os
from colorama import Fore, Style, init
init(autoreset=True) 


# Função para criar o personagem
def create_character():
    # Nome do personagem e sua arma.
    name = input(f"-- Coloque o nome do seu personagem: {Fore.MAGENTA}").strip().title()
    item = input(f"Ola, {Fore.MAGENTA}{name}{Fore.RESET}! -- Escolha sua arma inicial! (Adaga, Espada longa, Lança). ").lower().strip()
    # Escolha da arma inicial
    while True:
         if item == "adaga":
             item = 4
             break
         elif item == "espada longa":
             item = 5
             break
         elif item == "lança":
             item = 6
             break
         else:
             item = input(f"{Fore.RED}Arma inválida!{Fore.RESET} Escolha entre Adaga, Espada longa ou Lança: ").lower().strip()
             continue
    # Definição dos personagens e monstros como dicionários
    new_player = {
        "name": name,
        "life": 100,
        "max damage": 20,
        "bonus": item,
        "max heal": 12,
        "potions": 3,
        "wins": 0
    }
    return new_player
 
# Função para rolar o dado
def dice_roll(dice, bonus=0):  
    roll = random.randint(1, dice)
    final_roll = roll + bonus
    return final_roll



# Inicialização dos personagens
player = {}
# Inicialização do monstro
monster = {
        "name": "Lobisomem",
        "life": 45,
        "max damage": 16
    }
# Coloca a pasta de saves no mesmo local do script
script_dir = os.path.dirname(__file__) 
save_folder = os.path.join(script_dir, 'saves') 

print("-" * 73)
mensagem_bemvindo = " Bem-vindo ao jogo de turnos! "
print(f"{Fore.LIGHTMAGENTA_EX}{mensagem_bemvindo:^73}")
print("-" * 73)

os.makedirs(save_folder, exist_ok=True)
available_saves = os.listdir(save_folder)
if not available_saves:
    print(f"{'Nenhum jogo salvo encontrado. Vamos criar um novo personagem.':^73}")
    player = create_character()
else:
    # 2. Se houver saves, mostramos um menu para o jogador
    print(Fore.BLUE + "\nJogos salvos encontrados:")
    for i, save_name in enumerate(available_saves):
        print(f"  {i + 1}: {save_name[:-5]}")
    
    print("  0: Iniciar um novo jogo")

    while True:
        try:
            choice_str = input(f"\n -- Escolha um save para carregar ou inicie um novo jogo: {Fore.MAGENTA}")
            choice = int(choice_str)
            
            # Verifica se o número digitado está dentro do intervalo de opções
            if 0 <= choice <= len(available_saves):
                break  
            else:
                print(f"{Fore.RED}Opção inválida.{Fore.RESET} Por favor, escolha um número da lista.")
        except ValueError:
            # Se o jogador digitar um texto em vez de um número
            print(f"{Fore.RED}Entrada inválida. Por favor, digite apenas o número da opção.")

    if choice == 0:
        print(f"{Fore.BLUE}{'Iniciando um novo jogo...':^73}")
        player = create_character()
    else:
        # Se a escolha foi 1, pegamos o item 0 da lista (por isso escolha - 1)
        chosen_filename = available_saves[choice - 1]
        
        # Montamos o caminho completo para o arquivo (ex: "saves/antonietta.json")
        full_path = f"{save_folder}/{chosen_filename}"
        
        # Carregamos o arquivo JSON que o jogador escolheu
        with open(full_path, 'r') as save_file:
            player = json.load(save_file)
        vitorias_atuais = player.get("vitorias", 0)
        print(f"{Fore.RESET}Jogo de '{Fore.MAGENTA}{player['name']}{Fore.RESET}' carregado com sucesso! (Vitórias: {Fore.GREEN}{player['wins']}{Fore.RESET})")
       


# Rodadas do jogo
while player["life"] > 0 and monster["life"] > 0:
    mensagem_vida = f"Vida de(a) {Fore.MAGENTA}{player['name']}{Fore.RESET}: {Fore.LIGHTGREEN_EX}{player['life']}{Fore.RESET} | Vida do {monster['name']}: {Fore.LIGHTGREEN_EX}{monster['life']}{Fore.RESET}"
    print(" " * 73)
    print("-" * 73)
    print(f"{mensagem_vida:^73}")
    print("-" * 73)
    print(" " * 73)
    action = input(f"-- O quer quer fazer? (escreva 'atacar' para {Fore.LIGHTRED_EX}atacar{Fore.RESET} ou 'curar' para se {Fore.LIGHTYELLOW_EX}curar{Fore.RESET}): ").lower().strip()
    print(" " * 73)
    
    
    # Ataca 
    if action == "atacar":
        print("\n" * 12)
        player_atack = dice_roll(player["max damage"], player["bonus"])
        monster["life"] = monster["life"] - player_atack
        print(f"Você atacou o monstro e causou {Fore.LIGHTRED_EX}{player_atack}{Fore.RESET} de dano com bonus da sua arma escolhida!")
    
    # Cura
    elif action == "curar":
        print("\n" * 12)
        if player["potions"] > 0:
            player["potions"] = player["potions"] - 1
            player_heal = dice_roll(player["max heal"])
            player["life"] = player["life"] + player_heal
            print(f"Você se curou e recuperou {Fore.LIGHTYELLOW_EX}{player_heal}{Fore.RESET} de vida! Poções restantes: {Fore.YELLOW}{player['potions']}{Fore.RESET}")
        else:
            print(f"{Fore.RED}Você não tem mais poções de cura!{Fore.RESET}")
    
    # Ação inválida
    else:
        print(f"{Fore.RED}Ação inválida! Tente novamente.{Fore.RESET}")
        continue
    
    # Ataque do monstro
    if monster["life"] > 0:
        monster_atack = dice_roll(monster["max damage"])
        player["life"] = player["life"] - monster_atack
        print(f"O {Fore.YELLOW}{monster['name']}{Fore.RESET} atacou você e causou {Fore.LIGHTRED_EX}{monster_atack}{Fore.RESET} de dano!")

# Resultado final
if player["life"] <= 0:
    mensagem_derrota = f"{Fore.LIGHTRED_EX}Você foi derrotado pelo monstro!{Fore.RESET}"
    print(" " * 73)
    print("-" * 73)
    print(f"{mensagem_derrota:^73}")
    print("-" * 73)
    print(" " * 73)
    save_filename = f"saves/{player['name']}_savegame.json" 
    try:
        os.remove(save_filename)
        print(f"O arquivo de save '{os.path.basename(save_filename)}' foi apagado. {Fore.LIGHTRED_EX}Fim de jogo.{Fore.RESET}")
    except FileNotFoundError:
        print("Nenhum arquivo de save para apagar.")

else:
     mensagem_vitoria = f"{Fore.LIGHTGREEN_EX}Parabéns! Você derrotou o monstro!{Fore.RESET}"
     print(" " * 73)
     print("-" * 73)
     print(f"{mensagem_vitoria:^73}")
     print("-" * 73)
     print(" " * 73)
     if "wins" not in player:
         player["wins"] = 0
    
     player["wins"] += 1
     print(f"{Fore.MAGENTA}{player['name']}{Fore.RESET} agora tem {Fore.GREEN}{player['wins']}{Fore.RESET} vitória(s).")
     
     decisao = input(f"-- Deseja salvar seu progresso? {Fore.CYAN}(s/n){Fore.RESET}: ").lower().strip()
     if decisao == 's':
         save_filename = os.path.join(save_folder, f'{player["name"]}.json')
         
         with open(save_filename, 'w') as save_file:
             json.dump(player, save_file, indent=4)
         print(f"Progresso de {Fore.MAGENTA}{player['name']}{Fore.RESET} salvo com nome do arquivo '{os.path.basename(save_filename)}'.")
     else:
         print("Progresso não salvo.")