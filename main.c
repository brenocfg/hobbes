void main()
{
    int goToMenu = 0;
    poke(0x1009, 0x3c);
    
    while(1)
      {       
        if(!goToMenu)
          {
            printf("Press START for Main Menu!\n");
            while(!start_button());       
            while(start_button());
            goToMenu = 1;
        }
        
        start_menu();
    }
}
