/***************************************************************************
 *   Copyright (C) 2019 by João Netto <joaonetto901@gmail.com>             *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 ***************************************************************************/

#include "kjs_display_p.h"
#include "../form.h"

#include <kjs/kjsobject.h>
#include <kjs/kjsprototype.h>

#include <QString>

#include <memory>

using namespace Okular;

std::unique_ptr < KJSPrototype > g_displayProto;

// display.hidden
static KJSObject displayGetHidden( KJSContext *, void *  )
{
    return KJSNumber( FormField::FormHidden );
}

// display.visible
static KJSObject displayGetVisible( KJSContext *, void *  )
{
    return KJSNumber( FormField::FormVisible );
}

// display.noView
static KJSObject displayGetNoView( KJSContext *, void *  )
{
    return KJSNumber( FormField::FormNoView );
}

// display.noPrint
static KJSObject displayGetNoPrint( KJSContext *, void *  )
{
    return KJSNumber( FormField::FormNoPrint );
}

void JSDisplay::initType( KJSContext *ctx )
{
    if ( g_displayProto )
        return;

    g_displayProto.reset(new KJSPrototype);

    g_displayProto->defineProperty( ctx, QStringLiteral("hidden"), displayGetHidden );
    g_displayProto->defineProperty( ctx, QStringLiteral("visible"), displayGetVisible );
    g_displayProto->defineProperty( ctx, QStringLiteral("noView"), displayGetNoView );
    g_displayProto->defineProperty( ctx, QStringLiteral("noPrint"), displayGetNoPrint );
}

KJSObject JSDisplay::object( KJSContext *ctx )
{
    return g_displayProto->constructObject( ctx, nullptr );
}
