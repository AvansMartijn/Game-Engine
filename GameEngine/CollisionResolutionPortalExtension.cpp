#include "pch.h"
#include "CollisionResolutionPortalExtension.h"

CollisionResolutionPortalExtension::CollisionResolutionPortalExtension()
{
    type = "AbstractCollisionResolutionExtension";
}

bool CollisionResolutionPortalExtension::isDefault()
{
    return false;
}

void CollisionResolutionPortalExtension::link(shared_ptr<GameObject> linkedPortal) 
{
    _linkedPortal = linkedPortal;
}

void CollisionResolutionPortalExtension::resolveCollision(shared_ptr<GameObject> inputObject)
{
    //culling duplicate to prevent double operations
    auto objectLocation = std::find_if(Physics::getInstance().teleportQueue.begin(), Physics::getInstance().teleportQueue.end(), [inputObject](TeleportObject tellie) {return tellie.obj == inputObject; });
    if (objectLocation != Physics::getInstance().teleportQueue.end()) {
        return;
    }
   
    shared_ptr<CollisionResolutionPortalExtension> otherPortalExtension = dynamic_pointer_cast<CollisionResolutionPortalExtension>(_linkedPortal->getExtension(typeid(AbstractCollisionResolutionExtension)));
    if (!isActive || !otherPortalExtension->isActive) {
        return;
    }
    std::string otherExitSide = otherPortalExtension->exitSide;
    b2Vec2 newPos{ _linkedPortal->body.b2body->GetPosition().x,_linkedPortal->body.b2body->GetPosition().y };
    float diagonal = sqrt(pow(inputObject->body.width, 2) + pow(inputObject->body.height, 2));

    if (otherExitSide == "top") {
        newPos.y -= diagonal;
    }
    else if (otherExitSide == "bottom") {
        newPos.y += diagonal;
    }
    else if (otherExitSide == "left") {
        newPos.x -= diagonal;
    }
    else if (otherExitSide == "right") {
        newPos.x += diagonal;

    }

    float velX = inputObject->body.b2body->GetLinearVelocity().x;
    float velY = inputObject->body.b2body->GetLinearVelocity().y;

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
    if (velY > 50) {
        velY = 50;
    }
    std::cout << inputObject->body.b2body->GetLinearVelocity().x << " | " << inputObject->body.b2body->GetLinearVelocity().y << "\n";
    inputObject->body.b2body->SetLinearVelocity({ velX, velY });
    std::cout << inputObject->body.b2body->GetLinearVelocity().x << " | " << inputObject->body.b2body->GetLinearVelocity().y << "\n";


    
    Physics::getInstance().teleportQueue.push_back({ inputObject, newPos, {velX, velY}, true });
}

float CollisionResolutionPortalExtension::reverseFloat(float number) {
    if (number < 0) {
        return fabs(number);
    }
    else {
        return number * -1;
    }
}

std::string CollisionResolutionPortalExtension::getEntrySide(std::string exitSide) {
    if (exitSide == "top") {
        return "bottom";
    }
    else if (exitSide == "bottom") {
        return "top";
    }
    else if (exitSide == "left") {
        return "right";
    }
    else {
        return "left";
    }
    
}



