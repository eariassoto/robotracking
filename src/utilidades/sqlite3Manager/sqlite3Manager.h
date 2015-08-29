#pragma once
#include "sqlite3.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

/// Maneja la interacción con la base de datos SQLite
/**
	SQLite es un sistema que implementa un motor SQL para manejar una base de datos
	local. Esta clase engloba las operaciones necesarias para interactuar con un sistema
	sqlite3 de forma amigable. No están implementadas todas las funcionalidades que SQLite
	ofrece, sin embargo se motiva a que esta clase sea extendida y reutilizada.

	Para más información visitar https://www.sqlite.org/ y http://www.tutorialspoint.com/sqlite/sqlite_c_cpp.htm
	para una mejor referencia del API C/C++.

	Para crear y poblar la base de datos es mucho más cómodo utilizar una herramienta de terceros para
	armar las tablas e insertar datos en un ambiente al estilo DBMS. Se recomienda el uso de la herramienta
	SQLiteSpy
*/
class sqlite3Manager{

public:

	/// Constructor de la clase
	/**
		Dado un archivo con formado SQLite lo abre para poder ejecutar operaciones sobre la base de datos.

		\param dbLocation Lugar dentro del proyecto donde se encuentra ubicada la base de datos.
	*/
	sqlite3Manager(char*);

	/// Destructor de la clase
	/**
		Cierra la referencia a la base de datos.
	*/
	~sqlite3Manager();

	/// Ejecuta una sentencia SQL
	/**
		Dada una instruccion se asegura que pueda ser ejecuta y la realiza. Si hay filas en la respuesta
		las almacena en una matriz de hileras. Notese que de esta forma todo queda almacenado como hileras.

		\param sql Instrucción para ser ejecutada
		\return Matriz con n filas y m columnas
	*/
	vector<vector<string>> executeStatement(char*);

	/// Imprime una tabla en consola
	void printTable(vector<vector<string>>);

private:

	/// Instancia de la base de datos
	sqlite3 *db;
};