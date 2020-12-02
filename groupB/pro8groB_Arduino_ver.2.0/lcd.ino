void lcd_write(){
    lcd.setCursor(0, 0);
    lcd.print(rx);
    lcd.setCursor(0, 1);
    lcd.print("A:");
    lcd.print(deg_LR);
    if(deg_LR<100){
      lcd.print(" B:");
    }else{
      lcd.print("B:");
    }
    lcd.print(mode_B);
    lcd.print(" C:");
    lcd.print(mode_C);
    lcd.print(" D:");
    lcd.print(mode_D);
}

void lcd_reset(){
    lcd.setCursor(0, 0);
    lcd.print("                ");
    lcd.setCursor(0, 1);
    lcd.print("                ");
}
