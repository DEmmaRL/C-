import time
import operator
import random
from IPython.display import clear_output

# Diccionario para almacenar los jugadores y sus puntuaciones
jugadores = {'Ana': [100,70,30], 'Bryan': [30, 2, 10], 'Jonathan': [50, 30, 40], 'Alan': [5, 2, 5]}


#Preguntas
preguntas = [
        {
            "pregunta": "Menciona una fruta que tenga semillas:",
            "respuestas": [
                {"texto": "Naranja", "puntos": 10},
                {"texto": "Manzana", "puntos": 5},
                {"texto": "Sandía", "puntos": 3},
                {"texto": "Limón", "puntos": 2}
            ]
        },
        {
            "pregunta": "Menciona una forma popular de decir niño en México:",
            "respuestas": [
                {"texto": "Chamaco", "puntos": 10},
                {"texto": "Escuincle", "puntos": 5},
                {"texto": "Chiquillo", "puntos": 3},
                {"texto": "Criatura", "puntos": 2}
            ]
        },
        {
            "pregunta":"Menciona propósitos de año nuevo:",
            "respuestas": [
                {"texto": "Hacer Dieta", "puntos": 10},
                {"texto": "Hacer Ejercicio", "puntos": 5},
                {"texto": "Ahorrar", "puntos": 3},
                {"texto": "Comprar algún objeto", "puntos": 2}
            ]
        },
        {
            "pregunta":"Menciona superhéroes famosos:",
            "respuestas": [
                {"texto": "Superman", "puntos": 10},
                {"texto": "Spider-man", "puntos": 5},
                {"texto": "Batman", "puntos": 3},
                {"texto": "Mujer maravilla", "puntos": 2}
            ]
        },
        {
            "pregunta":"Subgéneros que pertenecen al género narrativo:",
            "respuestas": [
                {"texto": "Cuento", "puntos": 10},
                {"texto": "Leyenda", "puntos": 5},
                {"texto": "Mito", "puntos": 3},
                {"texto": "Fabula", "puntos": 2}
            ]
        },
        {
            "pregunta":"Lenguajes de programación más usados:",
            "respuestas": [
                {"texto": "Python", "puntos": 10},
                {"texto": "Java", "puntos": 5},
                {"texto": "C", "puntos": 3},
                {"texto": "C++", "puntos": 2}
            ]
        },
        {
            "pregunta":"Elementos de la poesía:",
            "respuestas": [
                {"texto": "Rima", "puntos": 10},
                {"texto": "Verso", "puntos": 5},
                {"texto": "Estrofa", "puntos": 3},
                {"texto": "Ritmo", "puntos": 2}
            ]
        },
        {
            "pregunta":"Tipos de cartas:",
            "respuestas": [
                {"texto": "Carta formal", "puntos": 10},
                {"texto": "Carta informal", "puntos": 5},
                {"texto": "Carta informativa", "puntos": 3},
                {"texto": "Carta comercial", "puntos": 2}
            ]
        },
        {
            "pregunta":"Cuando un niño se porta mal, con que se castiga:",
            "respuestas": [
                {"texto": "Juguetes", "puntos": 10},
                {"texto": "Televisión", "puntos": 5},
                {"texto": "Celular", "puntos": 3},
                {"texto": "Salir", "puntos": 2}
            ]
        },
        {
            "pregunta":"Menciona animales con mal olor:",
            "respuestas": [
                {"texto": "Zorrillo", "puntos": 10},
                {"texto": "Cerdo", "puntos": 5},
                {"texto": "Vaca", "puntos": 3},
                {"texto": "Borrego", "puntos": 2}
            ]
        },
        {
            "pregunta":"Comida Popular de México:",
            "respuestas": [
                {"texto": "Tacos", "puntos": 10},
                {"texto": "Pozole", "puntos": 5},
                {"texto": "Mole", "puntos": 3},
                {"texto": "Tamales", "puntos": 2}
            ]
        },
        {
            "pregunta":"Disfraz común en los festivales de primavera:",
            "respuestas": [
                {"texto": "Mariposa", "puntos": 10},
                {"texto": "Abejita", "puntos": 5},
                {"texto": "Flor", "puntos": 3},
                {"texto": "Conejito", "puntos": 2}
            ]
        },
        {
            "pregunta":"Regalo más común el día de las madres:",
            "respuestas": [
                {"texto": "Flores", "puntos": 10},
                {"texto": "Ropa", "puntos": 5},
                {"texto": "Peluches", "puntos": 3},
                {"texto": "Maquillaje", "puntos": 2}
            ]
        },
        {
            "pregunta":"Además de pan, que otro ingrediente se usa para preparar un sándwich:",
            "respuestas": [
                {"texto": "Jamón", "puntos": 10},
                {"texto": "Queso", "puntos": 5},
                {"texto": "Jitomate", "puntos": 3},
                {"texto": "Mayonesa", "puntos": 2}
            ]
        },
        {
            "pregunta":"Menciona países más grandes:",
            "respuestas": [
                {"texto": "Rusia", "puntos": 10},
                {"texto": "Canadá", "puntos": 5},
                {"texto": "China", "puntos": 3},
                {"texto": "Estados Unidos", "puntos": 2}
            ]
        },
        {
            "pregunta":"Menciona las marcas de moda deportiva más populares:",
            "respuestas": [
                {"texto": "Nike", "puntos": 10},
                {"texto": "Adidas", "puntos": 5},
                {"texto": "Puma", "puntos": 3},
                {"texto": "Rebook", "puntos": 2}
            ]
        }
    ]

