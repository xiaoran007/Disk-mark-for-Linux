#include <gtk/gtk.h>

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
