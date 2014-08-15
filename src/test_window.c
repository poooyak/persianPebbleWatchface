#include "test_window.h"
#include <pebble.h>
#include <stdio.h>
  
  
static GBitmap *s_res_img_battry_20_white;
static GBitmap *s_res_img_battry_30_white;
static GBitmap *s_res_img_battry_40_white;
static GBitmap *s_res_img_battry_50_white;
static GBitmap *s_res_img_battry_60_white;
static GBitmap *s_res_img_battry_70_white;
static GBitmap *s_res_img_battry_80_white;
static GBitmap *s_res_img_battry_90_white;
static GBitmap *s_res_img_battry_100_white;

static GBitmap *s_res_img_battry_Charge_white;
  
static int g_days_in_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
static int j_days_in_month[12] = {31, 31, 31, 31, 31, 31, 30, 30, 30, 30, 30, 29};
static const char *j_month_name[13] = {"",
                                "Farv", "Ordi", "Khor",
                                "Tir", "Mord", "Shah",
                                "Mehr", "Aban", "Azar",
                                "Dey", "Bah", "Esf"};
static const char *p_min_name[13] = {"",
                                "one", "two", "three",
                                "four", "five", "six",
                                "seven", "eight", "nine",
                                "ten", "eleven", "twelve"};
static const char *p_higher_min_name[6] = {"",
                                "", "twenty", "thirty",
                                "forty", "fifty"};



static void gregorian_to_jalali(int *j_y, int *j_m, int *j_d,
                         int  g_y, int  g_m, int  g_d)
{
   int gy, gm, gd;
   int jy, jm, jd;
   long g_day_no, j_day_no;
   int j_np;
 
   int i;

   gy = g_y-1600;
   gm = g_m-1;
   gd = g_d-1;
 
   g_day_no = 365*gy+(gy+3)/4-(gy+99)/100+(gy+399)/400;
   for (i=0;i<gm;++i)
      g_day_no += g_days_in_month[i];
   if (gm>1 && ((gy%4==0 && gy%100!=0) || (gy%400==0)))
      /* leap and after Feb */
      ++g_day_no;
   g_day_no += gd;
 
   j_day_no = g_day_no-79;
 
   j_np = j_day_no / 12053;
   j_day_no %= 12053;
 
   jy = 979+33*j_np+4*(j_day_no/1461);
   j_day_no %= 1461;
 
   if (j_day_no >= 366) {
      jy += (j_day_no-1)/365;
      j_day_no = (j_day_no-1)%365;
   }
 
   for (i = 0; i < 11 && j_day_no >= j_days_in_month[i]; ++i) {
      j_day_no -= j_days_in_month[i];
   }
   jm = i+1;
   jd = j_day_no+1;
   *j_y = jy;
   *j_m = jm;
   *j_d = jd;
}

  
// BEGIN AUTO-GENERATED UI CODE; DO NOT MODIFY
static Window *s_window;
static GFont s_res_gothic_14;
static GBitmap *s_res_img_battry_10;
static GFont s_res_bitham_42_bold;
static GFont s_res_bitham_42_light;
static TextLayer *s_textlayer_5;
static TextLayer *s_textlayer_6;
static BitmapLayer *s_bitmaplayer_1;
static TextLayer *s_textlayer_1;
static TextLayer *s_textlayer_2;
static TextLayer *s_textlayer_3;

