///////////////////////////////////////////////////////////////////////////////
// Name:        wxguidesigner/gui/editor/book.h
// Purpose:     EditorBook: Visual and code editor wxNotebook
// Author:      Andrea Zanellato
// Modified by:
// Created:     2011/11/30
// Revision:    $Hash$
// Copyleft:    (ɔ) Andrea Zanellato
// Licence:     GNU General Public License Version 3
///////////////////////////////////////////////////////////////////////////////
#ifndef __WXGUIDESIGNER_GUI_EDITOR_BOOK_H__
#define __WXGUIDESIGNER_GUI_EDITOR_BOOK_H__

#include <utility>
#include <map>

#include <wx/xml/xml.h>

#include "wxguidesigner/rtti.h"

class wxNotebook;
class wxWindow;

namespace wxGD
{
class Editor;
class Handler;

namespace RTTI
{
class EventPropertyEvent;
class PropertyEvent;
class ObjectEvent;
};

class EditorBook : public wxNotebook
{
public:
    EditorBook( Handler *handler, wxWindow* parent );
    ~EditorBook();

    Editor *GetGUIEditor() const;

private:
    void LoadCodeEditorPages();
    void Reload();
    void SetupWindow        ( wxWindow *window );

    void OnObjectCreated    ( RTTI::ObjectEvent           &event );
    void OnObjectDeleted    ( RTTI::ObjectEvent           &event );
    void OnObjectSelected   ( RTTI::ObjectEvent           &event );
    void OnEventChanged     ( RTTI::EventPropertyEvent    &event );
    void OnPropertyChanged  ( RTTI::PropertyEvent         &event );

    Handler *m_handler;
    Editor  *m_editor;

    typedef std::pair< RTTI::Object, wxObject * > wxGDObject;
    typedef std::map < RTTI::Object, wxObject * > wxGDObjects;
    wxGDObjects     m_objects;
    RTTI::Object    m_oldTop;
};
};

#endif //__WXGUIDESIGNER_GUI_EDITOR_BOOK_H__
