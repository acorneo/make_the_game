#include "app/EngineApplication.hpp"
int main()
{
    EngineApplication application;
    application.init();
    application.process();
    application.close();
}