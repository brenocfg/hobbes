/*-------------------- Róbs - sensors.c - Sensor interfacing ------------------
**----------------Authors: Breno Campos Ferreira Guimaraes---------------------
**-------------------------Alberto Nonato Passini------------------------------
**-------------------------Germano Luis Marques Moura Leite--------------------
*/

/*references for red->green and red->blue measurements*/
persistent int ref_rg_black;
persistent int ref_rb_black;
persistent int ref_rg_yellow;

/*references for green->red and green->black measurements*/
persistent int ref_gr_black;
persistent int ref_gb_black;
persistent int ref_gr_yellow;

/*references for blue->red and blue->green measurements*/
persistent int ref_br_black;
persistent int ref_bg_black;

/*attempts to identify which color the block is, based on the RGB input values*/
int get_color(int r, int g, int b) {
    int smallest;
    int dif_g, dif_r, dif_b;
    
    smallest = min(r, g, b);
    /*we determine color based on the difference between measurements*/
    switch(smallest) {
        /*RED reflected the most*/
        case red: {
            dif_g = abs(r - g);
            dif_b = abs(r - b);
            /*if the difference with the other two isn't significant, BLACK*/
            if (dif_g < ref_rg_black && dif_b < ref_rb_black) {
                return black;
            }
            /*if red+blue mix, then probably YELLOW*/
            else if (dif_g < ref_rg_yellow) {
                return yellow;
            }
            /*otherwise, probably RED*/
            else {
                return red;
            }
            break;
        }
        /*GREEN reflected the most*/
        case green: {
            dif_r = abs(g - r);
            dif_b = abs(g - b);
            /*if all measurements are close enough, probably BLACK*/
            if (dif_r < ref_gr_black && dif_b < ref_gb_black) {
                return black;
            }
            /*if green+red mix, probably YELLOW*/
            else if (dif_r < ref_gr_yellow) {
                return yellow;
            }
            /*otherwise, GREEN*/
            else {
                return green;
            }
            break;
        }
        /*BLUE reflected the most*/
        case blue: {
            dif_r = abs(b - r);
            dif_g = abs(b - g);
            /*if all measurements are close, probably BLACK*/
            if (dif_r < ref_br_black && dif_g < ref_bg_black) {
                return black;
            }
            /*otherwise BLUE*/
            else {
                return blue;
            }
            break;
        }
    }
}

/*measures input from the LDR using the RGB led, then attempts to ID
the block's color based on those measurements*/
void id_color() {
    int colors[3] = {0, 0, 0};
    int blockColor;
    
    /*get measurements, with average amongst 100 samples*/
    colors[0] = light_led(red, 100);
    colors[1] = light_led(green, 100);
    colors[2] = light_led(blue, 100);
    
    /*adjust blue measurement*/
    colors[2] = (int) ((float)colors[2] * 0.7);
    //printf("Colors: %d %d %d\n", colors[0], colors[1], colors[2]);
    
    /*get color*/
    blockColor = get_color(colors[0], colors[1], colors[2]);
    switch (blockColor) {
        case red: {
            printf("RED! RED! STOP!");
            break;
        }
        case green: {
            printf("GREEN day!");
            break;
        }
        case blue: {
            printf("I'm BLUE dabadidabada");
            break;
        }
        case yellow: {
            printf("YELLOW submarine!");
            break;
        }
        case black: {
            printf("BLACK Bloc, call 911!");
            break;
        }
    }
    sleep(5.0);
}

/*lights the given LED color, then measures the average of num_samples LDR outputs*/
int light_led(int color, int num_samples) {
    int t, value;
    t = 0;
    value = 0;    
    switch(color) {
        /*RED LED*/
        case red: {
            bit_set(0x1008, 0x10);    
            while (t < num_samples) {
                value += analog(6);
                t++;
                sleep(0.02);
            }
            value = value/num_samples;    
            bit_clear(0x1008, 0x10);
            break;
        }
        /*GREEN LED*/
        case green: {
            bit_set(0x1008, 0x04);
            while (t < num_samples) {
                t++;
                value += analog(6);
                sleep(0.02);
            }
            value = value/num_samples;
            bit_clear(0x1008, 0x04);
            break;  
        }
        /*BLUE LED*/
        case blue: {
            bit_set(0x1008, 0x08);
            while (t < num_samples) {
                value += analog(6);
                t++;
                sleep(0.02);
            }
            value = value/num_samples;
            bit_clear(0x1008, 0x08);
            break;  
        }
    }
    return value;    
}
