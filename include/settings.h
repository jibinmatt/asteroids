/* settings.h */
#ifndef SETTINGS_H
#define SETTINGS_H

#include <stdbool.h>

// Define GameSettings Instance
typedef struct {
  int windowWidth;
  int windowHeight;
  bool isFullscreen;
  int targetFPS;
} GameSettings;

extern int parseAndUpdateSettings(GameSettings *settings);

#endif /* settings.h */