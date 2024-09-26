#include "login_window.h"
#include <iostream>

LoginWindow::LoginWindow() {
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Login");

    GtkWidget *grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(window), grid);

    GtkWidget *usernameLabel = gtk_label_new("Username:");
    usernameEntry = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid), usernameLabel, 0, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), usernameEntry, 1, 0, 1, 1);

    GtkWidget *passwordLabel = gtk_label_new("Password:");
    passwordEntry = gtk_entry_new();
    gtk_entry_set_visibility(GTK_ENTRY(passwordEntry), FALSE);
    gtk_grid_attach(GTK_GRID(grid), passwordLabel, 0, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), passwordEntry, 1, 1, 1, 1);
}

LoginWindow::~LoginWindow() {
    gtk_widget_destroy(window);
}

void LoginWindow::show() {
    gtk_widget_show_all(window);
}

bool LoginWindow::authenticate() {
    const gchar *username = gtk_entry_get_text(GTK_ENTRY(usernameEntry));
    const gchar *password = gtk_entry_get_text(GTK_ENTRY(passwordEntry));

    // Simulação de autenticação
    return (std::string(username) == "admin" && std::string(password) == "password");
}

GtkWidget* LoginWindow::getWindow() {
    return window;
}
