// This is core/vgui/impl/qt/vgui_qt_window.h
#ifndef VGUI_QT_WINDOW_H_
#define VGUI_QT_WINDOW_H_
//:
// \file
// \brief qt windows
// \author Joris Schouteden, ESAT, K.U.Leuven
//
// \verbatim
//  Modifications
//   24.03.2000 JS  Initial Version, adapted from vgui_gtk_window
//   14.11.2005 Chanop Silpa-Anan  adapted to QT 3.3.5 for X11/Mac
//   02.05.2007 Christoph_John@gmx.de ported to QT 4.2.2
// \endverbatim

#include <vgui/vgui_window.h>
#include <vgui/vgui_menu.h>

#include "vgui_qt_statusbar.h"
#include "vgui_qt_adaptor.h"

#include <q3mainwindow.h>
#include <qobject.h>

class vgui_gtk_adaptor;

//: QT implementation of vgui_window.
class vgui_qt_window :
   public Q3MainWindow,
   public vgui_window
{
 public:
   vgui_qt_window(int w, int h, const vgui_menu& menu, const char* title);
   vgui_qt_window(int w, int h, const char* title);
  ~vgui_qt_window() { };

   void set_menubar(const vgui_menu &menu);

   vgui_statusbar* get_statusbar() { return &statusbar; }
   vgui_adaptor* get_adaptor() { return adaptor; };

   void show() { Q3MainWindow::show(); };
   void hide() { Q3MainWindow::hide(); };

 private:
   void setup_widget(int w, int h, const char* title);

   vgui_qt_adaptor*  adaptor ;
   vgui_qt_statusbar statusbar;

   bool use_menubar;
   bool use_statusbar;
};

#endif // VGUI_QT_WINDOW_H_
