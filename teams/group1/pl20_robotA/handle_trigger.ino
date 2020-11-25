/*
  handle_trigger.ino
  TRIGGERの管理
  作成者 b1018194 Ito Hajime
*/

void handle_trigger(TRIGGER *t)
{
  bool is_touch = touch_sense();
  int distance = distance_sense();
  
  if (is_touch) {
    t->touch = true;
  }
  else if (distance < 60)
  {
    t->distance = true;
  }
  else
  {
    t->none = true;
  }

  Serial.print("awake: ");
  Serial.println(t->awake ? "HIGH" : "LOW");
  Serial.print("distance: ");
  Serial.println(t->distance ? "HIGH" : "LOW");
  Serial.print("touch: ");
  Serial.println(t->touch  ? "HIGH" : "LOW");
  Serial.print("none: ");
  Serial.println(t->none ? "HIGH" : "LOW");
  Serial.println("\n\n");

  if (t->awake) {
    awake_action();
    t->awake = false;
  }
  if (t->distance) {
    near_action();
    t->distance = false;
  }
  if (t->touch) {
    touch_action();
    t->touch = false;
  }
  if (t->none) {
    t->none = false;
  }
}
