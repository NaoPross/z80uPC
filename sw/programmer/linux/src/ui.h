#ifndef __Z80PROG_UI_H__
#define __Z80PROG_UI_H_

#include "flash.h"

#include <stdbool.h>
#include <string.h>

#include <gtk/gtk.h>

#define UI_LOG_ERR	"[!] "
#define UI_LOG_WARN	"[#] "
#define UI_LOG_MSG	"[@] "

void ui_init(int *argc, char **argv[]);
void ui_log(const char *msg);
void ui_check_enable_flashbtn(void);

void ui_file_set(GtkFileChooserButton *btn, gpointer user_data);
void ui_connect_clicked(void);
void ui_disconnect_clicked(void);
void ui_flash_clicked(void);

#endif
