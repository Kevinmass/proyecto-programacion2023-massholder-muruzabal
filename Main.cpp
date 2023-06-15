#include <iostream>
#include <string>
#include <vector>
#include "Cliente.h"
#include <fstream>
using namespace std;

void PrimerIngreso(vector<Cliente> &C)
{
    int n, p, q, x, y = 0, w;
    string m;
    cout << "**No hay clientes registrados en el sistema...\n**Ingrese un cliente para continuar...\n\nCuantos clientes desea ingresar?\n\n";
    cin >> x;
    // 2 Nacho Magoia 1 Activo 100 12 2020 Black 1000 Juan Muruzabal 2 Pasivo 1 1 2019 Black 2000
    try
    {
        for (int i = 0; i < x; i++)
        {
            C.push_back(Cliente());
            cout << "Cliente nro: " << i + 1 << ":\n";
            cout << "Ingrese Nombre del cliente: \n";
            cin >> m;
            C.back().setNombre(m);
            cout << "\nIngrese Apellido del cliente: \n";
            cin >> m;
            C.back().setApellido(m);
            if (y == 0)
            {
                y++;
                cout << "\nIngrese el ID del cliente: \n";
                w = 0;
                do
                {
                    cin >> n;
                    if (n <= 0)
                    {
                        cout << "\n**Ingrese un ID positivo\n";
                    }
                    else
                        w = 1;
                } while (w == 0);
                C.back().setID(n);
            }
            else
            {
                w = 1;
                do
                {
                    cout << "\nIngrese el ID del cliente: \n";
                    q = 0;
                    do
                    {
                        cin >> n;
                        if (n <= 0)
                        {
                            cout << "\n**Ingrese un ID positivo\n";
                        }
                        else
                            q = 1;
                    } while (q == 0);
                    p = 1;
                    for (int i = 0; i < C.size(); i++)
                    {
                        if (n == C[i].getID())
                        {
                            cout << "\nEl ID ingresado ya existe, ingrese otro ID\n";
                            p = 0;
                            break;
                        }
                    }
                    if (p == 1)
                    {
                        w = 0;
                    }

                } while (w == 1);
                C.back().setID(n);
            }

            cout << "\nIngrese el estado de la cuenta: \n";
            cin >> m;
            C.back().setEstado(m);
            cout << "\nIngrese la fecha en la que la cuenta fue creada: \n";
            w = 0;
            do
            {
                cout << "Dia: \n";
                cin >> n;
                cout << "Mes: \n";
                cin >> p;
                cout << "Anio: \n";
                cin >> q;
                if (n <= 0 || p <= 0 || q <= 0)
                {
                    cout << "\n**Ingrese fechas que no sean negativas o nulas\n";
                }
                else
                    w = 1;
            } while (w == 0);

            C.back().setFecha(n, p, q);
            cout << "\nIngrese la clase de cuenta: \n\n**CUENTAS CON 3 O MAS ANIOS DE ANTIGUEDAD PUEDEN SER CLASE BLACK**\n**CUENTAS QUE NO CUMPLAN EL REQUERIMIENTO SERAN CONVERTIDAS CLASE GOLD**\n";
            cin >> m;
            C.back().setClase(m);
            cout << "\nIngrese la cantidad de dinero que tiene actualmente el cliente: \n";
            w = 0;
            do
            {
                cin >> n;
                if (n < 0)
                {
                    cout << "\n**Ingrese una cantidad positiva de dinero o nulo\n";
                }
                else
                    w = 1;
            } while (w == 0);
            C.back().setCaja(n);
            cout << "------------------------------------------------------------------------------------\n\n";
        }
    }
    catch (std::bad_alloc &)
    {
        cout << "Memoria Insuficiente\n";
    }
} // funciona

void Estado(vector<Cliente> &C)
{
    for (int i = 0; i < C.size(); i++)
    {
        Cliente *x = &C[i];
        cout << "\n\nCliente ID: " << x->getID() << "\n";
        cout << "Nombre: " << x->getNombre() << "\n";
        cout << "Apellido: " << x->getApellido() << "\n";
        cout << "Estado: " << x->getEstado() << "\n";
        cout << "------------------------------------------------------------------------------------\n\n";
    }

} // Funciona

