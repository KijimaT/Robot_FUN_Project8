void lcd_write(){
    lcd.setCursor(0, 0);
    lcd.print(rx);
    lcd.setCursor(0, 1);
    lcd.print("A");
    lcd.print(deg_LR);
    lcd.print("B");
    lcd.print(deg_UD);
    lcd.print("C");
    lcd.print(deg_M);
    lcd.print("D");
    lcd.print(deg_T);
}

void lcd_reset(){
    lcd.setCursor(0, 0);
    lcd.print("                ");
    lcd.setCursor(0, 1);
    lcd.print("                ");
}
