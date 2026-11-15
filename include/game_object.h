/* game_object.h */
#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

// Define GameObject Instance
typedef struct {
  float xPosition;
  float yPosition;
  float velocityX;
  float velocityY;
  float acceleration;
  float rotation;
} GameObject;

#endif /* game_object.h */