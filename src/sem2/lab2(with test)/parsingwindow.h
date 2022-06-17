#ifndef PARSINGWINDOW_H
#define PARSINGWINDOW_H

#include <QDialog>

namespace Ui {
class ParsingWindow;
}

class ParsingWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ParsingWindow(QWidget *parent = nullptr);
    ~ParsingWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::ParsingWindow *ui;
};

#endif // PARSINGWINDOW_H
