#include "Bar.h"

using namespace sdds;
int main() {
	Bar b;
    for (int i = 1; i <= 5; i++) {
        b.set("the bar", '=', i * 20);
        b.draw();
    }
    b.set("Bad Bar", '=', -200);
    b.draw();
    b.set("Bad Bar", '=', 200);
    b.draw();
    return 0;
}