static void initialise_ui(void) {
  s_window = window_create();
  window_set_background_color(s_window, GColorBlack);
  window_set_fullscreen(s_window, true);
  
  s_res_gothic_14 = fonts_get_system_font(FONT_KEY_GOTHIC_14);
  s_res_img_battry_10 = gbitmap_create_with_resource(RESOURCE_ID_IMG_BATTRY_10);
  s_res_bitham_42_bold = fonts_get_system_font(FONT_KEY_BITHAM_42_BOLD);
  s_res_bitham_42_light = fonts_get_system_font(FONT_KEY_BITHAM_42_LIGHT);
  // s_textlayer_5
  s_textlayer_5 = text_layer_create(GRect(4, 146, 71, 21));
  text_layer_set_background_color(s_textlayer_5, GColorClear);
  text_layer_set_text_color(s_textlayer_5, GColorWhite);
  text_layer_set_text(s_textlayer_5, "Aug 15");
  text_layer_set_font(s_textlayer_5, s_res_gothic_14);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_textlayer_5);
  
  // s_textlayer_6
  s_textlayer_6 = text_layer_create(GRect(68, 146, 71, 21));
  text_layer_set_background_color(s_textlayer_6, GColorClear);
  text_layer_set_text_color(s_textlayer_6, GColorWhite);
  text_layer_set_text(s_textlayer_6, "Mord 24");
  text_layer_set_text_alignment(s_textlayer_6, GTextAlignmentRight);
  text_layer_set_font(s_textlayer_6, s_res_gothic_14);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_textlayer_6);
  
  // s_bitmaplayer_1
  s_bitmaplayer_1 = bitmap_layer_create(GRect(0, 166, 144, 2));
  bitmap_layer_set_bitmap(s_bitmaplayer_1, s_res_img_battry_10);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_bitmaplayer_1);
  
  // s_textlayer_1
  s_textlayer_1 = text_layer_create(GRect(0, -2, 144, 51));
  text_layer_set_background_color(s_textlayer_1, GColorClear);
  text_layer_set_text_color(s_textlayer_1, GColorWhite);
  text_layer_set_text(s_textlayer_1, "eight");
  text_layer_set_font(s_textlayer_1, s_res_bitham_42_bold);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_textlayer_1);
  
  // s_textlayer_2
  s_textlayer_2 = text_layer_create(GRect(0, 35, 144, 50));
  text_layer_set_background_color(s_textlayer_2, GColorClear);
  text_layer_set_text_color(s_textlayer_2, GColorWhite);
  text_layer_set_text(s_textlayer_2, "fifty");
  text_layer_set_font(s_textlayer_2, s_res_bitham_42_light);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_textlayer_2);
  
  // s_textlayer_3
  s_textlayer_3 = text_layer_create(GRect(0, 72, 144, 53));
  text_layer_set_background_color(s_textlayer_3, GColorClear);
  text_layer_set_text_color(s_textlayer_3, GColorWhite);
  text_layer_set_text(s_textlayer_3, "eight");
  text_layer_set_font(s_textlayer_3, s_res_bitham_42_light);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_textlayer_3);
}

static void destroy_ui(void) {
  window_destroy(s_window);
  text_layer_destroy(s_textlayer_5);
  text_layer_destroy(s_textlayer_6);
  bitmap_layer_destroy(s_bitmaplayer_1);
  text_layer_destroy(s_textlayer_1);
  text_layer_destroy(s_textlayer_2);
  text_layer_destroy(s_textlayer_3);
  gbitmap_destroy(s_res_img_battry_10);
}
// END AUTO-GENERATED UI CODE

static void update_battry(BatteryChargeState charge) {
   //static char buffer1[20];
  if(charge.is_charging){
    bitmap_layer_set_bitmap(s_bitmaplayer_1, s_res_img_battry_Charge_white);

  }else{
    if(charge.charge_percent <= 10){
          bitmap_layer_set_bitmap(s_bitmaplayer_1, s_res_img_battry_10);

    }else if(charge.charge_percent <= 20){
          bitmap_layer_set_bitmap(s_bitmaplayer_1, s_res_img_battry_20_white);

    }else if(charge.charge_percent <= 30){
          bitmap_layer_set_bitmap(s_bitmaplayer_1, s_res_img_battry_30_white);

    }else if(charge.charge_percent <= 40){
          bitmap_layer_set_bitmap(s_bitmaplayer_1, s_res_img_battry_40_white);

    }else if(charge.charge_percent <= 50){
          bitmap_layer_set_bitmap(s_bitmaplayer_1, s_res_img_battry_50_white);

    }else if(charge.charge_percent <= 60){
          bitmap_layer_set_bitmap(s_bitmaplayer_1, s_res_img_battry_60_white);

    }else if(charge.charge_percent <= 70){
          bitmap_layer_set_bitmap(s_bitmaplayer_1, s_res_img_battry_70_white);

    }else if(charge.charge_percent <= 80){
          bitmap_layer_set_bitmap(s_bitmaplayer_1, s_res_img_battry_80_white);

    }else if(charge.charge_percent <= 90){
          bitmap_layer_set_bitmap(s_bitmaplayer_1, s_res_img_battry_90_white);

    }else if(charge.charge_percent == 100){
          bitmap_layer_set_bitmap(s_bitmaplayer_1, s_res_img_battry_100_white);

    }
  }
 // snprintf (buffer1,20,"%d%%",charge.charge_percent);
 // text_layer_set_text(s_textlayer_3, buffer1);
}

