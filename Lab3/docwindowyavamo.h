#ifndef DOCWINDOWYAVAMO_H
#define DOCWINDOWYAVAMO_H

#include <QTextEdit>
#include <QColorDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QColorDialog>

class DocWindowYavAmo : public QTextEdit
{
    Q_OBJECT
private:
    QString m_strFileName;
public:
    DocWindowYavAmo(QWidget* pwgt = 0);
signals:
    void changeWindowTitle(const QString&);

public slots:
void slotLoad();
void slotSave();
void slotSaveAs();
void slotColor();

};

#endif // DOCWINDOWYAVAMO_H
