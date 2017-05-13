#define Itens_Main_Menu 3
#define Itens_Part1_Menu 4

char MainMenu[Itens_Main_Menu][40] = {"1- Movement", "2- Sensors", "3- Decisions"};
char Part1Menu[Itens_Part1_Menu][40] = {"1- Line", "2- Triangle", "3- Square", "4- Return"};

void start_menu()
{
    int i = 0;
    int option;
    
    while(1)   
      {
        while((!start_button()) || (!stop_button()))
          {    
            printf("%s\n",MainMenu[i]);
            msleep(100L);
            
            if ( start_button() )
              {
                executeItem(i);
                while (start_button());
            }
            if ( stop_button() )
              {
                i = (i + 1)% Itens_Main_Menu;  
                while (stop_button());
            }
        }
        
    }
    
}

void executeItem(int MenuOption) {
    switch(MenuOption) {
        case 0: {
            part1_menu();
        }        
        case 1: {  
            light_led(green);  
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
    }
}

void part1_menu()
{
    int i = 0;
    int option;
    
    while(1)   
      {
        while((!start_button()) || (!stop_button()))
          {    
            printf("%s\n",Part1Menu[i]);
            msleep(100L);
            
            if ( start_button() )
              {
                executeItem(i+Itens_Main_Menu);
                while (start_button());
            }
            if ( stop_button() )
              {
                i = (i + 1)% Itens_Part1_Menu;  
                while (stop_button());
            }
        }
        
    }
    
}

void soundtrack () {
    while(1) {
        //missionImpossible();
    }
}

#define red 0
#define green 1
#define blue 2

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
