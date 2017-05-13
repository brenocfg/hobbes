void playRobotTheme()
{    
    float B = 493.88;  
    float D = 587.33;   
    float G = 392.00;       
    
    tone(B,0.5);       
    tone(B,0.5);    
    tone(B,0.5);    
    
    tone(G,0.4);     
    tone(D,0.2);           
    tone(B,0.5);        
    
    sleep(0.06);        
    
    tone(G,0.4);        
    tone(D,0.2);        
    tone(B,0.6);   
}

void missionImpossible()
{
    float B = 493.88;
    float Bb= 466.16;    
    float E = 659.25;  
    float G = 783.99;   
    float G_Grave = 392.00;    
    float A = 880.00;       
    float A_Grave = 440.00;     
    
    float D  = 587.33;   
    float Eb = 622.25;   
    
    //1
    tone(E,0.5);       
    tone(E,0.5);
    sleep(0.05);
    
    tone(G,0.3);       
    tone(A,0.3); 
    
    tone(E,0.5);       
    tone(E,0.5);
    sleep(0.05);
    
    tone(D,0.3);       
    tone(Eb,0.3);
    
    //2
    tone(E,0.5);       
    tone(E,0.5);
    sleep(0.05);
    
    tone(G,0.3);       
    tone(A,0.3); 
    
    tone(E,0.5);       
    tone(E,0.5);
    sleep(0.05);
    
    tone(D,0.3);       
    tone(Eb,0.3);
    
    //3
    tone(G,0.2);       
    tone(E,0.2);
    tone(B,1.0);    
    sleep(0.25);
    
    
    //4
    tone(G,0.2);       
    tone(E,0.2);
    tone(Bb,1.0);    
    sleep(0.25);
    
    //5
    tone(G,0.2);       
    tone(E,0.2);
    tone(A_Grave,1.0);    
    sleep(0.25);   
    
    tone(G_Grave,0.2);
    tone(A_Grave,0.2); 
}