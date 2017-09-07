#include "ui.h"

static bool ui_connected, ui_fileset;
static GtkBuilder *ui_builder;

void ui_init(int *argc, char **argv[])
{
    GtkWindow *window;
    GtkFileChooserButton *filechoosebtn;
    GtkButton *connectbtn, *flashbtn;

    ui_connected = ui_fileset = false;

    gtk_init(argc, argv);

    ui_builder = gtk_builder_new();
    gtk_builder_add_from_file(ui_builder, "z80prog.ui", NULL);

    /* connect objects to callbacks */
    window = GTK_WINDOW(gtk_builder_get_object(ui_builder, "window"));
    g_signal_connect(window, "delete_event", G_CALLBACK(flash_close), NULL);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    connectbtn = GTK_BUTTON(gtk_builder_get_object(ui_builder, "connectbtn"));
    g_signal_connect(connectbtn, "clicked", G_CALLBACK(ui_connect_clicked), NULL);

    flashbtn = GTK_BUTTON(gtk_builder_get_object(ui_builder, "flashbtn"));
    g_signal_connect(flashbtn, "clicked", G_CALLBACK(ui_flash_clicked), NULL);

    filechoosebtn = GTK_FILE_CHOOSER_BUTTON(gtk_builder_get_object(ui_builder, "filechoosebtn"));
    g_signal_connect(filechoosebtn, "file-set", G_CALLBACK(ui_file_set), NULL);

    /* start gtk window */
    gtk_main();
}

void ui_log(const char *msg) 
{
    GtkTextIter end;
    GtkTextView *ui_log;

    static GtkTextBuffer *ui_logbuf = NULL; 

    ui_log = GTK_TEXT_VIEW(gtk_builder_get_object(ui_builder, "logview"));

    if (ui_logbuf == NULL) {
        ui_logbuf = gtk_text_buffer_new(NULL);
        gtk_text_view_set_buffer(ui_log, ui_logbuf);
    }

    gtk_text_buffer_get_end_iter(ui_logbuf, &end);
    gtk_text_buffer_insert(ui_logbuf, &end, msg, -1);
    gtk_text_view_scroll_to_iter(ui_log, &end, .0, TRUE, .0, .1);
}

void ui_check_enable_flashbtn(void)
{
    GtkWidget *ui_flashbtn = GTK_WIDGET(gtk_builder_get_object(ui_builder, "flashbtn"));

    if (ui_connected && ui_fileset) 
        gtk_widget_set_sensitive(ui_flashbtn, TRUE);
    else
        gtk_widget_set_sensitive(ui_flashbtn, FALSE); 
}

void ui_file_set(GtkFileChooserButton *btn, gpointer user_data)
{
    GtkEntry *filepath = GTK_ENTRY(gtk_builder_get_object(ui_builder, "filepath"));

    gtk_entry_set_text(filepath, gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(btn)));
    ui_log(UI_LOG_MSG "file set\n");
    ui_fileset = true;

    ui_check_enable_flashbtn();
}

void ui_connect_clicked(void) 
{
    GtkEntry *ui_devpath = GTK_ENTRY(gtk_builder_get_object(ui_builder, "devpath"));
    GtkSpinButton *ui_baudrate = GTK_SPIN_BUTTON(gtk_builder_get_object(ui_builder, "devbaudrate"));
    GtkButton *ui_connectbtn = GTK_BUTTON(gtk_builder_get_object(ui_builder, "connectbtn"));

    unsigned long baudrate = gtk_spin_button_get_value_as_int(ui_baudrate);
    const char *devpath = gtk_entry_get_text(ui_devpath);

    if (flash_open(devpath, baudrate) != 0) {
        ui_log(UI_LOG_ERR "failed to open serial device\n");
    } else {
        ui_connected = true;
        ui_log(UI_LOG_MSG "connected to serial device ");
        ui_log(devpath);
        ui_log("\n");

        g_signal_handlers_disconnect_by_func(ui_connectbtn, G_CALLBACK(ui_connect_clicked), NULL);
        g_signal_connect(ui_connectbtn, "clicked", G_CALLBACK(ui_disconnect_clicked), NULL);

        gtk_button_set_label(ui_connectbtn, "gtk-disconnect");
        ui_check_enable_flashbtn();
    }
}

void ui_disconnect_clicked(void)
{
    GtkButton *ui_connectbtn = GTK_BUTTON(gtk_builder_get_object(ui_builder, "connectbtn"));

    flash_close();

    ui_connected = false;
    ui_log(UI_LOG_MSG "disconnected\n");

    g_signal_handlers_disconnect_by_func(ui_connectbtn, G_CALLBACK(ui_disconnect_clicked), NULL);
    g_signal_connect(ui_connectbtn, "clicked", G_CALLBACK(ui_connect_clicked), NULL);

    gtk_button_set_label(ui_connectbtn, "gtk-connect");
    ui_check_enable_flashbtn();
}

int ui_flash_write_start(void *ptr)
{
    const char *filepath = (const char *) ptr;

    flash_write(filepath, ui_log);
    ui_check_enable_flashbtn();

    return 0;
}

void ui_flash_clicked(void)
{
    GtkWidget *ui_flashbtn = GTK_WIDGET(gtk_builder_get_object(ui_builder, "flashbtn"));
    GtkEntry *ui_filepath = GTK_ENTRY(gtk_builder_get_object(ui_builder, "filepath"));

    const char *filepath = gtk_entry_get_text(ui_filepath);

    gdk_threads_add_idle_full(
        G_PRIORITY_HIGH_IDLE,
        ui_flash_write_start,
        (void *) filepath,
        NULL
    );

    gtk_widget_set_sensitive(ui_flashbtn, FALSE);
}
