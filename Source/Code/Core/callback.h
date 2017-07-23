#ifndef IMAGECOMPRESSIONMERGE_CALLBACK_H
#define IMAGECOMPRESSIONMERGE_CALLBACK_H

//Función en caso de error
void error_callback(const char *msg, void *client_data);

//Función en caso e warning
void warning_callback(const char *msg, void *client_data);

//Función en caso de información
void info_callback(const char *msg, void *client_data);

#endif //IMAGECOMPRESSIONMERGE_CALLBACK_H
