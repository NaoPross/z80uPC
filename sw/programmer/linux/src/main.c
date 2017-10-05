#include "config.h"
#include "ui.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <errno.h>

void out(const char *msg)
{
    printf("%s", msg);
}

int main(int argc, char *argv[])
{
    int opt;
    int use_ui = 0;

    unsigned long baudrate;
    char *file, *device, *baud;

    file = device = baud = NULL;

    while ((opt = getopt(argc, argv, "gf:d:b:")) != -1) {
        switch (opt) {
        case 'g':
            use_ui = 1;
            break;
        case 'f':
            file = optarg;
            break;
        case 'd':
            device = optarg;
            break;
        case 'b':
            baud = optarg;
            break;
        }
    }

    if (use_ui) {
        ui_init(&argc, &argv);
        return 0;
    }

    if (file == NULL || device == NULL || baud == NULL) {
        perror("Missing argument\n");
        return -1;
    }

    baudrate = strtoul(baud, NULL, 0);
    if (errno == ERANGE) {
        perror("Invalid baudrate\n");
        return -1;
    }

    if (flash_open(device, baudrate) < 0) {
        perror("Failed to open device\n");
        return -2;
    }

    flash_write(file, out);
    flash_close();

    return 0;
}
