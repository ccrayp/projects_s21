#ifndef LOGGER_H
#define LOGGER_H

#include <time.h>

typedef enum {
    DEBUG,
    INFO,
    WARNING,
    ERROR
} log_level_types;

void init_log(const char *filename);
void cat_log(log_level_types level, const char *message);
void close_log();

#endif
