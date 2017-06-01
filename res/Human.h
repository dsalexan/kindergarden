//
// Created by Danilo on 31/05/2017.
//

#ifndef KINDERGARGEN_HUMAN_H
#define KINDERGARGEN_HUMAN_H

#include <GL/glu.h>
#include <GL/glut.h>
#include "../util/Vectors.h"

typedef struct structHuman{
    GLUquadric* object;

    Vector mass_center;

    float height; // cm
} Human;

void human_make(Human *self, Vector position);
void human_draw(Human self);

void human_kill(Human *self);

#endif //KINDERGARGEN_HUMAN_H