#Función para normalizar el input del usuario    
def procesar_input(texto):
    # Convertir a minúsculas y eliminar acentos , NFKD es un tipo de normalización
    texto_normalizado = unicodedata.normalize('NFKD', texto).encode('ASCII', 'ignore').decode('utf-8').lower()
    return texto_normalizado

def menu():
  print(" ╔╗╔═══╦═══╗        ╔╗     ╔╗       ╔╗          ╔╗\n"
      "╔╝║║╔═╗║╔═╗║       ╔╝╚╗    ║║      ╔╝╚╗         ║║ ╔╗\n"
      "╚╗║║║║║║║║║║ ╔══╦══╬╗╔╬╗╔╦═╝╠╦══╦═╗╚╗╔╬══╦══╗ ╔═╝╠╗╚╬══╦═╦══╦═╗\n"
      " ║║║║║║║║║║║ ║║═╣══╣║║║║║║╔╗╠╣╔╗║╔╗╗║║║║═╣══╣ ║╔╗╠╣╔╣║═╣╔╣╔╗║╔╗╗\n"
      "╔╝╚╣╚═╝║╚═╝║ ║║═╬══║║╚╣╚╝║╚╝║║╔╗║║║║║╚╣║═╬══║ ║╚╝║║║║║═╣║║╚╝║║║║\n"
      "╚══╩═══╩═══╝ ╚══╩══╝╚═╩══╩══╩╩╝╚╩╝╚╝╚═╩══╩══╝ ╚══╩╝║╠══╩╝╚══╩╝╚╝\n"
      "                                                  ╔╝║\n"
      "                                                  ╚═╝")
  print("1. Registrar Jugador\n2. Verificar puntuaciones\n3. Jugar\n4. Salir")
  option = int(input("Ingrese una opción: "))
  clear_output()
  if option == 4 :
    print("Gracias por jugar!! Saliendo...")
    return 
  elif option == 1:
    return registrar_jugador()
  elif option == 2:
    return verificar_puntuaciones()
  elif option == 3:
    return jugar()

  else:
    print("Opción inválida, inténtalo de nuevo")
    return menu()

# Función para verificar las puntuaciones
def verificar_puntuaciones():
    nombre = input("Ingrese el nombre del jugador para verificar sus puntuaciones: ")
    
    while nombre not in jugadores:
        print("El jugador no existe. Por favor, ingrese un nombre válido.")
        nombre = input("Ingrese el nombre del jugador para verificar sus puntuaciones: ")
    print("Hola", nombre, "tus puntuaciones son las siguientes:")
    if jugadores[nombre] == 0:
        print("No has jugado aún.")
    else:
        partida_num = 1
        for jugador in jugadores:
            for puntos in jugadores[jugador]:
              if nombre == jugador:
                print("Partida", partida_num, "=", puntos, "puntos")
                partida_num += 1
    
    ranking = {}

    for jugador in jugadores:
      puntuacion_total = 0
      for puntos in jugadores[jugador]:
        puntuacion_total += puntos
      ranking.update({jugador: puntuacion_total})
    
    puntuaciones_globales = sorted(ranking.items(), key=operator.itemgetter(1), reverse=True)
    print("\nRANKING GLOBAL")
    for i, jugador in enumerate(puntuaciones_globales):
        print(jugador[0], jugador[1], "puntos")
        if jugador[0] == nombre:
            print("Actualmente te encuentras en la posición", i+1, "del Ranking.\n")
    time.sleep(5)
    clear_output()
    return menu()

