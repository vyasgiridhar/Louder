/* louder-application.c
 *
 * Copyright (C) 2017 Vyas Giridharan <vyasgiridhar27@gmail.com>
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

#include "louder-application.h"
#include "louder-window.h"


struct _LouderApplication
{
  GtkApplication parent;
};

typedef struct
{

} LouderApplicationPrivate;

G_DEFINE_TYPE_WITH_PRIVATE (LouderApplication, louder_application, GTK_TYPE_APPLICATION)

enum {
	PROP_0,
	N_PROPS
};

static GParamSpec *properties [N_PROPS];

LouderApplication *
louder_application_new (void)
{
	return g_object_new (LOUDER_TYPE_APPLICATION,
			     "application-id","org.vyasg.louder",
			     "flags",G_APPLICATION_HANDLES_OPEN,
			     NULL);
}

static void
louder_application_finalize (GObject *object)
{
	LouderApplication *self = (LouderApplication *)object;
	LouderApplicationPrivate *priv = louder_application_get_instance_private (self);

	G_OBJECT_CLASS (louder_application_parent_class)->finalize (object);
}

static void
louder_application_get_property (GObject    *object,
                                 guint       prop_id,
                                 GValue     *value,
                                 GParamSpec *pspec)
{
	LouderApplication *self = LOUDER_APPLICATION (object);

	switch (prop_id)
	  {
	  default:
	    G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
	  }
}

static void
louder_application_set_property (GObject      *object,
                                 guint         prop_id,
                                 const GValue *value,
                                 GParamSpec   *pspec)
{
	LouderApplication *self = LOUDER_APPLICATION (object);

	switch (prop_id)
	  {
	  default:
	    G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
	  }
}

static void
louder_application_activate (GApplication *app)
{
  LouderWindow *win;

  win = louder_window_new ();
  gtk_window_present (GTK_WINDOW (win));
}

static void
louder_application_open (GApplication  *app,
                         GFile        **files,
                         gint           n_files,
                         const gchar   *hint)
{

  LouderWindow *louder_window;

  louder_window = louder_window_new ();

  gtk_window_present (GTK_WINDOW (louder_window));
}

static void
louder_application_class_init (LouderApplicationClass *klass)
{
	GObjectClass *object_class = G_OBJECT_CLASS (klass);

	object_class->finalize = louder_application_finalize;
	G_APPLICATION_CLASS (object_class)->open = louder_application_open;
  	G_APPLICATION_CLASS (object_class)->activate = louder_application_activate;
	object_class->get_property = louder_application_get_property;
	object_class->set_property = louder_application_set_property;
}

static void
louder_application_init (LouderApplication *self)
{
}
