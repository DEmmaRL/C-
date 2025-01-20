import re

def sum_enabled_muls_from_file(filename):
    # Expresión regular para instrucciones
    instruction_pattern = r"mul\(\s*(\d+)\s*,\s*(\d+)\s*\)|do\(\)|don't\(\)"
    total = 0
    mul_enabled = True  # Al inicio, las instrucciones mul están habilitadas

    with open(filename, 'r') as file:
        for line in file:
            # Buscar todas las instrucciones en la línea
            instructions = re.finditer(instruction_pattern, line)
            for match in instructions:
                if match.group(0) == "do()":
                    mul_enabled = True
                elif match.group(0) == "don't()":
                    mul_enabled = False
                else:
                    # Es una instrucción `mul` válida
                    if mul_enabled:
                        x, y = map(int, match.groups())
                        total += x * y
    return total

# Nombre del archivo de entrada
input_file = "in"

# Resultado de la suma de todas las multiplicaciones válidas y habilitadas en el archivo
result = sum_enabled_muls_from_file(input_file)
print("Resultado:", result)
