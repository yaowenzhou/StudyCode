#include <QApplication>
#include "Butterfly"
#include <QGraphicsScene>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();
    QGraphicsScene *scene = new QGraphicsScene;
    scene->setSceneRect(QRectF(-200, -200, 400, 400));
    Butterfly *butterfly = new Butterfly;
    butterfly->setPos(-100, 0);
    scene->addItem(butterfly);

    QGraphicsView *view = new QGraphicsView;
    view->setScene(scene);
    view->resize(400, 400);
    view->show();

    QGraphicsView *view1 = new QGraphicsView;
    view1->setScene(scene);
    view1->resize(400, 400);
    view1->show();

    QGraphicsView *view2 = new QGraphicsView;
    view2->setScene(scene);
    view2->resize(400, 400);
    view2->show();

    return a.exec();
}
