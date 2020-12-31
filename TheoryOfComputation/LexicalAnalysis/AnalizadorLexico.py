#!/usr/bin/env python3
#Tarea 3, ejercicio 3 pag 27 
#Analizador Lexico, Raziel Lopez Escamilla

class Analizador:
    def __init__(self,TablaTransiciones): 
        """Inicializamos variables del analizador"""
        self.TablaTransiciones = TablaTransiciones
        self.Estado = 1
    
    def Procesar(self, cadena):
        """Procesamos la cadena ingresada al analizador,
        Retorna: 
        True - Cadena Valida
        False - Cadena Invalida"""

        CadenaValida = True
        for letra in cadena:
            CadenaValida = self.ProcesarCaracter(letra)
            if CadenaValida == False:
                #Letra invalida detectada
                break
        if CadenaValida != False:
            #Inicamos fin de cadena
            CadenaValida = self.ProcesarCaracter('\n')  
        return CadenaValida
    
    def ProcesarCaracter (self,letra):
        if letra.isdigit():
            Entrada = 0
        elif letra == '.':
            Entrada = 1
        elif letra == 'E':
            Entrada = 2
        elif letra == '+':
            Entrada = 3 
        elif letra == '-':
            Entrada = 4
        elif letra == '\n': 
            #indicador de FDC
            Entrada = 5
        else:
            #Caracter invalido
            return False
        
        self.Estado = self.TablaTransiciones[self.Estado - 1][Entrada]

        if self.Estado == 'error':
            return False
        else:  
            return True

def main():
    """Funcion principal que ejecuta un ejemplo de un analizar léxico"""
    print("Analizador Léxico")
    print("Raziel López Escamilla")
    print("Descripción: analizador léxico que acepta números reales")
    print("ej. 1.123 , 123E123, 23E+112, 123E-12 ")
    TablaTransiciones = [ [ 2, "error", "error", "error", "error",   "error"],
                        [ 2,       3,       5, "error", "error",   "error"],
                        [ 4, "error", "error", "error", "error",   "error"],
                        [ 4, "error",       5, "error", "error", "aceptar"],
                        [ 7, "error", "error",       6,       6,   "error"],
                        [ 7, "error", "error", "error", "error",   "error"],
                        [ 7, "error", "error", "error", "error", "aceptar"]]

    numero = input("Ingresa número real: ")
    An = Analizador(TablaTransiciones)
    if An.Procesar(numero) == False:
        print("Cadena Inválida.")
    else:
        print("Número real valido.")

main()


