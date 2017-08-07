#include "ui.h"

static bool ui_connected, ui_fileset;
static GtkTextBuffer *ui_logbuf;
static GtkBuilder *ui_builder;

void ui_init(int *argc, char **argv[])
{
    GtkWindow *window;
    GtkTextView *logview;
    GtkFileChooserButton *filechoosebtn;
    GtkButton *connectbtn, *flashbtn;

    /* set ui global variables */
    ui_connected = ui_fileset = false;

    /* start gtk */
    gtk_init(argc, argv);

    /* load glade gtk ui */
    ui_builder = gtk_builder_new();
    gtk_builder_add_from_file(ui_builder, "gbprog.ui", NULL);

    /* connect logger buffer (extern variable) */
    ui_logbuf = gtk_text_buffer_new(NULL);
    logview = GTK_TEXT_VIEW(gtk_builder_get_object(ui_builder, "logview"));

    gtk_text_view_set_buffer(logview, ui_logbuf);

    /* connect objects to function calls */
    // window
    window = GTK_WINDOW(gtk_builder_get_object(ui_builder, "window"));
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // connectbtn 
    connectbtn = GTK_BUTTON(gtk_builder_get_object(ui_builder, "flashbtn"));
    g_signal_connect(connectbtn, "clicked", 
                        G_CALLBACK(ui_connect_clicked), NULL);

    // flashbtn
    flashbtn = GTK_BUTTON(gtk_builder_get_object(ui_builder, "flashbtn"));
    g_signal_connect(flashbtn, "clicked", G_CALLBACK(ui_flash_clicked), NULL);

    // file chooser
    filechoosebtn = GTK_FILE_CHOOSER_BUTTON(
            gtk_builder_get_object(ui_builder, "filechoosebtn"));
    g_signal_connect(filechoosebtn, "file-set", G_CALLBACK(ui_file_set), NULL);

    /* start gtk window */
    gtk_main();
}

void ui_log(const char *msg, char type) 
{
    GtkTextIter end;
    gchar typech[4] = "[ ] ";

    switch (type) {
        case 'm': typech[1] = '@'; break; // message
        case 'w': typech[1] = '#'; break; // warning
        case 'e': typech[1] = '!'; break; // error
    }

    gtk_text_buffer_get_end_iter(ui_logbuf, &end);
    gtk_text_buffer_insert(ui_logbuf, &end, typech, 4);
    gtk_text_buffer_get_end_iter(ui_logbuf, &end);
    gtk_text_buffer_insert(ui_logbuf, &end, (const gchar *) msg, strlen(msg));
}

void ui_file_set(GtkFileChooserButton *btn, gpointer user_data)
{
    GtkEntry *filepath = 
            GTK_ENTRY(gtk_builder_get_object(ui_builder, "filepath"));

    gtk_entry_set_text(filepath, 
            gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(btn)));

    ui_log("File set\n", 'm');
    ui_fileset = true;
}

void ui_connect_clicked(void) 
{

}

void ui_flash_clicked(void)
{

}