static void update_time() {
  // Get a tm structure
  time_t temp = time(NULL); 
  struct tm *tick_time = localtime(&temp);
  // Create a long-lived buffer
   static char bufferHour[20]="";
   static char bufferMinFirst[20]="";
   static char bufferMinLast[20]="";
  char blanck[] = "";
  snprintf (bufferMinLast,20,"%s",blanck);
    text_layer_set_text(s_textlayer_1, bufferMinLast);
    text_layer_set_text(s_textlayer_2, bufferMinLast);
    text_layer_set_text(s_textlayer_3, bufferMinLast);
  
    APP_LOG(APP_LOG_LEVEL_DEBUG, "hour: %d ",tick_time->tm_hour);
    APP_LOG(APP_LOG_LEVEL_DEBUG,"min: %d ",tick_time->tm_min);

   if(tick_time->tm_min == 0){
        char oclock[] = "o'clock";  
        snprintf (bufferMinFirst,20,"%s",oclock);
   }else{
     if(tick_time->tm_min <= 19){
       if(tick_time->tm_min < 13){
         // bufferMinFirst = p_min_name[tick_time->tm_min];
          snprintf (bufferMinFirst,20,"%s",p_min_name[tick_time->tm_min]);

       }else{
        // bufferMinLast = "teen";
        
          if(tick_time->tm_min == 13){
           // bufferMinFirst = "thir";
             char thir[] = "thirteen";
             snprintf (bufferMinFirst,20,"%s",thir);

          }else if(tick_time->tm_min == 15){
            //bufferMinFirst = "fif";
            char fif[] = "fifteen";
           snprintf (bufferMinFirst,20,"%s",fif);
          }else if(tick_time->tm_min == 18){
            //bufferMinFirst = "eigh";
            char eigh[] = "eigh";
           snprintf (bufferMinFirst,20,"%s",eigh);
            char teen[] = "teen";
           snprintf (bufferMinLast,20,"%s",teen);
          }else{
            int index = tick_time->tm_min%10;
            //bufferMinFirst = p_min_name[index];
            snprintf (bufferMinFirst,20,"%s",p_min_name[index]);
            char teen[] = "teen";
           snprintf (bufferMinLast,20,"%s",teen);
          }
            
       }
     }else{
       int hIndex = tick_time->tm_min/10;
        int mIndex = tick_time->tm_min%10;
       // bufferMinFirst = p_higher_min_name[hIndex];
      //  bufferMinLast = p_min_name[mIndex];
        snprintf (bufferMinFirst,20,"%s",p_higher_min_name[hIndex]);
        snprintf (bufferMinLast,20,"%s",p_min_name[mIndex]);
     }
   }
  
  switch(tick_time->tm_hour){
    case 0:
      if(tick_time->tm_min == 0){
        //bufferHour = "mid";
        //bufferMinFirst = "night";
        char mid[] = "mid";
        snprintf (bufferHour,20,"%s",mid);
        char night[] = "night";
        snprintf (bufferMinFirst,20,"%s",night);
        char noonn[]="";
        snprintf (bufferMinLast,20,"%s",noonn);

      }else{
            snprintf (bufferHour,20,"%s",p_min_name[12]);
      }
    break;
    case 1:
            snprintf (bufferHour,20,"%s",p_min_name[1]);
    break;
    case 2:
            snprintf (bufferHour,20,"%s",p_min_name[2]);
    break;
    case 3:
            snprintf (bufferHour,20,"%s",p_min_name[3]);
    break;
    case 4:
            snprintf (bufferHour,20,"%s",p_min_name[4]);
    break;
    case 5:
            snprintf (bufferHour,20,"%s",p_min_name[5]);
    break;
    case 6:
            snprintf (bufferHour,20,"%s",p_min_name[6]);
    break;
    case 7:
            snprintf (bufferHour,20,"%s",p_min_name[7]);
    break;
    case 8:
            snprintf (bufferHour,20,"%s",p_min_name[8]);
    break;
    case 9:
            snprintf (bufferHour,20,"%s",p_min_name[9]);
    break;
    case 10:
            snprintf (bufferHour,20,"%s",p_min_name[10]);
    break;
    case 11:
            snprintf (bufferHour,20,"%s",p_min_name[11]);
    break;
    case 12:
      if(tick_time->tm_min == 0){
//        bufferHour = "noon";
        char noon[] = "noon";
           snprintf (bufferHour,20,"%s",noon);
        char noonn[]="";
        snprintf (bufferMinFirst,20,"%s",noonn);
        snprintf (bufferMinLast,20,"%s",noonn);

      }else{
            snprintf (bufferHour,20,"%s",p_min_name[12]);
      }    
    break;
    case 13:
            snprintf (bufferHour,20,"%s",p_min_name[1]);
    break;
    case 14:
            snprintf (bufferHour,20,"%s",p_min_name[2]);
    break;
    case 15:
            snprintf (bufferHour,20,"%s",p_min_name[3]);
    break;
    case 16:
            snprintf (bufferHour,20,"%s",p_min_name[4]);
    break;
    case 17:
            snprintf (bufferHour,20,"%s",p_min_name[5]);
    break;
    case 18:
            snprintf (bufferHour,20,"%s",p_min_name[6]);
    break;
    case 19:
            snprintf (bufferHour,20,"%s",p_min_name[7]);
    break;
    case 20:
            snprintf (bufferHour,20,"%s",p_min_name[8]);
    break;
    case 21:
            snprintf (bufferHour,20,"%s",p_min_name[9]);
    break;
    case 22:
            snprintf (bufferHour,20,"%s",p_min_name[10]);
    break;
    case 23:
            snprintf (bufferHour,20,"%s",p_min_name[11]);
    break;
    
  }
    text_layer_set_text(s_textlayer_1, bufferHour);
    text_layer_set_text(s_textlayer_2, bufferMinFirst);
    text_layer_set_text(s_textlayer_3, bufferMinLast);

     
  int y, m, d;
    gregorian_to_jalali(&y, &m, &d,
		       1900+tick_time->tm_year,
		       1+tick_time->tm_mon,
		       tick_time->tm_mday);
  
  static char buffer1[20];
  snprintf (buffer1,20,"%s %d",j_month_name[m],d);
  text_layer_set_text(s_textlayer_6, buffer1);
  
  static char bufferMonth[15];
  strftime(bufferMonth, 15, "%b %d", tick_time);
  text_layer_set_text(s_textlayer_5, bufferMonth);

}

