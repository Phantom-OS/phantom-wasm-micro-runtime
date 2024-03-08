// 
//
// 

double calculate_e(int N) {
    double fac = 1.0;
    double e = 1.0;

    for (int n = 1; n <= N; n++) {
        fac *= n;
        e += 1.0 / fac;
    }

    return e;
}
