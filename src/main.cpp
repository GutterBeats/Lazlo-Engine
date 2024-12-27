#include "core/Application.h"

int main(int argc, char *argv[])
{
    Lazlo::ApplicationConfig config;
    config.Dimensions.X = 800;
    config.Dimensions.Y = 600;
    config.Title = "Lazlo Engine";

    Lazlo::Application application(config);

    if (!application.Initialize())
    {
        return -1;
    }

    application.Run();
    application.Shutdown();

    return 0;
}
