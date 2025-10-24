//
// Created by janbu on 24.10.2025.
//

#pragma once

#include <wx/wx.h>

#define $APP_NAME "wxWidgets Template"
#define $APP_VERSION "v1.0"
#define $APP_VENDOR "org.janbuchholz"
#define $APP_CONFIG ""
#define $APP_TITLE wxString("wxWidgets Template") + " " + $APP_VERSION + " " + wxString("(w) 2025 Jan Buchholz")
#define $WELCOME _("Welcome to wxWidgets!")

#define $MENU_FILE _("File")
#define $MENU_EDIT _("Edit")
#define $MENU_HELP _("Help")

#define $MENU_FILE_NEW _("&New\tCtrl-N")
#define $MENU_FILE_OPEN _("&Open\tCtrl-O")
#define $MENU_FILE_SAVE _("&Save\tCtrl-S")
#define $MENU_FILE_SAVE_AS _("&Save as")
#define $MENU_FILE_EXIT _("&Quit\tCtrl-Q")

#define $MENU_EDIT_COPY _("&Copy\tCtrl-C")
#define $MENU_EDIT_CUT _("&Cut\tCtrl-X")
#define $MENU_EDIT_PASTE _("&Paste\tCtrl-V")
#define $MENU_EDIT_SELECT_ALL _("&Select all\tCtrl-A")
#define $MENU_EDIT_UNDO _("&Undo\tCtrl-Z")
#define $MENU_EDIT_REDO _("&Redo\tCtrl-Y")
#define $MENU_EDIT_PREFERENCES _("&Preferences")

#define $MENU_HELP_ABOUT _("&About")

#define $TIP_FILE_NEW _("Create new file")
#define $TIP_FILE_OPEN _("Open file")
#define $TIP_FILE_SAVE _("Save file")
#define $TIP_FILE_SAVE_AS _("Save file under a different name or in a different location")
#define $TIP_FILE_EXIT _("Quit application")

#define $TIP_EDIT_COPY _("Copy selection")
#define $TIP_EDIT_CUT _("Cut selection")
#define $TIP_EDIT_PASTE _("Paste selection")
#define $TIP_EDIT_SELECT_ALL _("Select all")
#define $TIP_EDIT_UNDO _("Undo last action")
#define $TIP_EDIT_REDO _("Redo last action")
#define $TIP_EDIT_PREFERENCES _("Application preferences")

#define $TIP_HELP_ABOUT _("About") + " " + $APP_NAME

#define $TEXT_ABOUT _("This is a wxWidgets template")

#define $CONFIG_WINDOW_SIZE_X "window/size/x"
#define $CONFIG_WINDOW_SIZE_Y "window/size/y"
#define $CONFIG_WINDOW_POSITION_X "window/position/x"
#define $CONFIG_WINDOW_POSITION_Y "window/position/y"
