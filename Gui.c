//#include <gtk/gtk.h>
#include"convert.h"
static void on_button_clicked(GtkButton *button,gpointer data);
static void on_entry_activate(GtkEntry *entry,gpointer data);
void create_window(int argc, char *argv[]);


void create_window(int argc, char *argv[])
{
    GtkWidget *window;
    GtkWidget *entry;
    GtkWidget *button;
    GtkWidget *hbox;

    gtk_init(&argc,&argv);
    window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window),"Sugar cups");
    gtk_window_set_position(GTK_WINDOW(window),GTK_WIN_POS_CENTER);
    gtk_container_set_border_width(GTK_CONTAINER(window),5);

    hbox=gtk_box_new(GTK_ORIENTATION_HORIZONTAL,5);
    gtk_container_add(GTK_CONTAINER(window),hbox);

    entry=gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(hbox),entry,TRUE,TRUE,5);

    button=gtk_button_new_with_label("Calculate");
    gtk_box_pack_start(GTK_BOX(hbox),button,FALSE,FALSE,0);

    g_signal_connect(G_OBJECT(window),"destroy",
                G_CALLBACK(gtk_main_quit),NULL);
    g_signal_connect(G_OBJECT(button),"clicked",
                G_CALLBACK(on_button_clicked),entry);
    g_signal_connect(G_OBJECT(entry),"activate",/* when you press ENTER */
                G_CALLBACK(on_entry_activate),NULL);

    gtk_widget_show_all(window);
    gtk_main();

  //  return 0;
}

static void on_button_clicked(GtkButton *button,gpointer data)
{
    GtkWidget *entry=(GtkWidget *)data;
    GtkWidget *dialog;
    gchar buff[1024];
     int grams = atoi(gtk_entry_get_text(GTK_ENTRY(entry)));
double cups = equation_s(grams);
    g_snprintf(buff,1024,"you need %0.2lf cups!",
                cups);

    dialog=gtk_message_dialog_new(NULL,GTK_DIALOG_MODAL,
                GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"%s",buff);
    gtk_dialog_run(GTK_DIALOG(dialog));

    gtk_widget_destroy(dialog);
    gtk_entry_set_text(GTK_ENTRY(entry),"");
}

static void on_entry_activate(GtkEntry *entry,gpointer data)
{
    g_print("%s\n",gtk_entry_get_text(GTK_ENTRY(entry)));
}




