#include "login_window.h"
#include "animal_window.h"
#include "database.h"
#include <gtk/gtk.h>

// Função callback para finalizar a aplicação
static void on_application_exit(GtkWidget *widget, gpointer data) {
    gtk_main_quit();
}

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    // Inicialização do banco de dados
    Database db("animals.db");
    if (!db.open()) {
        return -1; // Falha ao abrir o banco de dados
    }

    db.createTable(); // Cria a tabela se não existir

    // Criação da janela de login
    LoginWindow loginWindow;

    g_signal_connect(loginWindow.getWindow(), "destroy", G_CALLBACK(on_application_exit), NULL);

    // Exibe a janela de login
    loginWindow.show();

    if (loginWindow.authenticate()) {
        // Janela de gerenciamento de animais
        AnimalWindow animalWindow;
        g_signal_connect(animalWindow.getWindow(), "destroy", G_CALLBACK(on_application_exit), NULL);
        animalWindow.show();
    }

    gtk_main();

    db.close();
    return 0;
}
