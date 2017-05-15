/*-------------------- Róbs - main.c - Main file/Entry point ------------------
**----------------Authors: Breno Campos Ferreira Guimaraes---------------------
**-------------------------Alberto Nonato Passini------------------------------
**-------------------------Germano Luis Marques Moura Leite--------------------
*/

/*main program entry point*/
void main()
{
    int goToMenu = 0;

    /*setup digital outputs for LED interfacing*/
    poke(0x1009, 0x3c);
    bit_clear(0x1008, 0x04);
    bit_clear(0x1008, 0x08);
    bit_clear(0x1008, 0x10);
    
    while(1) {
        if(!goToMenu) {
            printf("Press START for Main Menu!\n");
            while(!start_button());       
            while(start_button());
            goToMenu = 1;
        }
        start_menu();
    }
}
