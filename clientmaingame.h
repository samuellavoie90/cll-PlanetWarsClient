#ifndef CLIENTMAINGAME_H
#define CLIENTMAINGAME_H

#include <QMainWindow>

namespace Ui {
    class ClientMainGame;
}

class ClientMainGame : public QMainWindow
{
    Q_OBJECT

public:
    explicit ClientMainGame(QWidget *parent = 0);
    ~ClientMainGame();

private:
    Ui::ClientMainGame *ui;
};

#endif // CLIENTMAINGAME_H
