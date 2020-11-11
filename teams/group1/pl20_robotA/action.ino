/*
  action.ino
  ロボットの動作処理
  作成者 b1018194 Ito Hajime
*/

void awake_action()
{
  String s[] = {
    "robotto/kidoushimasu.\r",
  };
  speak(s);
  nec_y.write(0);
  nec_x.write(0);
  arm_r.write(0);
  arm_l.write(0);
}

void near_action()
{
  String s[] = {
    "chikaiyo-.\r"
  };
  //speak(s);
}

void touch_action()
{
  String s[] = {
    "sawaranaide.\r"
  };
  //speak(s);
}
