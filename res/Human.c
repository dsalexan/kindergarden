//
// Created by Danilo on 31/05/2017.
//

#include "Human.h"

#define HUMAN_WIDTH 20.f
#define HUMAN_DEPTH 45.f
#define UPPER_CHEST_PROPORTION 0.25f
#define LOWER_CHEST_PROPORTION 0.125f

void human_make(Human *self, Vector position){
    self->object = gluNewQuadric();
    gluQuadricNormals(self->object, GLU_SMOOTH);

    vector_new(&(self->mass_center));
    self->mass_center.x = position.x;
    self->mass_center.y = position.y;
    self->mass_center.z = position.z;

    self->height = 180.f;
}

void human_draw(Human self){
    Vector pos;
    float h, w, d;

    vector_copy(&pos, self.mass_center);

    glTranslatef(pos.x,pos.y, pos.z);
    glColor3ub(255, 255, 255);

    // UPPER CHEST BOX
    h = self.height * UPPER_CHEST_PROPORTION;
    w = HUMAN_WIDTH / h;
    d = HUMAN_DEPTH / h;

    glPushMatrix();
    glTranslatef(0, -(h/2.f), 0);
    glScalef(w, 1, d);
    glutWireCube(h);
    glPopMatrix();

    // LOWER CHEST BOX
    h = self.height * LOWER_CHEST_PROPORTION;
    w = HUMAN_WIDTH / h;
    d = HUMAN_DEPTH / h;

    glPushMatrix();
    glTranslatef(0, (h/2.f), 0);
    glScalef(w, 1, d);
    glutWireCube(h);
    glPopMatrix();

}

void human_kill(Human *self){
    gluDeleteQuadric(self->object);
    free(self);
}