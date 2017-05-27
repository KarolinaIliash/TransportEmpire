#include "Server/Controllers/UserController.h"

#include "Model/User.h"
#include "Model/Credentials.h"

Reply UserController::login(const Request& request)
{
    Credentials provided{ request.getData() };

    return Reply(request);
}

void UserController::onRequestReceived(const Request& request)
{
    switch(request.getCommand())
    {
    case Command::LOGIN:
        emit replyReady(login(request));
        break;
    }
}
