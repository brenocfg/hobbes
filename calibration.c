/*---------------- Róbs - calibration.c - Sensor Calibration ------------------
**-------------------- Authors: Breno Campos Ferreira Guimaraes----------------
**------------------------------Alberto Nonato Passini-------------------------
**------------------------------Germano Luis Marques Moura Leite---------------
*/

/*calibrate values for Red LGB output*/
void calibrate_red() {
    int colors[3] = {0, 0, 0};
    int dif_rg, dif_rb, dif_gb;
    
    /*get measurements, with average amongst 100 samples*/
    colors[0] = light_led(red, 100);
    colors[1] = light_led(green, 100);
    colors[2] = light_led(blue, 100);
    
    /*adjust blue measurement*/
    colors[2] = (int) ((float)colors[2] * 0.7);
    printf("Colors: %d %d %d\n", colors[0], colors[1], colors[2]);
   
    /*get measurement differential*/ 
    dif_rg = abs(colors[0] - colors[1]);
    dif_rb = abs(colors[0] - colors[2]);
    dif_gb = abs(colors[1] - colors[2]);
    
    /*set thresholds*/
    ref_rg_yellow = dif_rg - (int)((float)dif_rg/3.33);
    ref_rb_black = dif_rb - (int) ((float)dif_rb/2.5);
    ref_rg_black = dif_rg - (int) ((float)dif_rg/2.0);
    
    sleep(5.0);
    calib_menu();
}

/*calibrate values for Green LGB output*/
void calibrate_green() {
    int colors[3] = {0, 0, 0};
    int dif_rg, dif_rb, dif_gb;
    
    /*get measurements, with average amongst 100 samples*/
    colors[0] = light_led(red, 100);
    colors[1] = light_led(green, 100);
    colors[2] = light_led(blue, 100);
    
    /*adjust blue measurement*/
    colors[2] = (int) ((float)colors[2] * 0.7);
    printf("Colors: %d %d %d\n", colors[0], colors[1], colors[2]);
   
    /*get measurement differentials*/ 
    dif_rg = abs(colors[0] - colors[1]);
    dif_rb = abs(colors[0] - colors[2]);
    dif_gb = abs(colors[1] - colors[2]);
    
    /*set thresholds*/
    ref_gr_yellow = dif_rg - (int)((float)dif_rg/3.33);
    ref_gr_black = dif_rg - (int) ((float)dif_rb/3.33);
    ref_gb_black = dif_gb - (int) ((float)dif_rg/2.0);
    
    sleep(5.0);
    calib_menu();
}

/*calibrate values for Blue LGB output*/
void calibrate_blue() {
    int colors[3] = {0, 0, 0};
    int dif_rg, dif_rb, dif_gb;
    
    /*get measurements, with average amongst 100 samples*/
    colors[0] = light_led(red, 100);
    colors[1] = light_led(green, 100);
    colors[2] = light_led(blue, 100);
    
    /*adjust blue measurement*/
    colors[2] = (int) ((float)colors[2] * 0.7);
    printf("Colors: %d %d %d\n", colors[0], colors[1], colors[2]);
   
    /*get measurement differentials*/ 
    dif_rg = abs(colors[0] - colors[1]);
    dif_rb = abs(colors[0] - colors[2]);
    dif_gb = abs(colors[1] - colors[2]);
   
    /*set thresholds*/ 
    ref_br_black = dif_rb - (int) ((float)dif_rb/3.33);
    ref_bg_black = dif_gb - (int) ((float)dif_rg/2.0);
    
    sleep(5.0);
    calib_menu();
}
