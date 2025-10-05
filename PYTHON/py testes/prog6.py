inventario = {'picareta', 'espada', 'tocha'}

while True:
    comando = input("O que você quer fazer? (Listar, Adicionar, Remover, Sair) ").strip().lower()
    
    # Listar itens do inventário
    if comando == "listar":
        print("Seu inventário contém:", ', '.join(inventario))
    
    # Adicionar item ao inventário
    elif comando == "adicionar":
        input_item = input("Qual item você quer adicionar? ").strip().lower()
        inventario.add(input_item)
        print(f"{input_item} adicionado ao inventário.")
    
    # Remover item do inventário    
    elif comando == "remover":
        input_item = input("Qual item você quer remover? ").strip().lower()
        if input_item in inventario:
            inventario.remove(input_item)
            print(f"{input_item} removido do inventário.")
        else:
            print(f"{input_item} não está no inventário.")
            
    # Sair do loop
    elif comando == "sair":
        print("Saindo do programa.")
        break            
    
    else:
        print("Comando não reconhecido.") 