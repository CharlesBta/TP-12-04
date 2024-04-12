#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int ID = 0;

typedef struct Correspondence {
    int id;
    struct Correspondence *next;
} Correspondence;

typedef struct Line {
    int id;
    int correspondences[50];
//    Correspondence *correspondences;
} Line;

int nbLignes = 3;
Line lignes[3];

Line ajouterLigne(int listeCorrespondences[], int nbCorrespondences) {
    Line newLine = (Line) {.id = ID};
    for (int i = 0; i < 50; ++i) {
        newLine.correspondences[i] = -1;
    }

    for (int i = 0; i < nbCorrespondences; ++i) {
        int index = 0;
        while (newLine.correspondences[index] != -1) {
            index++;
        }
        newLine.correspondences[index] = listeCorrespondences[i];
    }
    return newLine;
}

void GPS(Line depart, Line arrive) {
    int nbArrets;
    for (int i = 0; i < 3; i++) {
        bool found = false;
        for (int j = 0; j < 50; ++j) {
            if (found)
                break;
            if (lignes[i].correspondences[j] == arrive.id) {
                printf("next : %d\n", lignes[i].correspondences[j]);
                found = true;
                printf("found!\n");
                return;
            } else {
                for (int k = 0; k < 50; ++k) {
                    if (lignes[i].correspondences[k] == arrive.id) {
                        printf("next1 : %d\n", lignes[i].correspondences[j]);
                        found = true;
                        break;
                    }
                }
            }
        }
    }
}


int main() {
    lignes[0] = ajouterLigne((int[]) {1}, 2);
    lignes[1] = ajouterLigne((int[]) {0}, 1);
    lignes[2] = ajouterLigne((int[]) {1}, 1);

    GPS(lignes[2], lignes[0]);

    return 0;
}
