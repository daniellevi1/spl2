#include "../include/Action.h"
#include <string>
#include <iostream>

BaseAction::BaseAction() {

}

ActionStatus BaseAction::getStatus() const {
    return COMPLETED;
}

std::string BaseAction::toString() const {
}