def juego(rondas):
  puntuaciones_jugador1 = 0
  puntuaciones_jugador2 = 0
  for ronda in range(rondas):
      strike_jugador1 = 0
      strike_jugador2 = 0
      robo_puntos1 = 0
      robo_puntos2 = 0
      primer_turno = 1
      puntos_primer_turno2 = 0
      puntos_primer_turno = 0


      #Definición de quien inicia la ronda
      if ronda % 2 == 0:
        jugador_actual = 1
      else:
        jugador_actual = 2

      pregunta_actual = random.choice(preguntas)
      respuesta_jugador = ""
      respuestas_acertadas = []
      respuestas = pregunta_actual["respuestas"]

      while jugador_actual == 1 or jugador_actual == 2:
        clear_output()
        print("\nRonda", ronda + 1)
        print("Pregunta:", pregunta_actual["pregunta"])
        completado = 0
        puntos_actuales = 0
        print(respuesta_jugador)
        #Imprimir las tablas con las respuestas acertadas
        for respuesta in respuestas:
          k = 0
          valor = ""
          while k < len(respuestas_acertadas):
            if respuestas_acertadas[k] == respuesta["texto"]:
              valor = respuestas_acertadas[k]
              #Suma de puntos obtenidos hasta el momento
              puntos_actuales += int(respuesta["puntos"])
              break
            else:
              k += 1
          if valor != respuesta["texto"]:
            #Si una respuesta aún no se conoce, se imprimen asteriscos
            print("**********")
          else:
            completado += 1  #Bandera para el termino de la ronda cuando se descubran las 4 respuestas
            print(respuesta["texto"], "\t", respuesta["puntos"])
        if completado == 4:
          if jugador_actual == 1: 
            print("Jugador 1 tiene puntuación perfecta!!! Siguiente ronda.") 
            puntuaciones_jugador1 += puntos_actuales #Suma de puntos en caso de ronda perfecta
            jugador_actual = 2 #Cambio de jugador
            time.sleep(5)
            break
          if jugador_actual == 2:
            print("Jugador 2 tiene puntuación perfecta!!! Siguiente ronda.") 
            puntuaciones_jugador2 += puntos_actuales #Suma de puntos en caso de ronda perfecta
            jugador_actual = 1 #Cambio de jugador
            time.sleep(5)
            break
        if len(respuesta_jugador) != 0 and (primer_turno == 1 or primer_turno == 2):
          for respuesta in respuestas:
            if respuesta_jugador == respuesta["texto"] and primer_turno == 1:
              puntos_primer_turno = int(respuesta["puntos"])
            if respuesta_jugador == respuesta["texto"] and primer_turno == 2:
              puntos_primer_turno2 = int(respuesta["puntos"])

        if primer_turno == 1 and jugador_actual == 1 and puntos_primer_turno == 10 and len(respuesta_jugador) != 0:
          print("Respuesta con mayor puntuación!! Jugador 1 sigue respondiendo!!\n")
          primer_turno = 0
        elif primer_turno == 1 and jugador_actual == 2 and puntos_primer_turno == 10 and len(respuesta_jugador) != 0:
          print("Respuesta con mayor puntuación!! Jugador 2 sigue respondiendo!!\n")
          primer_turno = 0
        elif primer_turno == 1 and jugador_actual == 1 and puntos_primer_turno < 10 and len(respuesta_jugador) != 0:
          print("No es la respuesta de mayor puntuación. Jugador 2 tiene la oportunidad de responder!!\n")
          jugador_actual = 2
          primer_turno = 2
        elif primer_turno == 1 and jugador_actual == 2 and puntos_primer_turno < 10 and len(respuesta_jugador) != 0:
          print("No es la respuesta de mayor puntuación. Jugador 1 tiene la oportunidad de responder!!\n")
          jugador_actual = 1
          primer_turno = 2
        elif primer_turno == 2 and jugador_actual == 1 and puntos_primer_turno < puntos_primer_turno2 and len(respuesta_jugador) != 0:
          print("Respuesta con mayor puntuación!! Jugador 1 sigue respondiendo!!\n")
          primer_turno = 0
        elif primer_turno == 2 and jugador_actual == 2 and puntos_primer_turno < puntos_primer_turno2 and len(respuesta_jugador) != 0:
          print("Respuesta con mayor puntuación!! Jugador 1 sigue respondiendo!!\n")
          primer_turno = 0
        elif primer_turno == 2 and jugador_actual == 1 and puntos_primer_turno > puntos_primer_turno2 and len(respuesta_jugador) != 0:
          print("No es la respuesta de mayor puntuación. Jugador 2 siga respondiendo!!\n")
          jugador_actual = 2
          primer_turno = 0
        elif primer_turno == 2 and jugador_actual == 2 and puntos_primer_turno > puntos_primer_turno2 and len(respuesta_jugador) != 0:
          print("No es la respuesta de mayor puntuación. Jugador 1 siga respondiendo!!\n")
          jugador_actual = 1
          primer_turno = 0

        print("Turno: jugador", jugador_actual)

        respuesta_jugador = input("\nIngrese una respuesta: ")
        #Turno jugador 1
        if jugador_actual == 1:
          #Verificación de respuesta
          if respuesta_jugador not in [respuesta["texto"] for respuesta in respuestas]:
            if robo_puntos1 == 1:
              #Robo de puntos (Si está habilitado)
              print("Respuesta incorrecta!! Puntos para el jugador 2")
              puntuaciones_jugador2 += puntos_actuales
              time.sleep(5)
              break
            else:
              #Asignación de strikes
              strike_jugador1 += 1
              print(f"Respuesta incorrecta!! El jugador {jugador_actual} tiene {strike_jugador1} strikes!!")
              if strike_jugador1 == 3:
                robo_puntos1 = 1 #Bandera para robar puntos
                print(f"Jugador {jugador_actual} tiene 3 strikes!! Turno del siguiente jugador")
                jugador_actual = 2
                time.sleep(5)
          else:
            respuestas_acertadas.append(respuesta_jugador)

        #Turno Jugador 2
        if jugador_actual == 2:
          #Verificación de respuesta
          if respuesta_jugador not in [respuesta["texto"] for respuesta in respuestas]:
            if robo_puntos2 == 1:
              #Robo de puntos (Si está habilitado)
              print("Respuesta incorrecta!! Puntos para el jugador 1")
              puntuaciones_jugador1 += puntos_actuales
              time.sleep(5)
              break
            else:
              #Asignación de strikes
              strike_jugador2 += 1
              print(f"Respuesta incorrecta!! El jugador {jugador_actual} tiene {strike_jugador2} strikes!!")
              if strike_jugador2 == 3:
                robo_puntos1 = 1 #Bandera para robar puntos
                print(f"Jugador {jugador_actual} tiene 3 strikes!! Turno del siguiente jugador")
                jugador_actual = 1
                time.sleep(5)
          else:
            respuestas_acertadas.append(respuesta_jugador)
  return puntuaciones_jugador1, puntuaciones_jugador2

