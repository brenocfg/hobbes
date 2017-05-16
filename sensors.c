/*-------------------- Rbs - sensors.c - Sensor interfacing ------------------
**----------------Authors: Breno Campos Ferreira Guimaraes---------------------
**-------------------------Alberto Nonato Passini------------------------------
**-------------------------Germano Luis Marques Moura Leite--------------------
*/

/*lights the RGB LED with the given color, and measures LDR sensor output for a
few samples*/

int get_color(int *colors) {
    int smallest;
    smallest = min(*(colors), *(colors+1), *(colors+2));
    sleep(5.0);
}

void id_color() {
    int colors[3] = {0, 0, 0};
    int blockColor;
    colors[0] = light_led(red, 100);
    colors[1] = light_led(green, 100);
    colors[2] = light_led(blue, 100);
    printf("Colors: %d %d %d\n", colors[0], colors[1], colors[2]);
    sleep(5.0);
    
    blockColor = get_color(colors);
}

int light_led(int color, int num_samples) {
    int t, value;
    t = 0;
    value = 0;    
    switch(color) {
        case 0: {
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
        
        case 1: {
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
        
        case 2: {
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

void readDistance () {
    while (1) {
        printf("%d\n", analog(5));
    }
}
