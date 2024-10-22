#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "logger.h"
#include "log_levels.h"

static FILE *logging_file = NULL;

void init_log(const char *filename) {
    logging_file = fopen(filename, "a");
    if (logging_file == NULL) {
    }
}

void cat_log(log_level_types level, const char *message) {
    if (logging_file == NULL) {
        return;
    }

    const char *level_str[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    time_t now = time(NULL);
    struct tm *local_time = localtime(&now);
    fprintf(logging_file, "[%s] [%02d:%02d:%02d] %s\n",
            level_str[level],
            local_time->tm_hour, local_time->tm_min, local_time->tm_sec,
            message);
}

void close_log() {
    if (logging_file != NULL) {
        fclose(logging_file);
        logging_file = NULL;
    }
}