void MenuMantenimiento(vector<Cliente> &C)
{
    int n, p, q, x;
    string m;
    bool llave = false;
    cout << "\n\n--MENU MANTENIMIENTO--\n";
    do
    {
        cout << "\n\nQue desea hacer?\n1-Modificar datos de un cliente\n2-Modificar estado de una cuenta\n3-Modificar clase de una cuenta\n4-Regresar al menu principal\n";
        cin >> x;
        switch (x)
        {
        case 1:
            cout << "\n\nIngrese el ID del cliente que desea modificar: \n\n";
            cin >> n;
            q = 0;
            for (int i = 0; i < C.size(); i++)
            {
                Cliente *y = &C[i];
                if (y->getID() == n)
                {
                    q = 1;
                    cout << "\n\nCliente encontrado...\n\n";
                    cout << "Ingrese el nuevo nombre: \n";
                    cin >> m;
                    y->setNombre(m);
                    cout << "Ingrese el nuevo apellido: ";
                    cin >> m;
                    y->setApellido(m);

                    remove("clientes.txt");
                }
            }
            break;
            if (q == 0)
            {
                cout << "Cliente no encontrado...\n Verifique el ID ingresado...\n";
            }
        case 2:
            cout << "\n\nIngrese el ID del cliente que desea modificar: \n\n";
            cin >> n;
            q = 0;
            for (int i = 0; i < C.size(); i++)
            {
                Cliente *y = &C[i];
                if (y->getID() == n)
                {
                    q = 1;
                    cout << "\n\nCliente encontrado...\n\n";
                    cout << "Ingrese el nuevo estado: ";
                    cin >> m;
                    y->setEstado(m);

                    remove("clientes.txt");
                }
            }
            break;
            if (q == 0)
            {
                cout << "Cliente no encontrado...\n Verifique el ID ingresado...\n";
            }
        case 3:
            cout << "\n\nIngrese el ID del cliente que desea modificar: \n";
            cin >> n;
            q = 0;
            for (int i = 0; i < C.size(); i++)
            {
                Cliente *y = &C[i];
                if (y->getID() == n)
                {
                    q = 1;
                    cout << "Ingrese la nueva clase: \n";
                    cin >> m;
                    y->setClase(m);

                    remove("clientes.txt");
                }
            }
            break;
            if (q == 0)
            {
                cout << "Cliente no encontrado...\n Verifique el ID ingresado...\n";
            }
        case 4:
            cout << "\n\nSaliendo del menu de mantenimiento...\n";
            llave = true;
            break;

        default:
            cout << "Opcion no valida...\n";
            break;
        }
    } while (llave == false);
} // Funciona

bool CheqFecha(int x, int y, int z)
{
    Cliente W;
    int _x, _y;
    _x = W.FechaActual.getMes();
    _y = W.FechaActual.getAnio();
    if (z == 1)
    {
        if (_x < 6)
        {
            _x = 6 + _x;
            _y--;
            if (_y < y)
            {
                return true;
            }
        }
        else
            _x = _x - 6;

        if (_y == y)
        {
            if (x > _x)
            {
                return true;
            }
            else
                return false;
        }
        else if (_y - 1 > y)
        {
            return false;
        }
    }
    else if (z == 2)
    {
        if (_y == y)
        {
            return true;
        }
        else if (_y - 1 == y)
        {
            if (_x <= x)
            {
                return true;
            }
            else
                return false;
        }
        else if (_y - 1 > y)
        {
            return false;
        }
    }
    return false;
}

