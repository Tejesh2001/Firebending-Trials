// Copyright (c) 2020 CS126SP20. All rights reserved.

#ifndef FINALPROJECT_APPS_MYAPP_H_
#define FINALPROJECT_APPS_MYAPP_H_
#include "my_app.h"
#include <Box2D/Box2D.h>
#include <cinder/Rand.h>
#include <cinder/app/App.h>
#include <cinder/gl/gl.h>
#include "mylibrary/direction.h"
#include "mylibrary/engine.h"
#include <mylibrary/BulletController.hpp>
#include <mylibrary/ProjectWideVariables.h>
namespace myapp {
using namespace cinder::app;
class MyApp : public cinder::app::App {
 public:
  MyApp();
  void setup();
  void mouseDown(MouseEvent event);
  void mouseUp(MouseEvent event);
  void keyDown(KeyEvent event);
  void update();
  void draw();

  void DrawPlayer();

 private:
  bool is_mouse_pressed_;
  cinder::ivec2 mouse_position_;
  cinder::Timer timer_;
  const int kTimeChange = 2;
  const double kDoubleEqualityChecker = 0.001;
  cinder::Timer game_timer;
  bool max_score_check_;
  const int kMaxNumberOfBullets = 50;
  int number_of_bullets;
  b2World* world_;
  Player* player_;
  Engine* engine_;
  EnemyController enemy_controller_;
  BulletController bullet_controller_;
  void DrawBackground();
  template <typename C>
  void PrintText(const std::string& text, const C& color,
                 const glm::ivec2& size, const glm::vec2& loc);
  void CreateCeiling() const;
  void CreateLeftWall() const;
  void CreateRightWall() const;
  void AddBullet();
};

}  // namespace myapp

#endif  // FINALPROJECT_APPS_MYAPP_H_
