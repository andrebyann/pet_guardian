#include "animal_window.h"

AnimalWindow::AnimalWindow() {
    // Cria a janela de gerenciamento de animais
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Gerenciamento de Animais");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 300);

    GtkWidget *label = gtk_label_new("Bem-vindo ao gerenciamento de animais!");
    gtk_container_add(GTK_CONTAINER(window), label);
}

AnimalWindow::~AnimalWindow() {
    gtk_widget_destroy(window);
}

void AnimalWindow::show() {
    gtk_widget_show_all(window);
}

GtkWidget* AnimalWindow::getWindow() {
    return window;
}
