/*
  speaker.ino
  音声合成LSIの処理
  作成者 b1018194 Ito Hajime
*/

void speak(String messages[])
{
  byte index = 0;
  byte count = 0;
  byte str_count = 0;

  while (true) {
    if (messages[count].length() > 0) count++;
    else break;
  }

  while (count > index)
  {
    //メッセージをデバイスに送信
    Wire.beginTransmission(LSI_VOICE_ADDRESS);
    for (str_count = 0; str_count < messages[index].length(); str_count++) {
      Wire.write(messages[index][str_count]);
    }
    Wire.endTransmission();

    //次のメッセージを発声できるまでループする
    while (true) {
      //デバイスへ1byteのレジスタデータを要求する
      Wire.requestFrom(LSI_VOICE_ADDRESS, 1);
      //「>」(次の発声が準備OK)ならばループを抜ける
      while (Wire.available() == 0) {}
      byte c = Wire.read();
      if (c == '>')  break;
      delay(10);
    }
    index++;
  }
}
