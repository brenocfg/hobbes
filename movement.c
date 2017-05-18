/*--------------- Róbs - movement.c - Movement/motor interfacing --------------
**----------------Authors: Breno Campos Ferreira Guimaraes---------------------
**-------------------------Alberto Nonato Passini------------------------------
**-------------------------Germano Luis Marques Moura Leite--------------------
*/

/*global variable that determines whether the timer is running*/
int timer_running;

/*backs up a tiny amount, to avoid hitting blocks*/
void back() {
    bothMotors(-78, -84);
    sleep(0.5);
    ao();
}
    

/*turns left 90 degrees*/
void turn90degreesLeft() {
    bothMotors(-73, 80);
    sleep(1.75);
    ao();
}

/*turns right 90 degrees*/
void turn90degrees() {
    bothMotors(73, -80);
    sleep(1.75);
    ao();
}

/*turns right 135 degrees*/
void turn135degrees(){
    bothMotors(73, -80);
    sleep(2.5);
    ao();
}

/*turns on both motors with the given intensities*/
void bothMotors(int left, int right) {
    motor(0, left);
    motor(3, right);
}


/*walks in a straight line for roughly 30cm*/
void line(){
    int i;
    int left = 55;
    int right = 61;
    for (i = 0; i < 18; i++) {
        bothMotors(left, right);
        left++;
        right++;
        sleep(0.13);
    }
    bothMotors(78, 84);
    sleep(2.1);
    bothMotors(0, 0);
}

/*walks in a straight line for roughly 42cm*/
void longline(){
    int i;
    int left = 55;
    int right = 61;
    for (i = 0; i < 18; i++) {
        bothMotors(left, right);
        left++;
        right++;
        sleep(0.13);
    }
    bothMotors(78, 84);
    sleep(4.2);
    bothMotors(0, 0);
}

/*performs the first course, going in a straight line then back*/
void lineAndTurn() {
    line();
    turn90degrees();
    turn90degrees();
    line();
}

/*performs the "triangle" shape motion, making three lines and two turns*/
void triangle() {
    line();
    turn90degrees();
    line();
    turn135degrees();
    longline();
}

/*makes the "square" shape motion, making 4 lines and three turns*/
void square(){
    line();
    turn90degrees();
    line();
    turn90degrees();
    line();
    turn90degrees();
    line();
}

void explore() {
    int i;
    int distance = 255;
    int colors[3] = {0, 0, 0};
    int blockColor;  
    int timerid;

    /*starts timer thread (process, but whatever)*/ 
    timerid = start_process(timer(10.0));
    timer_running = 1;

    /*move forward while timer is running or no blocks have been found*/
    bothMotors(78, 84);
    while (distance > 100 && timer_running) {
        distance = analog(5);
    }
    ao();
    
    /*no obstacle, timer ran out, go back to main menu*/
    if (kill_process(timerid)) {
        start_menu();
    }
    
    /*if we get to this point, then there was an obstacle, so ID color*/
    colors[0] = light_led(red, 100);
    colors[1] = light_led(green, 100);
    colors[2] = light_led(blue, 100);
    
    /*adjust blue measurement*/
    colors[2] = (int) ((float)colors[2] * 0.7);
    
    /*get color and back up*/
    blockColor = get_color(colors[0], colors[1], colors[2]);
    back();
    
    /*decide what to do based on block color*/
    switch(blockColor) {
        /*red -> turn 180 degrees and go explore again*/
        case red: {
            turn90degrees();
            turn90degrees();
            explore();
            break;
        }
        /*green -> turn 360 degrees and stop completely*/
        case green: {
            turn90degrees();
            turn90degrees();
            turn90degrees();
            turn90degrees();
            break;
        }
        /*blue -> turn right 90 degrees and go exploring*/
        case blue: {
            turn90degrees();
            explore();
            break;
        }
        /*yellow -> turn left 90 degrees and go explore*/
        case yellow: {
            turn90degreesLeft();
            explore();
            break;
        }
        /*black or whatever else -> do nothing*/
        default: {
            break;
        }
    }
    start_menu();
}
