#include <SPI.h>
#include <TB_TFT_eSPI.h>
#include <MyFont.h>
#include <pic.h>

TFT_eSPI tft = TFT_eSPI();

void setup() {
  tft.init();
  tft.fillScreen(TFT_BLACK);
  tft.setCursor(10, 10, 1);
  tft.setTextColor(TFT_YELLOW);
  tft.setTextSize(2);
  tft.println("TFT_Text");
  tft.fillCircle(30,30,10,TFT_BLUE);
  tft.drawLine(10,50, 118, 50, TFT_WHITE);
  tft.drawPixel(70,70,TFT_RED);
  tft.setTextColor(TFT_WHITE,TFT_BLUE);
  tft.setCursor(10, 80, 1);
  tft.println("TFT_TEXT");
  
  showMyFonts(40, 50, "北风晴", TFT_RED);
}

void loop() {
  tft.fillScreen(TFT_BLACK);
  tft.setCursor(40, 64, 1);
  tft.setTextColor(TFT_YELLOW);
  tft.setTextSize(3);
  tft.println("Siu4");
  delay(500);

  tft.setSwapBytes(true);
  tft.pushImage(4, 4, 128, 128, siu2);
  delay(500);

  tft.setSwapBytes(true);
  tft.pushImage(4, 4, 128, 128, siu3);
  delay(500);

  tft.setSwapBytes(true);
  tft.pushImage(4, 4, 128, 128, siu4);
  delay(500);

}

void showMyFont(int32_t x, int32_t y, const char c[3], uint32_t color) { 
  for (int k = 0; k < 25; k++)// 根据字库的字数调节循环的次数
    if (hanzi[k].Index[0] == c[0] && hanzi[k].Index[1] == c[1] && hanzi[k].Index[2] == c[2])
    {
      tft.drawBitmap(x, y, hanzi[k].hz_Id, hanzi[k].hz_width, 16, color);
    }
    }
/*******************整句汉字显示****************/
void showMyFonts(int32_t x, int32_t y, const char str[], uint32_t color) { //显示整句汉字，字库比较简单，上下、左右输出是在函数内实现
  int x0 = x;
  for (int i = 0; i < strlen(str); i += 3) {
    showMyFont(x0, y, str+i, color);
    x0 += 17;
  }
}