void MenuTransacciones(vector<Cliente> &C, int &nro)
{
    int n, p, q, x, w, w1;
    string m;
    bool llave = false;
    cout << "\n\n--MENU TRANSACCIONES--\n";
    do
    {
        cout << "\n\nQue desea hacer?\n1-Depositar en un cliente\n2-Retirar de un cliente\n3-Ver transacciones realizadas\n4-Regresar al menu principal\n";
        cin >> x;
        switch (x)
        {
        case 1:
            cout << "\n\nIngrese el ID del cliente al que desea depositarle: \n";
            cin >> n;
            w = 0;
            for (int i = 0; i < C.size(); i++)
            {
                Cliente *y = &C[i];
                if (y->getID() == n)
                {

                    try
                    {
                        y->transaccion.push_back(Transacciones());
                        m = 'D';
                        y->transaccion.back().setClase(m);
                        w = 1;
                        y->transaccion.back() + (n);
                        nro++;
                        y->transaccion.back().setNumeroTransaccion(nro);
                        cout << "\nTransaccion nro: " << nro << "\n";
                        cout << "Ingrese la cantidad a depositar: \n";
                        cin >> n;
                        y->transaccion.back() + (n);
                        y->setCaja(y->getCaja() + n);
                        cout << "Ingrese la fecha de deposito: \n";
                        w1 = 0;
                        do
                        {
                            cout << "Dia: \n";
                            cin >> n;
                            cout << "Mes: \n";
                            cin >> p;
                            cout << "Anio: \n";
                            cin >> q;
                            if (n <= 0 || p <= 0 || q <= 0)
                            {
                                cout << "\n**Ingrese fechas que no sean negativas o nulas\n";
                            }
                            else
                                w1 = 1;
                        } while (w1 == 0);
                        y->transaccion.back().setFecha(n, p, q);
                    }
                    catch (std::bad_alloc &)
                    {
                        cout << "Memoria Insuficiente\n";
                    }
                }
            }
            break;
            if (w == 0)
            {
                cout << "Cliente no encontrado...\n Verifique el ID ingresado...\n";
            }

        case 2:
            cout << "\n\nIngrese el ID del cliente al que desea retirarle: \n";
            cin >> n;
            w = 0;
            for (int i = 0; i < C.size(); i++)
            {
                Cliente *y = &C[i];
                if (y->getID() == n)
                {

                    try
                    {
                        y->transaccion.push_back(Transacciones());
                        m = 'E';
                        y->transaccion.back().setClase(m);
                        w = 1;
                        y->transaccion.back() + (n);
                        nro++;
                        y->transaccion.back().setNumeroTransaccion(nro);
                        cout << "Transaccion nro: " << nro << "\n";
                        q = 0;
                        do
                        {
                            w1 = 0;
                            do
                            {
                                cout << "Ingrese la cantidad a retirar: \n";
                                cin >> n;
                                if (n <= 0)
                                {
                                    cout << "\n**Ingrese una cantidad positiva\n";
                                }
                                else
                                    w1 = 1;
                            } while (w1 == 0);

                            if (y->getCaja() < n)
                            {
                                cout << "**No se puede retirar, el cliente no tiene dinero suficiente en su cuenta...\n**Ingrese un aporte menor o ingrese 0 para salir...\n\n";
                            }
                            else if (y->getCaja() >= n)
                            {
                                q = 1;
                                y->transaccion.back() - (n);
                                y->setCaja(y->getCaja() - n);
                            }
                            else if (n == 0)
                            {
                                q = 1;
                            }
                        } while (q == 0);
                        if (n != 0)
                        {
                            cout << "Ingrese la fecha del retiro: \n";
                            w1 = 0;
                            do
                            {
                                cout << "Dia: \n";
                                cin >> n;
                                cout << "Mes: \n";
                                cin >> p;
                                cout << "Anio: \n";
                                cin >> q;
                                if (n <= 0 || p <= 0 || q <= 0)
                                {
                                    cout << "\n**Ingrese fechas que no sean negativas o nulas\n";
                                }
                                else
                                    w1 = 1;
                            } while (w1 == 0);
                            y->transaccion.back().setFecha(n, p, q);
                        }
                    }
                    catch (std::bad_alloc &)
                    {
                        cout << "Memoria Insuficiente\n";
                    }
                }
            }
            break;
            if (w == 0)
            {
                cout << "Cliente no encontrado...\n Verifique el ID ingresado...\n";
            }
        case 3:
            w = 0;
            for (int i = 0; i < C.size(); i++)
            {
                Cliente *y = &C[i];
                if (y->transaccion.size() != 0)
                {
                    w = 1;
                }
            }
            if (w == 1)
            {
                cout << "\n\nQue periodo desea ver?\n1-Por periodo de 6 meses\n2-Por periodo de un anio\n3-Todas las transacciones\n";
                cin >> x;
                switch (x)
                {
                case 1:
                    for (int i = 0; i < C.size(); i++)
                    {
                        Cliente *y = &C[i];
                        for (int j = 0; j < y->transaccion.size(); j++)
                        {
                            if (CheqFecha(y->transaccion[j].getMes(), y->transaccion[j].getAnio(), 1) == true)
                            {
                                cout << "\nTransaccion nro: " << y->transaccion[j].getNumeroTransaccion();
                                cout << "     Cantidad: " << y->transaccion[j].getCaja();
                                cout << "     Tipo: " << y->transaccion[j].getClase();
                                cout << "     Dia: " << y->transaccion[j].getDia();
                                cout << "     Mes: " << y->transaccion[j].getMes();
                                cout << "     Anio: " << y->transaccion[j].getAnio() << "\n";
                                cout << "      Cliente: " << y->getNombre() << " " << y->getApellido() << "\n";
                                cout << "------------------------------------------------------------------------------------------\n\n";
                            }
                        }
                    } // Funciona

                    break;
                case 2:
                    for (int i = 0; i < C.size(); i++)
                    {
                        Cliente *y = &C[i];
                        for (int j = 0; j < y->transaccion.size(); j++)
                        {
                            if (CheqFecha(y->transaccion[j].getMes(), y->transaccion[j].getAnio(), 2) == true)
                            {
                                cout << "\nTransaccion nro: " << y->transaccion[j].getNumeroTransaccion();
                                cout << "     Cantidad: " << y->transaccion[j].getCaja();
                                cout << "     Tipo: " << y->transaccion[j].getClase();
                                cout << "     Dia: " << y->transaccion[j].getDia();
                                cout << "     Mes: " << y->transaccion[j].getMes();
                                cout << "     Anio: " << y->transaccion[j].getAnio() << "\n";
                                cout << "      Cliente: " << y->getNombre() << " " << y->getApellido() << "\n";
                                cout << "------------------------------------------------------------------------------------------\n\n";
                            }
                        }
                    } // Funciona
                    break;
                case 3:
                    for (int i = 0; i < C.size(); i++)
                    {
                        Cliente *y = &C[i];
                        for (int j = 0; j < y->transaccion.size(); j++)
                        {
                            cout << "\nTransaccion nro: " << y->transaccion[j].getNumeroTransaccion();
                            cout << "     Cantidad: " << y->transaccion[j].getCaja();
                            cout << "     Tipo: " << y->transaccion[j].getClase();
                            cout << "     Dia: " << y->transaccion[j].getDia();
                            cout << "     Mes: " << y->transaccion[j].getMes();
                            cout << "     Anio: " << y->transaccion[j].getAnio() << "\n";
                            cout << "      Cliente: " << y->getNombre() << " " << y->getApellido() << "\n";
                            cout << "------------------------------------------------------------------------------------------\n\n";
                        }
                    } // Funciona

                    break;

                default:
                    cout << "Opcion no valida...\n";
                    break;
                }
                break;
            }
            else
                cout << "\n\n**Aun no se han realizado transacciones**\n\n";
        case 4:
            cout << "\n\nSaliendo del menu de transacciones...\n";
            llave = true;
            break;

        default:
            cout << "Opcion no valida...\n";
            break;
        }
    } while (llave == false);
} // Funciona

