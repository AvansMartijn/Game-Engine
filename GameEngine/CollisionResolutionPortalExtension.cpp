#include "pch.h"
#include "CollisionResolutionPortalExtension.h"

CollisionResolutionPortalExtension::CollisionResolutionPortalExtension() {
    type = "AbstractCollisionResolutionExtension";
}

bool CollisionResolutionPortalExtension::isDefault() {
    return false;
}

void CollisionResolutionPortalExtension::link(GameObject* linkedPortal) {
    _linkedPortal = linkedPortal;
}

void CollisionResolutionPortalExtension::resolveCollision(GameObject* inputObject) {
    //culling duplicate to prevent double operations
    auto objectLocation = std::find_if(Physics::getInstance().teleportQueue.begin(), Physics::getInstance().teleportQueue.end(), [inputObject](TeleportObject tellie) {return tellie.obj == inputObject; });
    if (objectLocation != Physics::getInstance().teleportQueue.end())
        return;
   
    CollisionResolutionPortalExtension* otherPortalExtension = _linkedPortal->getExtension<CollisionResolutionPortalExtension, AbstractCollisionResolutionExtension>();
    if (!isActive || !otherPortalExtension->isActive)
        return;

    std::string otherExitSide = otherPortalExtension->exitSide;
    Vec2 newPos = { _linkedPortal->body.getPosition().x, _linkedPortal->body.getPosition().y };
    float diagonal = sqrt(pow(inputObject->body.width, 2) + pow(inputObject->body.height, 2));

    if (otherExitSide == "top")
        newPos.y -= diagonal;
    else if (otherExitSide == "bottom")
        newPos.y += diagonal;
    else if (otherExitSide == "left")
        newPos.x -= diagonal;
    else if (otherExitSide == "right")
        newPos.x += diagonal;

    float velX = inputObject->body.getLinearVelocity().x;
    float velY = inputObject->body.getLinearVelocity().y;

    if (exitSide == "top") {
        if (otherExitSide == "top") {
            // reverse y axis
            velY = reverseFloat(velY);
        }
        else if (otherExitSide == "left") {
            float tempVel = velX;
            // +y axis to -x axis
            velX = reverseFloat(velY);
            // x axis to y axis
            velY = tempVel;
        }
        else if (otherExitSide == "right") {
            float tempVel = velX;
            // +y axis to + x axis
            velX = velY;
            // x axis to y axis
            velY = tempVel;
        }
    }
    else  if (exitSide == "bottom") {
        if (otherExitSide == "bottom") {
            // reverse y axis
            velY = reverseFloat(velY);
        }
        else if (otherExitSide == "left") {
            float tempVel = velX;
            // -y axis to -x axis
            velX = velY;
            // x axis to y axis
            velY = tempVel;
        }
        else if (otherExitSide == "right") {
            float tempVel = velX;
            // -y axis to + x axis
            velX = reverseFloat(velY);
            // x axis to y axis
            velY = tempVel;
        }
    } 
    else  if (exitSide == "left") {
        if (otherExitSide == "left") {
            //reverse x axis
            velX = reverseFloat(velX);
        }
        else if (otherExitSide == "bottom") {
            float tempVel = velY;
            // +x axis to +y axis
            velY = velX;
            // y axis to x axis
            velX = tempVel;
        }
        else if (otherExitSide == "top") {
            float tempVel = velY;
            // +x axis to -y
            velY = reverseFloat(velX);
            // y axis to x axis
            velX = tempVel;
        }
    }
    else  if (exitSide == "right") {
        if (otherExitSide == "right") {
            //reverse x axis
            velX = reverseFloat(velX);
        }
        else if (otherExitSide == "bottom") {
            float tempVel = velY;
            // -x axis to +y axis
            velY = reverseFloat(velX);
            // y axis to x axis
            velX = tempVel;
        }
        else if (otherExitSide == "top") {
            float tempVel = velY;
            // -x axis to -y
            velY = velX;
            // y axis to x axis
            velX = tempVel;
        }
    }
    if (velY > 30)
        velY = 30;
    
    Physics::getInstance().teleportQueue.push_back({ inputObject, newPos, {velX, velY}, true });
}

float CollisionResolutionPortalExtension::reverseFloat(float number) {
    if (number < 0)
        return fabs(number);
    else
        return number * -1;
}

std::string CollisionResolutionPortalExtension::getEntrySide(std::string exitSide) {
    if (exitSide == "top")
        return "bottom";
    else if (exitSide == "bottom")
        return "top";
    else if (exitSide == "left")
        return "right";
    else
        return "left";    
}



