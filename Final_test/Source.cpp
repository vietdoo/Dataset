#include<iostream>
#include <string>
#include <z3++.h>
using namespace std;
using namespace z3;

int main() {
    config cfg;
    cfg.set("auto_config", true);
    context c(cfg);

    expr x = c.real_const("x");
    expr y = c.real_const("y");

    solver s(c);
    s.add(pw(x) == 3);
   // s.add(4 * x * x + 20 * (y * y) - 12 * x - 60 * y == -49);
   // s.add((x + 4) * (x + 4) + (y - 3) * (y - 3) == 25);
    //s.add((x + 10) * (x + 10) + (y - 3) * (y - 3) == 1);


    if (!s.check()) {
        std::cout << "NULL KHONG GIAO\n";
        return 0;
    } 
    model m = s.get_model(); 

    set_param("pp.decimal", true);
    std::cout << (m) << "\n";

    expr_vector myVars(c);
    myVars.push_back(x);
    myVars.push_back(y);


    expr_vector blocker(c);

    cout << m.eval(myVars[0]) << endl;
    cout << m.eval(myVars[1]) << endl;

    

}