def jugar():
    print("¡Bienvenidos al juego!")

    jugador1 = input("Ingrese el nombre del Jugador 1: ")
    jugador2 = input("Ingrese el nombre del Jugador 2: ")

    if jugador1 not in jugadores or jugador2 not in jugadores:
        print("Ambos jugadores deben estar registrados para poder jugar.")
        time.sleep(5)
        return menu()

    print("Comienza el juego entre", jugador1, "y", jugador2)


    puntuaciones_jugador1, puntuaciones_jugador2 = juego(5)

# Ronda para decidir el desempate    
    while puntuaciones_jugador1 == puntuaciones_jugador2:
      print("Ronda de desempate")
      puntos_desempate1, puntos_desempate2 = juego(1)
      puntuaciones_jugador1 += puntos_desempate1
      puntuaciones_jugador2 += puntos_desempate2
    # Determinar al ganador
    if puntuaciones_jugador1 > puntuaciones_jugador2:
        print(f"{jugador1} gana el juego.")
    elif puntuaciones_jugador1 < puntuaciones_jugador2:
        print(f"{jugador2} gana el juego.")
    else:
        print("El juego termina en empate.")

    puntuaciones_jugador1_copy = []
    puntuaciones_jugador2_copy = []

    for jugador in jugadores:
      if jugador1 == jugador:
        for puntos in jugadores[jugador]:
          if puntos != 0:
            puntuaciones_jugador1_copy.append(puntos)
      if jugador2 == jugador:
        for puntos in jugadores[jugador]:
          if puntos != 0:
            puntuaciones_jugador2_copy.append(puntos)
    puntuaciones_jugador1_copy.append(puntuaciones_jugador1)
    puntuaciones_jugador2_copy.append(puntuaciones_jugador2)

    #Guardar puntuaciones de la ronda
    jugadores[jugador1] = puntuaciones_jugador1_copy
    jugadores[jugador2] = puntuaciones_jugador2_copy
    time.sleep(5)
    clear_output()
    return menu()


# Función para registrar un nuevo jugador
def registrar_jugador():
    nombre = input("Ingrese el nombre o alias del jugador: ")
    while nombre in jugadores:
        print("El nombre ya está registrado. Por favor, ingrese un nombre o alias distinto.")
        nombre = input("Ingrese el nombre o alias del jugador: ")
    
    jugadores[nombre] = [0]
    print("Registro exitoso. ¡Bienvenido,", nombre, "!")
    time.sleep(5)
    clear_output()
    return menu()

menu()