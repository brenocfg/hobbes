/*-------------------- Róbs - util.c - Utiliy functions ---- ------------------
**----------------Authors: Breno Campos Ferreira Guimaraes---------------------
**-------------------------Alberto Nonato Passini------------------------------
**-------------------------Germano Luis Marques Moura Leite--------------------
*/

/*returns absolute value (modulus) of an int*/
int abs (int n) {
    if (n & (1<<15)) {
        return n * (-1);
    }
    return n;
}

/*returns the INDEX (0, 1 or 2) of the minimum between 3 numbers*/
int min(int a, int b, int c) {
    int min = 0;
    int m = a;
    if (m > b) {
        m = b;
        min = 1;
    }
    if (m > c) {
        m = c;
        min = 2;
    }
    return min;
}

/*initiates a timer of @time seconds*/
void timer(float time) {
    sleep(time);
    timer_running = 0;
}
