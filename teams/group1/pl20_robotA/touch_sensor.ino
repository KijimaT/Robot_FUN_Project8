/*action
  touch_sensor.ino
  静電容量センサによるタッチ検出とその反応処理
  作成者 b1018194 Ito Hajime
*/

bool touch_sense()
{
  bool flag = false;
  //ここの30はノイズをとる強さ.大きくすればノイズは小さいが遅い.小さくすればノイズは大きいが速い
  long val = cs.capacitiveSensor(30);
  //値をシリアルに書き出し
  //Serial.print("value:tt");
  //Serial.println(val);
  delay(10); //放電
  if (val > 400) flag = true;
  return flag;
}
