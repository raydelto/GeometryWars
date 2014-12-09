#include "Utility/package.hpp"

#include "package.h"

//---------------------------------------------------------------------------------
// Written by Terence J. Grant - tjgrant [at] tatewake [dot] com
// Find the full tutorial at: http://gamedev.tutsplus.com/series/
//----------------------------------------------------------------------------------

Bullet::Bullet(const tPoint2f& position, const tVector2f& velocity)
{
    mImage = Art::getInstance()->getBullet();
    mPosition = position;
    mVelocity = velocity;
    mOrientation = atan2f(mVelocity.y, mVelocity.x);
    mRadius = 8;
    mKind = kBullet;
}

void Bullet::update()
{
    if (mVelocity.lengthSquared() > 0)
    {
        mOrientation = atan2f(mVelocity.y, mVelocity.x);
    }

    mPosition += mVelocity;

    if (!tRectf(0, 0, GameRoot::getInstance()->getViewportSize()).contains(tPoint2f((int32_t)mPosition.x, (int32_t)mPosition.y)))
    {
        mIsExpired = true;
    }
}