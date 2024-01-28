#include "gui.h"

static void activate(GtkApplication *app, gpointer user_data);
static void btn(GtkWidget *widget, gpointer user_data);

int main(int argc, char *argv[]){
    GtkApplication *app;
    int status;

    app = gtk_application_new ("tech.xiaoran.dml", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK (activate), NULL);
    status = g_application_run (G_APPLICATION (app), argc, argv);
    g_object_unref (app);

    return status;

}


static void activate(GtkApplication *app, gpointer user_data){
    GtkWidget *window;
    GtkWidget *progressbar, *progressbar2;
    GtkWidget *button;
    GtkStyleContext *context;

    GtkCssProvider *css_provider = gtk_css_provider_new();
    gtk_css_provider_load_from_path(GTK_CSS_PROVIDER(css_provider), "pgb.css");

    window = gtk_application_window_new (app);
    gtk_window_set_title (GTK_WINDOW (window), "DML");
    gtk_window_set_default_size (GTK_WINDOW (window), 600, 600);
    gtk_window_set_resizable (GTK_WINDOW (window), FALSE);

    progressbar = gtk_progress_bar_new();
    //gtk_widget_set_name(progressbar, "progressbar");
    
    gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(progressbar), 0.5);
    //gtk_progress_bar_set_text(GTK_PROGRESS_BAR(progressbar), "Loading...");
    //gtk_progress_bar_set_show_text(GTK_PROGRESS_BAR(progressbar), TRUE);
    //gtk_progress_bar_set_ellipsize(GTK_PROGRESS_BAR(progressbar), PANGO_ELLIPSIZE_MIDDLE);
    GtkWidget *overlay = gtk_overlay_new();
    gtk_overlay_set_child(GTK_OVERLAY(overlay), progressbar);
    GtkWidget *label = gtk_label_new("Loading...");
    gtk_widget_add_css_class(label, "my_label");
    gtk_overlay_add_overlay(GTK_OVERLAY(overlay), label);


    progressbar2 = gtk_progress_bar_new();
    //gtk_widget_set_name(progressbar, "progressbar");
    
    gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(progressbar2), 0.5);
    gtk_progress_bar_set_text(GTK_PROGRESS_BAR(progressbar2), "Loading...");
    gtk_progress_bar_set_show_text(GTK_PROGRESS_BAR(progressbar2), TRUE);
    gtk_progress_bar_set_ellipsize(GTK_PROGRESS_BAR(progressbar2), PANGO_ELLIPSIZE_MIDDLE);
    
    

    button = gtk_button_new_with_label("Start");

    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_window_set_child (GTK_WINDOW (window), box);
    gtk_box_append(GTK_BOX(box), overlay);
    gtk_box_append(GTK_BOX(box), button);
    gtk_box_append(GTK_BOX(box), progressbar2);

    context = gtk_widget_get_style_context(window);
    //gtk_style_context_add_provider(context, GTK_STYLE_PROVIDER(css_provider), GTK_STYLE_PROVIDER_PRIORITY_USER);
    gtk_style_context_add_provider_for_display(gtk_style_context_get_display(context), GTK_STYLE_PROVIDER(css_provider), GTK_STYLE_PROVIDER_PRIORITY_USER);
    
    

    g_object_unref(css_provider);

    gtk_window_present (GTK_WINDOW (window));

    g_print("%s\n", gtk_widget_get_css_name(progressbar));
}

static void btn(GtkWidget *widget, gpointer user_data){
    g_print("Button clicked\n");
}
