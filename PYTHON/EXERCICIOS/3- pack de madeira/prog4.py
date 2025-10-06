blocks = input("Olá! quantos blocos de madeira você tem? ")
int_blocks = int(blocks)

if int_blocks >= 64 :
    print("Você tem um pack de madeira!")

elif int_blocks < 32 :
    print("Você tem menos da metade de um pack.. Melhor pegar mais madeira!")

else :
    print("Você tem madeira para construir uma pequena casa! :D")