#ifndef DIV_H
#define DIV_H

#include <raylib.h>
#include <string>
#include <vector>
using namespace std;

class Div {
public:
  float x_position, y_position;
  float width, height;
  Color backgroundColor;
  Color borderColor;
  float borderWidth;
  float padding;
  Color color_text;
  vector<Div> childrens;
  string value;
  int id;
  static const int DIV_ID = 1;

  Div();
  static Div New();

  Div &setPosition(float x_pos, float y_pos);
  Div &setSize(float width_u, float height_u);
  Div &setBackgroundColor(Color color_user);
  Div &setBorderColor(Color color_u);
  Div &setBorderWidth(float border_w_u);
  Div &setText(string user_value, Color color_text_user);
  Div &addChild(const Div &children_div);

  void draw();
};

#endif // DIV_H
