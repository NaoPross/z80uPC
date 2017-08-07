#ifndef __Z80PROG_UI_H__
#define __Z80PROG_UI_H_

#include <stdbool.h>
#include <string.h>

#include <gtk/gtk.h>

void ui_init(int *argc, char **argv[]);
void ui_log(const char *msg, char type);

void ui_file_set(GtkFileChooserButton *btn, gpointer user_data);

void ui_connect_clicked(void);
void ui_flash_clicked(void);

#endif
