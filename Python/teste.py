def calcular_area_triangulo(base, altura):
    area = (base * altura) / 2
    return area

# Exemplo de uso:
base = float(input("Digite o valor da base do triângulo: "))
altura = float(input("Digite o valor da altura do triângulo: "))

area = calcular_area_triangulo(base, altura)
print("A área do triângulo é:", area)