/*
 * ct_app.h
 * 
 * Copyright 2017-2018 Giuseppe Penone <giuspen@gmail.com>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 */

#include <iostream>
#include <unordered_map>

#include <glibmm/i18n.h>
#include <gtkmm.h>

#include "ct_config.h"
#include "ct_main_win.h"

class CtTmp
{
public:
    CtTmp();
    virtual ~CtTmp();
    const gchar* getHiddenDirPath(const std::string& visiblePath);
    const gchar* getHiddenFilePath(const std::string& visiblePath);

protected:
    std::unordered_map<std::string,gchar*> _mapHiddenDirs;
    std::unordered_map<std::string,gchar*> _mapHiddenFiles;
};

class CtApp: public Gtk::Application
{
protected:
    CtApp();
    virtual ~CtApp();

public:
    static Glib::RefPtr<CtApp> create();

    static CtConfig* P_ctCfg;
    static Glib::RefPtr<Gtk::IconTheme> R_icontheme;
    static CtTmp* P_ctTmp;
    static Glib::RefPtr<Gtk::TextTagTable> R_textTagTable;
    static Glib::RefPtr<Gsv::LanguageManager> R_languageManager;
    static Glib::RefPtr<Gsv::StyleSchemeManager> R_styleSchemeManager;
    static Glib::RefPtr<Gtk::CssProvider> R_cssProvider;

protected:
    void on_activate() override;
    void on_open(const Gio::Application::type_vec_files& files, const Glib::ustring& hint) override;

    void _printHelpMessage();
    void _printGresourceIcons();
    void _iconthemeInit();

private:
    CtMainWin* create_appwindow();
    void on_hide_window(Gtk::Window* window);
};
