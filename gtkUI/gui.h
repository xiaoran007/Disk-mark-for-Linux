#include <gtk/gtk.h>

typedef struct {
    GtkWidget *readProgressBar;
    GtkWidget *writeProgressBar;
    GtkWidget *readLabel;
    GtkWidget *writeLabel;
    gchar *mode;
} mode_data;
