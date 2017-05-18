/*-------------------- Rbs - menu.c - Menu for user interface-----------------
**----------------Authors: Breno Campos Ferreira Guimaraes---------------------
**-------------------------Alberto Nonato Passini------------------------------
**-------------------------Germano Luis Marques Moura Leite--------------------
*/

/*number of options in each menu/submenu*/
#define Itens_Main_Menu 4
#define Itens_Part1_Menu 4
#define Itens_Part2_Menu 2
#define Itens_Part3_Menu 2
#define Itens_Calib_Menu 4

#define red 0
#define green 1
#define blue 2
#define yellow 3
#define black 4

/*the arrays that contain the menu options*/
char MainMenu[Itens_Main_Menu][40] = {"1- Movement", "2- Sensors", "3- Decisions", "4- Calibration"};
char Part1Menu[Itens_Part1_Menu][40] = {"1- Line", "2- Triangle", "3- Square", "4- Return"};
char Part2Menu[Itens_Part2_Menu][40] = {"1- ID Color", "2- Return"};
char Part3Menu[Itens_Part3_Menu][40] = {"1- GO EXPLORING", "2- Return"};
char CalibMenu[Itens_Calib_Menu][40] = {"1- Calibrate RED", "2- Calibrate GREEN", "3- Calibrate BLUE", "4- Return"};

/*the main start menu*/
void start_menu() {
    int i = 0;
    int option;
    
    while(1) {
        while((!start_button()) || (!stop_button())) {    
            printf("%s\n",MainMenu[i]);
            msleep(100L);
            
            if (start_button()) {
                executeItem(i);
                while (start_button());
            }
            if (stop_button()) {
                i = (i + 1)% Itens_Main_Menu;  
                while (stop_button());
            }
        }   
    }    
}

/*executes a menu item's function, given its position*/
void executeItem(int MenuOption) {
    switch(MenuOption) {
        case 0: {
            part1_menu();
            break;
        }        
        case 1: {  
            part2_menu();
            break;
        }
        case 2: {    
            part3_menu();
            break;
        }
        case 3: {
            calib_menu();
            break;
        }
        case 4: {
            lineAndTurn();
            break;
        }
        case 5: {
            triangle();
            break;
        }
        case 6: {
            square();
            break;
        }
        case 7: {
            start_menu();
            break;
        }
        case 8: {    
            id_color();
            break;
        }
        case 9: {
            start_menu();
            break;
        }
        case 10: {
            explore();
            break;
        }
        case 11: {
            start_menu();
            break;
        }
        case 12: {
            calibrate_red();
            break;
        }
        case 13: {
            calibrate_green();
            break;
        }
        case 14: {
            calibrate_blue();
            break;
        }
        case 15: {
            start_menu();
            break;
        }
    }
}

/*submenu for the movement section*/
void part1_menu() {
    int i = 0;
    int option;
    
    while(1) {
        while((!start_button()) || (!stop_button())) {    
            printf("%s\n",Part1Menu[i]);
            msleep(100L);
            
            if (start_button()) {
                executeItem(i+Itens_Main_Menu);
                while (start_button());
            }
            if (stop_button()) {
                i = (i + 1)% Itens_Part1_Menu;  
                while (stop_button());
            }
        }        
    }    
}

/*submenu for the sensoring section*/
void part2_menu() {
    int i = 0;
    int option;
    
    while(1) {
        while((!start_button()) || (!stop_button())) {    
            printf("%s\n",Part2Menu[i]);
            msleep(100L);
            
            if (start_button()) {
                executeItem(i+Itens_Main_Menu+Itens_Part1_Menu);
                while (start_button());
            }
            if (stop_button()) {
                i = (i + 1)% Itens_Part2_Menu;  
                while (stop_button());
            }
        }       
    }    
}

/*submenu for the decision-making section*/
void part3_menu() {
    int i = 0;
    int option;
    
    while(1) {
        while((!start_button()) || (!stop_button())) {    
            printf("%s\n",Part3Menu[i]);
            msleep(100L);
            
            if (start_button()) {
                executeItem(i+Itens_Main_Menu+Itens_Part1_Menu+Itens_Part2_Menu);
                while (start_button());
            }
            if (stop_button()) {
                i = (i + 1)% Itens_Part3_Menu;  
                while (stop_button());
            }
        }        
    }    
}

/*submenu for Calibration*/
void calib_menu() {
    int i = 0;
    int option;
    
    while(1) {
        while((!start_button()) || (!stop_button())) {    
            printf("%s\n",CalibMenu[i]);
            msleep(100L);
            
            if (start_button()) {
                executeItem(i+Itens_Main_Menu+Itens_Part1_Menu+Itens_Part2_Menu+Itens_Part3_Menu);
                while (start_button());
            }
            if (stop_button()) {
                i = (i + 1)% Itens_Calib_Menu;  
                while (stop_button());
            }
        }        
    }    
}
