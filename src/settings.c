#include <SDL3/SDL.h>
#include "tomlc17.h"
#include "settings.h"

int parseAndUpdateSettings(GameSettings *settings) {
  
  // Parse settings file
  toml_result_t tomlResult = toml_parse_file_ex("settings.toml");
  if (!tomlResult.ok) {
    SDL_Log("Could not parse settings.toml file: %s\n", tomlResult.errmsg);
    toml_free(tomlResult);
    return 1;
  }
  
  // Update each setting from the parsed document tree
  toml_datum_t settingsWidth = toml_seek(tomlResult.toptab, "window.width");
  if (settingsWidth.type == TOML_INT64) {
      settings->windowWidth = settingsWidth.u.int64;
  }

  toml_datum_t settingsHeight = toml_seek(tomlResult.toptab, "window.height");
  if (settingsHeight.type == TOML_INT64) {
      settings->windowHeight = settingsHeight.u.int64;
  }

  toml_datum_t settingsFullscreen = toml_seek(tomlResult.toptab, "window.isFullscreen");
  if (settingsFullscreen.type == TOML_BOOLEAN) {
      settings->isFullscreen = settingsFullscreen.u.boolean;
  }

  toml_datum_t settingsTargetFPS = toml_seek(tomlResult.toptab, "graphics.targetFPS");
  if (settingsTargetFPS.type == TOML_INT64) {
      settings->targetFPS = settingsTargetFPS.u.int64;
  }
  
  // Free the document tree after use
  toml_free(tomlResult);

  return 0;
}
