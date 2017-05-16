/*-------------------- Rbs - menu.c - Menu for user interface-----------------
**----------------Authors: Breno Campos Ferreira Guimaraes---------------------
**-------------------------Alberto Nonato Passini------------------------------
**-------------------------Germano Luis Marques Moura Leite--------------------
*/

/*number of options in each menu/submenu*/
#define Itens_Main_Menu 3
#define Itens_Part1_Menu 4
#define Itens_Part2_Menu 5
#define Itens_Part3_Menu 1

/*definition of color types (this must be in this file, because HandyBoard)*/
#define red 0
#define green 1
#define blue 2

/*the arrays that contain the menu options*/
char MainMenu[Itens_Main_Menu][40] = {"1- Movement", "2- Sensors", "3- Decisions"};
char Part1Menu[Itens_Part1_Menu][40] = {"1- Line", "2- Triangle", "3- Square", "4- Return"};
char Part2Menu[Itens_Part2_Menu][40] = {"1- Red", "2- Green", "3- Blue", "4- Distance", "5- Return"};
char Part3Menu[Itens_Part3_Menu][40] = {"1- Return"};


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
        }        
        case 1: {  
            part2_menu();  
        }
        case 2: {    
            light_led(blue);
        }
        case 3: {
            line();
        }
        case 4: {
            triangle();
        }
        case 5: {
            square();
        }
        case 6: {
            start_menu();
        }
        case 7: {    
            light_led(red);
        }
        case 8: {
            light_led(green);
        }
        case 9: {
            light_led(blue);
        }
        case 10: {
            readDistance();
        }
        case 11: {
            start_menu();
        }
        case 12: {
            start_menu();
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
            printf("%s\n",Part1Menu[i]);
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
