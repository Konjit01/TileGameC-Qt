#ifndef DATAVIEW_H
#define DATAVIEW_H

#include <QObject>

class DataView : public QObject
{
    Q_OBJECT
public:
    explicit DataView(QObject *parent = nullptr);

signals:

};

#endif // DATAVIEW_H
