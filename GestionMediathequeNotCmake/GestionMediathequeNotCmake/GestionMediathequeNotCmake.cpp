#include "Api.h"



//TODO std::map dangereuse en lecture mais efficace quand il y a beaucoup d'entrée sinon utiliser un std::vecor
// revoir lambda et std::function



int main()
{
    Library_Manager::API api;
    api.cmd_init();
    api.cmd_input();
    return 0;
}