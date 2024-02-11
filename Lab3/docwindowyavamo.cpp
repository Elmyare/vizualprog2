#include "docwindowyavamo.h"
#include <QFileDialog>

DocWindowYavAmo::DocWindowYavAmo(QWidget* pwgt) : QTextEdit(pwgt)
{

}

void DocWindowYavAmo::slotLoad()
{
    QString str = QFileDialog::getOpenFileName();
    if (str.isEmpty())return;
    QFile file(str);
    if (file.open(QIODevice::ReadOnly))
    {
        QTextStream stream(&file);
        setPlainText(stream.readAll());
        file.close();
        m_strFileName=str;
        emit changeWindowTitle(m_strFileName);
    }
}

void DocWindowYavAmo::slotSaveAs()
{
    QString str = QFileDialog::getSaveFileName(0, m_strFileName);
    if (!str.isEmpty())
    {
        m_strFileName=str;
        slotSave();
    }
}

void DocWindowYavAmo::slotSave()
{
    if(m_strFileName.isEmpty()){
        slotSaveAs();
        return;
    }
    QFile file(m_strFileName);

    if(file.open(QIODevice::WriteOnly))
    {
        QTextStream(&file)<<toPlainText();
        file.close();
        emit changeWindowTitle(m_strFileName);
        QMessageBox::information(this, "Save File", "File saved successfully");
    }
}

void DocWindowYavAmo::slotColor()
{
    setTextColor(QColorDialog::getColor());
}

