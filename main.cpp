#include "core/Application.h"


int main(){
Application app(
    "assets/shader/triangle.vert",
    "assets/shader/triangle.frag"
);

app.run();

}
