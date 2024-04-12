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
    ID++;
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
    for (int i = depart.correspondences[0]; i < 3; i = depart.correspondences[i+1]) {
//        printf("%d\n",i);
        bool found = false;
        for (int j = 0; j < 3; ++j) {
            if (found)
                break;
//            printf("%d :: %d\n", lignes[i].correspondences[j], arrive.id);
            if (lignes[i].id == arrive.id) {
                printf("next : %d\n", lignes[i].id);
                found = true;
                printf("found!\n");
                return;
            } else {
                for (int k = lignes[i].correspondences[0]; k < 3; k = lignes[i].correspondences[k+1]) {

                    if (lignes[i].correspondences[k] == arrive.id) {
                        found = true;
                        printf("next: %d\n", lignes[i].id);
                        break;
                    }
                }
            }
        }
    }
}


int main() {
    lignes[0] = ajouterLigne((int[]) {1,2}, 1);
    lignes[1] = ajouterLigne((int[]) {0}, 1);
    lignes[2] = ajouterLigne((int[]) {1}, 1);

    printf("2->0\n");
    GPS(lignes[2], lignes[0]);
    printf("\n0->1\n");
    GPS(lignes[0], lignes[1]);
    printf("\n2->1\n");
    GPS(lignes[2], lignes[1]);
    printf("\n1->0\n");
    GPS(lignes[1], lignes[0]);

    return 0;
}
