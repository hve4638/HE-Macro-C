#pragma once
#include "precompiled.h"

class IKeyListener {
public:
    virtual LRESULT pressing(PKBDLLHOOKSTRUCT) = 0;
    virtual LRESULT releasing(PKBDLLHOOKSTRUCT) = 0;
};