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
    GtkBuilder *builder;
    GtkWidget *window;

    //builder = gtk_builder_new_from_file("ui.xml");
    builder = gtk_builder_new_from_resource("/tech/xiaoran/dml/ui.xml");
    window = GTK_WIDGET(gtk_builder_get_object(builder, "window"));
    gtk_window_set_application(GTK_WINDOW(window), app);

    GtkWidget *progressbar1, *progressbar2;
    progressbar1 = GTK_WIDGET(gtk_builder_get_object(builder, "p1"));
    progressbar2 = GTK_WIDGET(gtk_builder_get_object(builder, "p2"));

    gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(progressbar1), 0.5);
    gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(progressbar2), 0.5);

    GtkCssProvider *css_provider = gtk_css_provider_new();
    //gtk_css_provider_load_from_path(GTK_CSS_PROVIDER(css_provider), "pgb.css");
    gtk_css_provider_load_from_resource(GTK_CSS_PROVIDER(css_provider), "/tech/xiaoran/dml/pgb.css");

    GtkStyleContext *context = gtk_widget_get_style_context(window);
    gtk_style_context_add_provider_for_display(gtk_style_context_get_display(context), GTK_STYLE_PROVIDER(css_provider), GTK_STYLE_PROVIDER_PRIORITY_USER);
    
    

    g_object_unref(css_provider);
    g_object_unref(builder);

    gtk_window_present (GTK_WINDOW (window));
}


static void btn(GtkWidget *widget, gpointer user_data){
    g_print("Button clicked\n");
}
