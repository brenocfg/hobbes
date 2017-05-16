/*-------------------- Róbs - sensors.c - Sensor interfacing ------------------
**----------------Authors: Breno Campos Ferreira Guimaraes---------------------
**-------------------------Alberto Nonato Passini------------------------------
**-------------------------Germano Luis Marques Moura Leite--------------------
*/

/*lights the RGB LED with the given color, and measures LDR sensor output for a
few samples*/
void light_led(int color) {
    int t;
    switch(color) {
        case 0: {
            bit_set(0x1008, 0x10);
            t = 0;
            while (t < 5000) {
                printf("%d\n", analog(6));
                t++;
            }
            sleep(1.0);
            bit_clear(0x1008, 0x10);
            break;
        }
        
        case 1: {
            bit_set(0x1008, 0x04);
            t = 0;
            while (t < 5000) {
                printf("%d\n", analog(6));
                t++;
            }
            sleep(1.0);
            bit_clear(0x1008, 0x04);
            break;  
        }
        
        case 2: {
            bit_set(0x1008, 0x08);
            t = 0;
            while (t < 5000) {
                printf("%d\n", analog(6));
                t++;
            }
            sleep(1.0);
            bit_clear(0x1008, 0x08);
            break;  
        }
    }
}

void readDistance () {
    while (1) {
        printf("%d\n", analog(5));
    }
}
