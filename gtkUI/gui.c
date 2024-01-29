#include "gui.h"

static void startup(GtkApplication *app);
static void activate(GtkApplication *app, gpointer user_data);
static void btn(GtkWidget *widget, gpointer user_data);
static void menuClicked(GSimpleAction *action, GVariant *parameter, gpointer user_data);
static void handleModeButtonClick(GtkWidget *widget, gpointer user_data);
void* subthread(void *arg);

int main(int argc, char *argv[]){
    GtkApplication *app;
    int status;

    app = gtk_application_new ("tech.xiaoran.dml", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "startup", G_CALLBACK (startup), NULL);
    g_signal_connect(app, "activate", G_CALLBACK (activate), NULL);
    status = g_application_run (G_APPLICATION (app), argc, argv);
    g_object_unref (app);

    return status;

}

static void startup(GtkApplication *app){
    GtkBuilder *menubarBuilder;
    menubarBuilder = gtk_builder_new_from_resource("/tech/xiaoran/dml/menubar.xml");

    GSimpleAction *action_open, *action_quit;
    action_open = g_simple_action_new("open", NULL);
    action_quit = g_simple_action_new("quit", NULL);
    g_action_map_add_action(G_ACTION_MAP(app), G_ACTION(action_open));
    g_action_map_add_action(G_ACTION_MAP(app), G_ACTION(action_quit));
    g_signal_connect(G_OBJECT(action_open), "activate", G_CALLBACK(menuClicked), NULL);
    g_signal_connect(G_OBJECT(action_quit), "activate", G_CALLBACK(menuClicked), NULL);

    gtk_application_set_menubar(app, G_MENU_MODEL(gtk_builder_get_object(menubarBuilder, "menubar")));
    g_object_unref(menubarBuilder);
}

static void activate(GtkApplication *app, gpointer user_data){
    GtkBuilder *builder;
    GtkWidget *window;
    
    builder = gtk_builder_new_from_resource("/tech/xiaoran/dml/ui.xml");
    
    window = GTK_WIDGET(gtk_builder_get_object(builder, "window"));
    
    gtk_window_set_application(GTK_WINDOW(window), app);
    

    GtkWidget *progressbar1, *progressbar2, *progressbar3, *progressbar4, *progressbar5, *progressbar6, *progressbar7, *progressbar8;
    progressbar1 = GTK_WIDGET(gtk_builder_get_object(builder, "p1"));
    progressbar2 = GTK_WIDGET(gtk_builder_get_object(builder, "p2"));

    GtkWidget *label1, *label2;
    label1 = GTK_WIDGET(gtk_builder_get_object(builder, "pl1"));
    label2 = GTK_WIDGET(gtk_builder_get_object(builder, "pl2"));
    
    mode_data *seq;
    seq = (mode_data*) malloc(sizeof(mode_data));
    seq->readProgressBar = progressbar1;
    seq->writeProgressBar = progressbar2;
    seq->readLabel = label1;
    seq->writeLabel = label2;
    seq->mode = "SEQ";

    GtkWidget *btn1;
    btn1 = GTK_WIDGET(gtk_builder_get_object(builder, "mode_button1"));
    

    g_signal_connect(btn1, "clicked", G_CALLBACK(handleModeButtonClick), seq);

    
    GtkCssProvider *css_provider = gtk_css_provider_new();
    gtk_css_provider_load_from_resource(GTK_CSS_PROVIDER(css_provider), "/tech/xiaoran/dml/style.css");

    GtkStyleContext *context = gtk_widget_get_style_context(window);
    gtk_style_context_add_provider_for_display(gtk_style_context_get_display(context), GTK_STYLE_PROVIDER(css_provider), GTK_STYLE_PROVIDER_PRIORITY_USER);

    g_object_unref(css_provider);
    g_object_unref(builder);

    gtk_window_present (GTK_WINDOW (window));
}


static void btn(GtkWidget *widget, gpointer user_data){
    g_print("Button clicked\n");
    gdouble fraction = gtk_progress_bar_get_fraction(GTK_PROGRESS_BAR(user_data));
    fraction += 0.1;
    if (fraction > 1.0){
        fraction = 0.0;
    }
    gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(user_data), fraction);
}

static void menuClicked(GSimpleAction *action, GVariant *parameter, gpointer user_data){
    g_print("Menu clicked, action: %s\n", g_action_get_name(G_ACTION(action)));
}

static void handleModeButtonClick(GtkWidget *widget, gpointer user_data){
    mode_data *data = (mode_data*) user_data;
    g_print("Mode: %s\n", data->mode);
    gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(data->readProgressBar), 0.0);
    gtk_label_set_label(GTK_LABEL(data->readLabel), "0.00");
    gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(data->writeProgressBar), 0.0);
    gtk_label_set_label(GTK_LABEL(data->writeLabel), "0.00");
    pthread_t thread;
    pthread_create(&thread, NULL, subthread, user_data);
}

void* subthread(void *arg){
    mode_data *data = (mode_data*) arg;
    sleep(1);
    gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(data->readProgressBar), 0.88);
    gtk_label_set_label(GTK_LABEL(data->readLabel), "892.63");
    sleep(1);
    gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(data->writeProgressBar), 0.66);
    gtk_label_set_label(GTK_LABEL(data->writeLabel), "636.23");
}