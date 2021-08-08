#include <include/funcs.hpp>
#include <include/types.h>

int main(int, char **)
{
    func<LightBulbSelector>();
    func<BuzzerSelector>("custom");
    return -1;
}
