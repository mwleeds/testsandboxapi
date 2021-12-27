/* testsandboxapi-window.c
 *
 * Copyright 2021 Phaedrus Leeds
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "testsandboxapi-config.h"
#include "testsandboxapi-window.h"
#include <libportal/portal.h>

struct _TestsandboxapiWindow
{
  GtkApplicationWindow  parent_instance;

  /* Template widgets */
  GtkHeaderBar        *header_bar;
  GtkLabel            *label;
};

G_DEFINE_TYPE (TestsandboxapiWindow, testsandboxapi_window, GTK_TYPE_APPLICATION_WINDOW)

static void
testsandboxapi_window_class_init (TestsandboxapiWindowClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/com/github/mwleeds/testsandboxapi/testsandboxapi-window.ui");
  gtk_widget_class_bind_template_child (widget_class, TestsandboxapiWindow, header_bar);
  gtk_widget_class_bind_template_child (widget_class, TestsandboxapiWindow, label);
}

static void
testsandboxapi_window_init (TestsandboxapiWindow *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
   g_autoptr(GError) error = NULL;
gboolean flatpak = xdp_portal_running_under_flatpak ();
gboolean snap = xdp_portal_running_under_snap (&error);
gboolean sandbox = xdp_portal_running_under_sandbox ();
g_print ("flatpak = %d, snap = %d, sandbox = %d\n", (int) flatpak, (int) snap, (int) sandbox);
g_print ("snap error = %s\n", error ? error->message : "none");
g_clear_error (&error);

flatpak = xdp_portal_running_under_flatpak ();
snap = xdp_portal_running_under_snap (&error);
sandbox = xdp_portal_running_under_sandbox ();
g_print ("flatpak = %d, snap = %d, sandbox = %d\n", (int) flatpak, (int) snap, (int) sandbox);
g_print ("snap error = %s\n", error ? error->message : "none");
}
