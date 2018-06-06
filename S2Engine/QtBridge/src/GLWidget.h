// GLWidget.h
//
#ifndef GUITOOLS_GLWIDGET_H
#define GUITOOLS_GLWIDGET_H

#include "QtBridge_API.h"

#include <QOpenGLWidget>

namespace QtBridge{


/**
Context Sharing
When multiple QOpenGLWidgets are added as children to the same top-level widget,
their contexts will share with each other. 
This does not apply for QOpenGLWidget instances that belong to different windows.

This means that all QOpenGLWidgets in the same window can access each other's sharable resources,
like textures, and there is no need for an extra "global share" context, as was the case with QGLWidget.

To set up sharing between QOpenGLWidget instances belonging to different windows,
set the Qt::AA_ShareOpenGLContexts application attribute before instantiating QApplication.
This will trigger sharing between all QOpenGLWidget instances without any further steps.
**/

class GLWidget: public QOpenGLWidget
{
	Q_OBJECT

public:
    GLWidget( QWidget *parent = Q_NULLPTR );
	virtual ~GLWidget();

protected:
    void initializeGL() override;

signals:
	void openGLInitialized();
};

}


#endif