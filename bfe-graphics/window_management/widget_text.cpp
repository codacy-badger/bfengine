////////////////////////////////////////////////////////////////////////////////
//
// This file is part of BFEngine, a 2D simulation engine.
// Copyright (C) 2017-2019 Torsten Büschenfeld
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
//
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
///
/// \file       widget_text.cpp
/// \brief      Implementation of class "CWidgetText"
///
/// \author     Torsten Büschenfeld (planeworld@bfeld.eu)
/// \date       2017-04-10
///
////////////////////////////////////////////////////////////////////////////////

#include "widget_text.h"

using namespace bfe;

////////////////////////////////////////////////////////////////////////////////
///
/// \brief Constructor, initialising members
///
/// \param _pFontManager Font manager to use for drawing
///
////////////////////////////////////////////////////////////////////////////////
CWidgetText::CWidgetText(CFontManager* const _pFontManager) :
                            IWidget(_pFontManager),
                            Text(_pFontManager)
{
    METHOD_ENTRY("CWidgetText::CWidgetText");
    CTOR_CALL("CWidgetText::CWidgetText");

    m_Type = WidgetTypeType::TEXT;
    
    m_UID.setName("Widget_Text_"+m_UID.getName());
    Text.setText(m_UID.getName());
}

////////////////////////////////////////////////////////////////////////////////
///
/// \brief Draws widget with text included
///
////////////////////////////////////////////////////////////////////////////////
void CWidgetText::draw()
{
    METHOD_ENTRY("CWidgetText::draw")

    m_Graphics.beginRenderBatch("world");
        this->drawFrame();
    m_Graphics.endRenderBatch();
   
    m_Graphics.setColor(1.0, 1.0, 1.0, 1.0);
    
    m_Graphics.beginRenderBatch("font");
        Text.setPosition(m_nFramePosX, m_nFramePosY);
        Text.setWordWrap(m_nFrameWidth);
        Text.display();
    m_Graphics.endRenderBatch();
    
    DOM_DEV(
        static bool bWarned = false;
        if (m_pUIDVisuals == nullptr)
        {
            if (!bWarned)
            {
                WARNING_MSG("Text Widget", "UID visuals not set.")
                bWarned = true;
            }
            goto DomDev;
        })
//     m_pUIDVisuals->draw(m_nFramePosX, m_nFramePosY, "Widget Text", m_UID.getValue());
    DOM_DEV(DomDev:)
}
