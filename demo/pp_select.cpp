#include <splat/pp_select.h>
#include <iostream>

#define move_single(a, _) a = std::move(a)
#define movecap(...) SPLAT_ITERATE_WITH(move_single, __VA_ARGS__)

int main() {
    std::string hello = "hello", world = "world";

    auto greet = [movecap(hello, world)] {
        std::cout << hello << " " << world << "\n";
    };

    greet();
}
