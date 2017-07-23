#include "callback.h"
#include <cstdio>

//Función en caso de error
void error_callback(const char *msg, void *client_data) {
    (void)client_data;
}

//Función en caso e warning
void warning_callback(const char *msg, void *client_data) {
    (void)client_data;
}

//Función en caso de información
void info_callback(const char *msg, void *client_data) {
    (void)client_data;
}
