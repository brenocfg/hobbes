/*-------------------- Robs - util.c - Utiliy functions ---- ------------------
**----------------Authors: Breno Campos Ferreira Guimaraes---------------------
**-------------------------Alberto Nonato Passini------------------------------
**-------------------------Germano Luis Marques Moura Leite--------------------
*/

int abs (int n) {
    if (n & (1<<15)) {
        return n * (-1);
    }
    return n;
}

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

void timer(float time) {
    sleep(time);
    ao();
}
