/*--------------- Rbs - movement.c - Movement/motor interfacing --------------
**----------------Authors: Breno Campos Ferreira Guimaraes---------------------
**-------------------------Alberto Nonato Passini------------------------------
**-------------------------Germano Luis Marques Moura Leite--------------------
*/

/*turns right 90 degrees*/
void turn90degrees() {
    bothMotors(73, -80);
    sleep(2.1);
    ao();
}

/*turns right 135 degrees*/
void turn135degrees(){
    bothMotors(73, -80);
    sleep(3.05);
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
    int right = 63;
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
    int right = 63;
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
