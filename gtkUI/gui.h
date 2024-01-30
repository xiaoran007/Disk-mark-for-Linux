#include <gtk/gtk.h>

#ifndef _GUI_H
#define GUI_H_

#if GLIB_CHECK_VERSION(2, 74, 0)
#define DEAFULT_FLAG G_APPLICATION_DEFAULT_FLAGS
#else
#define DEAFULT_FLAG G_APPLICATION_FLAGS_NONE
#endif

typedef struct {
    GtkWidget *readProgressBar;
    GtkWidget *writeProgressBar;
    GtkWidget *readLabel;
    GtkWidget *writeLabel;
    gchar *mode;
} mode_data;


void startup(GtkApplication *app);
void activate(GtkApplication *app, gpointer user_data);
static void btn(GtkWidget *widget, gpointer user_data);
static void menuClicked(GSimpleAction *action, GVariant *parameter, gpointer user_data);
static void handleModeButtonClick(GtkWidget *widget, gpointer user_data);
void* subthread(void *arg);

#endif