void MenuConsultas(vector<Cliente> &C, int &nro)
{
    int n, p, q, x, w;
    ofstream clientes;
    ofstream transacciones;
    bool llave = false;

    cout << "\n\n--CONSULTAS VARIAS--\n";
    do
    {
        cout << "\n\nQue desea hacer?\n1-Consultar cliente por ID\n2-Listado de todos los clientes\n3-Transacciones realizadas por cada cliente\n4-Salir\n\n";
        cin >> x;
        switch (x)
        {
        case 1:
            cout << "Ingrese el ID del cliente al que busca: \n";
            cin >> n;
            w = 0;
            p = C.size();
            for (int i = 0; i < p; i++)
            {
                Cliente *y = &C[i];
                if (y->getID() == n)
                {
                    w = 1;
                    cout << "\n\nCliente encontrado...\n\n";
                    cout << "Nombre: " << y->getNombre() << " \nApellido:" << y->getApellido() << "\n";
                    cout << "Estado de cuenta: " << y->getEstado() << "\n";
                    cout << "Clase: " << y->getClase() << "\n";
                    cout << "Saldo actual: $" << y->getCaja() << "\n";
                    cout << "Fecha de creacion de la cuenta: " << y->getDia() << " / " << y->getMes() << " / " << y->getAnio() << "\n";
                }
            }
            if (w == 0)
            {
                cout << "Cliente no encontrado...\n Verifique el ID ingresado...\n";
            }

            break;
        case 2:
            remove("clientes.txt");
            p = C.size();
            for (int i = 0; i < p; i++)
            {

                clientes.open("clientes.txt", ios::app);
                Cliente *y = &C[i];
                clientes << "\nID: " << y->getID() << "\n";
                clientes << "Nombre: " << y->getNombre() << " Apellido: " << y->getApellido() << "\n";
                clientes << "Estado de cuenta: " << y->getEstado() << "\n";
                clientes << "Clase: " << y->getClase() << "\n";
                clientes << "Saldo actual: $" << y->getCaja() << "\n";
                clientes << "Fecha de creacion de la cuenta: " << y->getDia() << "/" << y->getMes() << "/" << y->getAnio() << "\n";
                clientes << "------------------------------------------------------------------------------------------\n\n";
                clientes.close();

                cout << "\nID: " << y->getID() << "\n";
                cout << "Nombre: " << y->getNombre() << " Apellido: " << y->getApellido() << "\n";
                cout << "Estado de cuenta: " << y->getEstado() << "\n";
                cout << "Clase: " << y->getClase() << "\n";
                cout << "Saldo actual: $" << y->getCaja() << "\n";
                cout << "Fecha de creacion de la cuenta: " << y->getDia() << "/" << y->getMes() << "/" << y->getAnio() << "\n";
                cout << "------------------------------------------------------------------------------------------\n\n";
            }

            break;
        case 3:
            w = 0;
            p = C.size();
            for (int i = 0; i < p; i++)
            {
                Cliente *y = &C[i];
                if (y->transaccion.size() != 0)
                {
                    w = 1;
                }
            }
            if (w == 1)
            {
                for (int i = 0; i < p; i++)
                {

                    Cliente *y = &C[i];
                    q = y->transaccion.size();
                    remove("transacciones.txt");
                    for (int j = 0; j < q; j++)
                    {
                        
                        transacciones.open("transacciones.txt", ios::app);
                        transacciones << "Transaccion nro: " << y->transaccion[j].getNumeroTransaccion();
                        transacciones << "     Cantidad: " << y->transaccion[j].getCaja();
                        transacciones << "     Tipo: " << y->transaccion[j].getClase();
                        transacciones << "     Dia: " << y->transaccion[j].getDia();
                        transacciones << "     Mes: " << y->transaccion[j].getMes();
                        transacciones << "     Anio: " << y->transaccion[j].getAnio() << "\n";
                        transacciones << "     Cliente: " << y->getNombre() << " " << y->getApellido() << "\n";
                        transacciones << "------------------------------------------------------------------------------------------\n\n";

                        cout << "Transaccion nro: " << y->transaccion[j].getNumeroTransaccion();
                        cout << "     Cantidad: " << y->transaccion[j].getCaja();
                        cout << "     Tipo: " << y->transaccion[j].getClase();
                        cout << "     Dia: " << y->transaccion[j].getDia();
                        cout << "     Mes: " << y->transaccion[j].getMes();
                        cout << "     Anio: " << y->transaccion[j].getAnio() << "\n";
                        cout << "     Cliente: " << y->getNombre() << " " << y->getApellido() << "\n";
                        cout << "------------------------------------------------------------------------------------------\n\n";
                    }
                }

                break;
            }
            else
                cout << "\n\n**Aun no se han realizado transacciones**\n\n";
        case 4:
            cout << "Saliendo del menu de consultas...\n";
            llave = true;
            break;

        default:
            cout << "Opcion no valida...\n";
            break;
        }

    } while (llave == false);
} // Funciona

int main()
{
    int n, p, q, x, nro = 0;
    string m;
    Banco b;
    vector<Cliente> C;
    bool llave = false;
    cout << "INICIANDO SISTEMA BANCARIO...\n\n\n";
    cout << "----BIENVENIDO AL SISTEMA BANCARIO DE UCC----\n\n";
    do
    {
        if (C.size() == 0)
        {
            PrimerIngreso(C);
        }
        cout << "\n\n--MENU PRINCIPAL--\n";
        cout << "Que desea hacer?\n1-Mantenimiento de cuentas\n2-Menu TRANSACCIONES\n3-Menu Consultas varias\n4-Salir\n";
        cin >> x;
        switch (x)
        {
        case 1:
            Estado(C);
            MenuMantenimiento(C);
            break;
        case 2:
            MenuTransacciones(C, nro);
            break;
        case 3:
            MenuConsultas(C, nro);
            break;
        case 4:
            llave = true;
            cout << "\n\nGracias por utilizar nuestro sistema...\n";
            cout << "Saliendo del sistema...\n";
            break;
        default:
            cout << "Opcion no valida...\n";
            break;
        }
    } while (llave == false);

    return 0;
}