static void handle_window_unload(Window* window) {
  destroy_ui();
}

static void tick_handler(struct tm *tick_time, TimeUnits units_changed) {
  update_time();

}

static void battry_handler(BatteryChargeState charge){
  update_battry(charge);
}


void show_test_window(void) {
  initialise_ui();
  
 // s_res_img_battry_10_white = gbitmap_create_with_resource(RESOURCE_ID_IMG_BATTRY_10);
  s_res_img_battry_20_white = gbitmap_create_with_resource(RESOURCE_ID_IMG_BATTRY_20);
  s_res_img_battry_30_white = gbitmap_create_with_resource(RESOURCE_ID_IMG_BATTRY_30);
  s_res_img_battry_40_white = gbitmap_create_with_resource(RESOURCE_ID_IMG_BATTRY_40);
  s_res_img_battry_50_white = gbitmap_create_with_resource(RESOURCE_ID_IMG_BATTRY_50);
  s_res_img_battry_60_white = gbitmap_create_with_resource(RESOURCE_ID_IMG_BATTRY_60);
  s_res_img_battry_70_white = gbitmap_create_with_resource(RESOURCE_ID_IMG_BATTRY_70);
  s_res_img_battry_80_white = gbitmap_create_with_resource(RESOURCE_ID_IMG_BATTRY_80);
  s_res_img_battry_90_white = gbitmap_create_with_resource(RESOURCE_ID_IMG_BATTRY_90);
  s_res_img_battry_90_white = gbitmap_create_with_resource(RESOURCE_ID_IMG_BATTRY_100);
  s_res_img_battry_Charge_white = gbitmap_create_with_resource(RESOURCE_ID_IMG_BATTRY_CHARGE);

  
  tick_timer_service_subscribe(MINUTE_UNIT, tick_handler);
  battery_state_service_subscribe(battry_handler);
  
  window_set_window_handlers(s_window, (WindowHandlers) {
    .unload = handle_window_unload,
  });
  window_stack_push(s_window, true);
  update_time();
  update_battry(battery_state_service_peek());
}

void hide_test_window(void) {
    gbitmap_destroy(s_res_img_battry_20_white);
   gbitmap_destroy(s_res_img_battry_30_white);
   gbitmap_destroy(s_res_img_battry_40_white);
   gbitmap_destroy(s_res_img_battry_50_white);
   gbitmap_destroy(s_res_img_battry_60_white);
   gbitmap_destroy(s_res_img_battry_70_white);
   gbitmap_destroy(s_res_img_battry_80_white);
   gbitmap_destroy(s_res_img_battry_90_white);
   gbitmap_destroy(s_res_img_battry_100_white);
  

  window_stack_remove(s_window, true);
}
