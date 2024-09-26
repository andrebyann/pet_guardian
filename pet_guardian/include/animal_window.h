#ifndef ANIMAL_WINDOW_H
#define ANIMAL_WINDOW_H

#include <gtk/gtk.h>

class AnimalWindow {
public:
    AnimalWindow();
    ~AnimalWindow();

    void show();
    GtkWidget* getWindow();

private:
    GtkWidget *window;
    GtkWidget *addAnimalButton;
    GtkWidget *deleteAnimalButton;
    GtkWidget *animalList;
};

#endif // ANIMAL_WINDOW_H
