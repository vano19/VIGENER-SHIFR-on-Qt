#ifndef VIGENER_H
#define VIGENER_H

#include <QString>
#include <QFile>
#include <QTextStream>
#include <map>
#include <vector>
#include <QDialog>
#include <QLabel>
#include <QTextEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QWidget>
#include <QFileDialog>
#include <QMessageBox>

class Vigener
{
    QString afile;
    Vigener(Vigener&);
    std::vector<char> per;
public:
    Vigener();
    Vigener(std::string name);
    void num_lett() const;
    void goShifr();
    ~Vigener();
};

class Window: public QDialog,
              public Vigener
{
    Q_OBJECT
public:
    Window(QWidget *perent);
    Window();
private:
    QLabel *lbl;
    QTextEdit *line;
    QPushButton *shifr;
    QPushButton *colvo;
    QPushButton *close;
    QPushButton *loading;
private slots:
    inline void clicedLoad()
    {
        QString fileName = QFileDialog::getOpenFileName(this);
        if (fileName.isEmpty())
        {    QMessageBox::information(this, tr("No contacts in file"),
                                      tr("The file you are attempting to open contains no contacts."));
            return;
        }
        else {
            Vigener(static_cast<std::string>(fileName.toStdString()));
        }
    }
    void clicedColvo(){Vigener::num_lett();}
    void clicedShifr(){Vigener::goShifr();}

};



#endif // VIGENER_H
