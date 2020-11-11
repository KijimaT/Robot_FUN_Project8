/*
  distance_sensor.ino
  赤外線測距センサの処理
  作成者 b1018194 Ito Hajime
*/

int distance_sense()
{
  float Vcc = 5.0;
  float dist1 = 0;
  int dist2 = 0;
  int i = 0;
  for (i = 0; i < 1000; i++)
    dist1 += Vcc * analogRead(DISTANCE_SENSOR_PIN) / 1023;
  dist2 = round(26.549 * pow(dist1 / 1000, -1.2091));
  //Serial.println(dist2);
  delay(300);
  return dist2;
}
