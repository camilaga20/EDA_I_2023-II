biblioteca = []
# Función mostrar
def mostrar_menu():
    print("\n.:********MENÚ*********:.\n")
    print("1. Agregar libro\n")
    print("2. Eliminar libro\n")
    print("3. Ordenar biblioteca\n")
    print("4. Ver biblioteca\n")
    print("5. Salir")
#Función agregar
def agregar_libro():
    titulo = input("\nIngresa el título del libro: ")
    autor = input("Ingresa el autor del libro: ")
    año = input("Ingresa el año del libro: ")
    genero = input("Ingresa el género del libro: ")
    libro = {
        "título": titulo,
        "autor": autor,
        "año": año,
        "género": genero
    }
    biblioteca.append(libro)
    print("**Libro agregado con éxito.**\n")
#Función liminar
def eliminar_libro():
    titulo = input("\nIngresa el título del libro a eliminar: ")
    encontrado = False
    for libro in biblioteca:
        if libro["título"].lower() == titulo.lower():
            biblioteca.remove(libro)
            print("**Libro eliminado con éxito.**")
            encontrado = True
            break
    if not encontrado:
        print("**El libro no se encuentra en la biblioteca.**")
#Función ordenar
def ordenar_biblioteca():
    biblioteca.sort(key=lambda libro: libro["título"])
    print("\n*****Biblioteca ordenada alfabéticamente.*****")
#Función ver
def ver_biblioteca():
    if len(biblioteca) == 0:
        print("La biblioteca está vacía.")
    else:
        print("\n.:*****BIBLIOTECA*****:.")
        for libro in biblioteca:
            print("\nTítulo:", libro["título"])
            print("\nAutor:", libro["autor"])
            print("\nAño:", libro["año"])
            print("\nGénero:", libro["género"])
            print("--------------------")

# Función principal
def main():
    while True:
        mostrar_menu()
        opcion = input("\nElige una opción: ")
        
        if opcion == "1":
            agregar_libro()
        elif opcion == "2":
            eliminar_libro()
        elif opcion == "3":
            ordenar_biblioteca()
        elif opcion == "4":
            ver_biblioteca()
        elif opcion == "5":
            print("Gracias por usar el programa :)")
            break
        else:
            print("Opción inválida. Por favor, elige una opción válida.")

# Ejecutar la función principal
main()