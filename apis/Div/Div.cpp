#include "Div.h"
#include <cmath>
#include <cstdint>
#include <string>

Div::Div()
    : x_position(20.0), y_position(20.0), width(150), height(25),
      backgroundColor(WHITE), borderColor(BLACK), borderWidth(1.0), padding(1),
      color_text(BLACK), id(DIV_ID) {}

Div Div::New() { return Div(); }

Div &Div::setPosition(float x_pos, float y_pos) {
  x_position = x_pos;
  y_position = y_pos;
  return *this;
}

Div &Div::setSize(float width_u, float height_u) {
  width = width_u;
  height = height_u;
  return *this;
}

Div &Div::setBackgroundColor(Color color_user) {
  backgroundColor = color_user;
  return *this;
}

Div &Div::setBorderColor(Color color_u) {
  borderColor = color_u;
  return *this;
}

Div &Div::setBorderWidth(float border_w_u) {
  borderWidth = border_w_u;
  return *this;
}

Div &Div::setText(string user_value, Color color_text_user) {
  value = user_value;
  color_text = color_text_user;
  return *this;
}

Div &Div::addChild(const Div &children_div) {
  childrens.push_back(children_div);
  return *this;
}

void Div::draw() {
  DrawRectangle(x_position, y_position, width, height, backgroundColor);
  if (borderWidth > 0) {
    DrawRectangleLinesEx(Rectangle{x_position, y_position, width, height},
                         borderWidth, borderColor);
  }
  if (!value.empty()) {
    const uint32_t font_value = 20;
    uint32_t text_width = MeasureText(value.c_str(), font_value);
    uint32_t x_position_center = x_position + (width - text_width) / 2;
    uint32_t y_position_center = y_position + (height - font_value) / 2;

    DrawText(value.c_str(), x_position_center, y_position_center, font_value,
             color_text);
  }
  for (auto &child : childrens) {
    child.draw();
  }
}
