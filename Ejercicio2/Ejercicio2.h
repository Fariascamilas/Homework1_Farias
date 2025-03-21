#pragma once

#include <string>
using namespace std;

enum messages{DEBUG = 1, INFO, WARNING, ERROR, CRITICAL};

/**
 * @brief Registra un mensaje en el archivo de log con un nivel de severidad específico
 * 
 * @param message Mensaje a registrar en el log
 * @param severity_level Nivel de severidad del mensaje (DEBUG, INFO, WARNING, ERROR, CRITICAL)
 * 
 * Escribe un mensaje en el archivo "LogSystem.txt" con el formato:
 * [NIVEL_SEVERIDAD]<mensaje>
 */
void logMessage(string message, int severity_level);

/**
 * @brief Registra un mensaje de error en el archivo de log con información del nombre 
 * del archivo y numero de línea
 * 
 * @param error_message Mensaje de error a registrar
 * @param archive Nombre del archivo donde ocurrió el error
 * @param code_line Número de línea donde ocurrió el error
 * 
 * Escribe un mensaje de error en el archivo "LogSystem.txt" con el formato:
 * [ERROR]<mensaje> archive: nombre_archivo, line: número_línea
 */
void logMessage(string error_message,string archive,int code_line);

/**
 * @brief Registra un mensaje de seguridad en el archivo de log con información del usuario
 * 
 * @param acces_message Mensaje relacionado con el acceso a registrar
 * @param username Nombre del usuario involucrado en el evento de seguridad
 * 
 * Escribe un mensaje de seguridad en el archivo "LogSystem.txt" con el formato:
 * [SECUTRITY]<mensaje> user: nombre_usuario
 */
void logMessage(string acces_message,string username);