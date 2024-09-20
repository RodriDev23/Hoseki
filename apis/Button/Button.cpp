#include "Button.h"
#include "../Tailwind/tailwind_api.h"
#include <iostream>
#include <ostream>
#include <raylib.h>
using namespace std;

Button::Button() : Div(0.0, 0.0, 10.0, 50.0), clickCallback(nullptr) {}

Button Button::New() { return Button(); }

Button &Button::onHover(typeHover user_interaction) {
  float mouse_x = GetMouseX();
  float mouse_y = GetMouseY();
  Rectangle mouse_rect = {mouse_x, mouse_y, 1, 1};
  Rectangle user_rect = {this->x_position, this->y_position, this->width,
                         this->height}; // Use this->

  if (CheckCollisionRecs(mouse_rect, user_rect)) {
    SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
    cout << "hover here" << endl;
  } else {
    SetMouseCursor(MOUSE_CURSOR_DEFAULT);
  }
  if (CheckCollisionRecs(mouse_rect, user_rect) &&
      IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
    cout << "click it  here" << endl;
    this->backgroundColor = TailwindAPI::gray100;
  }

  return *this; // Return reference to allow chaining
}
