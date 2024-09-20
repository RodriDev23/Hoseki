#ifndef BUTTON_H
#define BUTTON_H

#include <functional>
#include <raylib.h>
#include <string>
using namespace std;

enum typeHover { CHANGE_BACKGROUND, CHANGE_SIZE, CHANGE_COLOR_TEXT };

struct types_onclick {
  string String;
  int Number;
};

class Button {
public:
  float x_position, y_position;
  float width, height;
  Color backgroundColor;
  Color borderColor;
  float borderWidth;
  float padding;
  Color color_text;
  string value;

  Button();
  static Button New();

  Button &setPosition(float x_pos, float y_pos);
  Button &setSize(float width_u, float height_u);
  Button &setBackgroundColor(Color color_user);
  Button &setBorderColor(Color color_u);
  Button &setBorderWidth(float border_w_u);
  Button &setText(string user_value, Color color_text_user);
  Button &onHover();

  void draw();
};

#endif // BUTTON_H
