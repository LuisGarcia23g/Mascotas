#include <iostream>
#include <string>

struct Mascotas {
    std::string nombre;    
    int edad;
    std::string vacunada;
};

// Funciones
void IngresarDatosMascotas(Mascotas& mascota);
void MostrarRegistros(const Mascotas& mascota);
void EditarVacunacion(Mascotas& mascota);
void FiltrarNoVacunados(Mascotas* mascotas, int cantidad);
void ContarMascotas(Mascotas* mascotas, int cantidad);
void BuscarMascotasPorNombre(Mascotas* mascotas, int cantidad, const std::string& nombre);

int main() {
    int cantidadMascotas;

    std::cout << "Cuantas mascotas tiene? : ";
    std::cin >> cantidadMascotas;

    if (cantidadMascotas <= 0 || cantidadMascotas > 100) {
        std::cout << "Maximo 100 mascotas.\n";
        return 1; // Termina el programa si la cantidad no es valida
    }

    Mascotas mascotas[100];
    int opcion;

    do {
        std::cout << "\t---MENU---" << "\n";
        std::cout << "1. Ingresar Datos de Mascotas\n";
        std::cout << "2. Mostrar Todos los Registros\n";
        std::cout << "3. Editar Estado de Vacunacion\n";
        std::cout << "4. Filtrar Mascotas por Estado de Vacunacion\n";
        std::cout << "5. Contar Mascotas por Estado de Vacunacion\n";
        std::cout << "6. Buscar Mascota por Nombre\n";
        std::cout << "7. Salir\n";
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1: 
                for (int i = 0; i < cantidadMascotas; i++) {
                    std::cout << "Ingresando datos para la mascota " << (i + 1) << ":\n";
                    IngresarDatosMascotas(mascotas[i]);
                }
                break;

            case 2:
                for (int i = 0; i < cantidadMascotas; i++) {
                    MostrarRegistros(mascotas[i]);
                }
                break;

            case 3: {
                std::cout << "Ingrese el nombre de la mascota a editar: ";
                std::string nombre;
                std::cin >> nombre;
                bool encontrado = false;
                for (int i = 0; i < cantidadMascotas; i++) {
                    if (mascotas[i].nombre == nombre) {
                        EditarVacunacion(mascotas[i]);
                        encontrado = true;
                        break;
                    }
                }
                if (!encontrado) {
                    std::cout << "Mascota no encontrada.\n";
                }
                break;
            }

            case 4:
                FiltrarNoVacunados(mascotas, cantidadMascotas);
                break;

            case 5: 
                ContarMascotas(mascotas, cantidadMascotas);
                break;

            case 6: {
                std::cout << "Ingrese el nombre de la mascota a buscar: ";
                std::string nombre;
                std::cin >> nombre;
                BuscarMascotasPorNombre(mascotas, cantidadMascotas, nombre);
                break;
            }

            case 7: 
                std::cout << "Gracias, besitos a tus mascotas.\n";
                break;

            default:
                std::cout << "Opcion no valida.\n";
        }
    } while (opcion != 7);

    return 0;
}

void IngresarDatosMascotas(Mascotas& mascota) {
    std::cout << "Ingrese el nombre de la mascota: ";
    std::cin >> mascota.nombre;
    std::cout << "Ingrese la edad de la mascota: ";
    std::cin >> mascota.edad;
    std::cout << "Esta vacunada? (si/no): ";
    std::cin >> mascota.vacunada;
    std::cout << "Mascota registrada.\n";
}

void MostrarRegistros(const Mascotas& mascota) {
    std::cout << "Nombre: " << mascota.nombre << ", Edad: " << mascota.edad
              << ", Vacunada: " << mascota.vacunada << "\n";
}

void EditarVacunacion(Mascotas& mascota) {
    std::cout << "Esta vacunada? (si/no): ";
    std::cin >> mascota.vacunada;
    std::cout << "Estado de vacunacion actualizado.\n";
}

void FiltrarNoVacunados(Mascotas* mascotas, int cantidad) {
    std::cout << "\tMascotas no vacunadas:\n";
    
    int cantidadNoVacunadas = 0;

    for (int i = 0; i < cantidad; i++) {
        if (mascotas[i].vacunada == "no") {
            std::cout << "Nombre: " << mascotas[i].nombre << ", Edad: " << mascotas[i].edad << "\n";
            cantidadNoVacunadas++;
        }
    }
    if (cantidadNoVacunadas == 0) {
        std::cout << "No hay mascotas no vacunadas.\n";
    }
}

void ContarMascotas(Mascotas* mascotas, int cantidad) {
    int vacunadas = 0, noVacunadas = 0;

    for (int i = 0; i < cantidad; i++) {
        if (mascotas[i].vacunada == "si") {
            vacunadas++;
        } else {
            noVacunadas++;
        }
    }

    std::cout << "Mascotas vacunadas: " << vacunadas << "\n";
    std::cout << "Mascotas no vacunadas: " << noVacunadas << "\n";
}

void BuscarMascotasPorNombre(Mascotas* mascotas, int cantidad, const std::string& nombre) {
    for (int i = 0; i < cantidad; i++) {
        if (mascotas[i].nombre == nombre) {
            MostrarRegistros(mascotas[i]);
            return;
        }
    }
    std::cout << "Mascota no encontrada.\n";
}

