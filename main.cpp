#include "apis/Button/Button.h"
#include "apis/Div/Div.h"
#include "apis/Tailwind/tailwind_api.h"
#include <cmath>
#include <raylib.h>
#include <string>
#include <sys/types.h>

using namespace std;

void update_state(int &state_number, int increment) {
  state_number += increment;
  printf("State Number: %d\n", state_number);
}

int main() {
  InitWindow(800, 600, "Custom GUI Library");

  int state_number = 16;
  int increment = 1;

  SetTargetFPS(144);
  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(TailwindAPI::gray900);

    Div::New()
        .setPosition(20, 20)
        .setSize(750, 550)
        .setBackgroundColor(TailwindAPI::gray950)
        .addChild(Div::New()
                      .setPosition(200, 100)
                      .setSize(300, 50)
                      .setText(to_string(state_number), TailwindAPI::gray100)
                      .setBackgroundColor(TailwindAPI::red400))

        .draw();
    Button::New()
        .onHover(typeHover::CHANGE_BACKGROUND)
        .setPosition(300, 300)
        .setSize(200, 50)
        .setText("hola button", TailwindAPI::gray100)
        .setBackgroundColor(TailwindAPI::gray950)
        .setBorderColor(TailwindAPI::gray100)
        .draw();

    EndDrawing();
  }

  CloseWindow();
  return 0;
}
