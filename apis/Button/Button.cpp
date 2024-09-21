#include "Button.h"
#include "../Tailwind/tailwind_api.h"
#include <raylib.h>
using namespace std;

Button::Button()
    : x_position(20.0), y_position(20.0), width(150), height(25),
      backgroundColor(WHITE), borderColor(BLACK), borderWidth(1.0), padding(1),
      color_text(BLACK) {}

Button Button::New() { return Button(); }

Button &Button::setPosition(float x_pos, float y_pos) {
  x_position = x_pos;
  y_position = y_pos;
  return *this;
}

Button &Button::setSize(float width_u, float height_u) {
  width = width_u;
  height = height_u;
  return *this;
}

Button &Button::setBackgroundColor(Color color_user) {
  backgroundColor = color_user;
  return *this;
}

Button &Button::setBorderColor(Color color_u) {
  borderColor = color_u;
  return *this;
}

Button &Button::setBorderWidth(float border_w_u) {
  borderWidth = border_w_u;
  return *this;
}

Button &Button::setText(string user_value, Color color_text_user) {
  value = user_value;
  color_text = color_text_user;
  return *this;
}

Button &Button::onHover() {
  float mouse_x = GetMouseX();
  float mouse_y = GetMouseY();
  Rectangle mouse_rect = {mouse_x, mouse_y, 1, 1};
  Rectangle user_rect = {this->x_position, this->y_position, this->width,
                         this->height}; // Use this->

  if (CheckCollisionRecs(mouse_rect, user_rect)) {
    SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
  } else {
    SetMouseCursor(MOUSE_CURSOR_DEFAULT);
  }

  return *this;
}

Button &Button::OnClick(function<void()> fun_user) {
  onClickCallback = fun_user;
  float mouse_x = GetMouseX();
  float mouse_y = GetMouseY();
  Rectangle mouse_rect = {mouse_x, mouse_y, 1, 1};
  Rectangle user_rect = {this->x_position, this->y_position, this->width,
                         this->height}; // Use this->

  if (CheckCollisionRecs(mouse_rect, user_rect) &&
      IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
    this->backgroundColor = TailwindAPI::gray100;
    onClickCallback();
    return *this;
  }
  return *this;
}

void Button::draw() {
  DrawRectangle(x_position, y_position, width, height, backgroundColor);
  if (borderWidth > 0) {
    DrawRectangleLinesEx(Rectangle{x_position, y_position, width, height},
                         borderWidth, borderColor);
  }
  if (!value.empty()) {
    DrawText(value.c_str(), x_position + 25, y_position + 2, 20, color_text);
  }
}
