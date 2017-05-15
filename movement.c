void bothMotors(int left, int right) {
    motor(3, left);
    motor(0, right);
}

void turn90degrees() {
    bothMotors(73, -80);
    sleep(2.0);
}

void turn135degrees(){
    bothMotors(73, -80);
    sleep(3.0);
}

void line(){
    int i;
    int left = 55;
    int right = 57;
    for (i = 0; i < 18; i++) {
        bothMotors(left, right);
        left++;
        right++;
        sleep(0.13);
    }
    bothMotors(73, 76);
    sleep(2.35);
    bothMotors(0, 0);
}

void longline(){
    int i;
    int left = 55;
    int right = 57;
    for (i = 0; i < 18; i++) {
        bothMotors(left, right);
        left++;
        right++;
        sleep(0.13);
    }
    bothMotors(73, 76);
    sleep(3.9);
    bothMotors(0, 0);
}

void triangle(){
    line();
    turn135degrees();
    longline();
    turn135degrees();
    line();
}

void square(){
    line();
    turn90degrees();
    line();
    turn90degrees();
    line();
    turn90degrees();
    line();
}
