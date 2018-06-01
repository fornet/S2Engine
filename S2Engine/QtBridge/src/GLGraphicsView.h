// GLGraphicsView.h
//
#ifndef GUITOOLS_GLGRAPHICSVIEW_H
#define GUITOOLS_GLGRAPHICSVIEW_H

#include "QtBridge_API.h"

#include <QGraphicsView>

namespace QtBridge{

class GLGraphicsScene;

class QTBRIDGE_API GLGraphicsView : public QGraphicsView
{
public:
    GLGraphicsView( QWidget *parent = Q_NULLPTR, QFrame::Shape shape = QFrame::Shape::StyledPanel );
    GLGraphicsView( GLGraphicsScene *scene, QWidget *parent = Q_NULLPTR, QFrame::Shape shape = QFrame::Shape::StyledPanel );
	virtual ~GLGraphicsView() {}
    
    void setScene( GLGraphicsScene *scene );

protected:
	void showEvent   ( QShowEvent *e );
	void resizeEvent ( QResizeEvent *e );
	void leaveEvent	 ( QEvent *e );
	void enterEvent	 ( QEvent *e );
};

}


#endif